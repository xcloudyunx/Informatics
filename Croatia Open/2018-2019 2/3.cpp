#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	char input[7];
	cin.getline(input, sizeof(input));
	int N; stringstream(input) >> N;
	
	char input1[10*N];
	cin.getline(input1, sizeof(input1));
	int v[N];
	int q = 0;
	int x;
	stringstream ss(input1);
	while (ss >> x) {
		v[q] = x;
		q++;
	}
	
	int paths[N-1][2];
	for (int i=0; i<N-1; i++) {
		char input2[4];
		cin.getline(input2, sizeof(input2));
		stringstream(input2) >> paths[i][0] >> paths[i][1];
	}
	
	int sum = 0;
	for (int i : v) {
		sum += i;
	}
	
	vector<vector<int>> other;
	
	for (int* path : paths) {
		int a = v[path[0]-1] ^ v[path[1]-1];
		sum += a;
		other.push_back({path[1], a});
	}
	
	for (int i=0; i<other.size(); i++) {
		for (int* path : paths) {
			if (other[i][0] == path[0]) {
				int a = other[i][1] ^ v[path[0]-1];
				sum += a;
				other.push_back({path[1], a})
			}
		}
	}
	
	cout << sum;
	
	return 0;
}