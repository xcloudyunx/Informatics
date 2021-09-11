#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	string s;
	getline(cin, s);
	string player, nplayer;
	int x, count;
	
	while (s != "#") {
		istringstream stream(s);
		stream >> player;
		nplayer = (player == "X") ? "O" : "X";
		count = 0;
		vector< vector<string> > grid(3, vector<string>(3, ""));
		while (stream >> x) {
			x--;
			if (count%2) {
				grid[x/3][x%3] = nplayer;
			} else {
				grid[x/3][x%3] = player;
			}
			count++;
		}
		
		if (grid[1][1] == grid[0][1] && grid[1][1] == grid[2][1] && grid[1][1] != "") {
			cout << grid[1][1];
		} else if (grid[1][1] == grid[1][0] && grid[1][1] == grid[1][2] && grid[1][1] != "") {
			cout << grid[1][1];
		} else if (grid[1][1] == grid[0][0] && grid[1][1] == grid[2][2] && grid[1][1] != "") {
			cout << grid[1][1];
		} else if (grid[1][1] == grid[2][0] && grid[1][1] == grid[0][2] && grid[1][1] != "") {
			cout << grid[1][1];
		} else if (grid[0][0] == grid[0][1] && grid[0][0] == grid[0][2] && grid[0][0] != "") {
			cout << grid[0][0];
		} else if (grid[0][0] == grid[1][0] && grid[0][0] == grid[2][0] && grid[0][0] != "") {
			cout << grid[0][0];
		} else if (grid[2][2] == grid[2][1] && grid[2][2] == grid[2][0] && grid[2][2] != "") {
			cout << grid[2][2];
		} else if (grid[2][2] == grid[1][2] && grid[2][2] == grid[0][2] && grid[2][2] != "") {
			cout << grid[2][2];
		} else {
			cout << "Draw";
		}
		cout << "\n";
		
		getline(cin, s);
	}
}