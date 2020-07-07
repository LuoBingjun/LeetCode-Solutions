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
        if (l1->val > l2->val)
        {
            ListNode *tmp = l1;
            l1 = l2;
            l2 = tmp;
        }
        ListNode *head = l1;
        ListNode *next;
        while (l1 != nullptr && l2 != nullptr)
        {
            next = l1->next;
            while (next != nullptr && next->val < l2->val)
            {
                l1 = next;
                next = next->next;
            }

            l1->next = l2;
            l1 = next;
            if (l1 == nullptr)
                break;

            next = l2->next;
            while (next != nullptr && next->val < l1->val)
            {
                l2 = next;
                next = next->next;
            }
            l2->next = l1;
            l2 = next;
            if (l2 == nullptr)
                break;
        }
        return head;
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