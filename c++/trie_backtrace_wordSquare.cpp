#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <set>

using namespace std;

struct trie{

  char c;
  vector<shared_ptr<trie>> children;
  set<int> idx;

  void display(string s){
     cout << s+c << endl;
     for (auto i: children){
        i->display(s+c);
     }
  }

};

shared_ptr<trie> buildTrie(vector<string>& dict){
   shared_ptr<trie> t = make_shared<trie>();
   for (auto& w: dict){
      auto root = t;
      for (auto c: w){
         bool found = false;
         for (auto& child:root->children){
            if (child->c == c){
               found = true;
               root = child;
               break;
            }
         }
         if (!found){
            auto new_trie = make_shared<trie>();
            new_trie->c = c;
            root->children.push_back(new_trie);
            root = new_trie;
         }
      }
   }
   return t;
}

int main(){
   vector<string> dict = {"a", "ab", "abc", "i", "have", "a", "dream", "ice", "dad"};
   auto root = buildTrie(dict);
   root->display("");
   return 0;
}
	
	


