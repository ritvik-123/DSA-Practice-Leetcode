import re
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = re.sub('[^A-Za-z0-9]+', '', s)
        s = s.lower()
        start = 0
        end = int(len(s)-1)
        n = int(end/2)
        str = list(s)
        if (start>end):
            return True
        for i in range(n+1):
            if(str[start] == str[end]):
                start = start + 1
                end = end - 1
                if(start>=end):
                    return True
            else:
                return False