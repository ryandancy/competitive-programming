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
bool par(string&s) {
  bool p=false;
  for (int i=0;i<s.size();i++) {
    int j=i;
    while (j>0&&s[j]<s[j-1]) {
      swap(s[j],s[j-1]);
      p=!p;
      j--;
    }
  }
  return p;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll q;
  cin>>q;
  while (q--) {
    ll n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int chs[26]={0},cht[26]={0};
    for (int i=0;i<n;i++) {
      chs[s[i]-'a']++;
      cht[t[i]-'a']++;
    }
    for (int i=0;i<26;i++) {
      if (chs[i]!=cht[i]) {
        cout<<"NO\n";
        goto nxt;
      }
    }
    for (int i=0;i<26;i++) {
      if (chs[i]>1||cht[i]>1) {
        cout<<"YES\n";
        goto nxt;
      }
    }
    if (par(s)==par(t)) cout<<"YES\n";
    else cout<<"NO\n";
    nxt:;
  }
}
