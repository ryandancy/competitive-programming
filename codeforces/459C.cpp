// base conversion, O(nd)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r[1000][1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,k,d;
  cin>>n>>k>>d;
  if (n<=k){
    for (int i=0;i<d;i++){
      for (int j=1;j<=n;j++){
        cout<<j<<(j==n?"\n":" ");
      }
    }
    return 0;
  }
  if (n>1&&k==1)return cout<<"-1\n",0;
  ll p=1;
  for (int i=0;i<d&&p<n;i++,p*=k);
  if (p<n)return cout<<"-1\n",0;
  for (int i=0;i<n;i++){
    int b=i;
    for (int j=0;j<d;j++){
      r[i][j]=(b%k)+1;
      b/=k;
    }
  }
  for (int j=0;j<d;j++){
    for (int i=0;i<n;i++){
      cout<<r[i][j]<<(i==n-1?"\n":" ");
    }
  }
}
