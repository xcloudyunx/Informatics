#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	string s, tag, tmp;
	getline(cin, s);
	bool intag;
	bool broken;
	
	while (s != "#") {
		intag = false;
		broken = false;
		stack<string> st;
		for (int i=0; i<s.size(); i++) {
			if (s[i] == '<') {
				tag = "";
				intag = true;
			} else if (s[i] == '>') {
				intag = false;
				if (s[i-1] != '/') {
					if (tag[0] == '/') {
						if (st.empty()) {
							cout << "illegal\n";
							broken = true;
							break;
						} else {
							tmp = '/'+st.top();
							if (tmp != tag) {
								cout << "illegal\n";
								broken = true;
								break;
							}
							st.pop();
						}
					} else {
						st.push(tag);
					}
				}
			} else if (intag) {
				if (s[i] == ' ') intag = false;
				else tag += s[i];
			}
		}
		if (!broken) {
			if (st.empty()) cout << "legal\n";
			else cout << "illegal\n";
		}
		
		getline(cin, s);
	}
}