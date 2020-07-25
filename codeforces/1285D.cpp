// Recursive O(n log A) where A = max(a)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100000];
ll lv(ll b, int l, int r) {
  if (b<0)return 0;
  ll m=(1ll<<b);
  int k=l;
  while ((a[k]&m)==0&&k<r)k++;
  if (k==l||k==r){
    return lv(b-1,l,r);
  } else {
    return m|min(lv(b-1,l,k),lv(b-1,k,r));
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  for (int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  cout<<lv(30,0,n)<<'\n';
}
