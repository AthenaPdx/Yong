#include<queue>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

using min_pq = priority_queue<int,vector<int>,greater<int>>;
using max_pq = priority_queue<int>;

int main(){

	vector<int> V = {1,2,3,4,5,6};
  min_pq min_q;
  max_pq max_q;

  for (auto& i: V){
    min_q.push(i);
    max_q.push(i);
	}

	cout << "min prioirty queue: " << endl;
  while (min_q.size()){
		cout << min_q.top() << "\t";
    min_q.pop();
  }
  cout << endl;

	cout << "max prioirty queue: " << endl;
  while (max_q.size()){
		cout << max_q.top() << "\t";
    max_q.pop();
  }
  cout << endl;
}

