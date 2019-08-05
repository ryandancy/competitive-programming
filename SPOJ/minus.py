#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""MINUS - Minus Operation"""

'''
The idea is to find an array of "+" and "-" that can be inserted into the array
as such: 4 - 5 + 2 - 5 - 6 + 3 ... such that this equals the goal value.

Note that we fix the first two elements of the array as (+, -), using the first
as a prefix (we add the first value) and observing that there is no way we could
possibly cancel out subtractions so as not to subtract the second value.

We do this using dynamic programming. We initialize an array, dp, with dictionaries
such that dp[n][m] is the (+, -, ...) pattern to create m using the first n elements
of the array, or False if m cannot be created. We then work backwards: for each
subproblem, we find whether the goal can be found using a plus, then a minus, then
we give up and assign False. This algorithm is fast enough for our purposes.

We then transform the (+, -, ...) pattern into a series of subtractions using a series
of steps:
1) For each (+, -) pair after the initial (+, -), we output the index of the "+" in order
   to fold the "-" into the "+" subtracted.
2) We fold any "-"s directly after the initial (+, -) pair into the initial "+" by outputting
   "1" repeatedly. The initial (+, -) pair is maintained.
3) The pattern now looks like (+, -, +, +, +, ...). We output "2" enough times to fold all "+"s
   into the "-".
4) We output "1" to fold the "-" into the "+".

This is sufficient to solve the problem.
'''

def path_to(seq, total_goal):
  # dp[max index of furthest int using] -> {goal: [plus/minus pattern] or False}
  # True is +, False is - in plus/minus pattern; False returned = impossible
  dp = [{} for _ in range(len(seq))]
  
  first_minus_last = seq[0] - seq[1] # first two guaranteed to be [+, -]
  
  def find_plus_minus_pattern(front, goal):
    if front == 1:
      return [True, False] if goal == first_minus_last else False
    if goal in dp[front]:
      return dp[front][goal]
    
    # find with +
    plus_res = find_plus_minus_pattern(front - 1, goal - seq[front])
    if plus_res:
      res = [*plus_res, True]
      dp[front][goal] = res
      return res
    
    # find with -
    minus_res = find_plus_minus_pattern(front - 1, goal + seq[front])
    if minus_res:
      res = [*minus_res, False]
      dp[front][goal] = res
      return res
    
    # no possible pattern
    dp[front][goal] = False
    return False
  
  pm_pattern = find_plus_minus_pattern(len(seq) - 1, total_goal)
  
  # We must now convert the plus/minus pattern into a list of indices to take out
  # For each minus following a plus AFTER the initial [plus, minus], we fold it into the preceding plus
  result = []
  while True:
    for i, (prev, nxt) in enumerate(zip(pm_pattern[2:], pm_pattern[3:])):
      if prev and not nxt: # prev is +, nxt is -
        result.append(i + 3) # index corrected for initial (+, -)
        break
    else:
      # didn't find a + followed by a -: go to next part
      break
    pm_pattern.pop(i + 3) # can't do this in the inner loop
  
  # If there are any minuses directly after the initial (+, -), we fold them into the initial -
  try:
    last_initial_minus = next(i for i, val in enumerate(pm_pattern[1:]) if val)
    result += [1] * (last_initial_minus - 1)
    
    # The pattern now consists of (+, -, +, +, +, +, +, ...)
    # We fold all the pluses after the initial (+, -) into the -, then fold it into the initial +
    result += [2] * (len(pm_pattern) - last_initial_minus - 1)
    result.append(1)
  except StopIteration:
    # If we didn't find a +, the pattern consists of (+, -, -, -, -, ...)
    # Just fold everything into the initial +
    result += [1] * (len(pm_pattern) - 1)
  
  return result

if __name__ == '__main__':
  test_cases = int(input())
  for _ in range(test_cases):
    len_seq, goal = map(int, input().split())
    seq = [int(input()) for _ in range(len_seq)]
    if len(seq) != 1:
      print('\n'.join(map(str, path_to(seq, goal))))
    print()
