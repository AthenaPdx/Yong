#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <set>

using namespace std;

struct trie{
  trie():isWord(false){};
  trie(char a):c(a),isWord(false){};
  char c;
  bool isWord;
  set<int> prefix_idx;;
  vector<shared_ptr<trie>> children;
  ~trie(){/*cout << "deleting    : " << c << endl;*/};
};

shared_ptr<trie> buildTrie(vector<string>& dict){
   shared_ptr<trie> t = make_shared<trie>('@');
   for (int i = 0; i<dict.size(); i++){
      auto w = dict[i];
      auto root = t;
      for (auto c: w){
         bool found = false;
         for (auto& child:root->children){
            if (child->c == c){
               found = true;
               root = child;
               root->prefix_idx.insert(i);
               break;
            }
         }
         if (!found){
            auto new_trie = shared_ptr<trie>(new trie(c));
            root->children.push_back(new_trie);
            root = new_trie;
            root->prefix_idx.insert(i);
         }
      }
      root->isWord = true;
   }
   return t;
}

/* It's hard to define findStr inside class. 
 * since children are vector or shared_ptr
 */
shared_ptr<trie> findStr(shared_ptr<trie> root, string s){
   bool found;
	for (auto& item: s){
    found = false;
		for (auto& child : root->children){
			if (child->c == item){
				found = true;
				root = child;
				break;
			}
		}	
    if (!found) return nullptr;
	}
	return root;
}


shared_ptr<trie> findWord(shared_ptr<trie> root, string s){
	auto node = findStr(root, s);
	if (node != nullptr && node->isWord)
		return node;
	else
		return nullptr;
}



void btHelper(vector<string>& dict, vector<string>& guess, int row, int final, shared_ptr<trie> root, vector<vector<string>>& ret){
   if (row == final){
      for (auto i: guess){
         if (findWord(root, i) == nullptr)
					  return;
      }
      ret.push_back(guess);
      return;
   }
   string s = "";
   for (int i=0; i<row; i++) s += guess[i][row];
   auto t = findStr(root, s);
   if (t == nullptr) return;
   for (auto i: t->prefix_idx){
      if (dict[i].size() == guess[0].size()){
         guess.push_back(dict[i]);
				 btHelper(dict, guess, row+1, final, root, ret);
				 guess.pop_back();
      }
   }
}

vector<vector<string>> wordSquare(vector<string>& dict){
	auto root = buildTrie(dict);
  vector<vector<string>> ret;
  for (auto w : dict){
    vector<string> guess;
    guess.push_back(w);
		btHelper(dict, guess, 1, w.size(), root, ret);
    guess.pop_back();
  }
  return ret;
}

int main(){
   vector<string> dict2 = {"a", "ab", "ba", "acd", "ca", "abdg", "bceh", "defi", "ghij", "uvw", "stv", "rsu"};
   auto ret = wordSquare(dict2);
   cout << "word square: \n" << endl;
   for (auto i: ret){
		 for (auto j: i)
        cout << j << endl;
     cout << endl;
   }
   return 0;
}

