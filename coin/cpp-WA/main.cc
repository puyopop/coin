#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cassert>
using namespace std;


int evaluate(int x, int y, int dx, int dy){
  return abs(x-dx) + abs(y-dy);
}

int a_star(vector<vector<int> > field, int H, int W, int sx, int sy, int dx, int dy){
    priority_queue<pair<pair<int, int>, pair<int, int> > > hq;
    vector<vector<bool> > visited(H, vector<bool>(W, false));
    hq.push(make_pair(make_pair(0, 0), make_pair(sx, sy)));
    while(!hq.empty()){
      pair<pair<int, int>, pair<int, int> > f_g_x_y = hq.top(); hq.pop();
      int g = f_g_x_y.first.second;
      int x = f_g_x_y.second.first;
      int y = f_g_x_y.second.second;
      if(visited[x][y]){
        continue;
      }
      if(x == dx && y == dy){
        return g;
      }      
      visited[x][y] = true;
      static const int DX[4] = {-1, 1, 0, 0};
      static const int DY[4] = {0, 0, -1, 1};
      for(int i = 0; i < 4; ++i){
        int nx = x + DX[i];
        int ny = y + DY[i];
        if(nx < 0 || H <= nx || ny < 0 || W <= ny){
          continue;
        }
        if(field[nx][ny] == -1){
          continue;
        }
        if(visited[nx][ny]){
          continue;
        }
        int gd = g + field[nx][ny];
        int fd = gd + evaluate(nx, ny, dx, dy);
        hq.push(make_pair(make_pair(-fd, gd), make_pair(nx, ny)));
      }
    }
    return -1;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int> > field(H, vector<int>(W));
  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      char c;
      cin >> c;
      if(c == '#'){
        field[i][j] = -1;
      }
      else{
        field[i][j] = c - '0';
      }
    }
  }
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for(int i = 0; i < N; ++i){
    cin >> X[i] >> Y[i];
    --X[i];
    --Y[i];
  }
  int ans = 0;
  for(int i = 0; i < (N - 1); ++i){
    int sx = X[i];
    int sy = Y[i];
    int dx = X[i+1];
    int dy = Y[i+1];
    int cost = a_star(field, H, W, sx, sy, dx, dy);
    if(cost == -1){
      ans = -1;
      break;
    }
    ans += cost;
  }
  cout << ans << endl;
}
