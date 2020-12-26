/** 从尾到头打印单链表

输入一个链表的头结点，按照 从尾到头 的顺序返回节点的值。
返回的结果用数组存储。

样例
输入：[2, 3, 5]
返回：[5, 3, 2]

思路：从头到尾遍历并存进数组，然后数组反转（单链表只能从前往后遍历）（可以用反向迭代器）
时间复杂度：O(n)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_1_v1 {
public:
    vector<int> printListReversingly(ListNode* head) {
        vector<int> v;
        for (auto cur = head; cur; cur = cur->next)
        {
        	v.push_back(cur->val);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};


class Solution_1_v2 {
public:
    vector<int> printListReversingly(ListNode* head) {
        vector<int> v;
        while (head)
        {
        	v.push_back(head->val);
        	head = head->next;
        }

        return vector<int>(v.rbegin(), v.rend());	//反向迭代器
    }
};

