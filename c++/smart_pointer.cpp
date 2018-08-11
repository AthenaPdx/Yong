#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>

template <class T> class SmartPointer {

   public: 

   SmartPointer(T* ptr){
      ref = ptr;
      ref_count = (unsigned*)malloc(sizeof(unsigned));
      *ref_count = 1;
   }

   SmartPointer(SmartPointer<T>& sptr){
      ref = sptr.ref;
      ref_count = sptr.ref_count;
      ++(*ref_count);
   }

   SmartPointer<T>& operator=(SmartPointer<T>& sptr){
      if (this == &sptr) return *this;
      if (*ref_count > 0){
         remove;
      }

      ref = sptr.ref;
      ref_count = sptr.ref_count;
      ++(*ref_count);
      return *this;
   }

   ~SmartPointer(){
      remove();
   }

   T getValue(){
      return *ref;
   }

   protected:
   void remove(){
      --(*ref_count);
      std::cout << "ref_count is: " << *ref_count << std::endl;
      if (*ref_count == 0){
         delete ref;
         free(ref_count);
         ref = NULL;
         ref_count = NULL;
      }
   }

   T* ref;
   unsigned* ref_count;
};


class foo{

public:
   foo(int i): val(i) {
      std::cout << "Creating foo: " <<  val << std::endl;
   }

   ~foo(){
      std::cout << "Deleting foo: " << val << std::endl;

   }

private:
   int val;

};



int main(){
   std::cout << "Test smartPointer" << std::endl;

   {
      foo foo10(10);
   }

   {
      SmartPointer<foo> smartFoo20(new foo(20));
   }

   {
      SmartPointer<foo> smartFoo30(new foo(30));
      {
         SmartPointer<foo> smartFoo30_ref1 = smartFoo30;
         SmartPointer<foo> smartFoo30_ref2(smartFoo30);
      }
   }


   return 0;

}


