/** 反转链表

定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。

思考题：
请同时实现迭代版本和递归版本。

样例
输入:1->2->3->4->5->NULL
输出:5->4->3->2->1->NULL

思路
迭代：一路向下找，直到尾节点为空
递归：首先明确reverseList函数的作用是翻转一个链表并且返回新链表的头结点，也就是原链表的尾节点。
可以先递归处理 reverseList(head->next)，这样我们可以将以head->next为头节点的链表翻转，
并得到原链表的尾节点tail，此时head->next是新链表的尾节点，我们令它的next指针指向head，
并将head->next指向空即可将整个链表翻转，且新链表的头节点是tail。

空间复杂度分析：总共递归 n 层，系统栈的空间复杂度是 O(n)，所以总共需要额外 O(n) 的空间。
时间复杂度分析：链表中每个节点只被遍历一次，所以时间复杂度是 O(n)

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//迭代版本
class Solution_iterate {
public:
    ListNode* reverseList(ListNode* head) {
       	ListNode* pre = nullptr;
       	auto cur = head;
       	while (cur){
       		ListNode* next = cur->next;
       		cur->next = pre;
       		pre = cur;
       		cur = next;
       	}
       	return pre;
    }
};

//递归版本
class Solution_recursive {
public:
    ListNode* reverseList(ListNode* head) {
       	if (!head || !head->next)
       		return head;
       	ListNode *tail = reverseList(head->next);
       	head->next->next = head;
       	head->next = nullptr;
       	return tail;
    }
};














