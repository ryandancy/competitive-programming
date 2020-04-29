#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
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
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  string t, e;
  cin>>t>>e;
  int ht=(t[0]-'0')*10+(t[1]-'0');
  int he=(e[0]-'0')*10+(e[1]-'0');
  int mt=(t[3]-'0')*10+(t[4]-'0');
  int me=(e[3]-'0')*10+(e[4]-'0');
  int st=(t[6]-'0')*10+(t[7]-'0');
  int se=(e[6]-'0')*10+(e[7]-'0');
  int tst=st+mt*60+ht*3600;
  int tse=se+me*60+he*3600;
  int ds=(tse-tst+86400)%86400;
  if (ds==0)ds=86400;
  int hr=ds/3600;
  ds%=3600;
  int mr=ds/60;
  ds%=60;
  int sr=ds;
  printf("%.2d:%.2d:%.2d\n", hr, mr, sr);
}
