#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> difficulty(N);

  for (int i=0; i<N; i++) {
    cin >> difficulty.at(i);
  }

  int score = 0;
  int half = N/2;

  if (N%2 == 0) {
    sort(difficulty.begin(), difficulty.end());
    vector<int> lowerHalf(difficulty.begin(), difficulty.begin()+half);
    vector<int> upperHalf(difficulty.begin()+half, difficulty.end());

    for (int i=0; i<half-1; i++) {
      score += upperHalf.back() - lowerHalf.back();
      lowerHalf.pop_back();
      score += upperHalf.back() - lowerHalf.back();
      upperHalf.pop_back();
    }
    score += upperHalf.back() - lowerHalf.back();
  } else {
    sort(difficulty.rbegin(), difficulty.rend());
    vector<int> lowerHalf(difficulty.begin()+half+1, difficulty.end());
    vector<int> upperHalf(difficulty.begin(), difficulty.begin()+half);

	if (upperHalf.back() - difficulty.at(half) > difficulty.at(half) - lowerHalf.front()) {
	  score += upperHalf.back() - difficulty.at(half);
	} else {
	  score += difficulty.at(half) - lowerHalf.front();
	}
    for (int i=0; i<half-1; i++) {
      score += upperHalf.back() - lowerHalf.back();
      upperHalf.pop_back();
      score += upperHalf.back() - lowerHalf.back();
      lowerHalf.pop_back();
    }
    score += upperHalf.back() - lowerHalf.back();
  }

  cout << score;

  return 0;
}