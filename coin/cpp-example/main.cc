#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> field(H);
  for(int i = 0; i < H; ++i){
    cin >> field[i];
  }
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for(int i = 0; i < N; ++i){
    cin >> X[i] >> Y[i];
  }
  cout << -1 << endl;
  return 0;
}
