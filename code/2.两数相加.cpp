/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(); // 存储加后结果
        ListNode* p = ans;  // 指向存储结果头
        int cur = 0; // 进制位
        // 不知道 l1 和 l2 谁长，直到一方到头退出循环
        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + cur;
            cur = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            int sum = l1->val + cur;
            cur = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            int sum = l2->val + cur;
            cur = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l2 = l2->next;
        }
        // 判断是否还需要进位，比如下面这个即使遍历完 l1 cur 还有进位
        /*
            9 9 9 9 9 9 9
          + 9 9 9 9       
            8 9 9 9 0 0 0 1
        */
        if (cur != 0) {
            p->next = new ListNode(cur);
        }
        return ans->next;
    }
};
// @lc code=end

