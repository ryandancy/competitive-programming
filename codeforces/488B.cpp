// lol it's linear time when n=2
#include <bits/stdc++.h>
using namespace std;
bool chk(int a, int b, int c, int d) {
  return (a+b+c+d)%4==0&&(b+c)%2==0&&(a+b+c+d)/4==(b+c)/2&&(b+c)/2==(d-a);
}
int tst3(int a, int b, int c) {
  if ((a+b)%2==0&&c-(a+b)/2<=a&&chk(c-(a+b)/2,a,b,c)) {
    return c-(a+b)/2;
  }
  if ((b+c)%2==0&&a+(c+b)/2>=c&&chk(a,b,c,a+(c+b)/2)){
    return a+(c+b)/2;
  }
  int x=2*(c-a)-b;
  if (a<=x&&x<=c&&(x<=b?chk(a,x,b,c):chk(a,b,x,c))){
    return x;
  }
  return 0;
}
int a[4], b[4];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=0;i<n;i++)cin>>a[i];
  if (n==0) {
    cout<<"YES\n1\n1\n3\n3\n";
    return 0;
  }
  sort(a,a+n);
  if (n==4) {
    if (chk(a[0],a[1],a[2],a[3])){
      cout<<"YES\n";
    } else cout<<"NO\n";
    return 0;
  }
  if (n==1){
    cout<<"YES\n"<<a[0]<<'\n'<<3*a[0]<<"\n"<<3*a[0]<<'\n';
    return 0;
  }
  if (n==3){
    int t=tst3(a[0],a[1],a[2]);
    if (t)cout<<"YES\n"<<t<<'\n';
    else cout<<"NO\n";
    return 0;
  }
  for (int x=1;x<=1000000;x++){
    b[0]=a[0];
    b[1]=a[1];
    b[2]=x;
    sort(b,b+3);
    int k;
    if (k=tst3(b[0],b[1],b[2])){
      cout<<"YES\n"<<x<<'\n'<<k<<'\n';
      return 0;
    }
  }
  cout<<"NO\n";
}
