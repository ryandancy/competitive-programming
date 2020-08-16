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
  int T;
  cin>>T;
  while (T--) {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int fl=0;
    while (fl<n&&!(s[fl]=='L'&&s[(fl-1+n)%n]=='R'))fl++;
    int res=0;
    if (fl==n){
      s[0]=(s[0]=='L'?'R':'L');
      fl=0;
      res++;
    }
    // debug("fl",fl);
    for (int i=0;i<n;){
      int j=(fl+i)%n;
      int oj=j;
      int sl=0;
      while (i<n&&s[j]==s[oj]) i++,j++,j%=n,sl++;
      if (sl<=2)continue;
      res+=(sl-2)/3+((sl-2)%3!=0);
    }
    cout<<res<<'\n';
  }
}
