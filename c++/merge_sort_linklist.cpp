#include <vector>
#include <iostream> 
#include "linkedlist.h"

using namespace std;


void combine(vector<int>& nums, int start, int end, int mid)
{
   std::cout << "bombine: start/end/mid: " << start << " " << end << " " << mid << endl;
   if (start >= end) return;
   vector<int> tmp;
   int left = start, right = mid+1;
   while (left <=mid || right <=end){
      if (left <=mid && right <=end){
         if (nums[left] <= nums[right]){
				    tmp.push_back(nums[left++]);
         }else{
				    tmp.push_back(nums[right++]);
         }
      }else if (left <=mid){
				    tmp.push_back(nums[left++]);
      }else {
				    tmp.push_back(nums[right++]);
      }
   }
   for (int i=start; i<=end; i++) nums[i] = tmp[i-start];
}

void mergeSortRecursive(vector<int>& nums, int start, int end)
{
	if (start >= end) return;
  int mid = start + (end - start)/2;
  mergeSortRecursive(nums, start, mid);
  mergeSortRecursive(nums, mid+1, end);
  combine(nums, start, end, mid);
}

void mergeSortBottomUp(vector<int>& nums, int start, int end)
{
  for (int step =1; step < nums.size(); step <<= 1){ // outter strike: step
     for (int j=0; j<=end; j+=step*2){               // inner  strike: 2*step
        combine(nums, j, min(end,j+step*2-1), j+step-1);
     }
  }
}

int main(){

   vector<int> nums{1, 8, 6, 7, 3, 23, 4, 2, 2, 1, 9, 7};
   listNode * ln = createNodeFromVector(nums);
   ln->print();
   return 0;
}
