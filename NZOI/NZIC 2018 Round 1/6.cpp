#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	char input[15];
	cin.getline(input, sizeof(input));
	
	int N, K; stringstream(input) >> N >> K;
	
	char str[12*N];
	cin.getline(str, sizeof(str));
	
	int x;
	vector<int> H;
	stringstream is(str);
	while (is >> x) {
		H.push_back(x);
	}
	
	int cost = 1000000000;
	int maximum = 0;
	int minimum = 1000000000;
	vector<int> heights(H.begin(), H.begin()+K);
	for (int j:heights) {
		maximum = max(j, maximum);
		minimum = min(j, minimum);
	}
	cost = min(maximum-minimum, cost);
	for (int i=1; i<N-K+1; i++) {
		if (H[i-1] == minimum) {
			minimum = 1000000000;
			vector<int> heights(H.begin()+i, H.begin()+i+K);
			for (int j:heights) {
				minimum = min(j, minimum);
			}
		} else if (H[i-1] == maximum) {
			maximum = 0;
			vector<int> heights(H.begin()+i, H.begin()+i+K);
			for (int j:heights) {
				maximum = max(j, maximum);
			}
		} else {
			minimum = min(minimum, H[i+K]);
			maximum = max(maximum, H[i+K]);
		}
		cost = min(maximum-minimum, cost);
	}
	
	cout << cost;
	
	return 0;
}