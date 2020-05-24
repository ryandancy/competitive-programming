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
const ll A1=911382323LL, B1=972663749LL, A2=914718861LL, B2=963782533LL;
ll p1[2000000], p2[2000000], h1[2000000], h2[2000000];
ll gh1(int a, int b) {
  return a==0?h1[b]:((h1[b]-h1[a-1]*p1[b-a+1])%B1+B1)%B1;
}
ll gh2(int a, int b) {
  return a==0?h2[b]:((h2[b]-h2[a-1]*p2[b-a+1])%B2+B2)%B2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while(T--) {
    string s;
    cin>>s;
    h1[0]=h2[0]=s[0];
    p1[0]=p2[0]=1;
    for (int i=1;i<s.size();i++){
      h1[i]=((h1[i-1]*A1+s[i])%B1+B1)%B1;
      h2[i]=((h2[i-1]*A2+s[i])%B2+B2)%B2;
      p1[i]=(p1[i-1]*A1%B1+B1)%B1;
      p2[i]=(p2[i-1]*A2%B2+B2)%B2;
    }
    int res=0;
    int n=s.size();
    for (int i=2;i<s.size()-1;i+=2) {
      // debug(0,i/2,i,i+(n-i)/2,n);
      // debug(gh1(0,0),gh1(1,1));
      if (gh1(0,i/2-1)==gh1(i/2,i-1)&&gh2(0,i/2-1)==gh2(i/2,i-1)
        &&gh1(i,i+(n-i)/2-1)==gh1(i+(n-i)/2,n-1)&&gh2(i,i+(n-i)/2-1)==gh2(i+(n-i)/2,n-1)) {
        res++;
      }
    }
    cout<<res<<'\n';
  }
}
