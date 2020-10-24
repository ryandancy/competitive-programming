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
string s[100000];
map<string,int> m;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  string t;
  for (int i=0;i<n;i++){
    cin>>t;
    for (char c:t) {
      if (c=='-')continue;
      if (c>='A'&&c<='C')c='2';
      if (c>='D'&&c<='F')c='3';
      if (c>='G'&&c<='I')c='4';
      if (c>='J'&&c<='L')c='5';
      if (c>='M'&&c<='O')c='6';
      if (c>='P'&&c<='S')c='7';
      if (c>='T'&&c<='V')c='8';
      if (c>='W'&&c<='Y')c='9';
      s[i] += c;
    }
  }
  sort(s,s+n);
  int i=0;
  while(i<n) {
    int j=i;
    i++;
    while (i<n&&s[i]==s[j])i++,m[s[j]]++;
  }
  if (m.size()==0)return cout<<"No duplicates\n",0;
  for (const pair<string,int>&p:m) {
    cout<<p.first.substr(0, 3)<<'-'<<p.first.substr(3)<<' '<<p.second+1<<'\n';
  }
}
