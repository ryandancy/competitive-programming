#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int n;
vector<int> adj[200000], ch[200000];
bool vo[200000]={false};
ll fac[200001];
ll f(int rt) {
  ll res=fac[ch[rt].size()+1];
  for (int&oc:ch[rt]) {
    res*=f(oc);
    res%=MOD;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  for (int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  stack<int> stk;
  stk.push(0); vo[0]=true;
  while (stk.size()) {
    int c=stk.top(); stk.pop();
    for (int&nb:adj[c]) {
      if (!vo[nb]) {
        vo[nb]=true;
        ch[c].push_back(nb);
        stk.push(nb);
      }
    }
  }
  fac[0]=1;
  for (ll i=1;i<=200000;i++){
    fac[i]=fac[i-1]*i%MOD;
  }
  if (ch[0].size()==0) {cout<<"1\n"; return 0;}
  int rt2=ch[0].back();
  ch[0].pop_back();
  cout<<((f(0)*f(rt2)%MOD)*n%MOD)<<'\n';
}
