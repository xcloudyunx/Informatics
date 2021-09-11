#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int G, N;
	cin >> G >> N;
	
	vector<string> good;
	map<string, int> points;
	
	for (int i=0; i<G; i++) {
		string s;
		cin >> s;
		good.push_back(s);
		if (points.find(s) == points.end()) {
			points.emplace(s, 1);
		} else {
			points.at(s)++;
		}
	}
	
	for (int i=0; i<N; i++) {
		string s;
		cin >> s;
		if (points.find(s) != points.end()) {
			points.erase(s);
		}
	}
	
	for (auto p : points) {
		cout << p.first << " " << p.second << endl;
	}
	
	return 0;
}