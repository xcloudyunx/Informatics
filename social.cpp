#include <bits/stdc++.h>

using namespace std;

int cfind(int x, vector<int> &parent) {
  if (parent.at(x) == x) {
    return x;
  } else {
    return parent.at(x) = cfind(parent.at(x), parent);
  }
}

void cmerge(int x, int y, vector<int> &parent, vector<int> &size) {
  x = cfind(x, parent);
  y = cfind(y, parent);

  if (x == y) {
    return;
  }

  if (size.at(x) < size.at(y)) {
    swap(x, y);
  }

  parent.at(y) = x;
  size.at(x) += size.at(y);
}

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> parent(N);
  vector<int> size(N, 1);
  iota(parent.begin(), parent.end(), 0);

  for (int i=0; i<Q; i++) {
    char ask;
	int A, B;
    cin >> ask >> A >> B;
	if (ask == 'f') {
		cmerge(A, B, parent, size);
	} else {
		if (cfind(A, parent) == cfind(B, parent)) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
  }

  return 0;
}