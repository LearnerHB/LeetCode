/**	复杂链表的复刻

请实现一个函数可以复制一个复杂链表。
在复杂链表中，每个结点除了有一个指针指向下一个结点外，还有一个额外的指针指向链表中的任意结点或者null。

注意：
函数结束后原链表要与输入时保持一致。

思路
综合了平台上大家的分享，大致有以下三种解法，由浅入深
1. 暴力求解，根据next指针新建链表，然后利用双重for循环找到random节点位置，时间复杂度O(n^2)
2. 哈希表，时间复杂度O(1)，空间复杂度O(n^2)，空间换时间
先建立原链表和目标链表的对应关系并存储到哈希表；
再遍历原链表，查看random节点，根据哈希表中存储的对应关系建立目标链表的random节点关系
3. 并行求解，通过直接复制链表各节点的方式来解决random节点的查找问题
先在链表的所有节点后面插入一个复制节点，作为并行链表
然后遍历新链表，遇到random节点之后对应改变并行链表中的节点
最后提取出并行链表

*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct ListNode {
 *     int val;
 *     ListNode *next, *random;
 *     ListNode(int x) : val(x), next(NULL), random(NULL) {}
 * };
 */

//	方法1：暴力求解
class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
        ListNode* dummy = new ListNode(-1);
        auto nextNode = dummy;

        //根据next指针新建链表
        for (auto node = head; node; node = node->next){
        	ListNode* newNode = new ListNode(node->val);
        	nextNode->next = newNode;
        	nextNode = nextNode->next;
        }

        //双重for循环，每找到一个random节点就重新遍历查找其位置
        //curNode是目标链表部分的当前节点，node是原链表部分的当前节点
        for (auto curNode = dummy->next, node = head; curNode && node; ){
        	if (node->random){
        		auto r_curNode = dummy->next, r_node = head;	//发现存在random节点，用来遍历查找其位置
        		while (r_node != node->random && r_node){
        			r_curNode = r_curNode->next;
        			r_node = r_node->next;
        		}
        		curNode->random = r_curNode;	//通过while遍历找到了random节点位置
        	}
        	curNode = curNode->next;
        	node = node->next;
        }
        return dummy->next;
    }
};



//	方法2：哈希表
class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
        unordered_map<ListNode*, ListNode*> hash;
        ListNode* dummy = new ListNode(-1);
        auto nextNode = dummy;

        //建立原链表和目标链表的对应关系，存储到hash表
        for (auto node = head; node; node = node->next){
        	ListNode* newNode = new ListNode(node->val);
        	nextNode->next = newNode;
        	hash.insert({node, newNode});
        	nextNode = nextNode->next;	
        }

        //遍历原链表，查看random节点，根据hash表中存储的对应关系建立目标链表的random节点关系
        for (auto node = head; node; node = node->next){
        	if (node->random){
        		auto curNode = hash[node];
        		curNode->random = hash[node->random];
        	}
        }

        return dummy->next;
    }
};






//	方法3：并行求解
class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
        //链表所有节点中间插入一个复制节点，作为并行链表
        for (auto node = head; node; ){
        	auto nextNode = node->next;
        	ListNode* newNode = new ListNode(node->val);
        	newNode->next = node->next;
        	node->next = newNode;
        	node = nextNode;
        }

        //遍历新链表，遇到random节点后对应改变并行链表中的节点
        for (auto node = head; node; node = node->next->next){
        	if (node->random){
        		node->next->random = node->random->next;
        	}
        }

        //提取出并行链表并恢复原链表
        ListNode* dummy = new ListNode(-1);	//创建虚拟头结点
        auto nextNode = dummy;
        for (auto node = head; node; node = node->next){
        	nextNode->next = node->next;
        	nextNode = nextNode->next;
        	node->next = node->next->next;
        }

        return dummy->next;
    }
};







