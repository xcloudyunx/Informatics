#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int count;
	string n, s;
	cin >> n >> s;
	
	if (s == "spades") count = 39;
	else if (s == "clubs") count = 26;
	else if (s == "diamonds") count = 13;
	else count = 0;
	
	if (n == "2") count += 12;
	else if (n == "3") count += 11;
	else if (n == "4") count += 10;
	else if (n == "5") count += 9;
	else if (n == "6") count += 8;
	else if (n == "7") count += 7;
	else if (n == "8") count += 6;
	else if (n == "9") count += 5;
	else if (n == "10") count += 4;
	else if (n == "J") count += 3;
	else if (n == "Q") count += 2;
	else if (n == "K") count += 1;
	
	cout << count;
	
	return 0;
}