#include <iostream>
#include <vector>

using namespace std;

int main() {
	int G;
	cin >> G;
	vector<int> gates;
	gates.resize(G+1, 0);
	
	int P;
	cin >> P;
	
	int planes = 0;
	
	bool complete = false;
	for (int i=0; i<P; i++) {
		int x;
		cin >> x;
		if (!complete) {
			bool broken = false;
			for (x; x>0; x--) {
				if (gates.at(x) == 0) {
					gates.at(x) = 1;
					planes++;
					broken = true;
					break;
				}
			}
			if (!broken) {
				complete = true;
			}
		}
	}
	
	cout << planes;
	
	return 0;
}