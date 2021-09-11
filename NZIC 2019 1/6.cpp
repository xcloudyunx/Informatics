#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int, int> combineSpell(tuple<int, int, int, int> s1, tuple<int, int, int, int> s2) {
	int a1 = get<0>(s1);
	int b1 = get<1>(s1);
	int c1 = get<2>(s1);
	int d1 = get<3>(s1);
	int a2 = get<0>(s2);
	int b2 = get<1>(s2);
	int c2 = get<2>(s2);
	int d2 = get<3>(s2);
	
	return make_tuple((a1*a2+c1*b2)%10000, (b1*a2+d1*b2)%10000, (a1*c2+c1*d2)%10000, (b1*c2+d1*d2)%10000);
}

tuple<int, int> castSpell(tuple<int, int, int, int> s, int u, int v) {
	int a = get<0>(s);
	int b = get<1>(s);
	int c = get<2>(s);
	int d = get<3>(s);
	return make_tuple((a*u+b*v)%10000, (c*u+d*v)%10000);
}

tuple<int, int, int, int> spellPower(tuple<int, int, int, int> s, int n) {
	if (n == 0) return make_tuple(1, 0, 0, 1);
	
	tuple<int, int, int, int> r = spellPower(s, n/2);
	r = combineSpell(r, r);
	if (n%2 == 1) r = combineSpell(r, s);
	return r;
}

int main() {
	int A, B, C, D, N;
	cin >> A >> B >> C >> D >> N;
	
	tuple<int, int> uv = castSpell(spellPower(make_tuple(A, B, C, D), N), 1, 1);
	
	cout << get<0>(uv) << " " << get<1>(uv) << endl;
	
	return 0;
}