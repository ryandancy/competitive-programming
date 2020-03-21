// 1081D - Maximum Distance
// The answer is the same for all nodes, so we can just do a modified
// Djikstra to get the answer for one special node and repeat it k times.
// Time complexity: O(n + m).
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int sp[100000];
bool v[100000]={false};
vector<pii> adj[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m, k;
  cin>>n>>m>>k;
  for (int i=0;i<k;i++)cin>>sp[i],sp[i]--;
  sort(sp,sp+k);
  for (int i=0;i<m;i++){
    int a, b, w;
    cin>>a>>b>>w;
    a--,b--;
    adj[a].push_back({b,w});
    adj[b].push_back({a,w});
  }
  int r=-1;
  priority_queue<pii> pq;
  pq.push({0,sp[0]});
  while (pq.size()) {
    pii cp=pq.top(); pq.pop();
    int d=-cp.first,c=cp.second;
    if (v[c]) continue;
    v[c]=true;
    if (binary_search(sp,sp+k,c)) {
      r=max(d,r);
    }
    for (const pii& nb:adj[c]) {
      if (v[nb.first]){continue;}
      pq.push({-max(nb.second,d),nb.first});
    }
  }
  for (int i=0;i<k;i++)cout<<r<<(i==k-1?'\n':' ');
}
