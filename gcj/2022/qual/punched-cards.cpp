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
char PC[50][50];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll t;
  cin>>t;
  for (int C=1;C<=t;C++) {
    ll r, c;
    cin>>r>>c;
    cout<<"Case #"<<C<<":\n";
    for (int i = 0; i < 2*c+1; i++) {
      for (int j = 0; j < 2*r+1; j++) {
        if (j%2==0) PC[i][j] = (i%2==0)?'+':'-';
        else PC[i][j] = (i%2==0)?'|':'.';
      }
    }
    PC[0][0]='.';
    PC[1][0]='.';
    PC[0][1]='.';
    for (int j=0;j<2*r+1;j++) {
      for (int i=0;i<2*c+1;i++) {
        cout<<PC[i][j];
      }
      cout<<'\n';
    }
  }
}
