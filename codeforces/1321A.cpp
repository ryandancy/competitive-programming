#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[100], b[100];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  for (int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  int ac=0,bc=0;
  for (int i=0;i<n;i++)if(a[i]!=b[i]){if(a[i]==1)ac++;else if(b[i]==1)bc++;}
  if (ac==0)return cout<<"-1\n",0;
  if (bc<ac)return cout<<"1\n",0;
  cout<<max(0,(bc-ac+1)/ac+((bc-ac+1)%ac!=0))+1<<endl;
}
