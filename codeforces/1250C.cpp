// cool segment tree for prefix sum stuff!
// segment tree can provide O(log n) update for finding max prefix sum
// also ONE FREAKING INT => LONG LONG cost me 3 hours and 5 submissions
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define LIM 200000
ll n,k,o;
struct prj {ll l,r,p;} rwp[200000], *plst[200000], *prst[200000];
struct node {
  ll lps, ss, lpsr, l, r;
} seg[1000000];
void cmb(ll x, ll b) {
  seg[x].ss=seg[x*2].ss+seg[x*2+1].ss;
  if ((!b||(seg[x*2].r>=b)==(seg[x*2+1].r>=b))&&seg[x*2].lps>seg[x*2+1].lps+seg[x*2].ss) {
    seg[x].lps=seg[x*2].lps;
    seg[x].lpsr=seg[x*2].lpsr;
  } else {
    seg[x].lps=seg[x*2].ss+seg[x*2+1].lps;
    seg[x].lpsr=seg[x*2+1].lpsr;
  }
}
void rmv(ll x,ll v) {
  x+=o-1;
  seg[x].lps-=v;
  seg[x].ss-=v;
  while (x/=2) cmb(x,0);
}
void bias(ll x) {
  for (ll y=x+o-1;y/=2;) cmb(y,x);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>k;
  for (ll i=0;i<n;i++) {
    cin>>rwp[i].l>>rwp[i].r>>rwp[i].p;
    plst[i]=&rwp[i];
    prst[i]=&rwp[i];
  }
  sort(plst,plst+n,[&](prj*a,prj*b){return a->l<b->l;});
  sort(prst,prst+n,[&](prj*a,prj*b){return a->r<b->r;});
  o=1;
  while (o<LIM)o*=2;
  for (ll i=0;o+i<1000000;i++) {
    seg[o+i].lps=seg[o+i].ss=-k;
    seg[o+i].l=seg[o+i].r=seg[o+i].lpsr=i+1;
  }
  for (ll i=0;i<n;i++) {
    seg[o+prst[i]->r-1].lps+=prst[i]->p;
    seg[o+prst[i]->r-1].ss+=prst[i]->p;
  }
  for (ll q=o/2;q;q/=2) {
    for (ll i=q;i<2*q;i++) {
      seg[i].l=seg[i*2].l;
      seg[i].r=seg[i*2+1].r;
      cmb(i,0);
    }
  }
  ll mxp=0,mxl=-1,mxr=-1;
  for (ll i=0;i<n;i++) {
    prj*s=plst[i];
    bias(s->l);
    ll p=seg[1].lps+k*(s->l-1);
    if (p>mxp) {
      mxp=p;
      mxl=s->l;
      mxr=seg[1].lpsr;
    }
    rmv(s->r,s->p);
  }
  if (mxp==0) {
    cout<<"0\n";
    return 0;
  }
  vector<ll> prjs;
  for (ll i=0;i<n;i++) {
    if (rwp[i].l>=mxl&&rwp[i].r<=mxr) prjs.push_back(i+1);
  }
  cout<<mxp<<' '<<mxl<<' '<<mxr<<' '<<prjs.size()<<'\n';
  for (ll i=0;i<prjs.size();i++) {
    cout<<prjs[i]<<(i==prjs.size()-1?'\n':' ');
  }
}
