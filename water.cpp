#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector< vector<int> > adj(N);
  vector< vector<int> > parents(N);
  vector<double> currentWater(N+M, 0);
  queue<int> q;

  for (int i=0; i<N; i++) {
    int a, b;
    cin >> a >> b;
    adj.at(i).push_back(a-1);
    adj.at(i).push_back(b-1);
	if (a-1 < N) {
		parents.at(a-1).push_back(i);
	}
	if (b-1 < N) {
		parents.at(b-1).push_back(i);
	}
  }
  
  currentWater.at(0) = 1;

  q.push(0);
  while (!q.empty()) {
	  int f = q.front();
	  q.pop();
	  for (int i : adj.at(f)) {
		  currentWater.at(i) += currentWater.at(f)/2;
		  if (i < N) {
			  parents.at(i).erase(remove(parents.at(i).begin(), parents.at(i).end(), f), parents.at(i).end());
			  if (parents.at(i).empty()) {
				  q.push(i);
			  }
		  }
	  }
  }

  cout.precision(7);
  for (int i=0; i<M; i++) {
    cout << fixed << currentWater.at(N+i) << endl;
  }

  return 0;
}