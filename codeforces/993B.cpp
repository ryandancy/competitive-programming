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
vector<int> adja[10], adjb[10];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n,m;
  cin>>n>>m;
  for (int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    adja[x].push_back(y);
    adja[y].push_back(x);
  }
  for (int i=0;i<m;i++) {
    int x,y;
    cin>>x>>y;
    adjb[x].push_back(y);
    adjb[y].push_back(x);
  }
  for (int i=1;i<10;i++) {
    for (int x : adja[i]) {
      int c=count(adjb[i].begin(),adjb[i].end(),x);
      if (adjb[i].size()-c && adjb[x].size()-c) {
        cout << "-1\n";
        return 0;
      }
    }
  }
  for (int i=1;i<10;i++) {
    for (int x : adjb[i]) {
      int c=count(adja[i].begin(),adja[i].end(),x);
      if (adja[i].size()-c && adja[x].size()-c) {
        cout << "-1\n";
        return 0;
      }
    }
  }
  int s=-2;
  bool f=false;
  for (int i=1;i<10;i++) {
    for (int x : adja[i]) {
      for (int y : adjb[i]) {
        if (x==y) continue;
        if (!f) s=i,f=true;
        else if (i!=s) s=0;
      }
    }
  }
  cout << s << '\n';
}
