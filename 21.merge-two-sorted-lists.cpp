/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode *cur = new ListNode(-1);
        ListNode *head = cur;
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 == nullptr)
            {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
            else if (l2 == nullptr)
            {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else if (l1->val < l2->val)
            {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        return head->next;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    sol.mergeTwoLists(
        new ListNode(1, new ListNode(2, new ListNode(4))),
        new ListNode(1, new ListNode(3, new ListNode(4))));
    sol.mergeTwoLists(
        new ListNode(1, new ListNode(2, new ListNode(4))),
        nullptr);
    sol.mergeTwoLists(
        nullptr,
        new ListNode(1, new ListNode(2, new ListNode(4))));
    return 0;
}