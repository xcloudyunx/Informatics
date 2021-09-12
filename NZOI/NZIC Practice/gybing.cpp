#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> totals;
vector<vector<int>> grid;
int W, L;

void dfs(int i, int j, int score) {
	if ((i == 0 || i == W-1) && (j != 0 && j != L-1)) {
		score -= grid.at(j).at(i) * grid.at(j).at(i);
	} else {
		score += grid.at(j).at(i);
	}
	
	if (j == L-1) {
		totals.push_back(score);
		return;
	}
	
	if (i != W-1) {
		dfs(i+1, j+1, score);
	}
	if (i != 0) {
		dfs(i-1, j+1, score);
	}
}

int main() {
	char input[15];
	cin.getline(input, sizeof(input));
	stringstream(input) >> W >> L;
	
	grid.resize(L);
	
	for (int i=0; i<L; i++) {
		char line[4*W];
		cin.getline(line, sizeof(line));
		int x;
		stringstream ss(line);
		while (ss >> x) {
			grid.at(i).push_back(x);
		}
	}
	
	for (int i=0; i<W; i++) {
		dfs(i, 0, 0);
	}
	
	cout << *max_element(totals.begin(), totals.end());
	
	return 0;
}