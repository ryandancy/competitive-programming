#include <bits/stdc++.h>
using namespace std;
int x[100][100];
bool lck[101]={false};
vector<int> ac[101];
int res[100]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin>>n>>m>>k;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++)cin>>x[i][j];
  }
  for (int j=0;j<m;j++){
    for (int v=1;v<=k;v++)ac[v].clear();
    for (int i=0;i<n;i++){
      if (res[i]==0&&x[i][j]) ac[x[i][j]].push_back(i);
    }
    for (int v=1;v<=k;v++){
      if (lck[v]||ac[v].size()>1) {
        for (int i:ac[v]) {
          if (res[i]==0)res[i]=j+1;
        }
        lck[v]=true;
      }
    }
  }
  for (int i=0;i<n;i++)cout<<res[i]<<'\n';
}
