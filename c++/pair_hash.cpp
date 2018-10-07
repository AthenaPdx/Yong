#include <iostream>
#include <unordered_map>
#include <utility>

typedef std::pair<int,int> int_pair;

struct pair_hash{
   template <class T1, class T2>
   size_t operator()(const std::pair<T1,T2>& some_pair) const
   {
      return std::hash<T1>{}(some_pair.first) ^ std::hash<T2>()(some_pair.second);
   }
};

int main(){
   std::unordered_map<int_pair, int_pair, pair_hash> my_map;
   my_map[std::make_pair(1,2)] = std::make_pair(3,4);
   for (auto& entry: my_map){
      std::cout << entry.first.first << "," << entry.second.second << std::endl;
   }
}
