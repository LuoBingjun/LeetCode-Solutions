#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        others = dict()
        for i, num in enumerate(nums):
            other = target - num
            if other in others:
                return others[other], i
            others[num] = i
# @lc code=end

