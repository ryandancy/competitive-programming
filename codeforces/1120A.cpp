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
int m,k,n,s;
int a[500001];
int nd[500001]={0}, fd[500001]={0};
bool boot[500001]={false};
int fc=0;
vector<pii> rgs;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>m>>k>>n>>s;
  for (int i=0;i<m;i++)cin>>a[i];
  for (int i=0,b;i<s;i++)cin>>b, nd[b]++;
  int l=0,r=0;
  while (l<m&&r<m) {
    while (r<m&&fc<s) {
      if (fd[a[r]]<nd[a[r]]) {
        fc++;
      }
      fd[a[r]]++;
      r++;
    }
    while (l<m&&fc>=s) {
      fd[a[l]]--;
      if (fd[a[l]]<nd[a[l]]) {
        fc--;
        rgs.push_back({l,r});
      }
      l++;
    }
  }
  for (pii&rg:rgs) {
    tie(l,r)=rg;
    int st=l-l%k;
    int av=m-n*k;
    int sz=r-l;
    if (l+sz<=st+k) {
      cout<<"0\n\n";
      return 0;
    }
    int q=max(sz-(st+k-l),0);
    if (sz<=k&&q<=av) {
      cout<<q<<'\n';
      for (int i=0;i<q;i++) cout<<i+1<<" ";
      cout<<'\n';
      return 0;
    }
    int mc=max(sz-k,0);
    int nsz=sz-mc;
    int mn=mc+max(nsz-(st+k-l),0);
    if (mn<=av) {
      cout<<mn<<'\n';
      for (int i=l;i<r&&mn>0;i++) {
        if (nd[a[i]]>0)nd[a[i]]--;
        else {
          boot[i]=true;
          cout<<i+1<<' ';
          mn--;
        }
      }
      for (int i=0;i<m&&mn>0;i++) {
        if (nd[a[i]]>0)nd[a[i]]--;
        else if (!boot[i]) {
          boot[i]=true;
          cout<<i+1<<" ";
          mn--;
        }
      }
      cout<<'\n';
      return 0;
    }
  }
  cout<<"-1\n";
}
