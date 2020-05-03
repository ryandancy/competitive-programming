#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <algorithm>
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
  for (int sc=1;sc<=T;sc++) {
    cout<<"Scenario #"<<sc<<":\n";
    int u;
    cin>>u;
    int d=2*u+1;
    for (int s=1;s<=2*u+1;s++){
      cout<<"slice #"<<s<<":\n";
      int r=abs(s-(u+1));
      for (int y=0;y<d;y++){
        for (int x=0;x<d;x++){
          int ds=abs(x-u)+abs(y-u)+r;
          if (ds>u)cout<<'.';
          else cout<<ds;
        }
        cout<<'\n';
      }
    }
    cout<<"\n";
  }
}
