#
# @lc app=leetcode id=4 lang=python3
#
# [4] Median of Two Sorted Arrays
#

from typing import List

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums2) < len(nums1):
            return self.findMedianSortedArrays(nums2, nums1)

        m = len(nums1)
        n = len(nums2)

        l = 0
        h = m

        while l <= h:
            i = l + (h - l) // 2
            j = (m + n + 1) // 2 - i

            l1 = nums1[i - 1] if i - 1 >= 0 else float("-inf")
            r1 = nums1[i] if i < m else float("inf")
            l2 = nums2[j - 1] if j - 1 >= 0 else float("-inf")
            r2 = nums2[j] if j < n else float("inf")
            
            if l1 <= r2 and l2 <= r1:
                if (m + n) % 2 == 0:
                    return (max(l1, l2) + min(r1, r2)) / 2
                else:
                    return max(l1, l2)
            elif l1 > r2:
                h = i - 1
            elif l2 > r1:
                l = i + 1

# @lc code=end

sol = Solution()
print(sol.findMedianSortedArrays([1, 3],[2]))
print(sol.findMedianSortedArrays([1, 2],[3, 4]))
print(sol.findMedianSortedArrays([1, 3],[2, 4]))
print(sol.findMedianSortedArrays([],[1]))
print(sol.findMedianSortedArrays([1],[]))
print(sol.findMedianSortedArrays([],[2, 3]))
print(sol.findMedianSortedArrays([3], [-2,-1]))
