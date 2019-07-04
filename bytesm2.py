#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""BYTESM2 - Philosophers Stone"""

# The optimal path is reversible, so we process as if the back was the first row.
# We assign a value to each cell depending on the maximum number of stones collectible from
# that position and iterate backwards.

# Note: the problem on SPOJ accepts only Python 2.7, so just replace all input() calls with raw_input()

def do():
  h, w = map(int, input().split())
  #stones = [list(map(int, raw_input().split())) for _ in range(h)]
  raw_stones = []
  while len(raw_stones) < h*w:
    raw_stones += list(map(int, input().split()))
  stones = [raw_stones[w*x:w*x+w] for x in range(h)]
  collectible = [[0 for _ in range(w)] for _ in range(h)]
  collectible[0] = stones[0]
  
  for y in range(1, h):
    for x in range(w):
      stone = stones[y][x]
      if x == 0:
        collectible[y][x] = stone + max(collectible[y-1][x:x+2]) # x and x+1
      elif x == w - 1:
        collectible[y][x] = stone + max(collectible[y-1][x-1:x+1]) # x-1 and x
      else:
        collectible[y][x] = stone + max(collectible[y-1][x-1:x+2]) # x-1, x, x+1
  
  print(max(collectible[-1]))

if __name__ == '__main__':
  cases = int(input())
  for _ in range(cases):
    do()
