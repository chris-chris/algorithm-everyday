# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
  def firstBadVersion(self, n):
    """
    :type n: int
    :rtype: int
    """
    # parametric search
    if n == 1:
      return 1
    p = 1
    q = n
    if isBadVersion(p):
      return p

    while p+1 < q:
      mid = int((p+q)/2)
      if isBadVersion(mid):
        q = mid
      else:
        p = mid
    if p == q:
      return p
    else:
      return q