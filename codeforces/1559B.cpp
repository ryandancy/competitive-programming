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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin>>t;
  while (t--) {
    int n; string s;
    cin>>n>>s;
    int l=0,r=0;
    while (l<n&&s[l]!='?') l++,r++;
    while (r<n) {
      while (r<n&&s[r]=='?') {
        r++;
      }
      char cl=l==0?'\0':s[l-1];
      char cr=r==n?'\0':s[r];
      char st;
      int len=r-l;
      if (cl=='R') st='B';
      else if (cl=='B') st='R';
      else if (cr=='R'&&len%2==0) st='R';
      else if (cr=='R'&&len%2==1) st='B';
      else if (cr=='B'&&len%2==0) st='B';
      else st='R';
      for (int i=l;i<r;i++) {
        s[i]=st;
        if (st=='R') st='B';
        else st='R';
      }
      while (r<n&&s[r]!='?') r++;
      l=r;
    }
    cout<<s<<'\n';
  }
}
