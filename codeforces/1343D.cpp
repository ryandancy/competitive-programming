#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
pll a[100000];
ll eq[500001]={0}, lm[500001]={0}, ps[500001]={0}, lw[500001]={0}, ls[500001]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    ll n,k;
    cin>>n>>k;
    fill_n(eq,2*k+2,0);
    fill_n(lm,2*k+2,0);
    fill_n(lw,2*k+2,0);
    for (int i=0;i<n/2;i++)cin>>a[i].first;
    for (int i=n/2-1;i>=0;i--)cin>>a[i].second;
    for (int i=0;i<n/2;i++) {
      if (a[i].first>a[i].second) swap(a[i].first,a[i].second);
    }
    for (int i=0;i<n/2;i++) {
      eq[a[i].first+a[i].second]++;
      lm[k+max(a[i].first,a[i].second)]++;
      lw[min(a[i].first,a[i].second)+1]++;
    }
    ps[0]=lm[0];
    for (int i=1;i<=2*k+1;i++) {
      ps[i]=ps[i-1]+lm[i];
    }
    ls[2*k+1]=lw[2*k+1];
    for (int i=2*k;i>=0;i--) {
      ls[i]=ls[i+1]+lw[i];
    }
    ll res=INF;
    for (int i=2;i<=2*k;i++) {
      res=min(res,n/2-eq[i]+ps[i-1]+ls[i+1]);
    }
    cout<<res<<'\n';
  }
}
