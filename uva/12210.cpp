#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int B, S, TC = 1;
	cin >> B >> S;
	while (B && S) {
		vi bach(B);
		for (int i=0; i<B; i++) cin >> bach[i];
		vi spin(S);
		for (int i=0; i<S; i++) cin >> spin[i];
		
		cout << "Case " << TC++ << ": " << max(0, B-S);
		if (B-S > 0) cout << " " << *min_element(bach.begin(), bach.end());
		cout << "\n";
		cin >> B >> S;
	}
	
	return 0;
}