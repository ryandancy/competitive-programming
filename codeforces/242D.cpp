#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
bool ex[100000]={false};
int a[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m;
  cin>>n>>m;
  for (int i=0;i<m;i++) {
    int x,y;
    cin>>x>>y;
    x--,y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i=0;i<n;i++) {
    cin>>a[i];
  }
  vector<int> res;
  queue<int> q;
  for (int i=0;i<n;i++) {
    if (a[i]==0) q.push(i);
  }
  while (q.size()>0) {
    int c=q.front(); q.pop();
    if (ex[c]) continue;
    ex[c]=true;
    res.push_back(c);
    for (int&nb:adj[c]) {
      if (!ex[nb]) {
        if (a[nb]==0) {ex[nb]=true; continue;}
        a[nb]--;
        if (a[nb]==0)q.push(nb);
      }
    }
  }
  cout<<res.size()<<'\n';
  for (int i=0;i<res.size();i++) cout<<res[i]+1<<(i==res.size()-1?'\n':' ');
}
