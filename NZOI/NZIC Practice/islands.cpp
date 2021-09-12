#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<char>> grid;
int W, H;

int checkCoordinates(int i, int j, int size) {
	if (grid.at(i).at(j) == '#') {
		size++;
		grid.at(i).at(j) = 'v';
		
		if (i != H-1) {
			size = checkCoordinates(i+1, j, size);
		}
		if (j != 0) {
			size = checkCoordinates(i, j-1, size);
		}
		if (i != 0) {
			size = checkCoordinates(i-1, j, size);
		}
		if (j != W-1) {
			size = checkCoordinates(i, j+1, size);
		}
	}
	return size;
}

int main() {
	char input[20];
	cin.getline(input, sizeof(input));
	int T;
	stringstream(input) >> W >> H >> T;
	
	for (int i=0; i<H; i++) {
		string str;
		cin >> str;
		grid.push_back(vector<char> (str.begin(), str.end()));
	}
	
	int islands = 0;
	
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			int size = checkCoordinates(i, j, 0);
			if (size >= T) {
				islands++;
			}
		}
	}
	
	cout << islands;
	
	return 0;
}