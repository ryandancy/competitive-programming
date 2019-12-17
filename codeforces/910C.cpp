// 910C - Minimum Sum
// We keep track of the contribution to setting each digit to 1, then
// sort by this contribution and assign digits accordingly (with special-case
// handling for making sure there are no zero digits in front). O(n).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nc[10] = {0};
bool nz[10] = {false};
ll a[10]={0,1,2,3,4,5,6,7,8,9};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  string s;
  for (ll i = 0; i < n; i++) {
    cin >> s;
    for (ll j = s.size()-1, f = 1; j >= 0; j--, f *= 10) {
      nc[s[j]-'a'] += f;
    }
    nz[s[0]-'a']=true;
  }
  sort(a,a+10,[](ll a, ll b){return nc[a]>nc[b];});
  ll z=0;
  while (nz[a[z]]) z++;
  ll sm = 0;
  for (ll m = 1, i = 0; m < 10; i++, m++) {
    if (i == z) {m--;continue;}
    sm += nc[a[i]]*m;
  }
  cout << sm << "\n";
}
