#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    ll a,b,n,m;
    cin>>a>>b>>n>>m;
    if (a+b<n+m) {cout<<"No\n";continue;}
    cout<<(m<=min(a,b)?"Yes\n":"No\n");
  }
}
