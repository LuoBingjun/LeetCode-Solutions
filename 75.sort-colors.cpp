/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        vector<int> counter(3, 0);
        for (int i : nums)
            counter[i]++;
        int i = 0;
        while (i < counter[0])
        {
            nums[i] = 0;
            i++;
        }
        while (i < counter[0] + counter[1])
        {
            nums[i] = 1;
            i++;
        }
        while (i < counter[0] + counter[1] + counter[2])
        {
            nums[i] = 2;
            i++;
        }
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> input1({2, 0, 2, 1, 1, 0});
    sol.sortColors(input1);
    return 0;
}