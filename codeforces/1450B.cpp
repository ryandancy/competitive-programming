#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int x[100], y[100];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin>>t;
  while (t--) {
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)cin>>x[i]>>y[i];
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        if (abs(x[i]-x[j])+abs(y[i]-y[j])>k) goto nxt;
      }
      cout<<"1\n";
      goto end;
      nxt:;
    }
    cout<<"-1\n";
    end:;
  }
}
