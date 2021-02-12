#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
string s[8];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  for (int i=0;i<8;i++)cin>>s[i];
  int nq=0;
  for (int i=0;i<8;i++) {
    for (int j=0;j<8;j++) {
      if (s[i][j]!='*') continue;
      nq++;
      for (int x=0;x<8;x++) {
        if (x!=i&&s[x][j]=='*') return cout<<"invalid\n",0;
        if (x!=j&&s[i][x]=='*') return cout<<"invalid\n",0;
      }
      for (int x=-8;x<=8;x++) {
        if (x!=0&&i+x>=0&&j+x>=0&&i+x<8&&j+x<8&&s[i+x][j+x]=='*')return cout<<"invalid\n",0;
        if (x!=0&&i-x>=0&&j+x>=0&&i-x<8&&j+x<8&&s[i-x][j+x]=='*')return cout<<"invalid\n",0;
      }
    }
  }
  // cout<<"valid\n";
  if (nq==8)cout<<"valid\n";
  else cout<<"invalid\n";
}
