#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool dp[100001]={false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
    for (ll b=0;b<(1<<6);b++) {
        ll d=0;
        for (ll k=6;k>=0;k--) {
            d*=10;
            if (b&(1<<k)) d++;
        }
        dp[d]=true;
    }
    for (ll x=0;x<=100000;x++) {
        if (!dp[x]) continue;
        for (ll b=0;b<(1<<6);b++) {
            ll d=0;
            for (ll k=6;k>=0;k--) {
                d*=10;
                if (b&(1<<k)) d++;
            }
            if (x*d<=100000) dp[x*d]=true;
            else break;
        }
    }
    ll t;
    cin>>t;
    while (t--) {
        ll n;
        cin>>n;
        if (dp[n]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
