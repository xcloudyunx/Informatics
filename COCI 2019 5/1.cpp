#include <bits/stdc++/h>

using namespace std;

int main() {
	vector< tuple< int, string, vector<string> > > srt(30);
	
	string s;
	getline(cin, s);
	while (s != "#\n") {
		int x = s.at(0)-'0';
		string time;
		getline(cin, time);
		
		srt.push_back(make_tuple(x, time, {}));
		
		getline(cin, s);
		while (s != "\n") {
			get<3>(srt.back()).push_back(s);
		}
	}
	
	return 0;
}