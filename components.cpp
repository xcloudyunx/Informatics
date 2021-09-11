#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> v;
vector<vector<int>> outputs;

void dfs(vector<vector<int>> adjlist, int i, int count) {
	v.at(i) = true;
	outputs.at(count).push_back(i);
	for (int j : adjlist.at(i)) {
		if (!v.at(j)) {
			dfs(adjlist, j, count);
		}
	}
}

int main() {
	int vertices;
	cin >> vertices;
	
	vector<vector<int>> adjlist;
	adjlist.resize(vertices);
	v.resize(vertices, false);
	outputs.resize(vertices+1);
	
	int a, b;
	cin >> a >> b;
	while (a != -1 and b != -1) {
		adjlist.at(b).push_back(a);
		adjlist.at(a).push_back(b);
		cin >> a >> b;
	}
	
	int count = 1;
	for (int i=0; i<vertices; i++) {
		if (!v.at(i)) {
			dfs(adjlist, i, count);
			count++;
		}
	}
	
	for (int i=1; i<=vertices; i++) {
		if (!outputs.at(i).empty()) {
			cout << i << ":";
			sort(outputs.at(i).begin(), outputs.at(i).end());
			for (int j : outputs.at(i)) {
				cout << " " << j;
			}
			cout << endl;
		}
	}
	
	return 0;
}