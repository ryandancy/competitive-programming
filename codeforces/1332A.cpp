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
  while (t--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x,y,x1,y1,x2,y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    if ((a!=0||b!=0)&&(x1==x2)){cout<<"NO\n";continue;}
    if ((c!=0||d!=0)&&(y1==y2)){cout<<"NO\n";continue;}
    int tx=b-a,ty=d-c;
    int nx=x+tx,ny=y+ty;
    if (nx<x1||nx>x2||ny<y1||ny>y2){cout<<"NO\n";continue;}
    cout<<"YES\n";
  }
}
