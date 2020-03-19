// O(n) with hashing
#include <bits/stdc++.h>
using namespace std;
#define A1 911382323
#define A2 941257264
#define B1 972663749
#define B2 952351623
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin>>t;
  string s;
  while (t--){
    cin>>s;
    int l=s.size();
    int i=0;
    while (i<=l/2&&s[i]==s[l-i-1]) i++;
    if (i>l/2){cout<<s<<'\n';continue;}
    int bl=-1,br=-1;
    ll ha1=0,ha2=0,hr1=0,hr2=0,m1=1,m2=1;
    for (int j=i;j<=l-i-1;j++){
      ll k=s[j];
      ha1=(ha1+m1*k%B1)%B1;
      ha2=(ha2+m2*k%B2)%B2;
      hr1=(k+A1*hr1%B1)%B1;
      hr2=(k+A2*hr2%B2)%B2;
      m1*=A1, m1%=B1;
      m2*=A2, m2%=B2;
      if (ha1==hr1&&ha2==hr2){
        bl=j;
      }
    }
    ha1=0,ha2=0,hr1=0,hr2=0,m1=1,m2=1;
    for (int j=l-i-1;j>=i;j--){
      ll k=s[j];
      ha1=(ha1+m1*k%B1)%B1;
      ha2=(ha2+m2*k%B2)%B2;
      hr1=(k+A1*hr1%B1)%B1;
      hr2=(k+A2*hr2%B2)%B2;
      m1*=A1, m1%=B1;
      m2*=A2, m2%=B2;
      if (ha1==hr1&&ha2==hr2){
        br=j;
      }
    }
    if (bl-i>l-i-1-br){
      cout<<s.substr(0,bl+1)+s.substr(l-i)<<'\n';
    }else{
      cout<<s.substr(0,i)+s.substr(br)<<'\n';
    }
  }
}
