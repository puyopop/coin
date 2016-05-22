#!/usr/bin/python

from random import randrange, seed

MAXH = 100
MAXW = 100
MAXN = 10
SMALLH = 10
SMALLW = 10
SMALLN = 5
TESTSET = 30
SAMPLESET = 4
CHAR = "123456789#"
seed(0)

def small(seq):
  filename = '%02d_small.in' % seq
  with open(filename, 'w') as f:
    H = randrange(1, SMALLH+1)
    W = randrange(1, SMALLW+1)
    N = randrange(1, SMALLN+1)
    print >>f, H, W
    for _ in range(H):
      print >>f, "".join(CHAR[randrange(len(CHAR))] for _ in range(W))
    print >>f, N
    visited = set()
    while N > 0:
      x, y = randrange(1, H+1), randrange(1, W+1)
      if (x, y) not in visited:
        print >>f, x, y
        visited.update([(x, y)])
        N -= 1;

def large(seq):
  filename = '%02d_large.in' % seq
  with open(filename, 'w') as f:
    H = randrange(SMALLH, MAXH+1)
    W = randrange(SMALLW, MAXW+1)
    N = randrange(SMALLN, MAXN+1)
    print >>f, H, W
    for _ in range(H):
      print >>f, "".join(CHAR[randrange(len(CHAR))] for _ in range(W))
    print >>f, N
    visited = set()
    while N > 0:
      x, y = randrange(1, H+1), randrange(1, W+1)
      if (x, y) not in visited:
        print >>f, x, y
        visited.update([(x, y)])
        N -= 1;

def sample(seq):
  outputfile = "%02d_sample.in" % seq
  inputfile = "sample/sample%02d.in" % seq
  with open(outputfile, 'w') as wf:
    with open(inputfile, 'r') as rf:
      for line in rf.readlines():
        print >>wf, line.strip()

def main():
  for i in range(SAMPLESET):
    sample(i)
  for i in range(SAMPLESET, SAMPLESET+TESTSET):
    small(i)
  for i in range(SAMPLESET+TESTSET,SAMPLESET+2*TESTSET):
    large(i)
 
if __name__ == '__main__':
  main()
