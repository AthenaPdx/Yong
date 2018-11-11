#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool str_comp(string& A, string& B){
   size_t loc1 = A.find(" ");
   string A_substr = A.substr(0,loc1);
   cout << A_substr << endl;
   size_t loc2 = B.find(" ");
   string B_substr = B.substr(0,loc2);
   cout << B_substr << endl;
   return A_substr < B_substr;
}


vector<string> sort_str(vector<string>& input){
   sort(input.begin(), input.end(), str_comp);
   return input;
}

int main(){
   vector<string> input
   {
      "cde this is a moment for fight",
      "abline1 this is a moment for fight",
      "abline1 this ais a moment for fight",
      "abline1 this 0is a moment for fight",
      "abline",
      "aaaaa",
      "zzzzz"
   };
   input = sort_str(input);
   for (auto i : input) cout << i << endl;
}



