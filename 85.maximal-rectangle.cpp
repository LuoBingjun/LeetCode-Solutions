/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, n);
        int max_area = 0;
        for (int i = 0; i < m; i++)
        {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    left[j] = max(left[j], cur_left);
                }
                else
                {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }

            for (int j = n - 1; j >= 0; j--)
            {
                if (matrix[i][j] == '1')
                {
                    right[j] = min(right[j], cur_right);
                }
                else
                {
                    right[j] = n;
                    cur_right = j;
                }
            }

            for (int j = 0; j < n; j++)
            {
                max_area = max(max_area, (right[j] - left[j]) * height[j]);
            }
        }
        return max_area;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<char>> input1({{'1', '0', '1', '0', '0'},
                                 {'1', '0', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '0', '0', '1', '0'}});
    sol.maximalRectangle(input1);
    vector<vector<char>> input2({{'0', '0', '0', '0', '0'},
                                 {'1', '0', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}});
    sol.maximalRectangle(input2);
    vector<vector<char>> input3({{'1'}});
    sol.maximalRectangle(input3);
    return 0;
}