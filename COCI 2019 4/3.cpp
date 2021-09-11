#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	vector< pair<long long, long long> > data(N);
	
	for (int i=0; i<N; i++) {
		cin >> data.at(i).second >> data.at(i).first;
	}
	
	sort(data.begin(), data.end());
	
	long long cwidth = 0;
	
	priority_queue<long long> q;
	for (int i=0; i<K; i++) {
		q.push(data.at(i).second);
		cwidth += data.at(i).second;
	}
	
	long long cmin = cwidth*data.at(K-1).first;
	
	for (int i=K; i<N; i++) {
		if (data.at(i).second < q.top()) {
			cwidth += data.at(i).second-q.top();
			q.pop();
			q.push(data.at(i).second);
		}
		cmin = min(cmin, cwidth*data.at(i).first);
	}
	
	cout << cmin << endl;
	
	return 0;
}