// Idea: Since there's only 10 lever types, we can do an O(n^2) BFS for each of the
// 2^10 combinations using a bitset to keep track. Initially, we BFS from the @ (keeping track
// of distance travelled in all the BFSes in the qv/vl variables) and every time we
// come across a lever that adds to the bitset, queue up a BFS starting point for that bitset
// (as we BFS each bitset in increasing order).
// Issue: doing this BFS requires that vl (distance travelled) be nondecreasing, which doesn't
// happen if we use a normal queue, and priority queues (either one big or many small) gives
// (let k = 10 be the number of lever types) a time complexity of O(2^k n^2 log(2^k n^2))
// which is too slow. Thus we use a "pre-queue" linked list to store the starting points we
// add, sort it at the beginning of each bitset, and MacGyver our own psuedo-priority queue
// by inserting into the main queues when they would become unsorted.
// Time complexity: O(2^k n^2) where k=10 is the number of distinct lever types.
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
string mp[200];
bool v[1<<10][200][200]={{{false}}};
list<tuple<int, int, int>> pq[1<<10];
queue<int> qx[1<<10], qy[1<<10], qv[1<<10];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=0;i<n;i++)cin>>mp[i];
  int sx=-1, sy;
  for (int y=0;y<n;y++){
    for (int x=0;x<n;x++){
      if (mp[y][x]=='@') {
        sx=x, sy=y;
        break;
      }
    }
    if (sx!=-1)break;
  }
  pq[0].push_back({0,sx,sy});
  int res=INF;
  int cnt=0;
  for (int b=0;b<(1<<10);b++){
    if (pq[b].size()) {
      pq[b].sort();
      int av, x, y;
      tie(av, x, y) = pq[b].front();
      pq[b].pop_front();
      qv[b].push(av), qx[b].push(x), qy[b].push(y);
    }
    while (qx[b].size()) {
      int vl=qv[b].front(), x=qx[b].front(), y=qy[b].front();
      qv[b].pop(), qx[b].pop(), qy[b].pop();
      cnt++;
      if (v[b][y][x])continue;
      v[b][y][x]=true;
      char c=mp[y][x];
      if (c=='#')continue;
      if (c=='$') {
        res=min(res,vl);
      }
      if (c>='A'&&c<='J') {
        int i=c-'A';
        if ((b&(1<<i))==0)continue;
      }
      if (c>='a'&&c<='j') {
        int i=c-'a';
        if ((b&(1<<i))==0){
          pq[b|(1<<i)].push_back({vl,x,y});
        }
      }
      for (int mx=-1;mx<=1;mx++){
        for (int my=-1;my<=1;my++){
          if ((mx&&my)||(!mx&&!my))continue;
          int nx=x+mx, ny=y+my;
          if (nx<0||nx>=n||ny<0||ny>=n)continue;
          char nc=mp[ny][nx];
          if (v[b][ny][nx]||nc=='#')continue;
          if (nc>='A'&&nc<='J') {
            int i=nc-'A';
            if ((b&(1<<i))==0)continue;
          }
          while (pq[b].size() && get<0>(pq[b].front())==vl) {
            int av, ax, ay;
            tie(av, ax, ay) = pq[b].front();
            pq[b].pop_front();
            qv[b].push(av), qx[b].push(ax), qy[b].push(ay);
          }
          qx[b].push(nx);
          qy[b].push(ny);
          qv[b].push(vl+1);
        }
      }
    }
  }
  if (res==INF)cout<<"IMPOSSIBLE\n";
  else cout<<res<<'\n';
}
