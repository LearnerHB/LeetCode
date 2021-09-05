/*    LRU缓存机制
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。
当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/    

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Sol 1: 哈希表 + 双向链表
// 双向链表按照被使用的顺序存储键值对，靠近头部的键值对是最近使用的，靠近尾部的是最久未使用的
// 哈希表通过缓存数据的key映射到其在双向链表中的位置
// Tips: 双向链表的实现中使用一个伪头部(dummy head)和伪尾部(dummy tail)标记界限
//       这样在添加和删除节点的时候不需要检查相邻的节点是否存在
struct DoubleLinkedNode {
    int key, value;
    DoubleLinkedNode* prev;
    DoubleLinkedNode* next;
    DoubleLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DoubleLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DoubleLinkedNode*> cache;
    DoubleLinkedNode* head;
    DoubleLinkedNode* tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        // use dummy head and dummy tail
        head = new DoubleLinkedNode();
        tail = new DoubleLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    // 首先判断key是否存在。如果不存在，返回-1; 
    // 如果存在，哈希表定位到该节点在双向链表中的位置，将其移动到头部，返回值
    int get(int key) {
        if (cache.count(key) == 0) {
            return -1;
        }
        DoubleLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    // 首先判断key是否存在。如果不存在，用key和value创建一个新的节点，加到双向链表的头部，并加入哈希表
    // 然后判断双向链表是否超出容量，是则删除双向链表尾部节点并删除哈希表中对应的项
    // 如果存在，与get类似，定位到节点之后更新节点值，并移动到头部
    void put(int key, int value) {
        if (cache.count(key) == 0) {
            DoubleLinkedNode* node = new DoubleLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            size++;
            if (size > capacity) {
                DoubleLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                // 防止内存泄露
                delete removed;
                size--;
            } 
        } 
        else {
            DoubleLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
    
    void addToHead(DoubleLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DoubleLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void moveToHead(DoubleLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }
    
    DoubleLinkedNode* removeTail() {
        DoubleLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};