// O(m log m)
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
int col[100000]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin>>n>>m;
  for (int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i=0;i<n;i++)sort(adj[i].begin(),adj[i].end());
  int cc[4]={0};
  for(int c=1,i=0;c<=3;c++){
    while (i<n&&col[i])i++;
    if (i==n)return cout<<"-1\n",0;
    for (int j=0;j<n;j++){
      if (!binary_search(adj[i].begin(),adj[i].end(),j)){
        if (col[j])return cout<<"-1\n",0;
        col[j]=c;
        cc[c]++;
      }
    }
  }
  for (int i=0;i<n;i++){
    if (!col[i])return cout<<"-1\n",0;
    if (adj[i].size()!=n-cc[col[i]])return cout<<"-1\n",0;
    for (int&b:adj[i]){
      if (col[b]==col[i])return cout<<"-1\n",0;
    }
  }
  for (int i=0;i<n;i++){
    cout<<col[i]<<(i==n-1?'\n':' ');
  }
}
