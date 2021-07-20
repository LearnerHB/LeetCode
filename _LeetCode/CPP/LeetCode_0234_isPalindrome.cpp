/*  回文链表

请判断一个链表是否为回文链表。

示例 1:
输入: 1->2
输出: false

示例 2:
输入: 1->2->2->1
输出: true

进阶：
你能否用O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Sol 1 复制链表值到数组列表 后用双指针法
// 时间O(n) 空间O(n) 不符合进阶要求
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while (head != nullptr) {
            vals.emplace_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = (int)vals.size()-1; i < j; i++, j--) {
            if (vals[i] != vals[j])
                return false;
        }
        return true;
    }
};

// Sol 2 快慢指针 反转链表(可参考LeetCode_0206_reverseList)
// 1. 快慢指针法找到前半部分链表尾节点; 2. 反转后半部分链表; 3. 判断是否回文; 4. 恢复链表; 5. 返回结果
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return true;
        // 1. 找到前半部分尾节点; 2. 反转后半部分
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);
        // 3. 判断回文
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool res = true;
        while (res && p2 != nullptr) {
            if (p1->val != p2->val)
                res = false;
            p1 = p1->next;
            p2 = p2->next;
        }
        // 4. 恢复链表; 5. 返回结果
        firstHalfEnd->next = reverseList(secondHalfStart);
        return res;
    }

    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

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


















