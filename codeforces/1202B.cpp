#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int res[10][10];
int ftw[10][10][10][10];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin>>s;
  int n=s.size();
  for (int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      for (int f=0;f<10;f++)for(int t=0;t<10;t++)ftw[i][j][f][t]=INF;
      for (int f=0;f<10;f++){
        ftw[i][j][f][(f+i)%10]=ftw[i][j][f][(f+j)%10]=1;
      }
      for (int m=0;m<10;m++){
        for (int f=0;f<10;f++){
          for (int t=0;t<10;t++){
            ftw[i][j][f][t]=min(ftw[i][j][f][t], ftw[i][j][f][m]+ftw[i][j][m][t]);
          }
        }
      }
    }
  }
  for (int i=0;i<10;i++){
    for (int j=0;j<=i;j++){
      ll c=0;
      for (int k=0;k<n-1;k++){
        if (ftw[i][j][s[k]-'0'][s[k+1]-'0']==INF){
          c=-1;
          break;
        } else {
          c+=ftw[i][j][s[k]-'0'][s[k+1]-'0']-1;
        }
      }
      res[i][j]=res[j][i]=c;
    }
  }
  for (int i=0;i<10;i++){
    for (int j=0;j<10;j++){
      cout<<res[i][j];
      if (j!=9)cout<<' ';
    }
    cout<<'\n';
  }
}
