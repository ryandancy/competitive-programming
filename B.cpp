#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin>>a>>b>>c;
  int x=(a+b-c)/2, y=(-a+b+c)/2, z=(a-b+c)/2;
  if ((a+b+c)%2||x<0||y<0||z<0)cout<<"Impossible\n";
  else cout<<x<<' '<<y<<' '<<z<<'\n';
}
