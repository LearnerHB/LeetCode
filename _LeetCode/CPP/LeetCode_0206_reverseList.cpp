/*	反转链表

给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Sol 1 迭代 双指针 时间O(n) 空间O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* tempNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempNext;
        }
        return prev;
    }
};