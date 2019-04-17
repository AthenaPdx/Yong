#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <set>

using namespace std;

struct trie{

  trie():isWord(false){cout << "constructing empty" << endl; };
  trie(char a):c(a),isWord(false){
    //cout << "constucting: " << a << endl;
  };
  char c;
  bool isWord;
  set<int> idx;
  vector<shared_ptr<trie>> children;

  ~trie(){
		//cout << "deleting    : " << c << endl;
  };


  void display(string s){
     cout << s+c << endl;
     for (auto i: children){
        i->display(s+c);
     }
  }

};



shared_ptr<trie> findStr(shared_ptr<trie> root, string s){
	bool found;
	for (auto& item: s){
		for (auto& child : root->children){
			if (child->c == item){
				found = true;
				root = child;
				break;
			}
		}	
	}
	if (found) return root;
	else return nullptr;
}

shared_ptr<trie> findWord(shared_ptr<trie> root, string s){
	auto node = findStr(root, s);
	if (node != nullptr && node->isWord)
		return node;
	else
		return nullptr;
}


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
               root->idx.insert(i);
               break;
            }
         }
         if (!found){
            auto new_trie = shared_ptr<trie>(new trie(c));
            root->children.push_back(new_trie);
            root = new_trie;
            root->idx.insert(i);
         }
      }
      root->isWord = true;
   }
   return t;
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

   if (t == nullptr){
       cout << "failed  finding: " << s << endl;
       return;
   }

   for (auto i: t->idx){
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
   vector<string> dict = {"a", "ab", "abc", "i", "have", "a", "dream", "ice", "dad"};
   auto root = buildTrie(dict);
   root->display("");
   cout << "a is a word: " << (findWord(root, "a") == nullptr ? 0 : 1) << endl;
   cout << "dad is a word: " << (findWord(root, "dad") == nullptr ? 0 : 1) << endl;
   cout << "hav is a word: " << (findWord(root, "hav") == nullptr ? 0 : 1) << endl;

   vector<string> dict2 = {"a", "ab", "ba", "acd", "ca", "abdg", "bceh", "defi", "ghij", "uvw", "stv", "rsu"};
   auto ret = wordSquare(dict2);

   cout << "\n--------> word square: \n" << endl;
   for (auto i: ret){
		 for (auto j: i)
        cout << j << endl;
     cout << endl;
   }

   return 0;
}

