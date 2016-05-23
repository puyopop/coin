#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;
const int MAXH = 100;
const int MAXW = 100;
const int MAXN = 14;
const int INF = 1 << 22;
const int DX[4] = {-1, 1, 0, 0};
const int DY[4] = {0, 0, -1, 1};

int field[MAXH][MAXW];
int table[MAXH][MAXW][MAXH][MAXW];
int X[MAXN];
int Y[MAXN];
int H, W, N;

int main() {
  cin >> H >> W;
  REP(i, H){
    REP(j, W){
      char c;
      cin >> c;
      if(c == '#'){
        field[i][j] = INF;
      }
      else{
        field[i][j] = c - '0';
      }
    }
  }
  cin >> N;
  REP(i, N){
    cin >> X[i] >> Y[i];
    --X[i];
    --Y[i];
  }

  REP(a, H){
    REP(b, W){
      REP(c, H){
        REP(d, W){
          table[a][b][c][d] = INF;
        }
      }
    }
  }

  REP(x, H){
    REP(y, W){
      REP(i, 4){
        int nx = x + DX[i];
        int ny = y + DY[i];
        if(nx < 0 || H <= nx || ny < 0 || W <= ny){
          continue;
        }
        table[x][y][nx][ny] = field[nx][ny];
      }
    }
  }
  
  REP(a, H){
    REP(b, W){
      REP(c, H){
        REP(d, W){
          REP(e, H){
            REP(f, W){              
              table[c][d][e][f] = min(table[c][d][e][f], table[c][d][a][b] + table[a][b][e][f]);
            }
          }
        }
      }
    }
  }

  int ans = INF;
  vector<int> perm(N);
  for(int i = 0; i < N; ++i){
    perm[i] = i;
  }
  do{
    int tmp = 0;    
    for(int i = 0; i < (N - 1); ++i){
      int from = perm[i];
      int to = perm[i+1];
      tmp += table[X[from]][Y[from]][X[to]][Y[to]];
    }
    ans = min(ans, tmp);
  }while(next_permutation(perm.begin(), perm.end()));

  if(ans >= INF){
    cout << -1 << endl;
  }
  else{
    cout << ans << endl;
  }
  return 0;
}
