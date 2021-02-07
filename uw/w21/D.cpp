#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;
#define T n
#define B (n+1)
ld l,w; ll n;
pll po[100];
ld c[102][102];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>l>>w>>n;
  for (int i=0;i<n;i++)cin>>po[i].first>>po[i].second;
  c[T][B]=c[B][T]=w;
  for (int i=0;i<n;i++) {
    ld x=po[i].first,y=po[i].second;
    c[i][T]=c[T][i]=y;
    c[i][B]=c[B][i]=w-y;
    for (int j=i;j<n;j++) {
      c[i][j]=c[j][i]=sqrtl((x-po[j].first)*(x-po[j].first)+(y-po[j].second)*(y-po[j].second))/2.0l;
    }
  }
  for (int k=0;k<=B;k++) {
    for (int i=0;i<=B;i++) {
      for (int j=0;j<=B;j++) {
        c[i][j]=min(c[i][j],max(c[i][k],c[k][j]));
      }
    }
  }
  cout<<setprecision(20)<<c[T][B]<<'\n';
}
