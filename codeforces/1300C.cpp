// 1300C - Anu Has a Function
// (x|y)-y = x&~y, so the order of every element but the first is irrelevant.
// Sum the bits in each position, find which element results in the highest when
// all duplicate bits are removed. O(n).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100000];
int bc[32];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int b=0; b<32; b++) {
      if ((a[i]&(1<<b))!=0) bc[b]++;
    }
  }
  ll b=-1,bi=-1;
  for (int i=0;i<n;i++) {
    ll r=0;
    for (int b=0;b<32;b++) {
      if (bc[b]==1&&(a[i]&(1<<b))!=0) r |= 1<<b;
    }
    if (r>b) {
      b=r; bi=i;
    }
  }
  cout << a[bi] << ' ';
  for (int i=0;i<n;i++) if(i!=bi)cout<<a[i]<<' ';
  cout<<'\n';
}
