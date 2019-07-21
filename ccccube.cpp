// CCCCUBE - Cube

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int n;
char cube[12][12][12]; // cube[z][y][x]
char cube2[12][12][12];
int canSeparate[12][12][12][6]; // [z][y][x][id]: -1 if unknown, 0 or 1 if known
bool visited[12][12][12];
vector<tuple<int, int, int>> samePiece;

void drag(int x, int y, int z, int dx, int dy, int dz) {
  if (x == 0 || x == n+1 || y == 0 || y == n+1 || z == 0 || z == n+1) return;
  
  if (visited[z][y][x]) return;
  visited[z][y][x] = true;
  
  int nx = x+dx, ny=y+dy, nz=z+dz;
  char ch = cube[z][y][x];
  cube2[nz][ny][nx] = ch;
  
  drag(nx, ny, nz, dx, dy, dz);
  if (cube[z][y][x+1] == ch) drag(x+1, y, z, dx, dy, dz);
  if (cube[z][y][x-1] == ch) drag(x-1, y, z, dx, dy, dz);
  if (cube[z][y-1][x] == ch) drag(x, y-1, z, dx, dy, dz);
  if (cube[z][y+1][x] == ch) drag(x, y+1, z, dx, dy, dz);
  if (cube[z-1][y][x] == ch) drag(x, y, z-1, dx, dy, dz);
  if (cube[z+1][y][x] == ch) drag(x, y, z+1, dx, dy, dz);
}

bool trySeparate(int x, int y, int z, int dx, int dy, int dz, int id) {
  for (int a = 0; a <= n+1; a++) {
    for (int b = 0; b <= n+1; b++) {
      for (int c = 0; c <= n+1; c++) {
        cube2[a][b][c] = '\0';
        visited[a][b][c] = false;
      }
    }
  }
  
  drag(x, y, z, dx, dy, dz);
  
  for (int z = dz+1; z <= dz+n; z++) {
    for (int y = dy+1; y <= dy+n; y++) {
      for (int x = dx+1; x <= dx+n; x++) {
        if (!cube2[z][y][x]) {
          return true;
        }
      }
    }
  }
  
  return false;
}

bool isStable() {
  for (int a = 1; a <= n; a++) {
    for (int b = 1; b <= n; b++) {
      if (trySeparate(1, a, b, -1, 0, 0, 0) || trySeparate(n, a, b, 1, 0, 0, 1)
          || trySeparate(a, 1, b, 0, -1, 0, 2) || trySeparate(a, n, b, 0, 1, 0, 3)
          || trySeparate(a, b, 1, 0, 0, -1, 4) || trySeparate(a, b, n, 0, 0, 1, 5)) {
        return false;
      }
    }
  }
  
  return true;
}

int main() {
  while (1) {
    cin >> n;
    if (!n) break;
    cin.ignore(256, '\n');
    
    for (int a = 0; a <= n+1; a++) {
      for (int b = 0; b <= n+1; b++) {
        for (int c = 0; c <= n+1; c++) {
          cube[a][b][c] = '\0';
        }
      }
    }
    
    for (int z = 1; z <= n; z++) {
      cin.ignore(256, '\n'); // waste empty line
      for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
          cube[z][y][x] = cin.get();
        }
        cin.ignore(256, '\n');
      }
    }
    
    cin.ignore(256, '\n');
    
    cout << (isStable() ? "Yes" : "No") << endl;
  }
}
