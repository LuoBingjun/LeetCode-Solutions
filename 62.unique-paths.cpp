/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (j < n - 1)
                {
                    if (i < m - 1)
                        ans[i][j] = ans[i + 1][j] + ans[i][j + 1];
                    else
                        ans[i][j] = ans[i][j + 1];
                }
                else
                {
                    if (i < m - 1)
                        ans[i][j] = ans[i + 1][j];
                    else
                        ans[i][j] = 1;
                }
            }
        }
        return ans[0][0];
    }
};
// @lc code=end

int main()
{
    Solution sol;
    sol.uniquePaths(3, 2);
    sol.uniquePaths(7, 3);
    return 0;
}