// O(n^2), somewhat naive
#include <bits/stdc++.h>
using namespace std;
int p[5000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  string s;
  while (t--){
    cin>>s;
    int l=s.size();
    int i=0;
    while (i<=l/2&&s[i]==s[l-i-1]) i++;
    if (i>l/2){cout<<s<<'\n';continue;}
    int bl=-1, br=-1;
    for (int j=i;j<=l-i-1;j++){
      int k=0;
      while (k<=(j-i)/2&&s[i+k]==s[j-k])k++;
      if (k>(j-i)/2)bl=j;
    }
    for(int j=l-i-1;j>=i;j--){
      int k=0;
      while (k<=(l-i-1-j)/2&&s[j+k]==s[l-i-1-k])k++;
      if (k>(l-i-1-j)/2)br=j;
    }
    if (bl-i>l-i-1-br){
      cout<<s.substr(0,bl+1)+s.substr(l-i)<<'\n';
    }else{
      cout<<s.substr(0,i)+s.substr(br)<<'\n';
    }
  }
}
