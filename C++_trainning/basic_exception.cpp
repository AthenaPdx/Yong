#include <iostream>
#include <string>
using namespace std;

void mightGoWrong() {
   bool error = false;
   bool error2 = true;

   if (error){
      throw "Something wrong";
   }

   if (error2){
      throw string("Something else wrong");
   }
}

int main(){

   try{
      mightGoWrong();
   }catch(int e){
      cout << "Error code: " << e << endl;
   }catch( char const* s){
      cout << "Error message: " << s << endl;
   }catch(string& e){
      cout << "Error str message: " << e.what() << endl;
   }
   return 0;
}
   

