/** 合并两个排序的链表

输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照递增排序的。

样例
输入：1->3->5 , 2->4->5
输出：1->2->3->4->5->5

思路
新建一个dummy虚拟头节点，其实就是建立一个新的链表然后用cur来表示当前链表的尾结点
最后返回的时候返回虚拟结点之后的链表即可

时间复杂度：两个链表各遍历一次，O(n)

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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (l1 && l2){
        	if (l1->val < l2->val){
        		cur->next = l1;
        		l1 = l1->next;
        	}
        	else {
        		cur->next = l2;
        		l2 = l2->next;
        	}
        	cur = cur->next;
        }
        cur->next = (l1 != NULL ? l1 : l2);
        return dummy->next;
    }  
};


