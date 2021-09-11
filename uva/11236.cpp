#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	for (int a=1; a<212; a++) {
		for (int b=a; b<667 && a*b<200000; b++) {
			for (int c=b; c<=1000 && (a*b*c)<20000000; c++) {
				if (a*b*c-1000000 == 0 || ((a+b+c)*1000000)%(a*b*c-1000000) != 0) continue;
				int d = ((a+b+c)*1000000)/(a*b*c-1000000);
				if (a+b+c+d > 2000 || d < c) continue;
				printf("%.2f %.2f %.2f %.2f\n", a/100.0f, b/100.0f, c/100.0f, d/100.0f);
			} 
		}
	}
	
	return 0;
}