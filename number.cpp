#include <bits/stdc++.h>

using namespace std;

int main() {
	unordered_map<int, char> nums = {{0,'0'}, {1,'1'}, {2,'2'}, {3,'3'}, {4,'4'}, {5,'5'}, {6,'6'}, {7,'7'}, {8,'8'}, {9,'9'}, {10,'A'}, {11,'B'}, {12,'C'}, {13,'D'}, {14,'E'}, {15,'F'}, {16,'G'}, {17,'H'}, {18,'I'}, {19,'J'}};
	
	string f;
	getline(cin, f);
	
	while (f != "#") {
		int s, t;
		cin >> s >> t;
		
		string num;
		
		while (t%s) {
			num.push_back(nums.at(t%s));
			t /= s;
		}
		
		for (auto i=num.rbegin(); i!=num.rend(); i++) {
			cout << *i;
		}
		
		cout << endl;
		getline(cin, f);
	}
	
	return 0;
}