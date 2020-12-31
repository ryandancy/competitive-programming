#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[200000], d[200000], ud[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin>>T;
  while (T--) {
    ll n;
    cin>>n;
    ll sm=0;
    for (int i=0;i<n;i++)cin>>w[i],sm+=w[i],d[i]=0,ud[i]=1;
    for (int i=0;i<n-1;i++){
      int a,b;
      cin>>a>>b;
      a--,b--;
      d[a]++;
      d[b]++;
    }
    priority_queue<pll> pq;
    for (int i=0;i<n;i++) {
      pq.push({w[i],i});
    }
    cout<<sm<<' ';
    while (pq.size()) {
      const pll&x=pq.top();
      ll cw,c;
      tie(cw,c)=x;
      if (ud[c]==d[c]) {
        pq.pop();
        continue;
      }
      sm+=cw;
      ud[c]++;
      cout<<sm;
      if (!(pq.size()==1&&ud[c]==d[c]))cout<<' ';
    }
    cout<<'\n';
  }
}
