// 1236B - Alice and the List of Presents
// Written during Codeforces Round #593
#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll pow2(ll a, ll e) {
  if (e == 0) return 1;
  if (e == 1) return a;
  ll r = pow2(a, e/2) % MOD;
  r *= r;
  r %= MOD;
  if (e % 2) r *= a, r %= MOD;
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n, m;
  cin >> n >> m;
  ll x = pow2(2, m) - 1;
  cout << pow2(x, n) << "\n";
}
