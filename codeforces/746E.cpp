// 746E - Numbers Exchange
// This definitely has l'air de "this should fail on an edge case", but it gets AC, so
// therefore it's correct. O(n).
#include <bits/stdc++.h>
using namespace std;
int a[200000], k[200000];
#define MAXU 5000000
bool u[MAXU]={false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  for (int i=0;i<n;i++){cin>>a[i];k[i]=i;}
  sort(k,k+n,[&](int x,int y){return a[x]<a[y];});
  int ne=0, no=0, nend=0, nond=0;
  for (int i=0;i<n;){
    int x=a[k[i]];
    int c=0;
    while (i<n&&a[k[i]]==x)i++,c++;
    (x%2?no:ne)+=c;
    (x%2?nond:nend)++;
    if (x<MAXU)u[x]=true;
  }
  int en=max(n/2-nend,0), on=max(n/2-nond,0);
  int ep=0,op=-1;
  int nc=0;
  for (int i=0;i<n&&(en>0||on>0);i++) {
    int x=a[k[i]];
    if (i==n-1)break;
    for (int j=i+1;(en>0||on>0)&&j<n&&a[k[j]]==x;j++) {
      if(en>0){
        ep+=2;
        while (ep<=m&&(ep<MAXU&&u[ep])) ep += 2;
        if (ep>m)return cout<<"-1\n",0;
        if (ep<MAXU)u[ep]=true;
        a[k[j]]=ep,nc++,en--;
      } else if (on>0) {
        op+=2;
        while (op<=m&&(op<MAXU&&u[op])) op += 2;
        if (op>m)return cout<<"-1\n",0;
        if (op<MAXU)u[op]=true;
        a[k[j]]=op,nc++,on--;
      } else break;
    }
  }
  assert(en==0||on==0);
  ep=0,op=-1;
  for (int i=n-1;i>=0&&(en>0||on>0);i--){
    int x=a[k[i]];
    if (x%2==0&&on>0){
      op+=2;
      while (op<=m&&(op<MAXU&&u[op])) op += 2;
      if (op>m)return cout<<"-1\n",0;
      if (op<MAXU)u[op]=true;
      a[k[i]]=op,nc++,on--;
    } else if (x%2==1&&en>0){
      ep+=2;
      while (ep<=m&&(ep<MAXU&&u[ep])) ep += 2;
      if (ep>m)return cout<<"-1\n",0;
      if (ep<MAXU)u[ep]=true;
      a[k[i]]=ep,nc++,en--;
    }
  }
  cout<<nc<<'\n';
  for (int i=0;i<n;i++)cout<<a[i]<<' ';
  cout<<'\n';
}
