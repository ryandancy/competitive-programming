#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100001], b[100001], av=0,n,m,q;
ll bj[100001],nbj[100001];
void pm() {
  ll*ba=lower_bound(bj,bj+m-n+1,-av);
  ll*bb=lower_bound(nbj,nbj+m-n+1,av);
  ll res;
  if (ba==bj+m-n+1) res=abs(av-*bb);
  else if (bb==nbj+m-n+1) res=abs(av+*ba);
  else res=min(abs(av-*bb),abs(av+*ba));
  cout<<res<<"\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m>>q;
  for (int i=1;i<=n;i++)cin>>a[i];
  for (int i=1;i<=m;i++)cin>>b[i];
  bool ls;
  for (int i=1;i<=n;i++) {
    if (i%2) bj[0]-=b[i],ls=false;
    else bj[0]+=b[i],ls=true;
  }
  for (int j=1;j<=m-n;j++) {
    bj[j]=-bj[j-1]-b[j]+(ls?1:-1)*b[j+n];
  }
  for (int j=0;j<=m-n;j++)nbj[j]=-bj[j];
  sort(bj,bj+m-n+1);
  sort(nbj,nbj+m-n+1);
  for (int i=1;i<=n;i++) {
    if (i%2) av+=a[i];
    else av-=a[i];
  }
  pm();
  while (q--) {
    ll l,r,x;
    cin>>l>>r>>x;
    if (l%2==r%2) {
      if (l%2) av+=x;
      else av-=x;
    }
    pm();
  }
}
