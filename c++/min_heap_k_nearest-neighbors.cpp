#include<string> 
#include<queue> 
#include<iostream> 

using namespace std;
struct point{
   point(int _x, int _y){
      x = _x;
      y = _y;
   }
   int x, y;
};

struct less_functor{
   bool operator()(const point& p1, const point& p2){
      return p1.x*p1.x + p1.y*p1.y > 
             p2.x*p2.x + p2.y*p2.y;
   }
};

// priority_queue <int, vector<int>, greater<int> > pq; 

int main(){
   priority_queue<point, vector<point>,less_functor> PP;
   for (int i=0; i<10; i++)
      PP.push(point(i,i));
   while (PP.size()){
      auto i = PP.top();
      cout << i.x <<  " " << i.y << endl;
      PP.pop();
   }
   return 0;
}


