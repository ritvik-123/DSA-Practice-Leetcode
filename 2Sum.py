class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        Len = len(nums)
        for i in range(Len):
            for j in range(i+1,Len):
                if (nums[i]+nums[j] == target):
                    return [i,j]
                else:
                    continue