// Some facts:
// - I implemented this solution from the editorial
// - This solution fails repeatedly on test 15
// - Testing with an O(k log k) "brute force" algorithm can't find a case where they differ
// - Therefore I have given up
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
ll a[100000], bv[100000]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n, k;
  cin>>n>>k;
  ll mx=0;
  for (int i=0;i<n;i++)cin>>a[i], mx=max(mx, a[i]);
  ll l=-3*mx*mx, r=mx;
  while (l<=r) {
    ll m=l+(r-l)/2.0l;
    ll uk=0;
    for (int i=0;i<n;i++){
      if (m>=a[i]-1) continue;
      ll b=(ll)min(floorl(0.5l+sqrtl((ld)(-3.0l+12.0l*(ld)a[i]-12.0l*(ld)m))/6.0l),(ld)a[i]);
      uk+=b;
    }
    if (k<uk) {
      l=m+1;
    } else {
      r=m-1;
    }
  }
  ll A=l+20;
  ll v=0;
  for (int i=0;i<n;i++) {
    if (A>=a[i]-1)continue;
    ll b=(ll)min(floorl(0.5l+sqrtl((ld)(-3.0l+12.0l*(ld)a[i]-12.0l*(ld)A))/6.0l),(ld)a[i]);
    v+=b;
    bv[i]=b;
  }
  priority_queue<pii> pq;
  for (int i=0;i<n;i++){
    pq.push({a[i]-3*(bv[i]+1)*(bv[i]+1)+3*(bv[i]+1)-1, i});
  }
  while (v<k) {
    int i;
    tie(ignore, i)=pq.top(); pq.pop();
    if (bv[i]==a[i])continue;
    bv[i]++, v++;
    pq.push({a[i]-3*(bv[i]+1)*(bv[i]+1)+3*(bv[i]+1)-1, i});
  }
  for (int i=0;i<n;i++){
    cout<<bv[i]<<(i==n-1?'\n':' ');
  }
}
