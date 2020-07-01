// 711D - Directed Roads
// There are n vertices and n edges, so there is exactly one cycle per component.
// Find the sizes a0, a1, ..., am of the cycles, then compute the answer via:
// (2^a0 - 2)*(2^a1 - 2)*...*(2^am - 2)*2^(n-a0-a1-...-am)
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
map<int,int> adj[200000];
bool v[200000]={0};
int d[200000];
ll f2exp(int n) {
  if (n==0)return 1;
  if (n==1)return 2;
  ll v=f2exp(n/2);
  v*=v;
  v%=MOD;
  if (n%2) v*=2, v%=MOD;
  return v;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  for (int i=0;i<n;i++){
    int x;
    cin>>x; x--;
    adj[i][x]++;
    adj[x][i]++;
  }
  stack<tuple<int,int>> stk;
  vector<int> cy;
  for (int in=0;in<n;in++){
    if (v[in])continue;
    stk.push({in,-1});
    d[in]=0;
    bool fi=false;
    while (stk.size()) {
      int c,l;
      tie(c,l)=stk.top();stk.pop();
      int nd=l==-1?0:d[l]+1;
      if (l!=-1) {
        adj[c][l]--;
        adj[l][c]--;
      }
      if (v[c]&&fi)continue;
      if (v[c]) {
        int rd=nd-d[c];
        cy.push_back(rd);
        fi=true;
        continue;
      }
      v[c]=true;
      d[c]=nd;
      for (auto& it:adj[c]){
        if (!it.second) continue;
        stk.push({it.first,c});
      }
    }
  }
  ll r=1;
  ll y=0;
  for (int k:cy){
    ll q=f2exp(k)-2;
    q=(q%MOD+MOD)%MOD;
    r*=q;
    r%=MOD;
    y+=k;
  }
  r*=f2exp(n-y);
  r=(r%MOD+MOD)%MOD;
  cout<<r<<'\n';
}
