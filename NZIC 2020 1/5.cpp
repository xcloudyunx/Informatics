#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define INF LLONG_MAX

int main() {
	int N, pos, tpos;
	ll clow = 0, c1 = 0, c2 = 0, alow = 0;
	cin >> N;
	vll huts(N);
	for (int i=0; i<N; i++) cin >> huts[i];
	
	if (N == 1) {
		cout << huts[0];
		return 0;
	}
	
	for (int j=0, num=N; j<N; j++, num--) clow += num*huts[j];
	for (int j=1, num=N; j<1+N; j++, num--) c1 += num*huts[j%N];
	
	if (clow <= c1) {
		pos = 0;
		for (int i=N/2; i>=0;) {
			tpos = (pos-i+N)%N;
			c1 = 0, c2 = 0;
			for (int j=tpos, num=N; j<tpos+N; j++, num--) c1 += num*huts[j%N];
			for (int j=tpos-1, num=N; j<tpos-1+N; j++, num--) c2 += num*huts[(j+N)%N];
			if (c2 < clow && c2 < c1) {
				clow = c2;
				pos = (tpos-1+N)%N;
			} else {
				if (!i) break;
				i /= 2;
			}
		}
	} else {
		clow = c1;
		pos = 1;
		for (int i=N/2; i>=0;) {
			tpos = (pos+i)%N;
			c1 = 0, c2 = 0;
			for (int j=tpos, num=N; j<tpos+N; j++, num--) c1 += num*huts[j%N];
			for (int j=tpos+1, num=N; j<tpos+1+N; j++, num--) c2 += num*huts[j%N];
			if (c2 < clow && c2 < c1) {
				clow = c2;
				pos = (tpos+1)%N;
			} else {
				if (!i) break;
				i /= 2;
			}
		}
	}
	
	c1 = 0;
	for (int j=0, num=N; j>-N; j--, num--) alow += num*huts[(j+N)%N];
	for (int j=1, num=N; j>1-N; j--, num--) c1 += num*huts[(j+N)%N];
	
	if (alow <= c1) {
		pos = 0;
		for (int i=N/2; i>=0;) {
			tpos = (pos-i+N)%N;
			c1 = 0, c2 = 0;
			for (int j=tpos, num=N; j>tpos-N; j--, num--) c1 += num*huts[(j+N)%N];
			for (int j=tpos-1, num=N; j>tpos-1-N; j--, num--) c2 += num*huts[(j+N+N)%N];
			if (c2 < alow && c2 < c1) {
				alow = c2;
				pos = (tpos-1+N)%N;
			} else {
				if (!i) break;
				i /= 2;
			}
		}
	} else {
		alow = c1;
		pos = 1;
		for (int i=N/2; i>=0;) {
			tpos = (pos+i)%N;
			c1 = 0, c2 = 0;
			for (int j=tpos, num=N; j>tpos-N; j--, num--) c1 += num*huts[(j+N)%N];
			for (int j=tpos+1, num=N; j>tpos+1-N; j--, num--) c2 += num*huts[(j+N)%N];
			if (c2 < alow && c2 < c1) {
				alow = c2;
				pos = (tpos+1)%N;
			} else {
				if (!i) break;
				i /= 2;
			}
		}
	}
	
	cout << min(alow, clow) << "\n";
	
	return 0;
}