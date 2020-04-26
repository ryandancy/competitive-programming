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
int oc[1001]={0};
void bit_inc(int x, int n) {
  x++;
  while (x<=n) {
    oc[x]++;
    x+=x&-x;
  }
}
int bit_sum(int x) {
  x++;
  int res=0;
  while (x > 0) {
    res+=oc[x];
    x-=x&-x;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m, q;
  cin>>n>>m>>q;
  string s, t;
  cin>>s>>t;
  for (int i=0;i<=n-m;i++){
    for (int j=0;j<m;j++){
      if (s[i+j]!=t[j]) {
        goto nxt;
      }
    }
    bit_inc(i,n);
    nxt:;
  }
  while (q--) {
    int l, r;
    cin>>l>>r;
    l--,r--;
    if (r-l+1<m) cout<<"0\n";
    else cout<<bit_sum(r-m+1)-bit_sum(l-1)<<'\n';
  }
}
