#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    ll n,r;
    cin>>n>>r;
    if (r<n){
      cout<<r*(r+1)/2<<'\n';
      continue;
    }
    cout<<n*(n-1)/2+1<<'\n';
  }
}
