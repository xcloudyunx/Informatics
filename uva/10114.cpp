#include <bits/stdc++.h>

using namespace std;

int main() {
	int d, r, month;
	float p, l1, l2, test;
	vector< pair<int, float> > data(2, make_pair(0, 0));
	cin >> d >> p >> l1 >> r;
	
	while (d > 0) {
		test = l1/d;
		month = 0;
		cin >> data.at(r%2).first >> data.at(r%2).second;
		l2 = (l1+p)*(1-data.at(r%2).second);
		if (l1 >= l2) {
			month = 1;
		}
		while (--r) {
			cin >> data.at(r%2).first >> data.at(r%2).second;
			if (l1 >= l2) {
				while (month < data.at(r%2).first) {
					l1 -= test;
					l2 *= 1-data.at((r+1)%2).second;
					if (l1 < l2) {
						break;
					}
					month++;
				}
			}
		}
		while (l1 >= l2) {
			l1 -= test;
			l2 *= 1-data.at(1).second;
			if (l1 < l2) {
				break;
			}
			month++;
		}
		if (month == 1) {
			cout << "1 month\n";
		} else {
			cout << month << " months\n";
		}
		
		cin >> d >> p >> l1 >> r;
	}
	
	return 0;
}