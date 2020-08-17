#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> xs, os;
vector<pii> ap;
bool cl[2500]={false};
vector<pii> rdx;
char res[100][100]={{'\0'}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  char ci;
  for (int y=0;y<n;y++) {
    for (int x=0;x<n;x++) {
      cin>>ci;
      if (ci=='x')xs.push_back({x,y}),ap.push_back({x,y});
      else if (ci=='o')os.push_back({x,y}),ap.push_back({x,y});
    }
  }
  sort(os.begin(),os.end());
  sort(xs.begin(),xs.end());
  sort(ap.begin(),ap.end());
  for (int xi=0;xi<xs.size();xi++) {
    if (cl[xi]) continue;
    pii&x=xs[xi];
    bool f=false;
    for (int i=0;i<os.size();i++) {
      pii d{x.first-os[i].first,x.second-os[i].second};
      vector<int> tk;
      bool ok=true;
      for (int j=0;j<os.size();j++) {
        if (j==i)continue;
        pii me{os[j].first+d.first,os[j].second+d.second};
        if (me.first<n&&me.first>=0&&me.second<n&&me.second>=0&&!binary_search(ap.begin(),ap.end(),me)) {
          ok=false; break;
        }
      }
      if (ok) {
        cl[xi]=true;
        for (int j=0;j<os.size();j++) {
          if (j==i)continue;
          pii me{os[j].first+d.first,os[j].second+d.second};
          int nxi=lower_bound(xs.begin(),xs.end(),me)-xs.begin();
          if (nxi<xs.size()&&xs[i]==me) {
            cl[nxi]=true;
          }
        }
        rdx.push_back(d);
        f=true;
        break;
      }
    }
    if (!f) {
      cout<<"NO\n";
      return 0;
    }
  }
  for (pii&r:rdx) {
    res[r.second+n-1][r.first+n-1]='x';
  }
  res[n-1][n-1]='o';
  cout<<"YES\n";
  for (int y=0;y<2*n-1;y++) {
    for (int x=0;x<2*n-1;x++) {
      cout<<(res[y][x]?res[y][x]:'.')<<(x==2*n-2?"\n":"");
    }
  }
}
