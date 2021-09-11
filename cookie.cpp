#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	vector<float> outputs;
	for (int z=0; z<T; z++) {
		float C, F, X;
		cin >> C >> F >> X;
		float time = X / 2;
		float prev = X / 2 +1;
		int fac = 0;
		float factime = 0;
		while (time < prev) {
			factime += C / (2+(fac*F));
			fac++;
			prev = time;
			time = factime + X / (2+(fac+1)*F);
			cout << fac << " " << factime << " " << time << endl;
		}
		outputs.push_back(prev);
	}
	
	for (int i=0; i<T; i++) {
		cout << "Case: #" << i+1 << ": " << outputs.at(i) << endl;
	}
	
	return 0;
}