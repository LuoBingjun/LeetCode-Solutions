#
# @lc app=leetcode id=17 lang=python3
#
# [17] Letter Combinations of a Phone Number
#
from typing import List
from collections import deque
# @lc code=start
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        mapping = ["abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        ans = []
        q = deque()
        
        if len(digits) > 0:
            digit = int(digits[0])
            for c in mapping[digit-2]:
                q.append(c)
            while len(q) > 0:
                s = q.popleft()
                if len(s) < len(digits):
                    digit = int(digits[len(s)])
                    for c in mapping[digit-2]:
                        q.append(s + c)
                else:
                    ans.append(s)

        return ans
            
# @lc code=end
sol = Solution()
print(sol.letterCombinations("2"))
print(sol.letterCombinations("23"))
print(sol.letterCombinations("234"))
