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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  set<int> st;
  string s; cin>>s; s+=',';
  for (int i=0,a=0;i<s.size();i++) {
    if (s[i]==',') st.insert(a), a=0;
    else {
      a*=10;
      a+=s[i]-'0';
    }
  }
  int lst=*st.begin();
  int rs=lst;
  for (auto it=++st.begin();it!=st.end();++it) {
    if (*it!=lst+1) {
      if (rs==lst) cout<<lst;
      else cout<<rs<<'-'<<lst;
      cout<<',';
      rs=*it;
    }
    lst=*it;
  }
  if (rs==lst) cout<<lst;
  else cout<<rs<<'-'<<lst;
  cout<<'\n';
}
