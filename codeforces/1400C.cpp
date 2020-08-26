#include <bits/stdc++.h>
using namespace std;
int r[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    string s;
    cin>>s;
    int x;
    cin>>x;
    int n=s.size();
    for (int i=0;i<n;i++) {
      r[i]=1;
    }
    for (int i=0;i<n;i++) {
      if (s[i]=='0') {
        if (i-x>=0)r[i-x]=0;
        if (i+x<n)r[i+x]=0;
      }
    }
    for (int i=0;i<n;i++) {
      if (s[i]=='1'&&(i-x<0||r[i-x]==0)&&(i+x>=n||r[i+x]==0)) {
        cout<<"-1\n";
        goto nxt;
      }
    }
    for (int i=0;i<n;i++) {
      cout<<r[i];
    }
    cout<<'\n';
    nxt:;
  }
}
