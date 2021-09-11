#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int k;
	cin >> k;
	while (k) {
		vi numbers(k);
		for (int i=0; i<k; i++) cin >> numbers[i];
		
		for (int a=0; a<k-5; a++) {
			for (int b=a+1; b<k-4; b++) {
				for (int c=b+1; c<k-3; c++) {
					for (int d=c+1; d<k-2; d++) {
						for (int e=d+1; e<k-1; e++) {
							for (int f=e+1; f<k; f++) {
								cout << numbers[a] << " " << numbers[b] << " " << numbers[c] << " " << numbers[d] << " " << numbers[e] << " " << numbers[f] << "\n";
							}
						}
					}
				}
			}
		}
		
		cin >> k;
		if (k) cout << "\n";
	}
	
	return 0;
}