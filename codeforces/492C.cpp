// 492C - Vanya and Exams
// Very simple - the required number of points is n*avg, so sort by the minimum number of essays required
// and write as many essays as needed to raise the total points to n*avg. O(n) time complexity.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int, int> exs[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n, r, av;
  cin >> n >> r >> av;
  ll req = n*av, a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    req -= a;
    exs[i].second = a;
    exs[i].first = b;
  }
  if (req <= 0) {
    cout << "0\n";
    return 0;
  }
  sort(exs, exs+n);
  ll i = 0, ans = 0;
  while (req > 0) {
    if (exs[i].second < r) {
      ll pts = min(req, r - exs[i].second);
      req -= pts;
      ans += exs[i].first*pts;
    }
    i++;
  }
  cout << ans << "\n";
}
