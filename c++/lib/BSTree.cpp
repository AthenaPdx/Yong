#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct treeNode{
  treeNode(int v):val(v){};
	int val;
	treeNode* left;
	treeNode* right;
};

treeNode* buildBST(vector<int> V, int start, int end){
  if (start > end) return NULL;
	int mid = start + (end - start)/2;
  auto t = new treeNode(V[mid]);
  t->left = buildBST(V, start,  mid-1);
  t->right = buildBST(V, mid+1, end);
  return t;
}

void printBST(treeNode* root){
	if (!root) return;
  printBST(root->left);
  cout << root->val << " ";	
  printBST(root->right);
}

treeNode* find(treeNode* root, int val){
  if (!root) return NULL;
	if (root->val == val) return root;
  if (root->val < val) return find(root->right, val);
  if (root->val > val) return find(root->left, val);
  return NULL;
}

treeNode* ancestor(treeNode* root){
  auto ret = root->left;
  while (ret && ret->right){
     ret = ret->right;
  }
  return ret;
}

treeNode* descedant(treeNode* root){
	auto ret = root->right;
  while (ret && ret->left){
     ret = ret->left;
  }
  return ret;
}


treeNode* insertBST(treeNode* root, int a){
	if (!root) return new treeNode(a);
  if (a < root->val){
    root->left = insertBST(root->left, a);		
  }else if (a > root->val){
    root->right = insertBST(root->right, a);		
	}else{ 
     cout << "node exist" << endl;
  }
  return root;
}


treeNode* deleteBST(treeNode* root, int a){
	if (!root) return root;
  if (a < root->val){
    root->left = deleteBST(root->left, a);		
  }else if (a > root->val){
    root->right = deleteBST(root->right, a);		
	}else{  // found the node
	   if (root->left) {
		   auto temp = ancestor(root); 
       root->val = temp->val;
       root->left = deleteBST(root->left, root->val);
     }else if (root->right){
		   auto temp = descedant(root); 
       root->val = temp->val;
       root->right = deleteBST(root->right, root->val);
  	 }else{
			 delete (root);
       root = NULL;
     }
  }
  return root;
}

int main(){
	vector<int> V = {1,8,3,7,2,9,4,6,5,10};
  sort(V.begin(), V.end());
  auto root = buildBST(V, 0, V.size()-1);
  printBST(root); cout << endl;

  root = deleteBST(root,5);
  printBST(root); cout << endl;

  root = deleteBST(root,1);
  printBST(root); cout << endl;

  root = deleteBST(root,10);
  printBST(root); cout << endl;

  root = insertBST(root,1);
  printBST(root); cout << endl;

  root = insertBST(root,5);
  root = insertBST(root,10);
  root = insertBST(root,1);
  root = insertBST(root,11);
  printBST(root); cout << endl;
  return 0;
}
