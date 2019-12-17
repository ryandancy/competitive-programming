// 590A - Median Smoothing
// The sequence always converges, and the only scenarios in which
// things are flipped are 010 and 101. We find "runs" of these
// (the only scenario in which it doesn't converge in 1 step)
// and calculate the deepest run, then fill in the runs. O(n).
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int a[500000];
vector<pii> rs;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int br = 0;
  int rl = 1, rr = 1;
  for (int i = 1; i < n-1; i++) {
    if (a[i] != a[i-1] && a[i-1] == a[i+1]) {
      rr++;
    } else {
      if (rr==rl) {rr=rl=i+1;continue;}
      if (rr-rl>br) br=rr-rl;
      rs.push_back({rl,rr-1});
      rr = rl = i+1;
    }
  }
  if (rr!=rl) {
    if (rr-rl>br) br=rr-rl;
    rs.push_back({rl,rr-1});
  }
  cout << (br+1)/2 << "\n";
  int cr = 0;
  for (int i = 0; i < n; i++) {
    if (cr>=rs.size()||i<rs[cr].first) {
      cout << a[i];
    } else if (i>=rs[cr].first&&i<=rs[cr].second) {
      cout << (i<=(rs[cr].first+rs[cr].second)/2 ? a[rs[cr].first-1]:a[rs[cr].second+1]);
    } else {
      cr++;
      cout << a[i];
    }
    if (i<n-1) cout << " ";
  }
  cout << "\n";
}
