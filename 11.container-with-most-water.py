#
# @lc app=leetcode id=11 lang=python3
#
# [11] Container With Most Water
#
from typing import List
# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        i = 0
        j = len(height) - 1
        maxRes = 0
        while i < j:
            if height[i] < height[j]:
                maxRes = max(maxRes, height[i] * (j - i))
                i += 1
            else:
                maxRes = max(maxRes, height[j] * (j - i))
                j -= 1
        
        return maxRes

# @lc code=end
sol = Solution()
print(sol.maxArea([1,8,6,2,5,4,8,3,7]))