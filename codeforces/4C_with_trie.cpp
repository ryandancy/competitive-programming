// 4C - Registration system
// A trie isn't necessary but let's implement one for practice, also with c-strings for fun
// This solution is marginally faster than the one in 4C.cpp

#include <iostream>
#include <cstring>

using namespace std;

struct node {
  int ends = 0; // number ended here
  node* children[26] = {nullptr};
  ~node() {
    for (node* child : children) {
      delete child;
    }
  }
};

node* root = new node;

int main() {
  int n;
  cin >> n;
  cin.ignore(256, '\n');
  
  char buff[50], intbuff[10];
  for (int t = 0; t < n; t++) {
    cin.getline(buff, 35);
    node** curr = &root;
    for (int i = 0; buff[i] && i < 50; i++) {
      curr = &(*curr)->children[buff[i]-'a'];
      if (!*curr) { *curr = new node; }
    }
    if ((*curr)->ends) {
      snprintf(intbuff, sizeof(intbuff), "%d", (*curr)->ends);
      printf(buff);
      printf(intbuff);
      printf("\n");
    } else {
      printf("OK\n");
    }
    (*curr)->ends++;
  }
  
  delete root;
}
