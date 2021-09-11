#include <bits/stdc++.h>

using namespace std;

int next_power_of_two(int value) {
    return 1 << (32 - __builtin_clz(value-1));
}

// Max segment tree
struct SegmentTree {
    vector<int> nodes;   

    SegmentTree(int size) : nodes(next_power_of_two(next_power_of_two(size)+1), 0) {
		
	}

    // inclusive exclusive left and right
    int query(int node, int c_left, int c_right, const int left, const int right) {
        // Check whether node is out of range
        if (c_right <= left || right <= c_left) return 0;
        if (left <= c_left && c_right <= right) {
            // Node is completely within range
            return nodes[node];
        }

        int middle = (c_left + c_right) / 2;
        return min(query(node * 2 + 1, c_left, middle, left, right), query(node * 2 + 2, middle, c_right, left, right));
    }

    // Adds to an element
    void update(int node, int c_left, int c_right, const int target, const int delta) {
        // Check whether node is out of range
        // Note the difference in condition
        if (c_right <= target || target < c_left) return;
        if (c_left == target && target + 1 == c_right) {
            // Remember: inclusive, exclusive
            nodes[node] += delta;
            return;
        }

        int middle = (c_left + c_right) / 2;
        update(node * 2 + 1, c_left, middle, target, delta);
        update(node * 2 + 2, middle, c_right, target, delta);
        nodes[node] = min(nodes[node * 2 + 1], nodes[node * 2 + 2]);
    }
};

int main() {
	SegmentTree s(5);
	cout << s.nodes.size() << endl;
}