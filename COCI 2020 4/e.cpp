#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, ctrue = 0, num, left, right;
	float cmax = 0.0f;
	string s;
	cin >> N >> s;
	
	if (N <= 100) {
		unordered_map<char, int> m;
		for (int i=0; i<N; i++) {
			for (int j=i+1; j<N; j++) {
				ctrue++;
				num = 0;
				for (int k=i; k<=j; k++) {
					if (m.find(s[k]) == m.end() || m[s[k]] != ctrue) {
						m[s[k]] = ctrue;
						num++;
					}
				}
				if ((j-i+1)/(float)num > cmax) {
					cmax = (j-i+1)/(float)num, left = i, right = j;
				}
			}
		}
		cout << left+1 << " " << right+1 << "\n";
	} else {
		int ccmax = 0, cleft = 0;
		num = 1;
		left = 0;
		for (int i=1; i<N; i++) {
			if (s[i] == s[i-1]) num++;
			else {
				if (num > ccmax) {
					ccmax = num;
					left = cleft;
					right = i-1;
				}
				cleft = i;
				num = 1;
			}
		}
		if (2*ccmax > N) cout << left+1 << " " << right+1 << "\n";
		else cout << 1 << " " << N << "\n";
	}
	
	return 0;
}