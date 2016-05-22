#!/usr/bin/python

import heapq
import sys

if sys.version_info[0] == 2:
  input = raw_input

DX = (-1, 1, 0, 0)
DY = (0, 0, -1, 1)
INF = float("inf")
H, W = list(map(int, input().split()))
FIELD = [input() for _ in range(H)]
N = int(input())
XY = [(lambda x: (int(x[0])-1, int(x[1])-1))(input().split()) for _ in range(N)]

def djikstra(startx_starty):
  startx, starty = startx_starty
  costs = [[INF] * W for _ in range(H)]
  hq = [(0, startx, starty)]
  while hq:
    c, x, y = heapq.heappop(hq)
    if costs[x][y] is not INF:
      continue    
    costs[x][y] = c
    costs[x][y] = c
    for dx, dy in zip(DX, DY):
      nx, ny = x + dx, y + dy
      if not(0 <= nx < H and 0 <= ny < W):
        continue
      if FIELD[nx][ny] == "#":
        continue
      if costs[nx][ny] is not INF:
        continue
      heapq.heappush(hq, (c + int(FIELD[nx][ny]), nx, ny))
  return [costs[x][y] for x, y in XY]

table = list(map(djikstra, XY))
# print(*table, sep="\n")
dp = [INF] * (1 << N)
for i in range(N):
  dp[1 << i] = 0
for bit in range(1 << N):
  for s in range(N):
    if ((bit >> s) & 1) == 0:
      continue
    for d in range(N):
      if ((bit >> d) & 1):
        continue
      dp[bit | (1 << d)] = min(dp[bit | (1 << d)], dp[bit] + table[s][d])
print(dp[(1 << N) - 1] if dp[(1 << N) - 1] < INF else -1)



    
    
    
            


