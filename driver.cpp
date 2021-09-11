#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  int S;
  cin >> S;

  vector<int> songs;
  for (int i=0; i<S; i++) {
    int x;
    cin >> x;
    songs.push_back(x);
  }

  int N, H, T;
  cin >> N >> H >> T;

  vector< vector< pair<int, int> > > adj(N);

  for (int i=0; i<T; i++) {
    int X, Y, M;
    cin >> X >> Y >> M;
    adj.at(X-1).push_back({Y-1, M});
    adj.at(Y-1).push_back({X-1, M});
  }

  vector< vector<int> > distance(N, vector<int> (S, INT_MAX/2));

  queue< pair<int, int> > q;
  q.push({H-1, 0});
  distance.at(H-1).at(0) = 0;

  while (!q.empty()) {
	  pair<int, int> f = q.front();
	  q.pop();

	  int eggs;
	  for (pair<int, int> i : adj.at(f.first)) {
		  //cout << "f: " << f.first << " " << f.second << " i: " << i.first << " " << i.second << endl;
		  if (i.second == songs.at(f.second)) {
			  eggs = 0;
		  } else {
			  eggs = 1;
		  }
		  int x = distance.at(f.first).at(f.second) + eggs;
		  //cout << "x: " << x << " other: " << distance.at(i.first).at(f.second) << endl;
		  if (x < distance.at(i.first).at(f.second)) {
			  distance.at(i.first).at(f.second+1) = x;
			  if (f.second < S-2) {
				q.push({i.first, f.second+1});
			  }
		  }
	  }
  }
  
  cout << distance.at(H-1).at(S-1);

  return 0;
}