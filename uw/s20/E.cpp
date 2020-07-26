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
int cn[100];
int c[100], r[100];
vector<int> ccn[100];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  int k, m;
  while (cin>>k, k) {
    for(int i=0;i<100;i++)ccn[i].clear();
    cin>>m;
    for (int i=0;i<k;i++)cin>>cn[i];
    for (int i=0;i<m;i++){
      cin>>c[i]>>r[i];
      for (int j=0;j<c[i];j++) {
        int x;
        cin>>x;
        ccn[i].push_back(x);
      }
      sort(ccn[i].begin(),ccn[i].end());
    }
    for (int i=0;i<k;i++){
      for (int j=0;j<m;j++){
        if (r[j]==0)continue;
        if (binary_search(ccn[j].begin(),ccn[j].end(),cn[i])) {
          r[j]--;
        }
      }
    }
    bool ok=true;
    for (int i=0;i<m;i++){
      if (r[i]){ok=false;break;}
    }
    cout<<(ok?"yes\n":"no\n");
  }
}
