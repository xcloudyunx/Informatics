#include <bits/stdc++.h>

using namespace std;

struct rect {
	int x1, x2, y1, y2;
	char colour;
};

int l(int val, vector<int> vec) {
	return lower_bound(vec.begin(), vec.end(), val) - vec.begin();
}

int main() {
	int H, W, N;
	cin >> H >> W >> N;
		
	vector<int> row = {0, H};
	vector<int> col = {0, W};
	vector<rect> toProcess;
	
	for (int i=0; i<N; i++) {
		int x, y, s;
		char c;
		cin >> x >> y >> s >> c;
		
		int x1 = max(0, x-s);
		int x2 = min(W, x+s+1);
		int y1 = max(0, y-s);
		int y2 = min(H, y+s+1);
		
		toProcess.push_back({x1, x2, y1, y2, c});
		col.push_back(x1);
		col.push_back(x2);
		row.push_back(y1);
		row.push_back(y2);
	}
	
	sort(row.begin(), row.end());
	sort(col.begin(), col.end());
	row.erase(unique(row.begin(), row.end()), row.end());
	col.erase(unique(col.begin(), col.end()), col.end());
	
	vector< vector<char> > canvas(100, vector<char> (100));
	
	for (auto r : toProcess) {
		for (int i=l(r.y1, row); i<l(r.y2, row); i++) {
			for (int j=l(r.x1, col); j<l(r.x2, col); j++) {
				canvas.at(i).at(j) = r.colour;
			}
		}
	}
	
	char C;
	cin >> C;
	long long total = 0;
	for (int i=0; i<row.size()-1; i++) {
		for (int j=0; j<col.size()-1; j++) {
			if (canvas.at(i).at(j) == C) {
				long long r = row.at(i+1)-row.at(i);
				long long c = col.at(j+1)-col.at(j);
				total += r*c;
			}
		}
	}
	
	cout << total << endl;
	
	return 0;
}