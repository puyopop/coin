#!/usr/bin/python

import re
import sys

MAXH = 100
MAXW = 100
MAXN = 10


def main():
  m = re.match(r'^(\d+) (\d+)\n', sys.stdin.readline())
  assert m, 'Does not match with regexp'
  H, W = map(int, m.groups())
  assert 1 <= H <= MAXH, "H out of range: {}".format(H)
  assert 1 <= W <= MAXW, "W out of range: {}".format(W)
  for i in range(H):
    line = sys.stdin.readline().strip() ###
    assert len(line) == W, "len(line) != W: len(line_{}) != {}".format(i, W)
    for c in line:
      assert c in "123456789#", 'value error: line_{}'.format(i)
  m = re.match(r'^(\d+)\n', sys.stdin.readline())
  assert m, 'Does not match with regexp'
  N = map(int, m.groups())[0]
  for i in range(N):
    m = re.match(r'^(\d+) (\d+)\n', sys.stdin.readline())
    print >>sys.stderr, m
    assert m, 'Does not match with regexp'
    x, y = map(int, m.groups())
    assert 1 <= x <= H, "x out of range: {}".format(x)
    assert 1 <= y <= W, "y out of range: {}".format(y)

if __name__ == '__main__':
  main()
