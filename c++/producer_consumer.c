#include <thread>
#include <stdlib.h>
#include <chrono>
#include <queue> 
#include <iostream>
#include <mutex>
#include <sstream>

static int MAX_QUEUE = 100;
std::queue<std::string> Q;
static std::mutex mtx;

void producer(std::queue<std::string>& Q){
   int loop = 5;
   while (loop--){
      auto lck = std::unique_lock<std::mutex>(mtx);
      if (Q.size() < MAX_QUEUE){
         std::stringstream ss;
         ss << std::this_thread::get_id();
         Q.push(ss.str());
         std::cout << "Pushed: " << ss.str() << std::endl;
         std::cout << "loop is: " << loop << std::endl;
         int sleep_s = rand()%10;
         std::this_thread::sleep_for(std::chrono::seconds(sleep_s));
      }
   }
}

void consumer(std::queue<std::string>& Q){
   int loop = 5;
   while (loop--){
      auto lck = std::unique_lock<std::mutex>(mtx);
      if (Q.size()){
         std::cout << "Poped: " << Q.front() << " by "  << std::this_thread::get_id() << std::endl;
         Q.pop();
         int sleep_s = rand()%10;
         std::this_thread::sleep_for(std::chrono::seconds(sleep_s));
         std::cout << "loop is: " << loop << std::endl;
      }
   }
}

int main(){

   auto p1 = std::thread(producer, std::ref(Q));
   auto p2 = std::thread(producer, std::ref(Q));
   auto c1 = std::thread(consumer, std::ref(Q));
   auto c2 = std::thread(consumer, std::ref(Q));
   p1.join();
   p2.join();
   c1.join();
   c2.join();
   return 0;
}
     

    







