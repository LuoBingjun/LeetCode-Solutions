/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        vector<int> ans(n + 1);
        ans[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                ans[i] = ans[i + 1];
            }
            else
            {
                ans[i] = ans[i + 1] + ans[i + 2];
            }
        }
        return ans[0];
    }
};
// @lc code=end

int main()
{
    Solution sol;
    sol.climbStairs(2);
    sol.climbStairs(3);
    return 0;
}