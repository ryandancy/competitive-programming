// 1036D - Vasya and Arrays
// Count the number of equal prefix sums. That's equal to the
// number of segments that can be combined to give the same array.
// O(n log n).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300000], b[300000];
ll pa[300000], pb[300000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  ll as=0;
  for (int i=0;i<n;i++)cin>>a[i],as+=a[i];
  int m;
  cin>>m;
  ll bs=0;
  for (int i=0;i<m;i++)cin>>b[i],bs+=b[i];
  if (as!=bs)return cout<<"-1\n",0;
  pa[0]=a[0], pb[0]=b[0];
  for (int i=1;i<n;i++)pa[i]=pa[i-1]+a[i];
  for (int i=1;i<m;i++)pb[i]=pb[i-1]+b[i];
  int c=0;
  for (int i=0;i<n;i++){
    if (binary_search(pb,pb+m,pa[i]))c++;
  }
  cout<<c<<'\n';
}
