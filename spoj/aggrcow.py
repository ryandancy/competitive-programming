#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""AGGRCOW - Aggressive Cows"""

def do(): # O(n log n)
  num_stalls, num_cows = map(int, input().split())
  stalls = [int(input()) for _ in range(num_stalls)]
  stalls.sort()
  
  stall_dists = [stall2 - stall1 for stall1, stall2 in zip(stalls, stalls[1:])]
  
  def can_be_min_dist(dist):
    # just place them at the min dist or greater along the stalls
    cows_left = num_cows - 1
    current_dist = 0
    for stall_dist in stall_dists:
      if stall_dist + current_dist >= dist:
        cows_left -= 1
        current_dist = 0
        if cows_left == 0:
          return True
      else:
        current_dist += stall_dist
    return False
  
  # binary search over possible range of minimum distances
  # we want to find the maximum distance that can possibly be a minimum distance
  # so we want the case where dist can be a min dist but dist+1 can't
  # the possible minimum distances range from 1 to stalls[-1] - stalls[0]
  a = 1
  b = stalls[-1] - stalls[0]
  while a <= b:
    dist = (a + b) // 2
    this_can_be = can_be_min_dist(dist)
    next_can_be = can_be_min_dist(dist + 1)
    if this_can_be and not next_can_be:
      print(dist)
      break
    elif this_can_be: # too low
      a = dist
    else: # next_can_be; too high
      b = dist
  else:
    print(1) # shouldn't happen

if __name__ == '__main__':
  cases = int(input())
  for _ in range(cases):
    do()
