#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll a[1001];
ll ch[1001][1001]={{0}};
vector<int> os;
ll r(ll b) {
  ll res=0;
  for (int i=0;i<os.size();i++) {
    if (b-i<0) break;
    res+=ch[os[i]][b-i];
    res%=MOD;
  }
  if (os.size()==b) res++,res%=MOD;
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string n; ll k;
  cin>>n>>k;
  if (k>=6) return cout<<"0\n",0;
  if (k==0) return cout<<"1\n",0;
  a[1]=0;
  for (int i=2;i<=1000;i++) {
    a[i]=a[__builtin_popcount(i)]+1;
  }
  for (int i=0;i<=1000;i++) {
    ch[i][0]=1;
    for (int j=1;j<=i;j++) {
      ch[i][j]=(ch[i-1][j]+ch[i-1][j-1])%MOD;
    }
  }
  for (int i=0;i<n.size();i++) {
    if (n[i]=='1')os.push_back(n.size()-i-1);
  }
  ll res=0;
  for (int i=1;i<=1000;i++) {
    if (a[i]==k-1) {
      res+=r(i);
      res%=MOD;
    }
  }
  if (k==1) res--,res+=MOD,res%=MOD;
  cout<<res<<'\n';
}
