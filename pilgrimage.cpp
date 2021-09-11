#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<int> cityNumbers(N);
  vector< vector< pair<int, int> > > adj(N); //weight, destination
  vector<bool> v(N);

  for (int i=0; i<N; i++) {
    cin >> cityNumbers.at(i);
  }

  for (int i=0; i<M; i++) {
    int A, B, R;
    cin >> A >> B >> R;
    adj.at(A).push_back({R, B});
    adj.at(B).push_back({R, A});
  }

  priority_queue< pair<int, int> > q;
  q.push({0, 0});
  long long people = 0;

  while (!q.empty()) {
    pair<int, int> f = q.top();
    q.pop();

    if (!v.at(f.second)) {
      v.at(f.second) = true;
      people += cityNumbers.at(f.second) + f.first;

      for (pair<int, int> i : adj.at(f.second)) {
        if (!v.at(i.second)) {
          q.push(i);
        }
      }
    }
  }

  cout << people << endl;

  return 0;
}