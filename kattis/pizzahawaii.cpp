// pizzahawaii - Pizza Hawaii
// We store each set of pizzas as a bitset and just naively iterate
// It could be faster but whatever
// O(ab) where a and b are foreign and domestic ingredients respectively
#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
unordered_map<string, ll> a, b;
vector<pair<string, string> > res;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  string s;
  for (int Tc = 0; Tc < T; Tc++) {
    int n, m;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
      cin >> s >> m;
      for (int j = 0; j < m; j++) {
        cin >> s;
        a[s] |= (1<<i);
      }
      cin >> m;
      for (int j = 0; j < m; j++) {
        cin >> s;
        b[s] |= (1<<i);
      }
    }
    
    for (auto ai = a.begin(); ai != a.end(); ++ai) {
      for (auto bi = b.begin(); bi != b.end(); ++bi) {
        if (ai->second == bi->second) {
          res.push_back({ai->first, bi->first});
        }
      }
    }
    
    sort(res.begin(), res.end());
    
    for (pair<string, string>& p : res) {
      cout << "(" << p.first << ", " << p.second << ")\n";
    }
    
    if (Tc < T-1) {
      cout << "\n";
      res.clear();
      a.clear();
      b.clear();
    }
  }
}
