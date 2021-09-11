#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool larger(pair<int, string> a, pair<int, string> b) {
	return a.first > b.first;
}

int main() {
	int N;
	cin >> N;
	cin.ignore();
	
	vector<pair<int, string>> tasks;
	for (int i=0; i<N; i++) {
		string tmp;
		getline(cin, tmp);
		tasks.push_back({0, tmp});
	}
	
	vector<vector<int>> big(N);
	vector<vector<int>> small(N);
	int src, dst;
	while (cin >> src >> dst) {
		big.at(src).push_back(dst);
		small.at(dst).push_back(src);
	}
	
	for (int i=0; i<N; i++) {
		if (tasks.at(i).first == 0) {
			queue<int> q;
			q.push(i);
			
			while (!q.empty()) {
				int f = q.front();
				q.pop();
				
				for (auto j=big.at(f).begin(); j!=big.at(f).end(); j++) {
					if (tasks.at(*j).first >= tasks.at(f).first) {
						tasks.at(*j).first = tasks.at(f).first-1;
						q.push(*j);
					}
				}
				
				for (auto j=small.at(f).begin(); j!=small.at(f).end(); j++) {
					if (tasks.at(*j).first <= tasks.at(f).first) {
						tasks.at(f).first = tasks.at(*j).first-1;
						q.push(f);
					}
				}
			}
		}
	}
	
	sort(tasks.begin(), tasks.end(), larger);
	
	for (pair<int, string> task : tasks) {
		cout << task.second << endl;
	}
	
	return 0;
}