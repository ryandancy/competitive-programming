#include <bits/stdc++.h>
using namespace std;
int a[500]; int*p;
int srt[501];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    int n,x;
    cin>>n>>x;
    for (int i=0;i<n;i++)cin>>a[i],srt[i]=a[i];
    srt[n]=x;
    sort(srt,srt+n+1);
    p=a; int s=0;
    while (n>0&&*p==srt[s]) s++,p++,n--;
    while (n>0&&p[n-1]==srt[s+n]) n--;
    if (n==0) {cout<<"0\n"; continue;}
    int res=0;
    for (int i=0;i<n;i++) {
      if (p[i]>x) {
        swap(p[i],x);
        res++;
      }
    }
    for (int i=1;i<n;i++){
      if (p[i]<p[i-1]) {cout<<"-1\n"; goto nxt;}
    }
    cout<<res<<'\n';
    nxt:;
  }
}
