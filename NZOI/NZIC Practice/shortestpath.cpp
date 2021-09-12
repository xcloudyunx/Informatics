#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	
	char input[20];
	cin.getline(input, sizeof(input));
	int start, end;
	stringstream(input) >> start >> end;
	
	vector<vector<int>> adjlist;
	adjlist.resize(n);
	
	while (!eof()) {
		int x, y;
		cin.getline(input, sizeof(input));
		stringstream(input) >> x >> y;
		adjlist.at(x).push_back(y);
	}
	
	for (vector<int> i : adjlist) {
		sort(i.begin(), i.end());
	}
	
	
	
	return 0;
}