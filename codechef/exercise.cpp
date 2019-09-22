// EXERCISE - Fitness Exercises
// We treat it as a heap in order to assign values
// Written during Codechef September Cook-Off 2019
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef long double ld;
int a[1000000];
int d[1000000];
int o=0;
struct hn {
  hn* l = nullptr;
  hn* r = nullptr;
  hn* pl = nullptr;
  hn* pr = nullptr;
  int v;
  int d;
  hn() : v(0) {}
  hn(int v) : v(v) {}
  bool operator()(hn* ot1, hn* ot2) {
    return ot1->d < ot2->d;
  }
};
priority_queue<hn*, vector<hn*>, hn> q;
void ex(int N) {
  while (!q.empty()) {
    q.pop();
  }
  hn *root = new hn(a[o]);
  hn **curr = &root;
  for (int i = o; i < o+N-1; i++) {
    if (d[i] == '>') {
      hn *nu = new hn(a[i+1]);
      nu->pl = *curr;
      curr = &(*curr)->r;
      *curr = nu;
    } else if (d[i] == '<') {
      hn *nu = new hn(a[i+1]);
      nu->l = *curr;
      curr = &(*curr)->pr;
      *curr = nu;
    } else {
      if ((*curr)->v == -1) {
        (*curr)->v = a[i+1];
      } else if (a[i+1]== -1) {
        // pass 
      } else if ((*curr)->v != a[i+1]) {
        cout << "NO\n";
        return;
      }
    }
  }
  curr = &root;
  (*curr)->d = 0;
  q.push(*curr);
  while (1) {
    int pd = (*curr)->d;
    if ((*curr)->pr) {
      curr = &(*curr)->pr;
      if (!*curr) break;
      (*curr)->d = pd+1;
    } else {
      curr = &(*curr)->r;
      if (!*curr) break;
      (*curr)->d = pd-1;
    }
    q.push(*curr);
  }
  while (!q.empty()) {
    hn* c = q.top(); q.pop();
    if (c->v == -1) {
      if (!(c->pl || c->pr)) {
        c->v = INF;
      } else if (c->pl && c->pr) {
        c->v = min(c->pl->v, c->pr->v)-1;
      } else if (c->pl) {
        c->v = c->pl->v-1;
      } else {
        c->v = c->pr->v-1;
      }
    } else {
      if (c->l) {
        if (c->v <= c->l->v) {
          cout << "NO\n";
          return;
        }
      } else if (c->pl) {
        if (c->v >= c->pl->v) {
          cout << "NO\n";
          return;
        }
      }
      if (c->r) {
        if (c->v <= c->r->v) {
          cout << "NO\n";
          return;
        }
      } else if (c->pr) {
        if (c->v >= c->pr->v) {
          cout << "NO\n";
          return;
        }
      }
    }
    if (c->v < 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> a[o+i];
    }
    char c;
    for (int i = 0; i < N-1; i++) {
      cin >> c;
      d[o+i] = c;
    }
    ex(N);
    o += N;
  }
}
