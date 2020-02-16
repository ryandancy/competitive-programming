// 523D - Statistics of Recompressing Videos
// Simple priority queue implementation
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct v {
  ll tr, d;
  ll s=-1,f=-1;
  bool operator<(const v& x) const {
    return f > x.f; // sort opposite
  }
};
vector<v> dn;
priority_queue<v> p;
queue<v> q;
int ns=0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n, k;
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    v c;
    cin >> c.tr >> c.d;
    q.push(c);
  }
  ll t=0;
  while (!q.empty()||!p.empty()) {
    if (p.empty() || (!q.empty() && p.top().f > q.front().tr && ns < k)) {
      v a = q.front();
      q.pop();
      t=max(t,a.tr);
      a.s=t;
      a.f=a.s+a.d;
      p.push(a);
      ns++;
    } else {
      v a = p.top();
      p.pop();
      t=a.f;
      dn.push_back(a);
      ns--;
    }
  }
  sort(dn.begin(), dn.end(), [&](v& a, v& b) {return a.tr < b.tr;});
  for (v& a : dn) {
    cout << a.f << '\n';
  }
}
