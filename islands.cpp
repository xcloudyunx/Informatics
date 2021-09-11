#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<char>> grid;
vector<vector<int>> visited;
int size, W, H;

void checkCoordinates(int i, int j) {
	if (grid[i][j] == '#' && visited[i][j] == 0) {
		size++;
		visited[i][j] = 1;
		
		if (i != 0) {
			checkCoordinates(i-1, j);
		}
		if (i != H-1) {
			checkCoordinates(i+1, j);
		}
		if (j != 0) {
			checkCoordinates(i, j-1);
		}
		if (j != W-1) {
			checkCoordinates(i, j+1);
		}
	}
	
}

int main() {
	char input[20];
	cin.getline(input, sizeof(input));
	int T;
	stringstream(input) >> W >> H >> T;
	
	visited.resize(H, vector<int> (W, 0));
	for (int i=0; i<H; i++) {
		string str;
		cin >> str;
		grid.push_back(vector<char> (str.begin(), str.end()));
	}
	
	int islands = 0;
	
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			size = 0;
			checkCoordinates(i, j);
			if (size >= T) {
				islands++;
			}
		}
	}
	
	cout << islands;
	
	return 0;
}