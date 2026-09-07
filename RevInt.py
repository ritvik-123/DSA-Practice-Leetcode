class Solution:
    def reverse(self, x: int) -> int:
        neg = False
        if (x<0):
            neg = True
            x = abs(x)
        length = len(str(x))
        rev = 0
        for i in range(length):
            rev = rev+(x%10)*(10**(length-i-1))
            x = int(x/10)
        if (neg == True):
            rev = rev - 2*rev
        if ((rev<(-2**31)) or (rev>((2**31)-1))):
            rev = 0
        return rev