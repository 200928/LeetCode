/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        // 巧妙运用 odd 和 even 遍历链表
        // 此时进入循环的时候已经是第三个节点，此时为奇节点
        // 并且出循环后已经指向了 null，此后无需手动 null
        while (odd->next != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = even->next;
            even->next = odd->next;
            even = odd->next;
        }
        // odd 不可能为 null，然后将偶数的接起来
        odd->next = evenHead;
        return head;
    }
};
// @lc code=end

