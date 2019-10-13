// 975D - Ghosts
// All ghosts obey the equations x = v_x*t + x_0 and y = v_y*t + y_0.
// Thus, two ghosts will collide if for some t, v_x1 * t + x_01 = v_x2 * t + x_02
// and v_y1 * t + y_01 = y_x2 * t + y_02.
// If we solve for t and substitute, we have (v_y2 - v_y1)(x_02 - x_01) = (v_x2 - v_x1)(y_02 - y_01).
// Now, y = ax + b, so we get (v_y2 - v_y1)(x_02 - x_01) = (v_x2 - v_x1)(ax_02 - ax_01).
// Thus v_y2 - v_y1 = av_x2 - av_x1, and so v_y2 - av_x2 = v_y1 - av_x1.
// We compute v_y - av_x for each ghost, store it in an array, sort the array, and see how many pairs
// are equal. Now, the equation also holds if the ghosts have parallel velocities, so we then store
// the velocities in an array, sort it, and subtract the number of velocity pairs that are equal.
// Overall time complexity: O(n log n).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
pll gs[200000];
ll rs[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n, a, b;
  cin >> n >> a >> b;
  int vx, vy;
  for (int i = 0; i < n; i++) {
    cin >> b >> vx >> vy;
    rs[i] = vy - a*vx;
    gs[i].first = vx;
    gs[i].second = vy;
  }
  sort(rs, rs+n);
  sort(gs, gs+n);
  ll rg = 0;
  ll rl = 1;
  ll l = rs[0];
  for (int i = 1; i < n; i++) {
    if (rs[i] == l) {
      rl++;
    } else {
      rg += rl*(rl-1LL)/2LL;
      l = rs[i];
      rl = 1;
    }
  }
  rg += rl*(rl-1LL)/2LL;
  pll& ol = gs[0];
  rl = 1;
  for (int i = 1; i < n; i++) {
    if (gs[i] == ol) {
      rl++;
    } else {
      rg -= rl*(rl-1LL)/2LL;
      ol = gs[i];
      rl = 1;
    }
  }
  rg -= rl*(rl-1LL)/2LL;
  cout << rg*2 << "\n";
}
