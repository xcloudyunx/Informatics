#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> totals;
vector<pair<int, int>> maxValues;

void dfs(vector<vector<int>> grid, int i, int j, int W, int L, int score, int prev) {
	if (j == L) {
		totals.push_back(score+grid.at(j).at(i));
		return;
	}
	
	if (prev == -1) {
		if (maxValues.at((W+1)*j + i - prev).first < score) {
			maxValues.at((W+1)*j + i - prev).first = score;
		} else {
			return;
		}
	} else if (prev == -1) {
		if (maxValues.at((W+1)*j + i - prev).second < score) {
			maxValues.at((W+1)*j + i - prev).second = score;
		} else {
			return;
		}
	}
	
	if (i != 0) {
		if (prev == 1) {
			dfs(grid, i-1, j+1, W, L, score - grid.at(j).at(i)*grid.at(j).at(i), -1);
		} else {
			dfs(grid, i-1, j+1, W, L, score+grid.at(j).at(i), -1);
		}
		
	}
	if (i != W) {
		if (prev == -1) {
			dfs(grid, i+1, j+1, W, L, score - grid.at(j).at(i)*grid.at(j).at(i), 1);
		} else {
			dfs(grid, i+1, j+1, W, L, score+grid.at(j).at(i), 1);
		}
	}
}

int main() {
	int W, L;
	cin >> W;
	cin >> L;
	
	vector<vector<int>> grid(L);
	maxValues.resize(W*L, {0, 0});
	
	for (int j=0; j<L; j++) {
		for (int i=0; i<W; i++) {
			int x;
			cin >> x;
			grid.at(j).push_back(x);
		}
	}
	
	for (int i=0; i<W; i++) {
		dfs(grid, i, 0, W-1, L-1, 0, 0);
	}
	
	cout << *max_element(totals.begin(), totals.end());
	
	return 0;
}