class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            ret = False
        else:
            count = 0
            length  = len(str(x))
            x = list(str(x))
            half = int(length/2)
            for i in range(half):
                if x[i] == x[length-i-1]:
                    count+=1
                else:
                    ret = False
                    break
            if count == half:
                ret = True
        return ret