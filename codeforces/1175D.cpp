// 1175D - Array Splitting
// just the first suffix sums + the k-1 largest other ones,
// by mathemagic. O(n log n).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300000];
ll ss[300000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, k;
  cin>>n>>k;
  for (int i=0;i<n;i++)cin>>a[i];
  ll s=0;
  for (int i=n-1;i>=0;i--){
    s+=a[i];
    ss[i]=s;
  }
  ll r=ss[0];
  sort(ss+1,ss+n);
  for (int i=0;i<k-1;i++){
    r+=ss[n-1-i];
  }
  cout<<r<<'\n';
}
