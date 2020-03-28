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
  string s;
  while (t--) {
    int n;
    cin>>n;
    cin>>s;
    bool f1=false;
    for (int i=0;i<n;i++){
      if (f1){
        cout<<'0';
      } else {
        if (s[i]=='2')cout<<'1';
        else if (s[i]=='1')cout<<'1',f1=true;
        else cout<<'0';
      }
    }
    cout<<'\n';
    f1=false;
    for (int i=0;i<n;i++){
      if (f1) {
        cout<<s[i];
      } else {
        if (s[i]=='2')cout<<'1';
        else if (s[i]=='1')cout<<'0',f1=true;
        else cout<<'0';
      }
    }
    cout<<'\n';
  }
}
