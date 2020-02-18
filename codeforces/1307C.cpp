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
ll ps[100000][26]={{0}};
ll p[26][26]={{0}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  string s;
  cin>>s;
  for (int i=0;i<s.size();i++) {
    int a=s[i]-'a';
    for (int j=0;j<26;j++) {
      if (i>0)ps[i][j]=ps[i-1][j];
      if (j==a)ps[i][j]++;
    }
  }
  ll bc=1;
  for (int i=0;i<26;i++){
    bc=max(max(bc,ps[s.size()-1][i]),ps[s.size()-1][i]*(ps[s.size()-1][i]-1)/2);
  }
  for (int i=0;i<s.size();i++) {
    int a=s[i]-'a';
    for (int j=0;j<26;j++){
      if (j==a)continue;
      p[a][j]+=ps[i][j];
    }
  }
  for (int i=0;i<26;i++) for (int j=0;j<26;j++) {
    bc=max(bc,p[i][j]);
  }
  cout<<bc<<'\n';
}
