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
int a[200000], lc[100001];
vector<int> cs[100001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  int n, mc, k;
  cin>>n>>mc>>k;
  fill_n(lc,mc+1,-1);
  for (int i=0;i<n;i++)cin>>a[i];
  for (int i=0;i<n;i++){
    int c=a[i];
    if (lc[c]!=-1) {
      cs[c].push_back(i-lc[c]-1);
    }
    lc[c]=i;
  }
  int res=1;
  for (int c=1;c<=mc;c++){
    int cr=1;
    list<int> cj; int ck=0;
    for (int j:cs[c]){
      while (cj.size()>0&&j+ck>k){
        ck-=cj.front();
        cj.pop_front();
      }
      if (cj.size()==0&&j+ck>k){
        continue;
      }
      cj.push_back(j);
      ck+=j;
      cr=max(cr,(int)cj.size()+1);
    }
    res=max(res,cr);
  }
  cout<<res<<'\n';
}
