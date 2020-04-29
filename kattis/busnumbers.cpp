#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  for (int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  for (int i=0;i<n;){
    cout<<a[i];
    int j=i;
    while (j<n-1&&a[j+1]==a[j]+1) j++;
    if (j-i>1) {
      cout<<'-'<<a[j];
      i=j+1;
      if (i<n)cout<<' ';
    } else {
      if (i<n)cout<<' ';
      i++;
    }
  }
  cout<<'\n';
}
