/**	删除链表中重复的节点

在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留。

样例1
输入：1->2->3->3->4->4->5
输出：1->2->5

样例2
输入：1->1->1->2->3
输出：2->3

思路
(线性扫描) O(n)
首先为了方便处理边界问题，我们先定义一个虚拟头结点dummy指向头结点
然后从前往后扫描整个链表，每次扫描元素相同的一段，如果这段中的元素个数多于1个，则将整段元素直接删除。
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
    ListNode* deleteDuplication(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* p = dummy;
        while(p->next){
        	ListNode* q = p->next;
        	while (q && p->next->val == q->val)	//p->next->val代表一串重复数字中的第一个数字
        		q = q->next;					//保持这个数，枚举后面的数查看是否与之相同
        	//上面遍历完之后，p->next开始，一直到q前面的一个数，都是重复的数字
        	if (p->next->next == q)			//这种情况表示刚刚过去的这个数没有重复
        		p = p->next;
        	else 							//否则有重复
        		p->next = q;	
        }
        return dummy->next;
    }
};







