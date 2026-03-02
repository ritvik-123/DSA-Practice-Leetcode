class Solution:
    def myAtoi(self, s: str) -> int:
        length = len(s)
        number = 0
        count=0
        neg = False
        pos = False
        first_int=False
        s = list(s)
        for i in range(length):
            if s[i] == " ":
                if first_int==True:
                    break
                elif neg == True or pos == True:
                    break
                else:
                    continue
            elif s[i].isdigit():
                if number == 0:
                    number = int(s[i])
                    first_int=True
                else:
                    number = (number*(10)) + int(s[i])
                    count+=1
                    if count == 1:
                        first_int=True
            elif s[i]=='-':
                if first_int==True:
                    break
                elif neg == True:
                    break
                else:
                    neg = True
            elif s[i]=='+':
                if first_int==True:
                    break
                elif pos == True:
                    break
                else:
                    pos = True
                    continue
            elif (s[i].isdigit() == False):
                break
            else: 
                continue
        if neg == True:
            if neg == True and pos == True:
                number = 0
            else:
                number=number*(-1)
        if (number<(-2**31)):
            number = -2**31
        elif (number>((2**31)-1)):
            number = (2**31)-1
        return number