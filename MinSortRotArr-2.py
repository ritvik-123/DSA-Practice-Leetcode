def breaking(arr: List[int]) -> List:
    start = 0
    end = len(arr)-1    
    while start<end:
        if (arr[start]>arr[start+1]):
            return arr[:start], arr[start+1:]
        elif (arr[start]<=arr[start+1]):
            start = start+1
    return arr[:0],arr[:]
def Min_binary(arr: List[int]) -> int:
    if(len(arr)>0):
        return (arr[0])
    else:
        return -1
        
class Solution:
    def findMin(self, nums: List[int]) -> int:
        arr_1, arr_2 = breaking(nums)
        min_1 = Min_binary(arr_1)
        min_2 = Min_binary(arr_2)
        if(min_1==-1 or min_2 == -1):
            return max(min_1,min_2)
        else:
            return min(min_1,min_2)
    
        