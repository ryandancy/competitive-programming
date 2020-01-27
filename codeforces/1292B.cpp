// 1292B - Aroma's Search
// The sequence can be described parametrically as x(n) = x_0*a_x^n + b_x*((a_x^n-1)/(a_x-1)),
// y(n) = y_0*a_y^n + b_y*((a_y^n-1)/(a_y-1)). The sequence grows exponentially in both x and y,
// so it reaches a value K in x or y in O(log K) iterations. This means it reaches the upper bound
// on the location that can be reached (2*10^16) in ~55 operations, so the sequence will never have
// more than ~55 useful terms in it.
// Another consequence of the exponential growth is that it is always optimal, once on one term in the
// sequence, to move to any adjacent term rather than to a non-adjacent term, unless adjacent terms
// have already been visited.
// Therefore, we simply generate all ~55 potentially-useful terms and try going backwards and forwards
// from each term. Mostly constant-time.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll> pll;
#define abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll x0, y0, ax, ay, bx, by, xs, ys, t;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
  vector<pll> nds;
  int ir=0;
  if (abs(xs,x0)+abs(ys,y0)<=t)ir++;
  while (1) {
    nds.push_back({x0,y0});
    x0 = x0*ax+bx;
    y0 = y0*ay+by;
    if (abs(xs,x0)+abs(ys,y0)<=t)ir++;
    if (x0>=(1ll<<57) || y0>=(1ll<<57)) break;
  }
  if (ir==0) return cout << "0\n", 0;
  ll mn=0;
  for (int i = 0; i < nds.size(); i++) {
    long long ct=t-(abs(xs,nds[i].first)+abs(ys,nds[i].second)), cn=1;
    for (int j = i+1; j < nds.size() && ct>0; j++) {
      ct-=abs(nds[j-1].first,nds[j].first)+abs(nds[j-1].second,nds[j].second);
      if (ct>=0)cn++;
    }
    for (int j = i-1,lst=nds.size()-1; j >= 0 && ct>0; j--) {
      ct-=abs(nds[j].first,nds[lst].first)+abs(nds[j].second,nds[lst].second);
      lst=j;
      if (ct>=0)cn++;
    }
    if (cn>mn)mn=cn;
    ct=t-(abs(xs,nds[i].first)+abs(ys,nds[i].second)), cn=1;
    for (int j = i-1; j >= 0 && ct>0; j--) {
      ct-=abs(nds[j].first,nds[j+1].first)+abs(nds[j].second,nds[j+1].second);
      if (ct>=0)cn++;
    }
    for (int j = i+1,lst=0; j < nds.size() && ct>0; j++) {
      ct-=abs(nds[lst].first,nds[j].first)+abs(nds[lst].second,nds[j].second);
      lst=j;
      if (ct>=0)cn++;
    }
    if (cn>mn)mn=cn;
  }
  cout << mn << '\n';
}
