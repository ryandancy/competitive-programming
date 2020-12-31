#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin>>T;
  while (T--) {
    cin>>n;
    for (int i=0;i<n;i++)cin>>x[i];
    x[n-1]++;
    for (int i=n-2;i>=0;i--) {
      if (x[i+1]>x[i]+1) {
        x[i]++;
      }
    }
    sort(x,x+n);
    int uq=1;
    for (int i=1;i<n;i++) {
      if (x[i]!=x[i-1])uq++;
    }
    cout<<uq<<'\n';
  }
}
