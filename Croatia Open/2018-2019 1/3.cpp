#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
	char input[14];
	cin.getline(input, sizeof(input));
	int N, M; stringstream(input) >> N >> M;
	
	unsigned int leftShoes[N];
	unsigned int rightShoes[M];
	
	int i = 0;
	char leftInput[20*N];
	cin.getline(leftInput, sizeof(leftInput));
	istringstream lis(leftInput);
	while (lis >> leftShoes[i]) {
		i++;
	}
	sort(leftShoes, leftShoes+N);
	
	i = 0;
	char rightInput[20*M];
	cin.getline(rightInput, sizeof(rightInput));
	istringstream ris(rightInput);
	while (ris >> rightShoes[i]) {
		i++;
	}
	sort(rightShoes, rightShoes+M);
	
	int difference = abs(N-M);
	int less = min(N, M);
	unsigned int maxShoe[max(N, M)];
	unsigned int minShoe[less];
	if (less == N) {
		memcpy(maxShoe, rightShoes, sizeof(rightShoes));
		memcpy(minShoe, leftShoes, sizeof(leftShoes));
	}
	else {
		memcpy(maxShoe, leftShoes, sizeof(leftShoes));
		memcpy(minShoe, rightShoes, sizeof(rightShoes));
	}
	unsigned int shoe[less];
	
	unsigned int maximum = 0;
	unsigned int minimum = 1000000000;
	
	for (int k=0; k<=difference; k++) {
		memcpy(shoe, maxShoe+k, sizeof(int)*less);
		maximum = 0;
		for (int j=0; j<less; j++) {
			maximum = max(maximum, max(shoe[j], minShoe[j]) - min(shoe[j], minShoe[j]));
		}
		minimum = min(minimum, maximum);
	}
	
	cout << minimum;
}