#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, i, j, a, b;
  cin>>n>>m>>i>>j>>a>>b;
  if ((i==1||i==n)&&(j==1||j==m))return cout<<"0\n",0;
  if ((a>i-1&&a>n-i)||(b>j-1&&b>m-j))return cout<<"Poor Inna and pony!\n",0;
  int res=INF;
  if ((i-1)%a==0&&(j-1)%b==0&&(((i-1)/a%2)+2)%2==(((j-1)/b%2)+2)%2) {
    res=min(res, max((i-1)/a, (j-1)/b));
  }
  if ((i-1)%a==0&&(m-j)%b==0&&(((i-1)/a%2)+2)%2==(((m-j)/b%2)+2)%2) {
    res=min(res, max((i-1)/a, (m-j)/b));
  }
  if ((n-i)%a==0&&(j-1)%b==0&&(((n-i)/a%2)+2)%2==(((j-1)/b%2)+2)%2) {
    res=min(res, max((n-i)/a, (j-1)/b));
  }
  if ((n-i)%a==0&&(m-j)%b==0&&(((n-i)/a%2)+2)%2==(((m-j)/b%2)+2)%2) {
    res=min(res, max((n-i)/a, (m-j)/b));
  }
  if (res==INF) cout<<"Poor Inna and pony!\n";
  else cout<<res<<'\n';
}
