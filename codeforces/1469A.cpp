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
  int T;
  cin>>T;
  while (T--) {
    string s;
    cin>>s;
    int a[3]={0}, v[2]={0};
    for (int i=0,j=0;i<s.size();i++) {
      if (s[i]=='?') a[j]++;
      else if (s[i]=='(') v[j++]=0;
      else v[j++]=1;
    }
    bool k;
    if (v[0]==0) k=(a[0]+a[1]+a[2])%2==0;
    else k=(a[0]+a[1]+a[2])%2==0&&a[0]&&a[2];
    cout<<(k?"YES\n":"NO\n");
  }
}
