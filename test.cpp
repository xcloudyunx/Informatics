#include <bits/stdc++.h>
using namespace std;


int dp(vector<pair<int, int> > &blockDimensions, int &maxHeight, int heightSoFar, size_t index) {
    if (index == blockDimensions.size()) {
        return heightSoFar;
    }

    int m = heightSoFar;

    if ((heightSoFar + blockDimensions[index].first) <= maxHeight) {
        m = dp(blockDimensions, maxHeight, heightSoFar + blockDimensions[index].first, index+1);
    } else {
		m = dp(blockDimensions, maxHeight, heightSoFar, index+1);
	}

    if ((heightSoFar + blockDimensions[index].second) <= maxHeight) {
        m = max(m, dp(blockDimensions, maxHeight, heightSoFar + blockDimensions[index].second, index+1));
    } else {
		m = max(m, dp(blockDimensions, maxHeight, heightSoFar, index+1));
	}

    /*return max(
        ((heightSoFar + blockDimensions[index].first) <= maxHeight) ? dp(blockDimensions, maxHeight, heightSoFar + blockDimensions[index].first, index+1) : heightSoFar,
        ((heightSoFar + blockDimensions[index].second) <= maxHeight) ? dp(blockDimensions, maxHeight, heightSoFar + blockDimensions[index].second, index+1) : heightSoFar
    );*/
    return m;
}

int main() {
    int blockCount, maxHeight;
    scanf("%d %d", &blockCount, &maxHeight);

    vector<pair<int, int /*width, height*/> > blockDimensions(blockCount);
    for (int i=0; i < blockCount; i++) {
        int width, height;
        scanf("%d %d", &width, &height);

        blockDimensions[i] = {width, height};
    }

    printf("%d\n", dp(blockDimensions, maxHeight, 0, 0));
}