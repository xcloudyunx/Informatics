#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	char input[3*N];
	cin.ignore();
	cin.getline(input, sizeof(input));
	int x;
	int K[N];
	stringstream ss(input);
	int i = 0;
	while (ss >> x) {
		K[i] = x;
		i++;
	}
	
	vector<int> lowest = {};
	for (int j : K) {
		bool broken = false;
		for (int k=0; k<lowest.size(); k++) {
			if (j < lowest.at(k)) {
				lowest.at(k) = j;
				broken = true;
				break;
			}
		}
		if (!broken) {
			lowest.push_back(j);
		}
	}
	
	cout << lowest.size();
	
	return 0;
}