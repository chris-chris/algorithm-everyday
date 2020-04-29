#maximal square

from collections import defaultdict

class Solution:
    def canConvert(self, str1: str, str2: str) -> bool:
        if str1 == str2:
            return True
        p = 0
        len1 = len(str1)
        len2 = len(str2)
        m = defaultdict(str)
        while p < len1 and p < len2:
            if str1[p] in m:
                if m[str1[p]] != str2[p]:
                    return False
            else:
                m[str1[p]] = str2[p]
            p += 1
        return len(set(str2)) != 26