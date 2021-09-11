#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void output(vector<int> prev, int start, int current) {
	if (prev.at(current) == start) {
		cout << start;
	} else {
		output(prev, start, prev.at(current));
	}
	cout << " " << current;
}

int main() {
	int vertices;
	cin >> vertices;
	int start, end;
	cin >> start >> end;
	
	vector<vector<int>> adjlist(vertices, vector<int>());
	vector<int> prev(vertices, -1);
	
	int x, y;
	while (cin >> x >> y) {
		adjlist.at(x).push_back(y);
	}
	
	if (start != end) {
		for (vector<int> &list : adjlist) {
			sort(list.begin(), list.end());
		}
		
		queue<int> q;
		q.push(start);
		
		bool broken = false;
		
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			
			for (auto i=adjlist.at(f).begin(); i!=adjlist.at(f).end(); i++) {
				if (prev.at(*i) == -1) {
					prev.at(*i) = f;
					
					if (*i == end) {
						broken = true;
						break;
					}
					
					q.push(*i);
				}
			}
			
			if (broken) {
				break;
			}
		}
		
		output(prev, start, end);
		
	} else {
		cout << start;
	}
	
	return 0;
}