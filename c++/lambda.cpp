#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){

   vector<int> V{1,2,3,4,5,6}; 
   auto f  = [&](int n) {V[n]+=10;};
   f(0);
   cout << V[0] << endl;
   auto v2 = V;
   auto f2  = [&](int n) {v2[n]+=10;};
   f2(0);
   cout << v2[0] << endl;
   vector<int> v3;
   auto f3  = [=,&v3](int n) {v3 = v2; v3[n]+=10;};
   f3(0);
   cout << v3[0] << endl;
   sort(v3.begin(), v3.end(), [](int A, int B){return (A > B); });
   for (auto i = v3.begin(); i!=v3.end(); i++){
     cout << *i << endl;
   }
   return 0;
}
