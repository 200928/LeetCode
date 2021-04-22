/*
 * @lc app=leetcode.cn id=328 lang=java
 *
 * [328] 奇偶链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

/* class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return head;
        }
        ListNode odd = head;
        ListNode even = head.next;
        ListNode evenHead = even;
        ListNode node = head.next.next;
        boolean cur = true;
        while (node != null) {
            if (cur) {
                odd.next = node;
                odd = node;
                cur = false;
            } else {
                even.next = node;
                even = node;
                cur = true;
            }
            node = node.next;
        }
        even.next = null;
        odd.next = evenHead;
        return head;
    }
} */

class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return head;
        }
        ListNode odd = head;
        ListNode even = head.next;
        ListNode evenHead = even;
        // 巧妙运用 odd 和 even 遍历链表
        // 此时进入循环的时候已经是第三个节点，此时为奇节点
        // 并且出循环后已经指向了 null，此后无需手动 null
        while (odd.next != null && even.next != null) {
            odd.next = even.next;
            odd = even.next;
            even.next = odd.next;
            even = odd.next;
        }
        // odd 不可能为 null，然后将偶数的接起来
        odd.next = evenHead;
        return head;
    }
}

// @lc code=end

