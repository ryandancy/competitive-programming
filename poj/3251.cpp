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
string mp[100];
int jx[10000], jy[10000], js=0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int N;
  cin>>N;
  for (int i=0;i<N;i++)cin>>mp[i];
  for (int y=0;y<N;y++){
    for (int x=0;x<N;x++) {
      if (mp[y][x]=='J') {
        jx[js]=x;
        jy[js++]=y;
      }
    }
  }
  int res=0;
  for (int i=0;i<js;i++){
    int x1=jx[i], y1=jy[i];
    for (int k=i+1;k<js;k++){
      int x2=jx[k], y2=jy[k];
      int vx=x2-x1, vy=y2-y1;
      int A=vx*vx+vy*vy;
      if (A<=res)continue;
      int dx=-vy, dy=vx;
      int nx1=x1+dx, ny1=y1+dy, nx2=x2+dx, ny2=y2+dy;
      if (nx1>=0&&nx1<N&&ny1>=0&&ny1<N&&nx2>=0&&nx2<N&&ny2>=0&&ny2<N&&mp[ny1][nx1]!='B'&&mp[ny2][nx2]!='B') {
        char c1=mp[ny1][nx1], c2=mp[ny2][nx2];
        bool j=c1=='J'||c2=='J', e=c1=='*'||c2=='*';
        bool bj=c1=='J'&&c2=='J';
        if (bj||(j&&e)) {
          res=A;
          continue;
        }
      }
      dx=vy, dy=-vx;
      nx1=x1+dx, ny1=y1+dy, nx2=x2+dx, ny2=y2+dy;
      if (nx1>=0&&nx1<N&&ny1>=0&&ny1<N&&nx2>=0&&nx2<N&&ny2>=0&&ny2<N&&mp[ny1][nx1]!='B'&&mp[ny2][nx2]!='B') {
        char c1=mp[ny1][nx1], c2=mp[ny2][nx2];
        bool j=c1=='J'||c2=='J', e=c1=='*'||c2=='*';
        bool bj=c1=='J'&&c2=='J';
        if (bj||(j&&e)) {
          res=A;
        }
      }
    }
  }
  cout<<res<<'\n';
}
