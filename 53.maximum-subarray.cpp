/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int max_sum = nums[0], cur_sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            cur_sum = max(cur_sum + nums[i], nums[i]);
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> input1({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    sol.maxSubArray(input1);
    return 0;
}