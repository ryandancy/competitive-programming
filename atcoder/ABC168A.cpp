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
  int n;
  cin>>n;
  switch(n%10) {
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
    cout<<"hon\n";
    break;
    case 0:
    case 1:
    case 6:
    case 8:
    cout<<"pon\n";
    break;
    case 3:
    cout<<"bon\n";
  }
  return 0;
}
