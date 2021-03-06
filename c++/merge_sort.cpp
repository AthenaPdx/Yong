#include <vector>
#include <iostream> 

using namespace std;

int partitian(vector<int>& nums, int start, int end){
   cout << "partion call   : " << start << " " << end << " " <<  endl;
   int val = nums[end];
   int left = start;
   int right = end-1;
   while (left < right){
      while (nums[left] < val) left++;
      while (nums[right] >= val) right--;
      if (left < right && nums[left] >= val){
         swap(nums[left], nums[right]);
         left++; right--;
      }
   }
   swap(nums[left],nums[end]);
   cout << "partion return: " << start << " " << end << " " << left<< endl;
   return left;
}

void _quickSortHelper(vector<int>& nums, int start, int end){
   if (start >= end) return;
   cout << "quickSort: " << start << " " << end << endl;
   int paviot = partitian(nums, start, end);
   _quickSortHelper(nums, start, paviot-1);
   _quickSortHelper(nums, paviot+1, end);
}

void quickSort(vector<int>& nums){
   _quickSortHelper(nums,0,nums.size()-1);
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
   int mid = start + (end-start)/2;
   mergeSort(nums, start, mid);
   mergeSort(nums, mid+1, end);
   merge(nums,start, end, mid);
}


class heap{

public: 
 int top() {return nums[0];}
 size_t size() {return nums.size();}

 void display(){
   cout << "****" << endl; 
   for (int i=0; i<nums.size(); i++) cout << nums[i] << " " ;
   cout << endl <<  "****" << endl; 
 }

 void push(int num){
   nums.push_back(num);
   int idx = nums.size()-1;
   while (idx){
      int parent = (idx-1)/2;
      if (nums[idx]<nums[parent]){
         swap(nums[idx], nums[parent]);
         idx = parent;
      }else{
         break;
      }
   }
 }

 void pop(){

   nums[0]=nums[nums.size()-1];
   nums.pop_back();
   //cout << "poped size: " << nums.size() << endl;
   //display();
   int head = 0;
   while (head < nums.size()-1){
      int left = head*2+1 < nums.size() ? head*2+1 :0 ;
      int right = head*2+2 < nums.size() ? head*2+2 :0 ;
      if (left && right){
        if (nums[left]<nums[head] && nums[left]<=nums[right]){
           swap(nums[left],nums[head]);
           head = left;
        }else if (nums[right]<=nums[head] && nums[right]<=nums[left]){
           swap(nums[right],nums[head]);
           head = right;
        }else{
           return;
        }
      }else{ //alredy reach to leaf. only left. since left + 1 = right
        if (left && nums[left]<nums[head]){
           swap(nums[left],nums[head]);
        }
        return;
      }
   }
 }

private: 
 vector<int> nums;
};

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
   vector<int> nums2 = {1, 8, 6, 7, 3, 23, 4, 2, 2, 1, 9, 7};
   print(nums2);
   quickSort(nums2);
   print(nums);
   print(nums2);

   vector<int> nums3 = {24, 1, 8, 6, 7, 3, 23, 4, 2, 2, 1, 9, 7};
   //vector<int> nums3 = {24, 1, 8, 6};
   print(nums3);
   heap H;
   for (auto i: nums3){
      H.push(i);
      //H.display();
   }
   cout << endl;
   while(H.size()){
      //H.display();
      cout << H.top() << " " ;
      H.pop();
   }
   cout << endl;


}
