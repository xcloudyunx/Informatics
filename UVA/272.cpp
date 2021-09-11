#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  bool start = true;
  while (getline(cin, s)) {
    string t;
    for (auto i : s) {
      if (i == '"') {
        if (start) {
          t.push_back('`');
          t.push_back('`');
          start = false;
        } else {
          t.push_back('\'');
          t.push_back('\'');
          start = true;
        }
      } else {
        t.push_back(i);
      }
    }
    cout << t << endl;
  }
}