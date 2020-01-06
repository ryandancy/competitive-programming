// 1277D - Let's Play the Words?
// We use a simple trie to store the set of words for O(word length) lookup.
// We need the numbers of words of form 1...0 and of form 0...1 to have difference <= 1.
// This is accomplished by flipping |# of form 1...0 - # of form 0...1|/2 of the most
// frequent one. We keep track of which can be reversed by looking each word's reversal up
// in a processing step. O(n + k)-ish where the sum of the word lengths is k.
#include <bits/stdc++.h>
using namespace std;
struct nd { nd *l0 = nullptr, *l1 = nullptr; bool eh = false; } *trie = nullptr;
string s[200000];
bool nrvb[200000];
int o=0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    trie = new nd;
    for (int i = o; i < o+n; i++) {
      cin >> s[i];
      nd *r = trie;
      for (int j = 0; j < s[i].size(); j++) {
        nd **nw = (s[i][j] == '0' ? &r->l0 : &r->l1);
        if (!*nw) *nw = new nd;
        r = *nw;
      }
      r->eh = true;
    }
    int rv[4]={0}, nr[4]={0}, t[4]={0};
    for (int i = o; i < o+n; i++) {
      int &rrv = rv[(s[i][0]-'0')*2+(s[i][s[i].size()-1]-'0')], &rnr = nr[(s[i][0]-'0')*2+(s[i][s[i].size()-1]-'0')];
      t[(s[i][0]-'0')*2+(s[i][s[i].size()-1]-'0')]++;
      nd *r = trie;
      bool v = true;
      for (int j = s[i].size()-1; j >= 0; j--) {
        nd *nw = (s[i][j] == '0' ? r->l0 : r->l1);
        if (!nw) {v = false; break;}
        r = nw;
      }
      if (v && !r->eh) v = false;
      if (v) rnr++;
      else rrv++;
      nrvb[i] = v;
    }
    int ntr = abs(t[0b10] - t[0b01]) / 2;
    if (t[0b10]==0 && t[0b01]==0 && t[0b11] != 0 && t[0b00] != 0) {
      cout << "-1\n";
      goto end;
    }
    if (abs(t[0b10] - t[0b01]) <= 1) {
      cout << "0\n\n";
      goto end;
    }
    if (t[0b10] > t[0b01]) {
      if (rv[0b10] < ntr) {
        cout << "-1\n";
        goto end;
      }
      cout << ntr << '\n';
      for (int i = 0; i < n && ntr; i++) {
        if (s[o+i][0] == '1' && s[o+i][s[o+i].size()-1] == '0' && !nrvb[o+i]) {
          cout << i+1 << ' ';
          ntr--;
        }
      }
      cout << '\n';
    } else {
      if (rv[0b01] < ntr) {
        cout << "-1\n";
        goto end;
      }
      cout << ntr << '\n';
      for (int i = 0; i < n && ntr; i++) {
        if (s[o+i][0] == '0' && s[o+i][s[o+i].size()-1] == '1' && !nrvb[o+i]) {
          cout << i+1 << ' ';
          ntr--;
        }
      }
      cout << '\n';
    }
    end:
    delete trie;
    o += n;
  }
}
