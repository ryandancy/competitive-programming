// 1337C - Linova and Kingdom
// Assign depth and subtree size to each.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> adj[200000];
int d[200000]={0};
bool v[200000]={false};
int s[200000]={0};
int x[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin>>n>>k;
  for (int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  d[0]=0;
  v[0]=true;
  queue<int> q;
  q.push(0);
  while (!q.empty()){
    int c=q.front();q.pop();
    for (int nb:adj[c]) {
      if (!v[nb]) {
        v[nb]=true;
        d[nb]=d[c]+1;
        q.push(nb);
      }
    }
  }
  stack<pii> st;
  st.push({0,0});
  while (st.size()){
    pii p=st.top();st.pop();
    int t=p.first, c=p.second;
    if (t==0){
      st.push({1,c});
      for (int nb:adj[c]){
        if (d[nb]>d[c]){
          st.push({0,nb});
        }
      }
    } else {
      for (int nb:adj[c]){
        if (d[nb]>d[c]) {
          s[c]+=s[nb]+1;
        }
      }
    }
  }
  for (int i=0;i<n;i++)x[i]=i;
  sort(x,x+n,[&](int a, int b){return d[a]-s[a]>d[b]-s[b];});
  ll r=0;
  for (int i=0;i<k;i++){
    r+=d[x[i]]-s[x[i]];
  }
  cout<<r<<'\n';
}
