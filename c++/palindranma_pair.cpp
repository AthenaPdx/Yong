/*
Input: ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]] 
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isPalindrom(string& A, int start, int end){
   while(start < end){
      if (A[start++] != A[end--]) return false;
   }
   return true;
}

vector<pair<int,int>> pl_pair(vector<string>& S){

   vector<pair<int,int>> ret;
   unordered_map<string, int> M;

   for (int i=0; i<S.size(); i++){
     auto s = S[i];
     reverse(s.begin(), s.end());
     M[s] = i;
   } 

   for (int i=0; i<S.size(); i++){
      auto& w = S[i]; 
      int len = w.size();
      string tmp = "";
      string tmp2 = w;
      for(int j=0; j<len; j++){
         tmp.push_back(w[j]);
         //tmp2.pop_front();
         tmp2.erase(tmp2.begin());
         //A X R(A)
         if (M.count(tmp)){
            if (isPalindrom(w,j+1,len-1)){
						   if (i != M[tmp])
								  ret.push_back(make_pair(i,M[tmp]));
            }
         }

         //R(A) X (A)
         if (M.count(tmp2)){
            if (isPalindrom(w,0,j)){
						   if (i != M[tmp2])
								  ret.push_back(make_pair(M[tmp2],i));
               }
            }
         }
   }
   return ret;
}

int main(){

   vector<string> S = {"abcd","dcba","lls","s","sssll"};

   for (int i=0; i<S.size(); i++){
      cout << i << " : " << S[i] << '\t' ;
   } 
   std::cout << endl;

   auto P = pl_pair(S);
   for(auto p: P )
		  cout << "[" << p.first <<"," << p.second << "]\t";
   cout << endl;
}
