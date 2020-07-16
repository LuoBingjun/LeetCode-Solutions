/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1)
                {
                    if (j < n - 1)
                        grid[i][j] += grid[i][j + 1];
                }
                else
                {
                    if (j == n - 1)
                        grid[i][j] += grid[i + 1][j];
                    else
                        grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
                }
            }
        }
        return grid[0][0];
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<int>> input1({{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}});
    sol.minPathSum(input1);
    return 0;
}