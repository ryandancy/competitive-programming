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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin>>T;
  while (T--) {
    string x,y;
    cin>>x>>y;
    int a=0;
    for (int i=y.size()-1;i>=0;i--,a++){
      if (y[i]=='1'){
        break;
      }
    }
    int b=a;
    for (int i=x.size()-a-1;i>=0;i--,b++){
      if (x[i]=='1'){
        break;
      }
    }
    cout<<(b-a)<<'\n';
  }
}
