from typing import List

class Solution:
  def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
    result = []
    nums.append(upper+1)
    pre = lower - 1
    for i in nums:
      if (i == pre + 2):
        result.append(str(i-1))
      elif (i > pre + 2):
        result.append(str(pre + 1) + "->" + str(i -1))
      pre = i
    return result