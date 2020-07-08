/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if (s.size() < 2)
            return 0;
        int ans = -1;
        vector<int> mem(s.size());
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                continue;
            int l = -1;
            int k = 1;
            int j = i;
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[j] == '(')
                {
                    if (mem[j] > 0)
                    {
                        j += mem[j];
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (k > 0)
                    {
                        k--;
                    }
                    else
                    {
                        break;
                    }
                }

                if (k == 0)
                {
                    l = j - i;
                }
            }
            mem[i] = l;
            ans = max(ans, l);
        }
        return ans + 1;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    sol.longestValidParentheses("(()");
    sol.longestValidParentheses(")()())");
    sol.longestValidParentheses(")(");
    return 0;
}