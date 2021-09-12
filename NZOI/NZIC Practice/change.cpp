#include <iostream>

using namespace std;

int main() {
	int P;
	cin >> P;
	
	int score = P/100;
	P %= 100;
	
	if (P >= 70) {
		P -= 50;
		score += 2;
	}
	
	if (P < 30 || (P >= 35 && P < 40) || (P >= 45 && P < 55) || (P >=60 && P < 65)) {
		score += P/25;
		P %= 25;
	} else if ((P >= 55 && P < 60) || (P >= 65 && P < 70)) {
		P -= 25;
		score++;
	}
	
	score += P/10;
	P %= 10;
	
	score += P;
	
	cout << score;
}