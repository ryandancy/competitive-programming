// 676D - Theseus and labyrinth
// The idea is to transform this into a classical shortest-path question by
// splitting each block into four vertices, one for each orientation. We connect
// everything appropriately for the four orientations and then run Djikstra's algorithm.
// This was a super annoying implementation.
#include <bits/stdc++.h>
using namespace std;
typedef pair<ll, ll> pll;
int R, C;
int m[1000][1000]; // URDL
vector<int> G[4000000]; // 0123 rotations CW
bool v0[4000000]={false};
#define k(i,j,x) (4*(C*(i)+(j))+(x))
#define DU 0b1000
#define DR 0b0100
#define DD 0b0010
#define DL 0b0001
int ri, ci, rf, cf;
ll dj(int s, bool v[]) {
  int e = k(rf,cf,0);
  priority_queue<pll> q;
  q.push({0,s});
  while (!q.empty()) {
    const pll p = q.top(); q.pop();
    ll d = -p.first, x = p.second;
    if (x>=e && x<=e+3) {
      return d;
    }
    int nx = x - x%4 + ((x%4)+1)%4;
    if (!v[nx]) {q.push({-d-1,nx}); v[nx] = true;}
    for (int g : G[x]) {
      if (!v[g]) {q.push({-d-1,g}); v[g] = true;}
    }
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> C;
  char c;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> c;
      switch (c) {
        case '+': m[i][j] = DU|DR|DD|DL; break;
        case '-': m[i][j] = DL|DR; break;
        case '|': m[i][j] = DU|DD; break;
        case '^': m[i][j] = DU; break;
        case '>': m[i][j] = DR; break;
        case 'v': m[i][j] = DD; break;
        case '<': m[i][j] = DL; break;
        case 'U': m[i][j] = DR|DL|DD; break;
        case 'R': m[i][j] = DU|DL|DD; break;
        case 'D': m[i][j] = DU|DL|DR; break;
        case 'L': m[i][j] = DU|DR|DD; break;
        case '*': m[i][j] = 0; break;
        default: 1/0;
      }
    }
  }
  cin >> ri >> ci >> rf >> cf;
  ri--; rf--; ci--; cf--;
  if (ri == rf && ci == cf) return cout << "0\n", 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (j < C-1) {
        if ((m[i][j] & DR) && (m[i][j+1] & DL)) {
          G[k(i,j,0)].push_back(k(i,j+1,0));
          G[k(i,j+1,0)].push_back(k(i,j,0));
        }
        if ((m[i][j] & DU) && (m[i][j+1] & DD)) {
          G[k(i,j,1)].push_back(k(i,j+1,1));
          G[k(i,j+1,1)].push_back(k(i,j,1));
        }
        if ((m[i][j] & DL) && (m[i][j+1] & DR)) {
          G[k(i,j,2)].push_back(k(i,j+1,2));
          G[k(i,j+1,2)].push_back(k(i,j,2));
        }
        if ((m[i][j] & DD) && (m[i][j+1] & DU)) {
          G[k(i,j,3)].push_back(k(i,j+1,3));
          G[k(i,j+1,3)].push_back(k(i,j,3));
        }
      }
      if (i < R-1) {
        if ((m[i][j] & DD) && (m[i+1][j] & DU)) {
          G[k(i,j,0)].push_back(k(i+1,j,0));
          G[k(i+1,j,0)].push_back(k(i,j,0));
        }
        if ((m[i][j] & DR) && (m[i+1][j] & DL)) {
          G[k(i,j,1)].push_back(k(i+1,j,1));
          G[k(i+1,j,1)].push_back(k(i,j,1));
        }
        if ((m[i][j] & DU) && (m[i+1][j] & DD)) {
          G[k(i,j,2)].push_back(k(i+1,j,2));
          G[k(i+1,j,2)].push_back(k(i,j,2));
        } 
        if ((m[i][j] & DL) && (m[i+1][j] & DR)) {
          G[k(i,j,3)].push_back(k(i+1,j,3));
          G[k(i+1,j,3)].push_back(k(i,j,3));
        }
      }
    }
  }
  int s = k(ri,ci,0);
  ll r = dj(s,v0);
  cout << r << "\n";
}
