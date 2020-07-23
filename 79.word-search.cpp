/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
    int m, n;
    bool DFS(vector<vector<char>> &board, vector<vector<bool>> &occupied, string &word, int i, int j, int k)
    {
        if (occupied[i][j] == false && word[k] == board[i][j])
        {
            occupied[i][j] = true;
            if (k == word.size() - 1)
                return true;
            if (i - 1 >= 0 && DFS(board, occupied, word, i - 1, j, k + 1))
                return true;
            if (j - 1 >= 0 && DFS(board, occupied, word, i, j - 1, k + 1))
                return true;
            if (i + 1 < m && DFS(board, occupied, word, i + 1, j, k + 1))
                return true;
            if (j + 1 < n && DFS(board, occupied, word, i, j + 1, k + 1))
                return true;
            occupied[i][j] = false;
        }
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty())
            return false;
        if (word.empty())
            return true;
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> occupied(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (DFS(board, occupied, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<char>> input({{'A', 'B', 'C', 'E'},
                                {'S', 'F', 'C', 'S'},
                                {'A', 'D', 'E', 'E'}});
    sol.exist(input, "ABCCED");
    sol.exist(input, "SEE");
    sol.exist(input, "ABCB");
    return 0;
}