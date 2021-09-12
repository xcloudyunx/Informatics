#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	char input[20];
	cin.getline(input, sizeof(input));
	int N, K;
	stringstream(input) >> N >> K;
	
	vector<vector<string>> passports;
	for (int i=0; i<N; i++) {
		cin.getline(input, sizeof(input));
		string ptype, pnumber;
		stringstream(input) >> ptype >> pnumber;
		passports.push_back(vector<string> {pnumber, ptype});
	}
	
	vector<string> outputs;
	for (int i=0; i<K; i++) {
		string str;
		cin >> str;
		bool broken = false;
		for (vector<string> element : passports) {
			if (str == "ALL") {
				outputs.push_back(element.at(0));
				passports.erase(passports.begin());
				broken = true;
				break;
			} else if (element.at(1) == str) {
				outputs.push_back(element.at(0));
				passports.erase(remove(passports.begin(), passports.end(), element), passports.end());
				broken = true;
				break;
			}
		}
		if (!broken) {
			outputs.push_back("NA");
		}
	}
	
	for (string i : outputs) {
		cout << i << endl;
	}
	
	return 0;
}