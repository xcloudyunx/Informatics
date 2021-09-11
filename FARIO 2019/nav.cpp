#include "nav.h"
#include <bits/stdc++.h>

using namespace std;

vector<int> C;
vector<int> D;
int mid;
int low = 0;
int high;

void init(int subtask, int n, int m, std::vector<int> A, std::vector<int> B) {
	C = A;
	D = B;
	int high = n;
	mid = n/2;
}

int findPrime() {
    int x = nav(mid);
	while (x != -1) {
		if (C.at(x) > mid || D.at(x) > mid) {
			low = mid+1;
		} else {
			high = mid-1;
		}
		mid = (high+low)/2;
		x = nav(mid);
	}
    return mid;
}

