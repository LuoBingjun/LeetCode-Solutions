/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
            return intervals;

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            if (a[0] < b[0])
                return true;
            else
                return false;
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int>& back = ans.back();
            if (back[1] >= intervals[i][0])
            {
                back[1] = max(back[1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<int>> input1({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    sol.merge(input1);
    vector<vector<int>> input2({{1, 4}, {4, 5}});
    sol.merge(input2);
    return 0;
}