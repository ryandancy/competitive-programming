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
int a[100];
bool u[101];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    int n, k;
    cin>>n>>k;
    fill_n(u,101,false);
    for (int i=0;i<n;i++)cin>>a[i], u[a[i]]=true;
    vector<int> d;
    for (int i=1;i<=n;i++) if(u[i])d.push_back(i);
    if (d.size()>k) {
      cout<<"-1\n";
      continue;
    }
    if (d.size()<k){
      for (int i=1;i<=n;i++){
        if (!u[i]) {
          d.push_back(i);
          if (d.size()==k) break;
        }
      }
    }
    int m=d.size()*n;
    cout<<m<<'\n';
    for (int i=0;i<n;i++){
      for (int j=0;j<d.size();j++){
        cout<<d[j];
        m--;
        if (m==0)cout<<'\n';
        else cout<<' ';
      }
    }
  }
}
