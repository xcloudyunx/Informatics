#include <iostream>
#include <sstream>

using namespace std;

char grid[100];
int fig1 = 0;
int fig2 = 0;
int fig3 = 0;
int fig4 = 0;
int fig5 = 0;

int check(int x, int y, bool main=false) {
	char letter = grid[y][x];
	grid[y][x] = ".";
	if (grid[y][x+1] == letter) {
		check([y][x+1]);
	}
	if (grid[y+1][x] == letter) {
		check([y+1][x]);
	}
	if (grid[y][x-1] == letter) {
		check([y][x-1]);
	}
	if (grid[y-1][x] == letter) {
		check([y-1][x]);
	}
	
	return;
}

int main() {
	char input[6];
	cin.getline(input, sizeof(input));
	int N, M; stringstream(input) >> N >> M;
	
	for (int i=0; i<N; i++) {
		cin >> grid[i];
	}
	
	int figure;	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (grid[i][j] != ".") {
				figure = check(j, i, true);
				switch (figure) {
					case 1:
						fig1++;
						break;
					case 2:
						fig2++;
						break;
					case 3:
						fig3++;
						break;
					case 4:
						fig4++;
						break;
					case 5:
						fig5++;
						break;
					default:
						break;
				}
			}
		}
	}
}