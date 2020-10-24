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
int a[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  int mx=0;
  for (int i=0;i<n;i++)cin>>a[i],mx=max(mx,a[i]);
  int bs=0;
  for (int i=0;i<n;i++) {
    while (i<n&&a[i]!=mx)i++;
    int l=i;
    while (i<n&&a[i]==mx)i++;
    int r=i;
    int sz=r-l;
    if (sz>bs){
      bs=sz;
    }
  }
  cout<<bs<<'\n';
}
