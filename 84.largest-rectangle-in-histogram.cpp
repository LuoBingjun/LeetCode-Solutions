/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        if (n == 0)
            return 0;
        vector<int> left(n);
        vector<int> right(n);
        left[0] = -1;
        right[n - 1] = n;
        for (int i = 1; i < n; i++)
        {
            int j = i - 1;
            while (j >= 0 && heights[j] >= heights[i])
                j = left[j];
            left[i] = j;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            int j = i + 1;
            while (j < n && heights[j] >= heights[i])
                j = right[j];
            right[i] = j;
        }

        int max_rect = 0;
        for (int i = 0; i < n; i++)
        {
            max_rect = max(max_rect, heights[i] * (right[i] - left[i] - 1));
        }
        return max_rect;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> input1({2, 1, 5, 6, 2, 3});
    sol.largestRectangleArea(input1);
    vector<int> input2({1, 1});
    sol.largestRectangleArea(input2);
    return 0;
}