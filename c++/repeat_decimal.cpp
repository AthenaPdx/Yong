#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string repeatDecimal(int n, int d){ //n: numerator d:denominator
  cout << "----> " << endl;
  vector<char> ret;
  if (n*d < 0) ret.push_back('-'); 
  n = abs(n); d = abs(d);

  stringstream ss;   
  ss << n/d; 
  auto str = ss.str();
  ss.str("");
  cout << str << endl;
  for (auto it = str.begin(); it !=str.end(); it++)
    ret.push_back(*it);

  int r = (n%d)*10;
  if (r !=0) ret.push_back('.');

  unordered_map<int, int> c_index;
  c_index[r] = ret.size();
  while (r !=0){
    while (r<d){
      r *= 10;
      ss << '0';
    }
    ss << r/d;
    str = ss.str();
    ss.str("");
    cout << str << endl;

    for (auto it = str.begin(); it !=str.end(); it++)
      ret.push_back(*it);

    r = (r%d)*10;
    if (c_index.find(r) != c_index.end()){
       ret.emplace(ret.begin()+c_index[r], '(');
       ret.push_back(')');
       return string(ret.begin(), ret.end());
    }else{
      c_index[r] = ret.size();
    }
  }   
  return string(ret.begin(), ret.end());
}

int main(){
  cout << "2/100: " << repeatDecimal(2,100) << endl;
  cout << "100/2: " << repeatDecimal(100,2) << endl;
  cout << "10/6: " << repeatDecimal(10,6) << endl;
  cout << "-10/196: " << repeatDecimal(-10,196) << endl;
  cout << "12/-33: " << repeatDecimal(12,-33) << endl;
	return 0;
}


