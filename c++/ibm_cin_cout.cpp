/* hilight:

  int int_to_read;                ------> read num from cursor
  cin >> int_to_read;

  string str_to_read;
  getline(cin, str_to_read);       -----> read string fron cursor (cin)

  ifstream ifile_ptr;   
  file_ptr.open("xxx");    
  while(
    getline(file_ptr, str_to_read)) -----> read string from file (file_ptr)
  }

  ifstream ofile_ptr;              ------> write to file
  file_ptr.open("xxx");    
  ofile_ptr << "some string" 

  */

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <sstream>


using namespace std;

vector<string> read_lines_to_strV(){
   vector<string> ret;
   cout << "Please input line to write: (q to quit)" << endl;
   string input_line;
   getline(cin, input_line);
   while (input_line != "q"){
      ret.push_back(input_line);
      cout << "Please input another line to write: (q to quit)" << endl;
      getline(cin, input_line);
   }
   return ret;
}

void output_str_to_file(vector<string>& data, string fileName){
   ofstream out_file;
   out_file.open(fileName);
   for (auto i: data)
     out_file << i << endl;
   out_file.close();
}


vector<string> read_strV_from_file(string fileName){
   vector<string> ret;
   ifstream in_file;
   in_file.open(fileName);
   string line;
   while (getline(in_file, line)){
      ret.push_back(line);
   }
   in_file.close();
   return ret;
}

vector<int> get_num_token(string& str){
   int num;
   vector<int> ret;
   stringstream ss(str);
   while (ss >> num){
     ret.push_back(num);
   }
   return ret;
}


int kthSmallestNum(int i, int k, priority_queue<int>& PQ){
   PQ.push(i);
   if (PQ.size() < k) return -1;
   if (PQ.size() == k) return PQ.top();
   PQ.pop();
   return PQ.top();
}


int main(){
  //auto data = read_lines_to_strV();
  //output_str_to_file(data, "ibm.txt");
  auto str_v = read_strV_from_file("ibm.txt");

  std::priority_queue<int> PQ;

  int kth;
  std::cout << "input which(th) smallest value to display: " << std::endl;
  std::cin >> kth;

  for (auto i: str_v){
    auto nums = get_num_token(i);
      for (auto n : nums){
        cout << "adding " << n << endl;
        cout << "current " << kth << "th smallest is: " << 
             kthSmallestNum(n, kth, PQ) << endl;
      }
  }
  return 0;
}
