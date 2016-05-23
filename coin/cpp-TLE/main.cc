#include <iostream>
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
int dp[1 << MAXN];
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
  // debug();

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

  // debug_table();

  REP(bit, (1<<N)){    
    dp[bit] = INF;
  }
  REP(i, N){
    dp[1<<i] = 0;
  }
  REP(bit, (1<<N)){    
    REP(s, N){
      if(((bit >> s) & 1) == 0){
        continue;
      }
      REP(d, N){
        dp[bit|(1 << d)] = min(dp[bit|(1 << d)], dp[bit] + table[X[s]][Y[s]][X[d]][Y[d]]);
      }
    }
  }
  // cout << "N=" << N << endl;
  // REP(bit, (1 << N)){
  //   cout << bit << ": " << dp[bit] << endl;
  // }
  int ans = dp[(1 << N) - 1];
  if(ans >= INF){
    cout << -1 << endl;
  }
  else{
    cout << dp[(1 << N) - 1] << endl;
  }
  return 0;
}
