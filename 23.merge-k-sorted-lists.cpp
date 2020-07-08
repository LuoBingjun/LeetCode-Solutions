/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        return mergeKLists(lists, 0, lists.size() - 1);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists, int i, int j)
    {
        if (j - i == 0)
        {
            return lists[i];
        }
        else if (j - i == 1)
        {
            return merge2Lists(lists[i], lists[j]);
        }
        else
        {
            int k = (i + j) / 2;
            ListNode *a = mergeKLists(lists, i, k);
            ListNode *b = mergeKLists(lists, k + 1, j);
            return merge2Lists(a, b);
        }
    }

    ListNode *merge2Lists(ListNode *a, ListNode *b)
    {
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;
        ListNode *cur = new ListNode(-1);
        ListNode *head = cur;
        while (a || b)
        {
            if (a == nullptr)
            {
                cur->next = b;
                cur = cur->next;
                b = b->next;
            }
            else if (b == nullptr)
            {
                cur->next = a;
                cur = cur->next;
                a = a->next;
            }
            else if (a->val < b->val)
            {
                cur->next = a;
                cur = cur->next;
                a = a->next;
            }
            else
            {
                cur->next = b;
                cur = cur->next;
                b = b->next;
            }
        }
        return head->next;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    ListNode* ans;
    vector<ListNode*> input0({
        new ListNode(1, new ListNode(4, new ListNode(5))), 
        new ListNode(1, new ListNode(3, new ListNode(4))), 
        new ListNode(2, new ListNode(6))});
    ans = sol.mergeKLists(input0);
    vector<ListNode*> input1({
        nullptr,
        new ListNode(2, new ListNode(6)), 
        nullptr});
    ans = sol.mergeKLists(input1);
    vector<ListNode*> input2({
        nullptr,
        nullptr});
    ans = sol.mergeKLists(input2);
    return 0;
}