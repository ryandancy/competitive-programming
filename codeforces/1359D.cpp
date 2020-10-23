#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[100000],n;
int kad(int mx) {
  int bst=0,cur=0;
  for (int i=0;i<n;i++) {
    cur=max(0,cur+(a[i]>mx?-INF:a[i]));
    bst=max(bst,cur);
  }
  return bst;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  for (int i=0;i<n;i++)cin>>a[i];
  int bst=0;
  for (int x=0;x<=30;x++) {
    bst=max(bst,kad(x)-x);
  }
  cout<<bst<<'\n';
}
