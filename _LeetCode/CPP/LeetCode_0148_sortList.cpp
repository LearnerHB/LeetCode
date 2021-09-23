/*    排序链表

给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：
你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

Tips: 
时间复杂度O(nlogn)的方法有归并排序、堆排序和快速排序，其中最适合链表的排序算法是归并排序
要大导O(1)的空间复杂度，需要使用自底向上的实现方式
 
示例 1：
输入：head = [4,2,1,3]
输出：[1,2,3,4]
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

// Sol 1: 归并排序
/* 
0. 首先求得链表长度 length； 
1. 初始化引入dummyhead
2. subLen=1, 链表拆成若干长为 subLen 的子链表（最后一个可以小于 subLen
然后合并链表（合并链表可用 LeetCode_0021 合并有序链表的方法）
3. subLen *= 2，重复 2 步，直到有序链表的长度大于或等于 length，排序完毕

*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        } 
        // 0. 计算链表长度length
        int length = 0;
        ListNode* tmp = head;
        while (tmp != nullptr) {
            length++;
            tmp = tmp->next;
        }
        // 1. 初始化引入dummyHead
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        // 2. 每次将链表拆分成若干长度subLen的子链表，每两个子链表为一组合并
        for (int subLen = 1; subLen < length; subLen <<=1) {
            ListNode* prev = dummyHead;
            ListNode* curr = dummyHead->next;   // curr 记录拆分链表的位置

            while (curr != nullptr) {   // 如果链表没有被拆分完
                // 2.1 拆分subLen长度的链表1
                ListNode* head1 = curr;
                for (int i = 1; i < subLen && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }

                // 2.2 拆分subLen长度的链表2
                ListNode* head2 = curr->next;   
                curr->next = nullptr;       // 断开第一个链表和第二个链表的链接
                curr = head2;               // 第二个链表头
                for (int i = 1; i < subLen && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }        

                // 2.3 再次断开第二个链表后的next的链接
                ListNode* next = nullptr;  // next用于记录，拆分完两个链表的结束位置，下一次重复第2步操作就从next开始
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;   // 断开链接
                }

                // 2.4 合并两个subLen长度的有序链表
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;      // 将prev移到subLen*2的位置
                }
                curr = next;
            }
        }

        return dummyHead->next;
    }

    // O(m+n)
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead;
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                temp->next = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        temp->next = (head1==nullptr) ? head2 : head1;
        return dummyHead->next;
    }
};