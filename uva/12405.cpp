#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int T, N, i, num;
	string field;
	cin >> T;
	for (int TC=1; TC<=T; TC++) {
		cin >> N >> field;
		i = 0;
		num = 0;
		while (i < N) {
			if (field[i] == '.') {
				num++;
				i += 3;
			} else i++;
		}
		cout << "Case " << TC << ": " << num << "\n";
	}
	
	return 0;
}