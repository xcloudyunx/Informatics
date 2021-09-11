#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	string N;
	cin >> N;
	int x;
	while (N != "0") {
		x = 1;
		for (int i=0; i<N.size(); i++) {
			if (N[i] == '1') x += 3;
			else if (N[i] == '0') x += 5;
			else x += 4;
		}
		
		cout << x << '\n';
		cin >> N;
	}
}