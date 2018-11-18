#include <vector>
#include <iostream> 

using namespace std;


void quickSort(vector<int>& nums){
   _quickSortHelper(nums,0,nums.size()-1;
}

int partitian(vector<int>& nums, int start, int end){
   int val = nums[end];
   int paviot = end;
   int left = start;
   int right = end-1;
   while (left <= right){
      while (nums[left] < val) left++;
      while (nums[right] > val) right--;
      if (left < right && nums[left] > val){
         swap(nums[left], nums[right]);
         left++; right--;
      }
      return 
   }
}

void _quickSortHelper(vector<int>& nums, int start, int end){
   if (start >= end) return;
   int paviot = 

}

void merge(vector<int>& nums, int start, int end, int mid) {
   //cout << "merge: " << start << " " << end << " " << mid << endl;
   if (start >=end) return;
   int left = start;
   int right = mid+1;
   vector<int> temp;
   while (left <=mid || right <= end){
      if (left<= mid && right <=end){
         if (nums[left]<= nums[right]){
           temp.push_back(nums[left]);
           left++;
        }else{
           temp.push_back(nums[right]);
           right++;
        }
      }else if (left <=mid){
         for (int i=left; i<=mid; i++)
            temp.push_back(nums[i]);
         break;
      }else{
         for (int i=right; i<=end; i++)
            temp.push_back(nums[i]);
         break;
      }
   }
   for (int i=start; i<=end; i++)
      nums[i] = temp[i-start];
   return;
}
void mergeSort(vector<int>& nums, int start, int end){
   //cout << "sort: " << start << " " << end << endl;
   if (start >=end) return;
   //int mid = (start + end)/2; 
   //use start + (end-start-1)/2 to avoid overflow
   mid = start + (end-1)/2
   mergeSort(nums, start, mid);
   mergeSort(nums, mid+1, end);
   merge(nums,start, end, mid);
}

int main(){

   auto print = [](vector<int>& nums){
      cout << endl;
      for (auto i: nums) cout << i << " ";
      cout << endl;
   };

   vector<int> nums{1, 8, 6, 7, 3, 23, 4, 2, 2, 1, 9, 7};
   print(nums);
   mergeSort(nums,0, nums.size()-1);
   print(nums);

}
