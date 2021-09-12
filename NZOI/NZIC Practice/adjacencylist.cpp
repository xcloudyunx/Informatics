#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	
	vector<vector<int>> adjlist;
	adjlist.resize(n);
	
	int x;
	int y;
	char input[10];
	cin.getline(input, sizeof(input));
	stringstream(input) >> x >> y;
	while (x != -1 && y != -1) {
		adjlist.at(x).push_back(y);
		cin.getline(input, sizeof(input));
		stringstream(input) >> x >> y;
	}
	
	for (int i=0; i<n; i++) {
		cout << i << ":";
		sort(adjlist.at(i).begin(), adjlist.at(i).end());
		for (int j : adjlist.at(i)) {
			cout << " " << j;
		}
		cout << endl;
	}
	
	return 0;
}