#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, T, x, num;
	cin >> N >> T;
	
	map<int, int> weights;
	for (int i=0; i<N; i++) {
		cin >> x;
		if (weights.find(x) == weights.end()) weights[x] = 0;
		weights[x]++;
	}
	
	while (T != 0) {
		auto start = weights.begin();
		auto end = prev(weights.end());
		auto val1 = next(start)->first - start->first;
		auto val2 = end->first - prev(end)->first;
		
		num = min({val1, val2, T});
		if (start->second > 1 || end->second > 1) num = 1;
		if (start->first + num > end->first - num) num--;
		T -= num;
		
		if (weights.find(start->first + num) == weights.end()) weights[start->first + num] = 0;
		weights[start->first + num]++;
		if (weights.find(end->first - num) == weights.end()) weights[end->first - num] = 0;
		weights[end->first - num]++;
		if (start->second == 1) weights.erase(start);
		else start->second--;
		if (end->second == 1) weights.erase(end);
		else end->second--;
		
		//cout << prev(weights.end())->first << " " << weights.begin()->first << endl;
		if (weights.size() <= 2 && prev(weights.end())->first - weights.begin()->first <= 1) break;
		/*cout << num << endl;
		for (auto i : weights) {
			cout << i.first << " " << i.second << ",  ";
		}
		cout << endl;*/
	}
	
	cout << prev(weights.end())->first - weights.begin()->first << "\n";
	
	return 0;
}