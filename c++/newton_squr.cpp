#include <iostream>
#include <vector>

using namespace std;
int sqrt(int x){
   double y = x/2;
   while (abs(y*y-x) >0.0001){
      double delta = y*y-x;
      y = y - delta/(2*y);
   }
   return (int)y;
}

int main(){

vector<double> D= {144, 169, 2, 3, 4.0, 49, 48, 50};
	for (auto i: D){
     cout << "squr(" <<  i << ")= " << sqrt(i) << endl;
	}
  return 0;
}
