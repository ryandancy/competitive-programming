#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[1000000]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin>>N;
  string s;
  for (int i=0;i<N;i++) {
    cin>>s;
    for (char&ch:s) {
      b[i]^=(1ll<<(ch-'a'));
    }
  }
  sort(b,b+N);
  ll res=0;
  for (ll i=0;i<N;) {
    ll j=i;
    while (j<N&&b[j]==b[i])j++;
    ll c=j-i;
    res+=c*(c-1);
    for (ll k=0;k<26;k++) {
      ll o=b[i]^(1ll<<k);
      ll no=upper_bound(b,b+N,o)-lower_bound(b,b+N,o);
      res+=no*c;
    }
    i=j;
  }
  cout<<res/2<<'\n';
}
