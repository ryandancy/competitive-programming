// 2A - Winner
// We use a map of names to lists of pairs of (score, index received).
// We retrieved the maximum score, compile a vector of names with that end score,
// and iterate through the vector, removing elements until we find the name with
// score greater than or equal to the maximum and the minimum index.
// Worst case time complexity, I think, is O(n^2).

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, list<pair<int, int> > > m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  
  // Read into the overly templated data structure - O(n)
  string s;
  int c;
  for (int i = 0; i < n; i++) {
    cin >> s >> c;
    if (m.count(s)) m[s].push_back({m[s].back().first+c, i});
    else m[s].push_back({c, i});
  }
  
  // Find the ones with the maximum - O(n)
  int mx = 0;
  vector<string> hasmx;
  for (pair<string, list<pair<int, int> > > p : m) {
    if (p.second.back().first > mx) {
      mx = p.second.back().first;
      hasmx.clear();
      hasmx.push_back(p.first);
    } else if (p.second.back().first == mx) {
      hasmx.push_back(p.first);
    }
  }
  
  // Find the lowest index with score >= maximum - O(n^2) worst case
  for (int lowest = 0; lowest < n; lowest++) {
    for (string a : hasmx) {
      if (m[a].size() == 0) continue;
      if (m[a].front().second == lowest) {
        if (m[a].front().first >= mx) {
          cout << a << "\n";
          return 0;
        }
        m[a].pop_front();
        break;
      }
    }
  }
  
  // This was guaranteed not to happen
  cout << "????\n";
}
