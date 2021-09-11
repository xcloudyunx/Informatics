#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> numbers;
	
	for (int i=0; i<N; i++) {
		int S;
		cin >> S;
		numbers.push_back(S);
	}
	
	sort(numbers.rbegin(), numbers.rend());
	
	for (int i=0; i<K; i++) {
		cout << numbers.at(i) << endl;
	}
	
	return 0;
}