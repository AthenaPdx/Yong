#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> R = {{"JFK","AFO"},{"JFK","ATL"},{"AFO","ATL"},{"ATL","JFK"},{"ATL","AFO"}};
map<string, multiset<string>> targets;
vector<string> route;


void visit(string airport) {
    cout << airport << endl;
    if (targets[airport].size() == 0) {
       cout << " done: " << airport << endl;
    }
		while (targets[airport].size()) {
        for (auto& i: targets[airport])
           cout << " " << i << endl;
				string next = *targets[airport].begin();
				targets[airport].erase(targets[airport].begin());
				visit(next);
		}
		route.push_back(airport);
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
	for (auto ticket : tickets)
			targets[ticket[0]].insert(ticket[1]);
	visit("JFK");
	return vector<string>(route.rbegin(), route.rend());
}

int main(){
  auto I = findItinerary(R);
  for (auto& i: I) 
     cout << i << " ";
  cout << endl;
  return 0;
}
  
