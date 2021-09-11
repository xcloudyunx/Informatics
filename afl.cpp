#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<bool> row(n, false);
	vector<int> booked = {-1, n};
	
	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		int x;
		cin >> x;
		row.at(x-1) = true;
		booked.push_back(x-1);
	}
	
	sort(booked.begin(), booked.end());
	
	int b;
	cin >> b;
	for (int i=0; i<b; i++) {
		int x;
		cin >> x;
		int size = booked.size();
		int largestdifference = 0;
		int start;
		for (int j=1; j<size; j++) {
			int difference = booked.at(j)-booked.at(j-1);
			if (booked.at(j)-booked.at(j-1) > largestdifference) {
				largestdifference = difference;
				start = booked.at(j-1);
			}
		}
		start++;
		cout << start+1 << endl;
		for (int j=0; j<x; j++) {
			row.at(start+j) = true;
			booked.push_back(start+j);
		}
		sort(booked.begin(), booked.end());
		
		/*for (bool x : row) {
			cout << x << " ";
		}
		cout << endl;
		for (int x : booked) {
			cout << x << " ";
		}*/
	}
	
	return 0;
}