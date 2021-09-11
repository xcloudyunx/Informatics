#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	vector<string> outputs;
	
	int nodes;
	cin >> nodes;
	while (nodes != 0) {
		int edges;
		cin >> edges;
		
		vector<vector<int>> adjlist(nodes);
		for (int i=0; i<edges; i++) {
			int a, b;
			cin >> a >> b;
			adjlist.at(a).push_back(b);
			adjlist.at(b).push_back(a);
		}
		
		vector<int> colour(nodes, 0);
		
		queue<int> q;
		q.push(0);
		colour.at(0) = 1;
		
		bool broken = false;
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			int cc = colour.at(f);
			
			for (auto i=adjlist.at(f).begin(); i!=adjlist.at(f).end(); i++) {
				if (colour.at(*i) == cc) {
					broken = true;
					break;
				} else if (colour.at(*i) == 0) {
					colour.at(*i) = -cc;
					q.push(*i);
				}
			}
			if (broken) {
				break;
			}
		}
		
		if (broken) {
			outputs.push_back("NOT BICOLORABLE.");
		} else {
			outputs.push_back("BICOLORABLE.");
		}
		
		cin >> nodes;
	}
	
	for (string i : outputs) {
		cout << i << endl;
	}
	
	return 0;
}