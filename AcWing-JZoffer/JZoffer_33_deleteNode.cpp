/**	在O(1)时间删除链表结点

给定单向链表的一个节点指针，定义一个函数在O(1)时间删除该结点。
假设链表一定存在，并且该节点一定不是尾节点。

样例
输入：链表 1->4->6->8
      删掉节点：第2个节点即6（头节点为第0个节点）
输出：新链表 1->4->8

思路
由于是单链表，没有办法找到前驱节点，所以可以换个思路
将下一个节点的值复制到这个节点上，然后再删除下一个节点

注意
仅仅在面试题范围内，可以采用这种思路。但是在实际的工程问题中，
这样的处理方案很可能会出现内存问题，留下安全漏洞，所以不推荐。

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
    void deleteNode(ListNode* node) {
        ListNode* p = node->next;

        node->val = p->val;
        node->next = p->next;

        delete p;
    }
};




