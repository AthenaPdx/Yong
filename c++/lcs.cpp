//#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
int lcs_2D(string s1, string s2){

  cout << endl;
  int len1 = s1.size();
  int len2 = s2.size();
  vector<vector<int>> DP(len1+1, vector<int>(len2+1,0));
  for (int i=1; i<=len1; i++){
    for (int j=1; j<=len2; j++){ 
       if (s1[i-1]==s2[j-1]) 
         DP[i][j]=DP[i-1][j-1]+1;
       else
         DP[i][j]=max(DP[i-1][j], DP[i][j-1]);
    }
    for (int j=1; j<=len2; j++) cout << DP[i][j];
    cout << endl;
  }
  cout << endl;
  return DP[len1][len2];
}

int lcs_1D(string s1, string s2){

  cout << endl;
  int len1 = s1.size();
  int len2 = s2.size();
  vector<int> DP_cur(len2+1,0);
  vector<int> DP_pre(len2+1,0);
  for (int i=1; i<=len1; i++){
    swap(DP_cur, DP_pre);
    for (int j=1; j<=len2; j++){ 
       if (s1[i-1]==s2[j-1]) 
         DP_cur[j]=DP_pre[j-1]+1;
       else
         DP_cur[j]=max(DP_cur[j-1], DP_pre[j]);
    }
    for (int j=1; j<=len2; j++) cout << DP_cur[j];
    cout << endl;
  }
  cout << endl;
  return DP_cur[len2];
}



int main(){
  string s1 = "apple_and_oranges";
  string s2 = "always";
  std::cout << "longest common character(1D) of " << s1 << " and " << s2;
  std::cout << " is: " << lcs_1D(s1,s2) << endl;
  std::cout << "longest common character(2D) of " << s1 << " and " << s2;
  std::cout << " is: " << lcs_2D(s1,s2) << endl;
}

