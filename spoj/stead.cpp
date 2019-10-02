// STEAD - Steady Cow Assignment
// Dinic's algorithm for maxflow + binary search
// We represent the problem as a flow graph with s and t the source and sink,
// and each cow and barn a node. s is connected to each cow with cap 1, and
// t is connected to each barn with cap of the capacity of the barn. Each cow
// is connected to their barns in an allowed preference range with cap 1.
// Then if the max flow is N (num cows), then all cows can be assigned a barn
// and the given preference range is allowed. We used Dinic's algorithm for
// max flow because it's the only one that's fast enough.
// We then binary search for the range, testing each possible preference range
// with a given size.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

#define INF 1000000
#define key(first, second) ((first)*10000+(second))
#define S 0
#define T (N+B+1)

using namespace std;

int N, B;
int cows[1000][20];
int barnCapac[20];

unordered_map<int, int> capacs; // key(node1, node2) -> capacity of edge
unordered_map<int, int> flows; // key(node1, node2) -> flow of edge
vector<int> adj[1022]; // 0 is s, 1 to N are cows, N+1 to N+B are barns, N+B+1 is t
int levels[1022];
int edgesTaken[1022];

int sendFlow(int node = S, int flow = INF) {
  if (flow == 0) return 0;
  if (node == T) return flow;
  
  while (edgesTaken[node] < adj[node].size()) {
    int neigh = adj[node][edgesTaken[node]];
    if (levels[neigh] == levels[node] + 1 && capacs[key(node, neigh)] > flows[key(node, neigh)]) {
      int minFlow = sendFlow(neigh, min(flow, capacs[key(node, neigh)] - flows[key(node, neigh)]));
      if (minFlow > 0) {
        flows[key(node, neigh)] += minFlow;
        flows[key(neigh, node)] -= minFlow;
        return minFlow;
      }
    }
    edgesTaken[node]++;
  }
  
  return 0; // no path found = no flow
}

int maxflow() {
  int maxFlow = 0;
  
  while (1) {
    // assign a level to each node with BFS
    fill(levels, levels+1022, -1);
    levels[S] = 0;
    queue<int> bfs;
    bfs.push(S);
    
    int curr;
    while (!bfs.empty()) {
      curr = bfs.front();
      bfs.pop();
      for (int& neigh : adj[curr]) {
        if (levels[neigh] == -1 && capacs[key(curr, neigh)] > flows[key(curr, neigh)]) {
          levels[neigh] = levels[curr] + 1;
          bfs.push(neigh);
        }
      }
    }
    
    if (levels[T] == -1) break;
    
    // add flow via DFS
    fill(edgesTaken, edgesTaken+1022, 0);
    int flow;
    while ((flow = sendFlow())) maxFlow += flow;
  }
  
  return maxFlow;
}

bool ok(int start, int range) {
  adj[S].clear();
  adj[T].clear();
  for (int b = 1; b <= B; b++) adj[N+b].clear(); // clear barns
  
  for (int c = 1; c <= N; c++) {
    // s to cows - capacity 1
    adj[c].clear();
    adj[S].push_back(c);
    adj[c].push_back(S);
    flows[key(S, c)] = flows[key(c, S)] = capacs[key(c, S)] = 0;
    capacs[key(S, c)] = 1;
    
    // cows to selected barns - capacity 1
    for (int pref = start; pref < start + range; pref++) {
      int b = N + cows[c-1][pref] + 1; // technically we could get rid of the -- later and skip the +1
      adj[c].push_back(b);
      adj[b].push_back(c);
      flows[key(c, b)] = flows[key(b, c)] = capacs[key(b, c)] = 0;
      capacs[key(c, b)] = 1;
    }
  }
  
  // barns to end - capacity of each barn's capacity
  for (int b = 1; b <= B; b++) {
    adj[N+b].push_back(T);
    adj[T].push_back(N+b);
    flows[key(N+b, T)] = flows[key(T, N+b)] = capacs[key(T, N+b)] = 0;
    capacs[key(N+b, T)] = barnCapac[b-1];
  }
  
  return maxflow() == N;
}

int search() {
  // binary search for the answer and see if any make it
  int lo = 0, hi = B;
  int best = B;
  while (lo < hi) {
    int range = (lo + hi) / 2; // no risk of overflow with numbers this low
    for (int start = 0; start < B - range + 1; start++) {
      if (ok(start, range)) {
        // found - too big or good
        hi = best = range;
        goto nextrange;
      }
    }
    // none found - too small
    lo = range + 1;
    nextrange:;
  }
  return best;
}

int main() {
  cin >> N >> B;
  
  for (int cow = 0; cow < N; cow++) {
    for (int pref = 0; pref < B; pref++) {
      cin >> cows[cow][pref];
      cows[cow][pref]--;
    }
  }
  
  for (int barn = 0; barn < B; barn++) {
    cin >> barnCapac[barn];
  }
  
  cout << search() << endl;
}
