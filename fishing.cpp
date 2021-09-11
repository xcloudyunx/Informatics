#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
  int N, x, y, v, cmax = 0;
  cin >> N;

  map<int, int> left;
  map<int, int> right;
  vii l;
  vii r;

  while (N--) {
    cin >> x >> y >> v;
    x += y*v;
    if (v == 1) {
      if (right.find(x) == right.end()) right[x] = 0;
      right[x]++;
    } else {
      if (left.find(x) == left.end()) left[x] = 0;
      left[x]++;
    }
  }

  auto j = left.begin();
  
  for (auto i=right.begin(); i!=right.end(); i++) {
	  while (j != left.end() && (*j).first < (*i).first) j++;
	  if (j == left.end()) break;
	  cmax = max(cmax, (*i).second+(*j).second);
  }

  cout << cmax;

  return 0;
}