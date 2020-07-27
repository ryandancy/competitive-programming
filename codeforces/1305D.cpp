#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
int n,ce=0;
bool elim[1000]={false};
int fdfs(int s){
  int mx=s,mxd=0;
  stack<int>sp,spv,sd;
  sp.push(s), spv.push(-1), sd.push(0);
  while (sp.size()) {
    int p=sp.top(),pv=spv.top(),d=sd.top();
    sp.pop(); spv.pop(); sd.pop();
    if (d>mxd){mxd=d;mx=p;}
    for (int&nb:adj[p]){
      if (nb==pv||elim[nb])continue;
      sp.push(nb);
      spv.push(p);
      sd.push(d+1);
    }
  }
  return mx;
}
void dia(int s,int&a,int&b){
  a=fdfs(s);
  b=fdfs(a);
}
void melim(int s,int l) {
  stack<int> sp;
  sp.push(s);
  while (sp.size()) {
    int p=sp.top(); sp.pop();
    elim[p]=true;
    ce++;
    for (int&nb:adj[p]){
      if (nb==l||elim[nb])continue;
      sp.push(nb);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for (int i=0;i<n-1;i++){
    int x,y;
    cin>>x>>y;
    x--,y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int a=-1,b=-2,l=0;
  while (ce<n-1) {
    dia(l,a,b);
    cout<<"? "<<a+1<<" "<<b+1<<"\n";
    cout.flush();
    cin>>l;
    if (l==-1)return 0;
    l--;
    melim(a,l);
    melim(b,l);
  }
  cout<<"! "<<l+1<<"\n";
  cout.flush();
}
