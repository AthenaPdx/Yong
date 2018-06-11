#include<vector>
#include<iostream>

using namespace std;


void flip_filter(vector<vector<int>>& F){
   int row = F.size();
   int col = F[0].size();
   for (int i=0; i< row; i++){
      int start =0;
      int end = col -1;
      while (start < end){
         swap(F[i][start++], F[i][end--]);
      }
   }
   // swap rows
   int start = 0;
   int end = row -1;
   while (start < end){
      swap(F[start++], F[end--]);
   }
}


void printVector(vector<vector<int>>& A){
   int row = A.size();
   int col = A[0].size();
   for (int i=0; i< row; i++){
      for (int j=0; j< col; j++)
         cout << A[i][j];
      cout << endl;
   }

}
int main(){
   vector<vector<int>> A(3,vector<int>(3));
   int value = 0;
   for (int i=0; i<3; i++)
      for (int j=0; j<3;j++)
         A[i][j] = ++value;

   printVector(A);
   flip_filter(A);
   printVector(A);
   return 0;

}



