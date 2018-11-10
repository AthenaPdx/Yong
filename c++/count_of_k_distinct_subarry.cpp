#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

int count_subarry(string input, int k){

   int len = input.size();
   if (len < k) return 0;
   int ret = 0;

   unordered_map<char, int> m;
   int count = 0;

   // check first K-size window
   for (int i=0; i<k; i++){
      auto c = input[i];
      if (m.count(c) == 0){
         m[c] = 1;
         count++; 
         if (count == k) ret++;
      }else{
         m[c]++;
      }
   }
   
   // move K-size window forward
   int index = k;
   while(index < input.size()){
     auto to_move = input[index-k];
     if (m.count(to_move) == 1){
        m.erase(to_move);
        count--;
     }else{
        m[to_move]--;
     }
     auto to_add = input[index];
     if(m.count(to_add) == 0){
        m[to_add] = 1;
        count++; 
        if (count == k) ret++;
     }else{
         m[to_add]++;
     }
     index++;
   }
   return ret;
} 

int main(){
   int k = 4;
   string input("1245323");
   cout << input << " k=" << k << " -> " << count_subarry(input, k) << endl;
   return 0;
}
