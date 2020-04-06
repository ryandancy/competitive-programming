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
int c[26]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin>>t;
  string s;
  while(t--){
    int n, k;cin>>n>>k;
    cin>>s;
    int ct=0;
    for (int x=0;x<k/2;x++){
      fill_n(c,26,0);
      for (int i=x;i<n;i+=k){
        c[s[i]-'a']++;
      }
      for (int i=k-x-1;i<n;i+=k){
        c[s[i]-'a']++;
      }
      int bf=0;
      for (int i=0;i<26;i++){
        if (c[i]>bf){
          bf=c[i];
        }
      }
      // debug(s,"pos",x,"f",bf);
      ct+=(n/k)*2-bf;
    }
    if (k%2==1){
      fill_n(c,26,0);
      for (int i=k/2;i<n;i+=k){
        c[s[i]-'a']++;
      }
      int bf=0;
      for (int i=0;i<26;i++){
        if (c[i]>bf){
          bf=c[i];
        }
      }
      ct+=n/k-bf;
    }
    cout<<ct<<'\n';
  }
}
