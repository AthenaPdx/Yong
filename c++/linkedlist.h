#include <iostream>
#include <vector>

struct listNode{

   listNode(int _val):val(_val), next(NULL){};

   void print (){
      listNode* tmp = this;
      while (tmp){
         std::cout << tmp->val << " "; 
         tmp = tmp->next;
      }
      std::cout << std::endl;
   }

   int val;
   listNode* next;
};

listNode* createNodeFromVector(std::vector<int>& V){
   if (V.size() == 0 ) return NULL;
   listNode* head = new listNode(V[0]);
   auto tmp = head;
   for (int i=1; i<V.size(); i++){
      tmp->next = new listNode(V[i]);
      tmp = tmp->next;
   }
   return head;
}

