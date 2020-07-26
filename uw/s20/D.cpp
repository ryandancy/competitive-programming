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
vector<int> ls[100000];
vector<int>*ps[100000];
int chk(int l, int r, int v){
  int res=0;
  while (l<r&&ps[l]->size()<=v)l++;
  if (l==r)return 0;
  int nl=l;
  int nr=l;
  while (nl<r) {
    while (nr<r&&(ps[nr]->size()<=v||ps[nr]->operator[](ps[nr]->size()-v-1)==ps[nl]->operator[](ps[nl]->size()-v-1)))nr++;
    res+=1+chk(nl,nr,v+1);
    nl=nr;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  int nc;
  while (cin>>nc, nc) {
    int nh;
    for (int i=0;i<nc;i++){
      ls[i].clear();
      cin>>nh;
      for (int j=0;j<nh;j++){
        string s;
        cin>>s;
        int v=0;
        if (s.length()==3)v=10;
        else if(s[0]=='A')v=1;
        else if (s[0]=='J')v=11;
        else if(s[0]=='Q')v=12;
        else if (s[0]=='K')v=13;
        else v=s[0]-'0';
        v--;
        v*=4;
        char u=s[s.length()-1];
        if (u=='C')v+=0;
        else if (u=='D')v+=1;
        else if (u=='H')v+=2;
        else if (u=='S')v+=3;
        ls[i].push_back(v);
      }
    }
    for (int i=0;i<nc;i++){
      ps[i]=ls+i;
    }
    sort(ps,ps+nc,[&](vector<int>*a,vector<int>*b){
      vector<int>&x=*a,&y=*b;
      for (int i=0;i<x.size()&&i<y.size();i++){
        if (x[x.size()-i-1]<y[y.size()-i-1])return true;
        else if (x[x.size()-i-1]>y[y.size()-i-1])return false;
      }
      return x.size()<y.size();
    });
    cout<<chk(0,nc,0)<<'\n';
  }
}
