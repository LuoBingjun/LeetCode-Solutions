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
        if (heights.empty())
            return 0;
        int max_rect = 0;
        stack<int> st;
        int i = 0;
        while (i < heights.size())
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int h = heights[st.top()];
                st.pop();
                if (st.empty())
                    max_rect = max(max_rect, i * h);
                else
                    max_rect = max(max_rect, (i - st.top() - 1) * h);
            }
            st.push(i);
            i++;
        }

        while (!st.empty())
        {
            int h = heights[st.top()];
            st.pop();
            if (st.empty())
                max_rect = max(max_rect, i * h);
            else
                max_rect = max(max_rect, (i - st.top() - 1) * h);
        }
        return max_rect;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> input({2, 1, 5, 6, 2, 3});
    sol.largestRectangleArea(input);
    return 0;
}