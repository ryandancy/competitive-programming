// that was stupid
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin>>x>>y;
  if (y==0)return cout<<"No\n",0;
  if (y==1)return cout<<(x==0?"Yes\n":"No\n"),0;
  x-=y-1;
  cout<<(x>=0&&x%2==0?"Yes\n":"No\n");
}
