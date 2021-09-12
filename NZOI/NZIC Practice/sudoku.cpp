#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	char input[10];
	cin.getline(input, sizeof(input));
	int R, C;
	stringstream(input) >> R >> C;
	
	int xline;
	int xpos;
	int grid[R][C];
	vector<int> numbers;
	for (int i=0; i<R; i++) {
		char row[200];
		cin.getline(row, sizeof(row));
		
		if (find(begin(row), end(row), 'x') != end(row)) {
			xline = i;
			row[find(begin(row), end(row), 'x') - row] = '0';
		}
		
		stringstream ss(row);
		for (int j=0; j<C; j++) {
			ss >> grid[i][j];
		}
		
		numbers.push_back(i+1);
	}
	
	for (int i=0; i<C; i++) {
		if (grid[xline][i] == 0) {
			xpos = i;
			break;
		}
	}
	
	for (int i=0; i<R; i++) {
		if (i != xline) {
			numbers.erase(remove(numbers.begin(), numbers.end(), grid[i][xpos]), numbers.end());
		}
	}
	
	grid[xline][xpos] = numbers[0];
	
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}