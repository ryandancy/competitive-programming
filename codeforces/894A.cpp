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
  string s;
  cin>>s;
  int res=0;
  for (int a=0;a<s.size();a++) {
    if (s[a]!='Q')continue;
    for (int b=a+1;b<s.size();b++) {
      if (s[b]!='A')continue;
      for (int c=b+1;c<s.size();c++) {
        if (s[c]!='Q')continue;
        res++;
      }
    }
  }
  cout<<res<<'\n';
  // int qa=0;
  // int res=0;
  // bool lq=false;
  // for (char c:s) {
  //   if (c=='Q') lq=true,res+=qa;
  //   else if (c=='A') {
  //     if (lq) lq=false,qa++;
  //   }
  // }
  // cout<<res<<"\n";
  // int st=-1;
  // int res=0;
  // for (char c:s) {
  //   switch (st) {
  //   case -1:
  //     st=c=='Q'?0:-1;
  //     break;
  //   case 0:
  //     st=c=='A'?1:c=='Q'?0:-1;
  //     break;
  //   case 1:
  //     if (c=='Q'){res++;st=0;}
  //     else st=-1;
  //   }
  // }
  // cout<<res<<'\n';
}
