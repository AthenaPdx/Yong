/*
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

    Each 0 marks an empty land which you can pass by freely.
    Each 1 marks a building which you cannot pass through.
    Each 2 marks an obstacle which you cannot pass through.
Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

*/

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <iostream>
#include <climits>

using namespace std;


vector<int> getNeighbor(int n, int rows, int cols){
   int row = n/cols;
   int col = n%cols;
   vector<int> ret;
   if (col>0) ret.push_back(n-1); // left
   if (col<cols-1) ret.push_back(n+1); //right
   if (row>0) ret.push_back(n-cols); //upper
   if (row<rows-1) ret.push_back(n+cols); //lower
   //cout << n << " neighbors: " << endl;
   //for (auto& i: ret) cout << i << " ";
	 //cout << endl;
   return ret;
}

int shortestDistance(vector<vector<int>> grid){

  int rows = grid.size();
  if (!rows) return 0;
  int cols = grid[0].size();

	set<int> wall, land, obstacle; 
  for (int i=0; i<rows;i++){
		for (int j=0; j<cols; j++){
			int idx = i*cols+j;
      switch (grid[i][j]){
				case 0:
					land.insert(idx);
          break;
				case 1:
					wall.insert(idx);
          break;
				case 2:
					obstacle.insert(idx);
          break;
			}
		}
  }

  for (auto i: wall) cout << "wall: " << i << endl;

  cout << wall.size() << " " << obstacle.size() << " " << land.size() << endl;

  int ret = INT_MAX;
  for (auto& l: land){
     cout << "land: " << l << endl;
     stack<int> neighbor1; 
     stack<int> neighbor2; 
     unordered_map<int, int> dist;
     neighbor1.push(l);
     int curr_dist = 0;
     while (neighbor1.size()){
		   auto node = neighbor1.top(); 
       neighbor1.pop();
       if (dist.count(node) == 0) dist[node] = curr_dist;
			 auto adj = getNeighbor(node, rows, cols);
			 for (auto i: adj){
					if (!dist.count(i)){
            dist[i] = curr_dist + 1;
						if (land.count(i)) neighbor2.push(i);
					}
			 }
       if (neighbor1.empty()){
				 swap(neighbor1, neighbor2);
				 cout << curr_dist++ << endl;
			 }
		 }

     int count=0; 
		 int dis_sum = 0;
     for (auto i: dist){
       cout << i.first << "----> " << i.second << endl;
		   if (wall.count(i.first)){
				  count++;
					dis_sum += i.second;
			 }
     }
     cout << "touching wall: " << count << endl;
		 if (count == wall.size()) ret = min(ret, dis_sum);
  }
  return ret;
}

int main(){
   vector<vector<int>> grid = {{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
   //getNeighbor(6, 3, 5);
   cout << shortestDistance(grid) << endl;
   return 0;
}
