/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.empty())
            return 1;

        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] <= 0 || nums[i] > nums.size() || nums[nums[i] - 1] == nums[i])
            {
                i++;
                continue;
            }
            int tmp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = tmp;
        }

        i = 0;
        while (i < nums.size())
        {
            if (nums[i] != i + 1)
                break;
            i++;
        }

        return i + 1;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> input1({1, 2, 0});
    sol.firstMissingPositive(input1);
    vector<int> input2({3, 4, -1, 1});
    sol.firstMissingPositive(input2);
    vector<int> input3({7, 8, 9, 11, 12});
    sol.firstMissingPositive(input3);
    return 0;
}