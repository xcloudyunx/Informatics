#include <bits/stdc++.h>

using namespace std;

pair<int, int> binarySearch(int high, vector<int> list, int x) {
	int low = -1;
	
	while (low <= high) {
		int mid = (low+high)/2;
		if (low+1 == high) {
			return make_pair(low, high);
		} else if (x < list.at(mid)) {
			high = mid;
		} else {
			low = mid;
		}
	}
	
	return make_pair(-1, -1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, p, a;
	cin >> N;
	
	vector<int> position(N);
	vector< pair<int, int> > info(N, make_pair(0, 10)); //damage, health
	
	int dmg = 0;
	
	for (int i=0; i<N; i++) {
		cin >> position.at(i) >> info.at(i).first;
		dmg += info.at(i).first;
	}
	
	cin >> p >> a;
	int health = 60;
	
	pair<int, int> ps = binarySearch(N, position, p);
	int x = ps.first;
	int y = ps.second;
	
	while (true) {		
		if (x >= 0) {
			info.at(x).second -= a;
			if (info.at(x).second <= 0) {
				dmg -= info.at(x).first;
				x--;
			}
		}
		
		if (y < N) {
			info.at(y).second -= a;
			if (info.at(y).second <= 0) {
				dmg -= info.at(y).first;
				y++;
			}
		}
		
		if (dmg == 0) {
			cout << "Shadow wins!";
			break;
		}
		
		
		health -= dmg;
		
		if (health <= 0) {
			cout << "We win! Players alive: ";
			for (int i=0; i<=x; i++) {
				cout << position.at(i) << " ";
			}
			for (int i=y; i<N; i++) {
				cout << position.at(i) << " ";
			}
			break;
		}
	}
	
	return 0;
}