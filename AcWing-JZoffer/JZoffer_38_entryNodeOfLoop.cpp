/**	链表中环的入口结点		🌟🌟

给定一个链表，若其中包含环，则输出环的入口节点。
若其中不包含环，则输出null。

思路
快慢双指针，从头开始同时遍历，
如果快指针走到null说明不存在环
否则当二者相遇，快指针走了x+(y+z)*n+y，慢指针走了(x+y)
而x+(y+z)*n+y=2(x+y)，解得x=(n-1)*(y+z)+z
让快指针从c开始慢速(1)走，走x步正好会到环入口b点，
让慢指针回去同步慢速(1)走，也是走x步，到达b点

https://www.acwing.com/solution/content/741/

时间复杂度
O(n)

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
    ListNode *entryNodeOfLoop(ListNode *head) {
    	if (!head || !head->next)
    		return 0;
    	ListNode *first = head, *second = head;
    	while (first && second){
    		first = first->next;
    		second = second->next;
    		if (second)
    			second = second->next;
    		else 
    			return 0;

    		if (first == second){
    			first = head;
    			while (first != second){
    				first = first->next;
    				second = second->next;
    			}
    			return first;
    		}
    	}
    	return 0;
    }
};