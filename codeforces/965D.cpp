// I'm actually super not sure of the time complexity and I'm kinda surprised
// that it doesn't time out - maybe O(w sqrt l).
// This sends as many frogs through as possible greedily jumping as far as possible.
// A better solution (or at least one with a more definite time complexity) is to
// binary search on the number of frogs somehow.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100000],f[100000]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll w,l;
  cin>>w>>l;
  for (int i=0;i<w-1;i++)cin>>a[i];
  for (int i=0;i<l;i++)f[i]=a[i];
  stack<int> nz;
  for (int i=0;i<w-l-1;i++) {
    if (f[i+l]<a[i+l])nz.push(i+l);
    ll q=f[i];
    while(q&&nz.size()){
      int j=nz.top();
      int d=min(a[j]-f[j],q);
      f[j]+=d, q-=d;
      if (f[j]==a[j])nz.pop();
    }
  }
  ll res=0;
  for (int i=w-l-1;i<w-1;i++){
    res+=f[i];
  }
  cout<<res<<'\n';
}
