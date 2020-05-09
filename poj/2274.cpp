// TIL: std::set is SUPER FRICKIN SLOW, use std::priority_queue whenever possible.
// A std::set is a fancy self balancing BST, std::priority_queue is just a heap lol.
// BIT to count inversions for the pass count, then greedily take the closest
// pass loading with each v1/v2/x1 combination (since max(vi) is small) using priority queues.
// Time complexity: if V is the max vi and we output the first K passings,
// O(N log V) for the pass count and O((NV^2 + K) log K) for the first K passings.
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
int v[250000], bit[101]={0};
vector<int> ipv[101], xpv[101];
void bit_inc(int x) {
  while (x<=100) {
    bit[x]++;
    bit[x]%=1000000;
    x+=x&-x;
  }
}
int bit_sum(int x) {
  int res=0;
  while (x>0){
    res+=bit[x];
    res%=1000000;
    x-=x&-x;
  }
  return res;
}
struct ps {
  double y, t; int i, j, v1, v2;
  bool operator<(const ps& o) const {
    return t!=o.t ? t<o.t : y<o.y;
  }
  bool operator>(const ps& o) const {
    return t!=o.t ? t>o.t : y>o.y;
  }
};
priority_queue<ps> pq;
priority_queue<ps, vector<ps>, greater<ps> > gpq;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  scanf("%d", &n);
  for (int i=0,x;i<n;i++){
    scanf("%d %d", &x, v+i);
    ipv[v[i]].push_back(i);
    xpv[v[i]].push_back(x);
  }
  int ic=0;
  bool m10k=false;
  bit_inc(v[0]);
  for (int i=1;i<n;i++){
    ic+=i-bit_sum(v[i]);
    if (ic>10000)m10k=true;
    ic%=1000000;
    bit_inc(v[i]);
  }
  printf("%d\n", ic);
  for (int v1=1;v1<=100;v1++){
    int xv1s=xpv[v1].size();
    for (int v2=1;v2<v1;v2++){
      int xv2s=xpv[v2].size();
      double dv=v1-v2;
      for (int i=0,j=0;i<xv1s;i++) {
        int x1=xpv[v1][i], x2;
        while (j<xv2s&&(x2=xpv[v2][j])<x1) j++;
        if (j==xv2s)break;
        double y=(double)(v1*x2-v2*x1)/dv, t=(double)(x2-x1)/dv;
        ps nps={y, t, i, j, v1, v2};
        if (pq.size() < 10000 || nps < pq.top()) {
          if (pq.size() == 10000) pq.pop();
          pq.push(nps);
        }
      }
    }
  }
  while (pq.size()) {
    gpq.push(pq.top());
    pq.pop();
  }
  for (int k=0; k<(m10k?10000:ic); ++k) {
    ps p=gpq.top(); gpq.pop();
    printf("%d %d\n", ipv[p.v1][p.i]+1, ipv[p.v2][p.j]+1);
    p.j++;
    if (p.j>=xpv[p.v2].size()) continue;
    int x1=xpv[p.v1][p.i], x2=xpv[p.v2][p.j];
    double dv=p.v1-p.v2;
    p.y=(double)(p.v1*x2-p.v2*x1)/dv;
    p.t=(double)(x2-x1)/dv;
    gpq.push(p);
  }
}
