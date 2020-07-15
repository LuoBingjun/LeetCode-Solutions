/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() < 2)
            return true;
        int i = 0, j = 0;
        while (j < nums.size())
        {
            int max_end = j;
            for (int k = i; k <= j; k++)
            {
                if (k + nums[k] >= nums.size() - 1)
                {
                    return true;
                }
                else
                {
                    max_end = max(max_end, k + nums[k]);
                }
            }

            if (max_end == j)
            {
                return false;
            }
            else
            {
                i = j + 1;
                j = max_end;
            }
        }
        return false;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> input1({2, 3, 1, 1, 4});
    sol.canJump(input1);
    vector<int> input2({3, 2, 1, 0, 4});
    sol.canJump(input2);
    vector<int> input3({2, 1, 2, 2, 1, 2, 2, 2});
    sol.canJump(input3);
    return 0;
}