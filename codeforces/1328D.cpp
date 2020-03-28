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
int t[200050];
char v[200050];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int q;
  cin>>q;
  while (q--){
    int n;
    cin>>n;
    int ot=-1,o1t=true;
    for (int i=0;i<n;i++){
      cin>>t[i];
      if (ot==-1){
        ot=t[i];
      } else if (t[i]!=ot){
        o1t=false;
      }
    }
    if (o1t){
      cout<<"1\n";
      for (int i=0;i<n;i++){
        cout<<"1";
        if (i<n-1)cout<<' ';
      }
      cout<<'\n';
      continue;
    }
    if (n%2==0){
      cout<<"2\n";
      for (int i=0;i<n;i++){
        cout<<(i%2==0?'1':'2');
        if (i<n-1)cout<<' ';
      }
      cout<<'\n';
      continue;
    }
    for (int i=0;i<n;i++){
      int j=(i+1)%n;
      if (t[i]==t[j]) {
        for(int k=0;k<n;k++){
          int c=(j+k)%n;
          v[c]=(k%2==0?'1':'2');
        }
        cout<<"2\n";
        for (int k=0;k<n;k++){
          cout<<v[k];
          if (k<n-1)cout<<' ';
        }
        cout<<'\n';
        goto nxt;
      }
    }
    cout<<"3\n";
    for (int i=0;i<n-1;i++){
      cout<<(i%2==0?'1':'2')<<' ';
    }
    cout<<"3\n";
    nxt:;
  }
}
