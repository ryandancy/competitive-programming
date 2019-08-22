// 1207D - Number Of Permutations
// Using inclusion-exclusion, the number of good permutations is the number of total permutations (n!),
// minus the number of permutations in which the first elements are sorted, minus the number of permutations
// in which the second elements are sorted, plus the number of permutations in which both are sorted.
// The number of permutations in which elements are sorted equals n! minus the product of the factorials
// of the sizes of groups of equal elements. Reducing, if product(k_1!) is the product of the factorials
// of the sizes of groups of equal first elements, product(k_2!) is analogous for the second elements,
// and product(k_t!) is the same for the elements overall, the answer is n! - product(k_1!) - product(k-2!)
// + product(k_t!). We achieve this by sorting twice for an O(n log n) solution.
// Written during Codeforces Educational Round #71
#include <bits/stdc++.h>
#define MOD 998244353LL
using namespace std;
typedef long long ll;
ll fac[300001];
pair<int, int> s[300000];
bool cmp2(pair<int, int>& a, pair<int, int>& b) {
  return a.second<b.second;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n;
  cin >> n;
  fac[1] = 1;
  for (ll i=2;i<=n;i++) {
    fac[i]=fac[i-1]*i;
    fac[i]%=MOD;
  }
  for (int i=0;i<n;i++) cin>>s[i].first>>s[i].second;
  sort(s, s+n);
  ll r1=1, cr=0;
  for (int i=0;i<n;i++) {
    cr++;
    if (i==n-1||s[i].first!=s[i+1].first) {
      r1*=fac[cr];
      r1%=MOD;
      cr=0;
    }
  }
  ll rt=1; cr=0;
  for (int i=0;i<n;i++) {
    cr++;
    if (i<n-1&&(s[i].first>s[i+1].first||s[i].second>s[i+1].second)) {
      rt=0;
      break;
    }
    if (i==n-1||s[i]!=s[i+1]) {
      rt*=fac[cr];
      rt%=MOD;
      cr=0;
    }
  }
  sort(s, s+n,cmp2 );
  ll r2=1;
  cr=0;
  for (int i=0;i<n;i++) {
    cr++;
    if (i==n-1||s[i].second!=s[i+1].second) {
      r2*=fac[cr];
      r2%=MOD;
      cr=0;
    }
  }
  ll res = fac[n];
  res-=r1; res %= MOD; if (res<0) res += MOD;
  res-=r2; res %= MOD; if (res<0) res += MOD;
  res+= rt; res %=MOD;
  cout << res << '\n';
}
