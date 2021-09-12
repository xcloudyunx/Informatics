#include <iostream>
#include <sstream>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	for (int i=0; i<N; i++) {
		int S;
		cin >> S;
		int pounds = 0;
		int shillings = 0;
		int pence = 0;
		for (int j=0; j<S; j++) {
			char input[9];
			cin >> input;
			for (int k=0; input[k]!='\0'; k++) {
				if (!isdigit(input[k])) {
					input[k] = ' ';
				}
			}
			
			int x, y, z; stringstream(input) >> x >> y >> z;
			pounds += x;
			shillings += y;
			pence += z;	
		}
		shillings += pence/12;
		pence %= 12;
		pounds += shillings/20;
		shillings %= 20;
		cout << "#" << pounds << "-" << shillings << "-" << pence << endl;
	}
	
	return 0;
}