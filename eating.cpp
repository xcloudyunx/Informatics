#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<int> cows(N);
	
	for (int i=0; i<N; i++) cin >> cows.at(i);
	
	vector< vector<int> > table(2, vector<int>(4));
	table.at(0) = {INT_MAX, 0, 0, 0};
	table.at(1).at(0) = INT_MAX;
	
	for (int i=1; i<=N; i++) {
		int c = i%2;
		int p = (i-1)%2;
		if (cows.at(i-1) == 1) {
			table.at(c).at(1) = table.at(p).at(1);
			table.at(c).at(2) = min(table.at(p).at(1), table.at(p).at(2))+1;
			table.at(c).at(3) = *min_element(table.at(p).begin(), table.at(p).end())+1;
		} else if (cows.at(i-1) == 2) {
			table.at(c).at(1) = table.at(p).at(1)+1;
			table.at(c).at(2) = min(table.at(p).at(1), table.at(p).at(2));
			table.at(c).at(3) = *min_element(table.at(p).begin(), table.at(p).end())+1;
		} else {
			table.at(c).at(1) = table.at(p).at(1)+1;
			table.at(c).at(2) = min(table.at(p).at(1), table.at(p).at(2))+1;
			table.at(c).at(3) = *min_element(table.at(p).begin(), table.at(p).end());
		}
		
		/*for (int j=1; j<4; j++) {
			cout << table.at(c).at(j) << " ";
		}
		cout << endl;*/
	}
	
	//cout << endl;
	
	int first = *min_element(table.at(N%2).begin(), table.at(N%2).end());
	
	reverse(cows.begin(), cows.end());
	table.at(0) = {INT_MAX, 0, 0, 0};
	
	for (int i=1; i<=N; i++) {
		int c = i%2;
		int p = (i-1)%2;
		if (cows.at(i-1) == 1) {
			table.at(c).at(1) = table.at(p).at(1);
			table.at(c).at(2) = min(table.at(p).at(1), table.at(p).at(2))+1;
			table.at(c).at(3) = *min_element(table.at(p).begin(), table.at(p).end())+1;
		} else if (cows.at(i-1) == 2) {
			table.at(c).at(1) = table.at(p).at(1)+1;
			table.at(c).at(2) = min(table.at(p).at(1), table.at(p).at(2));
			table.at(c).at(3) = *min_element(table.at(p).begin(), table.at(p).end())+1;
		} else {
			table.at(c).at(1) = table.at(p).at(1)+1;
			table.at(c).at(2) = min(table.at(p).at(1), table.at(p).at(2))+1;
			table.at(c).at(3) = *min_element(table.at(p).begin(), table.at(p).end());
		}
		
		/*for (int j=1; j<4; j++) {
			cout << table.at(c).at(j) << " ";
		}
		cout << endl;*/
	}
	
	int second = *min_element(table.at(N%2).begin(), table.at(N%2).end());
	
	cout << min(first, second) << endl;
	
	return 0;
}