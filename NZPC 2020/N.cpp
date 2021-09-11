#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int n, x;
	cin >> n;
	string line;
	
	while (n) {
		vector<vi> adjList(n);
		cin.ignore();
		for (int i=0; i<n; i++) {
			getline(cin, line);
			istringstream stream(line);
			while (stream >> x) adjList[i].push_back(x);
		}
		
		queue<int> q;
		q.push()
		
		
		cin >> n;
	}
}