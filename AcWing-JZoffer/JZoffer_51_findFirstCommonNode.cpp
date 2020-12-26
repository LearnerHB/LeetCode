/**	两个链表的第一个公共结点		🌟

输入两个链表，找出它们的第一个公共结点。
当不存在公共节点时，返回空节点。

样例
给出两个链表如下所示：
A：        a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
输出第一个公共节点c1

思路
1.	有公共部分的话，后面肯定是重叠的。先分别计算链表长度；
	让长度长的先走二者长度之差，两个再一起开始走，相遇的时候就找到第一个公共结点

2.	假设长度分为两部分，相遇前+相遇后，A:a+c, B:b+c。由于a+c+b=b+c+a
	让两个一起走，A走到头再转向B，B走到头转向A，能在相遇点相遇

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//方法1
class Solution {
public:
	ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB){
		auto p = headA, q = headB;
		int la = 0, lb = 0;
		for (auto t = headA; t; t = t->next)	la++;
		for (auto t = headB; t; t = t->next)	lb++;
		int k = la - lb;
		if (la < lb) {
			p = headB, q = headA;
			k = lb - la;
		}
		while (k--) {
			p = p->next;
		}
		while (p) {
			if (p == q)	return p;
			p = p->next;
			q = q->next;
		}
		return nullptr;
	}
};




//方法2
class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        auto p = headA, q = headB;
        while (p != q){
        	if (p)	p = p->next;
        	else 	p = headB;
        	if (q)	q = q->next;
        	else 	q = headA;
        }
        return p;
    }
};







