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
int c[26];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    fill_n(c,26,0);
    for (char ch:s){
      c[ch-'a']++;
    }
    int nm=0;
    for (int i=0;i<26;i++)nm+=(c[i]!=0);
    if (nm==1) {
      for (int i=0;i<n/k+(n%k!=0);i++)cout<<s[0];
      cout<<'\n';
      continue;
    }
    string r;
    for (int i=0;i<26;i++){
      if (!c[i])continue;
      if (c[i]>=k){
        if (c[i]==k&&nm==2) {
          for (int j=0;j<c[i]/k;j++){
            r+=(char)(i+'a');
          }
          int j;
          for (j=i+1;j<26;j++) {
            if (c[j])break;
          }
          for (int x=0;x<(c[j]%k==0?c[j]/k:c[j]/k+1);x++){
            r+=(char)(j+'a');
          }
          break;
        } else {
          c[i]-=k-1;
          for (int j=i;j<26;j++){
            while (c[j]--){
              r+=(char)(j+'a');
            }
          }
          break;
        }
        // if (nm>2) {
        //   for (int j=i+1;j<26;j++){
        //     while (c[j]--) {
        //       r+=(char)(j+'a');
        //     }
        //   }
        //   break;
        // }
        // if (c[i]%k!=0){
        //   k=c[i]%k;
        // }
        // if (nm==1) {
        //   for (int j=0;j<(c[i]%k==0?c[i]/k:c[i]/k+1);j++){
        //     r+=(char)(i+'a');
        //   }
        //   break;
        // } else if (nm==2) {
        //   for (int j=0;j<c[i]/k;j++){
        //     r+=(char)(i+'a');
        //   }
        //   int j;
        //   for (j=i+1;j<26;j++)if(c[j])break;
        //   for (int x=0;x<(c[j]/k);x++)r+=(char)(j+'a');
        //   break;
        // } else {
        //   // c[i]-=k-1;
        //   // for (int j=i;j<26;j++){
        //   //   while (c[j]--) {
        //   //     r+=(char)(j+'a');
        //   //   }
        //   // }
        //   c[i]-=k-1;
        //   break;
        // }
      } else {
        int x=c[i];
        int mr=i;
        for (int j=i+1;x<k&&j<26;j++){
          if (c[j]) {
            mr=j;
            x+=c[j];
          }
        }
        r+=(char)(mr+'a');
        break;
        // int j;
        // for (j=i+1;j<26;j++){
        //   if (c[j])break;
        // }
        // r+=(char)(j+'a');
        // break;
      }
    }
    cout<<r<<'\n';
  }
}
