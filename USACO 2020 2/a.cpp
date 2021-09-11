#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	ifstream infile;
	infile.open("word.in");
	ofstream outfile;
	outfile.open("word.out");
	
	int N, K, count = 0;
	infile >> N >> K;
	
	vector<string> s(N);
	for (int i=0; i<N; i++) infile >> s[i];
	
	for (auto i : s) {
		if (count+i.size() <= K) {
			if (count) outfile << " ";
			outfile << i;
			count += i.size();
		} else {
			outfile << "\n" << i;
			count = i.size();
		}
	}
	
	infile.close();
	outfile.close();
	
	return 0;
}