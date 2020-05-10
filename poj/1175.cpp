#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll A1=912746827LL, B1=994914637LL, A2=876242111LL, B2=917920657LL;
char mp[100][101];
int cmp[100][100];
bool v[100][100]={{false}};
int cw[500], ch[500];
ll hs[500][8][2]={{{0}}};
char cc[500]={'\0'};
int main() {
  for (int i=0;i<100;i++) for (int j=0;j<100;j++) cmp[i][j]=-1;
  int w, h;
  scanf("%d\n%d\n", &w, &h);
  for (int y=0;y<h;y++){
    scanf("%s\n", mp[y]);
  }
  int k=0;
  for (int iy=0;iy<h;iy++){
    for (int ix=0;ix<w;ix++){
      if (v[iy][ix]||mp[iy][ix]=='0')continue;
      stack<pii> st;
      st.push({ix,iy});
      int mnx=ix,mxx=ix,mny=iy,mxy=iy;
      while (st.size()) {
        pii xy=st.top(); st.pop();
        int &x=xy.first, &y=xy.second;
        if (v[y][x])continue;
        mnx=min(mnx,x); mxx=max(mxx,x); mny=min(mny,y); mxy=max(mxy,y);
        cmp[y][x]=k;
        v[y][x]=true;
        for (int dx=-1;dx<=1;dx++) for (int dy=-1;dy<=1;dy++) if (dx!=0||dy!=0) {
          int nx=x+dx, ny=y+dy;
          if (nx<0||nx>=w||ny<0||ny>=h||v[ny][nx]||mp[ny][nx]!='1')continue;
          st.push({nx,ny});
        }
      }
      cw[k]=mxx-mnx+1;
      ch[k]=mxy-mny+1;
      int q;
      q=0; for (int y=mny;y<=mxy;y++) for (int x=mnx;x<=mxx;x++) {
        hs[k][q][0]*=A1; hs[k][q][0]+=cmp[y][x]==k; hs[k][q][0]%=B1;
        hs[k][q][1]*=A2; hs[k][q][1]+=cmp[y][x]==k; hs[k][q][1]%=B2;
      }
      q=4; for (int y=mny;y<=mxy;y++) for (int x=mxx;x>=mnx;x--) {
        hs[k][q][0]*=A1; hs[k][q][0]+=cmp[y][x]==k; hs[k][q][0]%=B1;
        hs[k][q][1]*=A2; hs[k][q][1]+=cmp[y][x]==k; hs[k][q][1]%=B2;
      }
      q=6; for (int y=mxy;y>=mny;y--) for (int x=mnx;x<=mxx;x++) {
        hs[k][q][0]*=A1; hs[k][q][0]+=cmp[y][x]==k; hs[k][q][0]%=B1;
        hs[k][q][1]*=A2; hs[k][q][1]+=cmp[y][x]==k; hs[k][q][1]%=B2;
      }
      q=2; for (int y=mxy;y>=mny;y--) for (int x=mxx;x>=mnx;x--) {
        hs[k][q][0]*=A1; hs[k][q][0]+=cmp[y][x]==k; hs[k][q][0]%=B1;
        hs[k][q][1]*=A2; hs[k][q][1]+=cmp[y][x]==k; hs[k][q][1]%=B2;
      }
      q=5; for (int x=mnx;x<=mxx;x++) for (int y=mny;y<=mxy;y++) {
        hs[k][q][0]*=A1; hs[k][q][0]+=cmp[y][x]==k; hs[k][q][0]%=B1;
        hs[k][q][1]*=A2; hs[k][q][1]+=cmp[y][x]==k; hs[k][q][1]%=B2;
      }
      q=1; for (int x=mnx;x<=mxx;x++) for (int y=mxy;y>=mny;y--) {
        hs[k][q][0]*=A1; hs[k][q][0]+=cmp[y][x]==k; hs[k][q][0]%=B1;
        hs[k][q][1]*=A2; hs[k][q][1]+=cmp[y][x]==k; hs[k][q][1]%=B2;
      }
      q=3; for (int x=mxx;x>=mnx;x--) for (int y=mny;y<=mxy;y++) {
        hs[k][q][0]*=A1; hs[k][q][0]+=cmp[y][x]==k; hs[k][q][0]%=B1;
        hs[k][q][1]*=A2; hs[k][q][1]+=cmp[y][x]==k; hs[k][q][1]%=B2;
      }
      q=7; for (int x=mxx;x>=mnx;x--) for (int y=mxy;y>=mny;y--) {
        hs[k][q][0]*=A1; hs[k][q][0]+=cmp[y][x]==k; hs[k][q][0]%=B1;
        hs[k][q][1]*=A2; hs[k][q][1]+=cmp[y][x]==k; hs[k][q][1]%=B2;
      }
      k++;
    }
  }
  char ccc='a';
  for (int i=0;i<k;i++){
    if (cc[i])continue;
    cc[i]=ccc;
    for (int j=i+1;j<k;j++){
      if (cc[j]) continue;
      if (cw[i]==cw[j]&&ch[i]==ch[j]) {
        for (int m=0;m<=6;m+=2) {
          if (hs[i][0][0]==hs[j][m][0]&&hs[i][0][1]==hs[j][m][1]) {
            cc[j]=ccc;
            goto nx;
          }
        }
      }
      if (cw[i]==ch[j]&&ch[i]==cw[j]) {
        for (int m=1;m<=7;m+=2) {
          if (hs[i][0][0]==hs[j][m][0]&&hs[i][0][1]==hs[j][m][1]) {
            cc[j]=ccc;
            goto nx;
          }
        }
      }
      nx:;
    }
    ccc++;
  }
  for (int y=0;y<h;y++){
    for (int x=0;x<w;x++){
      if (mp[y][x]=='1') {
        mp[y][x]=cc[cmp[y][x]];
      }
    }
    printf("%s\n", mp[y]);
  }
}
