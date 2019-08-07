#include<vector>
#include<iostream>

using namespace std;

bool findFromSortedMatrix(vector<vector<int>>& V, int target){
	int rows = V.size(); 
  if (rows == 0) return false;
  int cols = V[0].size();
  int row = rows -1, col = 0; 
  while (row >=0 && col < cols){
		if (V[row][col] == target)
			return true;
		else if (V[row][col] > target)
			row--;
    else
			col++;
  }
	return false;
}

int main(){
	vector<vector<int>> V =
  {{1,3,5,7},
   {21,23,25,27},
   {31,33,35,37},
   {41,43,45,47}};


  vector<int> I = {3, 4, 5, 7, 1, 21, 18, 47, 50};
  
  for (auto i: I)
	   cout << "finding: " << i << " " << findFromSortedMatrix(V, i) << endl;
  return 0;
}


