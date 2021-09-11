#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, M, book1, book2, low, mid, high;
	while (cin >> N) {
		vi books(N);
		for (int i=0; i<N; i++) cin >> books[i];
		cin >> M;
		sort(books.begin(), books.end());
		book1 = -1, book2 = 1000001;
		for (int i=0; i<N; i++) {
			low = i, high = N;
			while (high-low > 1) {
				mid = (low+high)/2;
				if (books[i]+books[mid] == M) {
					if (books[mid]-books[i] < book2-book1) book1 = books[i], book2 = books[mid];
					break;
				}
				else if (books[i]+books[mid] < M) low = mid;
				else if (books[i]+books[mid] > M) high = mid;
			}
		}
		cout << "Peter should buy books whose prices are " << book1 << " and " << book2 << ".\n\n";
	}
	
	return 0;
}