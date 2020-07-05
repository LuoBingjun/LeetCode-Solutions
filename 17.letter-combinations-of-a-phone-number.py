#
# @lc app=leetcode id=17 lang=python3
#
# [17] Letter Combinations of a Phone Number
#
from typing import List
# @lc code=start
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        mapping = ["abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        ans = []
        def DFS(s, k):
            digit = int(digits[k])
            if k == len(digits) - 1:
                for c in mapping[digit-2]:
                    ans.append(s + c)
            else:
                for c in mapping[digit-2]:
                    DFS(s + c, k+1)
        
        if len(digits) > 0:
            DFS("", 0)
        return ans
            
# @lc code=end
sol = Solution()
print(sol.letterCombinations("2"))
print(sol.letterCombinations("23"))
print(sol.letterCombinations("234"))
