#include <iostream>
#include <queue>
#include <map>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;

typedef pair<int, pair<int, int> > PII;
typedef vector<int> VI;
typedef vector<VI> VII;

const int MAXH = 100;
const int MAXW = 100;
const int MAXN = 10;
const int INF = 1 << 22;
const int DX[4] = {-1, 1, 0, 0};
const int DY[4] = {0, 0, -1, 1};

int field[MAXH][MAXW];
int table[MAXH][MAXW][MAXH][MAXW];
int X[MAXN];
int Y[MAXN];
int dp[1 << MAXN];
int H, W, N;

VI pickup(VII costs){
  VI ret;
  REP(i, N){
    ret.push_back(costs[X[i]][Y[i]]);
  }
  return ret;
}

VII dijkstra(int startx, int starty){
  VII costs(H, VI(W, INF));
  priority_queue<PII> hq;
  hq.push(make_pair(0, make_pair(startx, starty)));
  while(!hq.empty()){
    PII c_x_y = hq.top(); hq.pop();
    int c = -c_x_y.first;
    int x = c_x_y.second.first;
    int y = c_x_y.second.second;
    if(costs[x][y] < INF){
      continue;
    }
    costs[x][y] = c;
    REP(i, 4){
      int nx = x + DX[i];
      int ny = y + DY[i];
      if(nx < 0 || H <= nx || ny < 0 || W <= ny){
        continue;
      }
      if(field[nx][ny] >= INF){
        continue;
      }
      if(costs[nx][ny] < INF){
        continue;
      }
      int tmp = c + field[nx][ny];  
      hq.push(make_pair(-tmp, make_pair(nx, ny)));
    }
  }
  return costs;
}

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
  
  VII costs;
  REP(i, N){
    costs.push_back(pickup(dijkstra(X[i], Y[i])));
  }

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
        dp[bit|(1 << d)] = min(dp[bit|(1 << d)], dp[bit] + costs[s][d]);
      }
    }
  }
  int ans = dp[(1 << N) - 1];
  if(ans >= INF){
    cout << -1 << endl;
  }
  else{
    cout << ans << endl;
  }
  return 0;
}
