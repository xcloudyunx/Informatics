#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, T, K;
  cin >> N >> T >> K;

  int quality = 0;
  int addition = 0;
  vector<int> original(N, 0);

  int currentMaxScore = 0;
  int currentMaxDay = 0;

  int j = 0;
  for (int i=0; i<K; i++) {
    int d, m, r;
    cin >> d >> m >> r;

    while (j < d-1) {
	  j++;
      quality += addition;
      if (quality >= currentMaxScore) {
        currentMaxScore = quality;
        currentMaxDay = j;
      }
	  //cout << j << " " << quality << endl;
    }
	
	addition -= original.at(m-1);
	addition += r;
    original.at(m-1) = r;
  }

  while (j < T) {
	j++;
    quality += addition;
    if (quality >= currentMaxScore) {
      currentMaxScore = quality;
      currentMaxDay = j;
    }
  }
  cout << currentMaxDay << " " << currentMaxScore;

  return 0;
}