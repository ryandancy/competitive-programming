#include <bits/stdc++.h>
using namespace std;
int x[2000], res[2000];
vector<int> chs[2000];
bool g(list<int>& l, int c) {
  assert(l.empty());
  for (int ch:chs[c]) {
    list<int> nl;
    if (!g(nl, ch)) return false;
    l.splice(l.end(), nl);
  }
  if (l.size()<x[c]) return false;
  auto it=l.begin();
  advance(it, x[c]);
  l.insert(it, c);
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  int rt=-1;
  for (int i=0, p;i<n;i++) {
    cin>>p>>x[i];
    p--;
    if (p==-1) rt=i;
    else chs[p].push_back(i);
  }
  list<int> l;
  if (!g(l, rt)) return cout<<"NO\n", 0;
  int i=1;
  for (int v:l) {
    res[v]=i++;
  }
  cout<<"YES\n";
  for (int i=0;i<n;i++){
    cout<<res[i]<<(i==n-1?'\n':' ');
  }
}
