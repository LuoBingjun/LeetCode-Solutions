#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            other = target - nums[i]
            for j in range(len(nums)):
                if i == j:
                    continue
                if nums[j] == other:
                    return i, j
# @lc code=end

