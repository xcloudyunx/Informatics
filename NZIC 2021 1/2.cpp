#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int red = 0, pink = 0, purple = 0, blue = 0;
	string s;
	for (int i=0; i<7; i++) {
		cin >> s;
		if (s == "Red") red++;
		else if (s == "Blue") blue++;
		else if (s == "Pink") pink++;
		else purple++;
	}
	
	if (red == 1) cout << "Red";
	else if (blue == 1) cout << "Blue";
	else if (pink == 1) cout << "Pink";
	else cout << "Purple";
	
	return 0;
}