#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int a,b;
  cin>>a>>b;
  vector<int> r;
  r.push_back(b);
  bool ok=a==b;
  while (b>a) {
    bool any=false;
    if (b%2==0) b/=2,r.push_back(b),any=true;
    if (b==a){ok=true;break;}
    if (b%10==1) b--,b/=10,r.push_back(b),any=true;
    if (b==a){ok=true;break;}
    if (!any) return cout<<"NO\n",0;
  }
  if (ok) {
    cout<<"YES\n";
    cout<<r.size()<<'\n';
    for (int i=r.size()-1;i>=0;i--) {
      cout<<r[i]<<(i==0?'\n':' ');
    }
  } else cout<<"NO\n";
}
