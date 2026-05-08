def binary_search(arr: List[int], n:int , target: int) -> bool:
    start = 0
    end = n - 1
    if (end==-1):
        return False
    elif (end == 0):
        if(arr[0] == target):
            return True
        else:
            return False
    while start<=end:
        mid = (start+end) // 2
        if(target == arr[mid]):
            return True
        elif (target<arr[mid]):
            end = mid-1
        else:
            start = mid+1
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])
        print(m,n)
        for i in range(n):
            res = binary_search(matrix[i], m, target)
            if res == True:
                return res
        return res
    