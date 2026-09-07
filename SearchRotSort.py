def breaks(nums: List[int]):
    end = len(nums)-1
    ele = 0
    while(ele<=end):
        if (nums[ele]<nums[ele-1]):
            return nums[:ele],nums[ele:],ele
        else:
            ele+=1


def binary(arr: List[int], target: int) -> int:
    start = 0
    end = len(arr)-1
    if(end==0):
        if target == arr[0]:
            return 0
        else:
            return -1 
    elif end==1:
        if target == arr[0]:
            return 0
        elif target == arr[end]:
            return 1
        else:
            return -1
    while(start<=end):
        mid = (start+end)//2
        print(start,mid,end)
        if(arr[mid]==target):
            return mid
        elif (arr[mid]<target):
            start = mid+1
        elif (arr[mid]>target):
            end = mid-1
    if(start>end or end==0):
        return -1
    else:
        return mid

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums)-1
        if(end==0):
            if target == nums[0]:
                return 0
            else:
                return -1 
        elif end==1:
            if target == nums[0]:
                return 0
            elif target == nums[end]:
                return 1
            else:
                return -1
        arr_1, arr_2, pivot = breaks(nums)
        res_1 = binary(arr_1,target)
        res_2 = binary(arr_2,target)
        if (res_1==-1 and res_2==-1):
            return -1
        elif res_2 == -1 and res_1 != -1:
            return res_1
        else:
            res_2 = res_2 + pivot
            return max(res_1, res_2)
                

        
                
    
            
                