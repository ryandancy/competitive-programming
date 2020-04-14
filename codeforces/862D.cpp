// 862D - Mahmoud and Ehab and the binary string
// Binary search
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  cout<<"? ";
  for (int i=0;i<n;i++)cout<<'0';
  cout<<endl;
  int n1;
  cin>>n1;
  cout<<"? 1";
  for (int i=0;i<n-1;i++)cout<<'0';
  cout<<endl;
  int a;
  cin>>a;
  int p0=-1,p1=-1;
  if (a>n1){
    p0=0;
  } else {
    p1=0;
  }
  bool l1=p1==-1;
  int l=1,r=n-1;
  int nq=1;
  while (l<=r){
    int c=(l+r)/2;
    if (nq>=15){
      cout<<l<<" "<<r<<" "<<n<<endl;
      assert(1/0);
      return 0;
    }
    cout<<"? ";
    for (int i=0;i<n;i++){
      if (i>=l&&i<=c)cout<<'1';
      else cout<<'0';
    }
    cout<<endl;
    nq++;
    int m;
    cin>>m;
    if (l1){
      if (m-n1==-(c-l+1)) {
        p1=c;
        break;
      } else if (m-n1==c-l+1) {
        if (c-l+1==1){
          p1=c+1;
          break;
        }
        l=c+1;
      } else {
        r=c;
      }
    } else {
      if (m-n1==c-l+1){
        p0=c;
        break;
      } else if (m-n1==-(c-l+1)){
        if (c-l+1==1){
          p0=c+1;
          break;
        }
        l=c+1;
      } else {
        r=c;
      }
    }
  }
  cout<<"! "<<p0+1<<' '<<p1+1<<endl;
}
