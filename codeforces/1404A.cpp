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
  int t;
  cin>>t;
  while (t--) {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int c[2]={0},nq=0;
    for (int i=0;i<n-k;i++) {
      if (s[i]=='?') continue;
      if (s[i+k]!='?'&&s[i]!=s[i+k]) {
        cout<<"NO\n"; goto nxt;
      }
      s[i+k]=s[i];
    }
    for (int i=n-1;i>=k;i--) {
      if (s[i]=='?') continue;
      if (s[i-k]!='?'&&s[i]!=s[i-k]) {
        cout<<"NO\n"; goto nxt;
      }
      s[i-k]=s[i];
    }
    for (int i=0;i<k;i++) {
      if (s[i]!='?')c[s[i]-'0']++;
      else nq++;
    }
    if (abs(c[1]-c[0])<=nq) cout<<"YES\n";
    else cout<<"NO\n";
    nxt:;
  }
}
