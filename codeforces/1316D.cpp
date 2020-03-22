// 1316D - Nash Matrix
// BFS-based solution, O(n^2).
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
pii b[1000][1000];
char v[1000][1000]={{'\0'}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cin>>b[i][j].first>>b[i][j].second;
      if (b[i][j].first!=-1)b[i][j].first--, b[i][j].second--;
    }
  }
  int k=0;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (!v[i][j]&&i==b[i][j].first&&j==b[i][j].second){
        v[i][j]='X'; k++;
        queue<int> xq, yq;
        xq.push(i); yq.push(j);
        while (xq.size()){
          int r=xq.front(),c=yq.front();xq.pop();yq.pop();
          if (r>0&&!v[r-1][c]&&b[r-1][c]==b[r][c]) {v[r-1][c]='D'; k++; xq.push(r-1); yq.push(c);}
          if (r<n-1&&!v[r+1][c]&&b[r+1][c]==b[r][c]) {v[r+1][c]='U'; k++; xq.push(r+1); yq.push(c);}
          if (c>0&&!v[r][c-1]&&b[r][c-1]==b[r][c]) {v[r][c-1]='R'; k++; xq.push(r); yq.push(c-1);}
          if (c<n-1&&!v[r][c+1]&&b[r][c+1]==b[r][c]) {v[r][c+1]='L'; k++; xq.push(r); yq.push(c+1);}
        }
      }
    }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (!v[i][j]&&b[i][j].first==-1&&b[i][j].second==-1){
        int oi=-1,oj=-1;
        if (i>0&&b[i-1][j]==b[i][j]) oi=i-1,oj=j,v[i][j]='U',v[i-1][j]='D';
        else if (i<n-1&&b[i+1][j]==b[i][j]) oi=i+1,oj=j,v[i][j]='D',v[i+1][j]='U';
        else if (j>0&&b[i][j-1]==b[i][j]) oi=i,oj=j-1,v[i][j]='L',v[i][j-1]='R';
        else if (j<n-1&&b[i][j+1]==b[i][j]) oi=i,oj=j+1,v[i][j]='R',v[i][j+1]='L';
        else return cout<<"INVALID\n", 0;
        k+=2;
        queue<int> xq, yq;
        xq.push(i); yq.push(j);
        xq.push(oi); yq.push(oj);
        while (xq.size()){
          int r=xq.front(),c=yq.front();xq.pop();yq.pop();
          if (r>0&&!v[r-1][c]&&b[r-1][c]==b[r][c]) {v[r-1][c]='D'; k++; xq.push(r-1); yq.push(c);}
          if (r<n-1&&!v[r+1][c]&&b[r+1][c]==b[r][c]) {v[r+1][c]='U'; k++; xq.push(r+1); yq.push(c);}
          if (c>0&&!v[r][c-1]&&b[r][c-1]==b[r][c]) {v[r][c-1]='R'; k++; xq.push(r); yq.push(c-1);}
          if (c<n-1&&!v[r][c+1]&&b[r][c+1]==b[r][c]) {v[r][c+1]='L'; k++; xq.push(r); yq.push(c+1);}
        }
      }
    }
  }
  if (k!=n*n) return cout<<"INVALID\n",0;
  cout<<"VALID\n";
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cout<<v[i][j];
    }
    cout<<'\n';
  }
}
