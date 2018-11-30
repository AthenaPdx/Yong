#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

double getNfrom2SortedArray(vector<int>& V1, int idx1, vector<int>& V2, int idx2, int N){
  //cout << "idx1: " << idx1 << " idx2: " << idx2 << " N: " << N << endl;
  this_thread::sleep_for(chrono::seconds(1));
  if (V1.size()-idx1 > V2.size()-idx2) 
     return getNfrom2SortedArray(V2, idx2, V1, idx1, N);
  if (V1.size()<=idx1) return V2[idx2+N];
  if (N==0) return min(V1[idx1],V2[idx2]);
  int end1 = min(idx1 + N/2, (int)V1.size()-1);
  int end2 = idx2 + N - (end1-idx1+1);
  if (V1[end1] == V2[end2]) return V1[end1];
  else if (V1[end1] < V2[end2]){
     return getNfrom2SortedArray(V1, end1+1, V2, idx2, N-(end1-idx1+1));
  }else{
     return getNfrom2SortedArray(V1, idx1, V2, end2+1, N-(end2-idx2+1));
  }
}

double medianOf2SortedArray(vector<int>& V1, vector<int>& V2){
   int odd = (V1.size()+V2.size())%2;
   int mid  = (V1.size()+V2.size())/2;
   if (odd)
      return getNfrom2SortedArray(V1, 0, V2, 0, mid);
   else
      return 0.5*(getNfrom2SortedArray(V1, 0, V2, 0, mid)+
                  getNfrom2SortedArray(V1, 0, V2, 0, mid-1));
}

int main(){

   vector<int> V1{1,2,3,5,7,9,11,12};
   vector<int> V2{1,2,4,6,8,10,13};
   cout << "median is: " <<  medianOf2SortedArray(V1, V2) << endl;
   return 0;
}
