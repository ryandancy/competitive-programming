#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a, b;
  cin>>a>>b;
  if (a<b)swap(a,b);
  ll c=0;
  while (a>0&&b>0){
    c+=a/b;
    a%=b;
    swap(a,b);
  }
  cout<<c<<'\n';
}
