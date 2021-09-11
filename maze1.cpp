#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int vertices;
	cin >> vertices;
	int start = 0;
	int end = vertices-1;
	
	vector<vector<int>> adjlist;
	vector<vector<int>> paths;
	adjlist.resize(vertices, vector<int> {});
	paths.resize(vertices, vector<int> {-1});
	
	int x, y;
	while (cin >> x >> y) {
		adjlist.at(x).push_back(y);
		adjlist.at(y).push_back(x);
	}
	
	if (start != end) {
		queue<int> q;
		q.push(start);
		paths.at(start) = {start};
		
		bool broken = false;
		while (true) {
			int f = q.front();
			q.pop();
			
			for (auto i=adjlist.at(f).begin(); i!=adjlist.at(f).end(); i++) {
				if (paths.at(*i).front() == -1) {
					q.push(*i);
					paths.at(*i) = paths.at(f);
					paths.at(*i).push_back(*i);
				
					if (*i == end) {
						broken = true;
						break;
					}
				}
			}
			if (broken) {
				break;
			}
		}
		
		for (int i : paths.at(end)) {
			cout << i << " ";
		}
	} else {
		cout << start;
	}
	
	return 0;
}