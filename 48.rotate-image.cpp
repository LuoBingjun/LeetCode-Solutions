/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<int>> input1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    sol.rotate(input1);
    vector<vector<int>> input2({{5, 1, 9, 11},
                                {2, 4, 8, 10},
                                {13, 3, 6, 7},
                                {15, 14, 12, 16}});
    sol.rotate(input2);
    return 0;
}