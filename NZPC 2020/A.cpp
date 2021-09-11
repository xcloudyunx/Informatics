#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N;
	cin >> N;
	string s;
	int x;
	int Joe = 0, James = 0, Jean = 0, Jane = 0, U = 0;
	for (int i=0; i<N; i++) {
		cin >> s;
		if (s == "S") {
			James++;
		} else if (s == "M" || s == "L") {
			Joe++;
		} else if (s == "X") {
			U++;
		} else {
			x = stoi(s);
			if (x >= 12) {
				Jean++;
			} else {
				Jane++;
			}
		}
	}
	cout << Joe << " " << Jean << " " << Jane << " " << James << " " << U;
}