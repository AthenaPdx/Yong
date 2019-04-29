#include <memory>
#include <unordered_map>
#include <iostream>
#include <string> 

struct trie {

  trie() {cout << "****** constructor" << endl;}

	unordered_map<char, shared_ptr<trie>> items;
  bool isWord;

  ~trie() {cout << "****** destructor" << endl;}

  void display(string& s){
    for (auto& i: item){
       string s2 = s + i.first;
       cout << s2 <<  endl;
       i.second.display(s2);
    }
  }

};

void addWord(shared_ptr<trie> T , string& word){

  auto root = T;
  for (auto i: word){
    if (root->items.count(i)){
			root = items[i];   
    }else{
      auto t = make_shared<trie>();
			root.item[i] = t;
      root = t;
		}
  }
  root->isWord = true;
}

void deleteWord(shared_ptr<trie> T, string & word, bool recur){

	auot root = t;	
	for (auto i: word){
		if (t.count(i) == 0) return;
    root = root->item[i];
  }

  if (root->item.size() == 0){
  
  }
}
