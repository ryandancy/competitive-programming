// 550C - Divisibility by Eight
// Note that since 1000 % 8 == 0, we only care about a 3-digit subset divisible by 8
// We pregenerate a trie of the digits of all numbers < 1000 divisible by 8
// We then iterate through the input string and keep track of the points in the trie
// that we've seen thus far, outputting if we reach an endpoint
// We *could* remove items from looking (the vector<int> to keep track of the points)
// if all their children have been visited, but that sounds like extra code
// This solution gives worst-case O(n^2), but n<=100 so that is fine

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int trie[10000][10] = {{0}};
int en[10000];
bool visited[10000][10] = {{false}};

void gen() {
  fill_n(en, 10000, -1);
  int id = 1;
  for (int x = 0; x < 1000; x += 8) {
    string r = to_string(x);
    int l = 0;
    for (unsigned i = 0; i < r.length(); i++) {
      int n = r[i]-'0';
      if (trie[l][n]) {
        l = trie[l][n];
      } else {
        trie[l][n] = id;
        l = id;
        id++;
      }
    }
    en[l] = x;
  }
}

int main() {
  gen();
  
  string s;
  cin >> s;
  
  vector<int> looking(1);
  looking.push_back(0);
  
  for (char c : s) {
    int n = c-'0';
    int ls = looking.size(); // here since looking's size changes, but we want to loop only over original
    for (int i = 0; i < ls; i++) {
      int id = looking[i];
      if (trie[id][n] && !visited[id][n]) {
        visited[id][n] = true;
        if (en[trie[id][n]] != -1) {
          cout << "YES\n" << en[trie[id][n]] << "\n";
          return 0;
        } else {
          looking.push_back(trie[id][n]);
        }
      }
    }
  }
  
  cout << "NO\n";
}
