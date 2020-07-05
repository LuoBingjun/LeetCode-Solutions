#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#
from typing import List
# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        i = 0
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            j = i + 1
            k = len(nums) - 1
            while j < k:
                res = nums[i] + nums[j] + nums[k]
                if res == 0:
                    ans.append([nums[i], nums[j], nums[k]])
                    while j + 1 < k and nums[j] == nums[j + 1]:
                        j += 1
                    j += 1
                    while j < k - 1 and nums[k] == nums[k - 1]:
                        k -= 1
                    k -= 1
                elif res > 0:
                    k -= 1
                else:
                    j += 1
            
            i += 1
        
        return ans



# @lc code=end
sol = Solution()
sol.threeSum([-1, 0, 1, 2, -1, -4])

