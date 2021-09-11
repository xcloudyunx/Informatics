#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

void printOptions(vi &test, vector< vector<string> > &dic) {
	
}

int main() {
	int N;
	cin >> N;
	int n = 1;
	while (N) {
		vector< vector<string> > dic(23);
		string s;
		
		for (int i=0; i<N; i++) {
			cin >> s;
			dic[s.size()].push_back(s);
		}
		
		int C;
		cin >> C;
		cin.ignore();
		vi test;
		for (int i=0; i<C; i++) {
			getline(cin, s);
			istringstream stream(s);
			string x;
			while (stream >> x) {
				test.push_back(x.size())
			}
		}
		
		printOptions(test, dic);
		
		cin >> N;
		n++;
	}
}