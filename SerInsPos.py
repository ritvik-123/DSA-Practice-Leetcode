class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums)-1
        if(end == -1):
            return 0
        if(end == 0):
            if(nums[end]<target):
                return 1
            else:
                return 0
        n = len(nums)-1
        while(start<=end):
            mid = (start+end)//2
            if(nums[mid]==target):
                return mid
            elif(mid == n):
                return mid+1
            elif(target<nums[mid+1] and target>nums[mid]):
                return mid+1
            elif(target<nums[mid] and target>nums[mid-1]):
                return mid
            elif(target<nums[mid]):
                end = mid-1
            elif(target>nums[mid]):
                start = mid+1
            else:
                pass
        if(start>end):
            print(start)
            return start
        