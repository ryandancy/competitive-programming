#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll a[200000], bit[200001], n, m, dp[200000];
void add(ll p, ll v) {
  for (p++; p<n; p += p&-p) bit[p] += v;
}
ll query(ll p) {
  ll r = 0;
  for (p++; p; p -= p&-p) r += bit[p];
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin >> n >> m;
  for (ll i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  for (ll i = 0; i < n; i += 2) bit[i+1] = a[i];
  for (ll k = 2; k <= n; k *= 2) {
    for (ll i = k; i <= n; i += 2*k) {
      bit[i] = query(i-2) + a[i-1];
    }
  }
  // for (int i = 0; i < n; i++) cout << bit[i] << "\n";
  for (ll i = 0; i < m; i++) {
    dp[i] = query(i);
  }
  for (ll i = m; i < n; i++) {
    dp[i] = dp[i-m] + query(i);
  }
  for (ll i = 0; i < n; i++) {
    cout << dp[i];
    if (i<n-1) cout << " ";
    else cout << "\n";
  }
}
