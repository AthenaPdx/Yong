#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<pair<int, int>> skyLine(vector<vector<int>>& buildings){
   priority_queue<pair<int,int>> PQ;
   vector<pair<int,int>> ret;

   // adding building
   for (auto B : buildings){
      cout << "adding element" << endl;
      // cleanup pre- exiting buildings
      while (PQ.size() && B[0] > PQ.top().second){
         auto t = PQ.top();
         PQ.pop();
         while (PQ.size() && PQ.top().second<=t.second){
            PQ.pop();
         }
         if (PQ.size()){
            ret.push_back({t.second, PQ.top().second});
         }else{
            ret.push_back({t.second, 0});
         }
      }
      // add one elelement
      if (PQ.size()){
         if (B[2] > PQ.top().first){
            ret.push_back({B[0],B[2]});
         }
      }else{
            ret.push_back({B[0],B[2]});
      }
      PQ.push({B[2],B[1]});

   }
   

   //exiting building

   while (PQ.size()){
      auto t = PQ.top();
      PQ.pop();
      while (PQ.size() && PQ.top().second<=t.second){
         PQ.pop();
      }
      if (PQ.size()){
         ret.push_back({t.second, PQ.top().first});
      }else{
         ret.push_back({t.second, 0});
      }
   }
   return ret;
}


int main(){
  vector<vector<int>> input{{2, 9, 10}, {3, 7, 15},{5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
  auto ret = skyLine(input);
  cout << endl;
  for (auto r : ret){
     cout << "{" << r.first <<"," << r.second << "} ";
  }
  cout << endl;
  return 0;
}


