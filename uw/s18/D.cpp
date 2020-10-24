#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n,bd[100][100]={{0}}; //[r][c]
void mvl(int r, int t) {
  for (int i=0;i<n;i++) {
    swap(bd[r][i],t);
    if (t==0) return;
  }
}
void mvr(int r, int t) {
  for (int i=n-1;i>=0;i--) {
    swap(bd[r][i],t);
    if (t==0) return;
  }
}
void mvt(int c, int t) {
  for (int i=0;i<n;i++) {
    swap(bd[i][c],t);
    if (t==0)return;
  }
}
void mvb(int c, int t) {
  for (int i=n-1;i>=0;i--) {
    swap(bd[i][c],t);
    if (t==0)return;
  }
}
char win() {
  int a[3]={0};
  for (int r=0;r<n;r++) {
    int v=bd[r][0];
    if (v==0) continue;
    for (int c=1;c<n;c++) {
      if (bd[r][c]!=v) goto nxt;
    }
    a[v]++;
    nxt:;
  }
  for (int c=0;c<n;c++) {
    int v=bd[0][c];
    if (v==0) continue;
    for (int r=1;r<n;r++) {
      if (bd[r][c]!=v) goto nxt2;
    }
    a[v]++;
    nxt2:;
  }
  if (a[1]>a[2]) return 'X';
  if (a[1]<a[2]) return 'O';
  return '\0';
}
void pb() {
// #ifdef DEBUG
//   for (int r=0;r<n;r++){
//     for (int c=0;c<n;c++) {
//       switch(bd[r][c]) {
//         case 0: cout<<'.'; break;
//         case 1: cout<<'X'; break;
//         case 2: cout<<'O'; break;
//       }
//     }
//     cout<<'\n';
//   }
// #endif
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  string s;
  int t=1;
  while (cin>>s,s!="QUIT") {
    char dir=s[0];
    int rc=s[1]-'1';
    switch(dir) {
      case 'L': mvl(rc,t); break;
      case 'R': mvr(rc,t); break;
      case 'T': mvt(rc,t); break;
      case 'B': mvb(rc,t); break;
    }
    char w=win();
    if (w) {
      pb();
      cout<<w<<" WINS\n";
      return 0;
    }
    t=(t==1)?2:1;
  }
  pb();
  cout<<"TIE GAME\n";
}
