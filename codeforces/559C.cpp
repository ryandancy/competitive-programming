// 599C - Gerald and Giant Chess
// Ways from (1, 1) to (x, y) is binomial(x+y-2, x-1) = (x+y-2)!/((x-1)!(y-1)!)
// We precompute all modular factorials and inverses from 1 to h+w to speed this up
// This is O((h+w)log(h+w)) with O(log n) exponentiation
// Then we use dp expanding outwards from (1, 1)

#include <iostream>
#include <algorithm>
#include <utility>
#define MOD 1000000007

using namespace std;

typedef long long ll;

pair<ll, ll> bcells[2001];
ll facs[200001], invs[200001], dp[2001];

ll power(ll x, ll pow) {
  if (x == 1) return 1;
  if (pow == 1) return x;
  if (pow == 2) return (x*x)%MOD;
  ll y = power(x, pow/2)%MOD;
  y = (y*y)%MOD;
  if (pow % 2 == 1) y = (y*x)%MOD;
  return y;
}

ll waysto(ll x, ll y) { // computes binomial(x+y-2, x-1) % MOD
  ll numer = facs[x+y-2];
  ll xden = invs[x-1];
  ll yden = invs[y-1];
  ll den = (xden*yden)%MOD;
  return (numer*den)%MOD;
}

bool lt(pair<ll, ll>& a, pair<ll, ll>& b) {
  return a.first + a.second < b.first + b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  ll h, w;
  cin >> h >> w >> n;
  
  ll fact = 1;
  facs[0] = facs[1] = 1;
  invs[0] = invs[1] = 1;
  for (ll i = 2; i <= h+w; i++) {
    fact *= i;
    fact %= MOD;
    facs[i] = fact;
    invs[i] = power(fact, MOD-2);
  }
  
  for (int i = 0; i < n; i++) {
    cin >> bcells[i].first >> bcells[i].second;
  }
  bcells[n].first = h; bcells[n].second = w;
  
  sort(bcells, bcells+n+1, lt); // process inner before outer
  
  for (int i = 0; i <= n; i++) {
    dp[i] = waysto(bcells[i].first, bcells[i].second);
    for (int j = 0; j < i; j++) {
      if (bcells[j].first <= bcells[i].first && bcells[j].second <= bcells[i].second) {
        dp[i] -= (dp[j] * waysto(bcells[i].first - bcells[j].first + 1,
          bcells[i].second - bcells[j].second + 1)) % MOD;
        if (dp[i] < 0) dp[i] += MOD;
      }
    }
  }
  
  cout << dp[n] << endl;
}
