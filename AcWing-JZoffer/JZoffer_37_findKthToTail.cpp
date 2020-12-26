/**	链表中倒数第k个节点

输入一个链表，输出该链表中倒数第k个结点。

注意：
k >= 0;
如果k大于链表长度，则返回 NULL;

样例
输入：链表：1->2->3->4->5 ，k=2
输出：4

思路
O(n)
遍历两次，一次获取链表长度n,第二次由前向后遍历到n-k+1个节点就是答案
注意当k>n，返回nullptr

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        int n = 0;
        for (ListNode* p = pListHead; p; p=p->next)
        	n++;
        if (n < k)	
        	return nullptr;
        ListNode* p = pListHead;
        for (int i = 0; i < n-k; i++)	
        	p = p->next;
        return p;
    }
};