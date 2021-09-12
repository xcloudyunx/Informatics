#include <iostream>

using namespace std;

int main() {
	int deck[14];
	for (int i=1; i<14; i++) {
		deck[i] = 4;
	}
	
	int N;
	cin >> N;
	int cards[N];
	for (int i=0; i<N; i++) {
		cin >> cards[i];
	}
	
	int sum = 0;
	for (int i : cards) {
		sum += i;
		deck[i] -= 1;
	}
	
	int difference = 21-sum;
	int cardsLeft = 0;
	for (int i=1; i<=difference; i++) {
		cardsLeft += deck[i];
	}
	
	if (cardsLeft > (52-N)/2) {
		cout << "VUCI" << endl;
	}
	else {
		cout << "DOSTA" << endl;
	}
}