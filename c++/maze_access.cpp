#include <string>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;


struct point{

   point(int _x, int _y):x(_x),y(_y){};

   bool operator==(point& other) {
      return x==other.x && y==other.y;
   }

   int x,y;
};

/*
struct point_hash{
   size_t operator()(const point&) {
      return hash<int>()(point.x) ^ hash<int>()(point.y);
   }
};
*/


bool hasAccess(vector<vector<int>>& maze, point& start, point end){

   int rows = maze.size();
   int cols = maze[0].size();

   queue<point> Q;
   //set<point, point_hash> S;
   set<int> S;
   bool hasAccess = false;

   Q.push(point(start));
   S.insert(start.x*cols+start.y);
   while(Q.size()){
      auto cur = Q.front();     
      Q.pop();
      
      //sorth
      if (cur.x+1< rows && maze[cur.x+1][cur.y] == 0){
         point s = point(cur.x+1, cur.y);
         if (s == end){
            hasAccess = true;
            break;
         }
         if (S.count(s.x*cols+s.y) == 0){
            S.insert(s.x*cols+s.y);
            Q.push(s);
         }
      }

      // east
      if (cur.y+1<cols && maze[cur.x][cur.y+1] == 0){
         point e = point(cur.x, cur.y+1);
         if (e == end){
            hasAccess = true;
            break;
         }
         if (S.count(e.x*rows+e.y) == 0){
            S.insert(e.x*rows+e.y);
            Q.push(e);
         }
      }
   }
   for (auto i: S) cout <<  i << " " << endl;
   return hasAccess;
}

int main(){
   vector<vector<int>> M{
      {0,1,1,0},
      {0,1,1,0},
      {0,1,1,1},
      {0,0,0,0},
   };
   point start(0,0);
   point end(3,3);
   cout << "0-0 to 3-3 has access: " << hasAccess(M, start, end);
   return 0;
}
