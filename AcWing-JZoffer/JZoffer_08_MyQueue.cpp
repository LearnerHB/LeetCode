/**	用两个栈实现队列

请用栈实现一个队列，支持如下四种操作：

push(x) – 将元素x插到队尾；
pop() – 将队首的元素弹出，并返回该元素；
peek() – 返回队首元素；
empty() – 返回队列是否为空；

注意：
你只能使用栈的标准操作：push to top，peek/pop from top, size 和 is empty；
如果你选择的编程语言没有栈的标准库，你可以使用list或者deque等模拟栈的操作；
输入数据保证合法，例如，在队列为空时，不会进行pop或者peek等操作；

样例
MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false

思路：栈后入先出，队列先进先出
用两个栈来实现队列，一个主栈用来存储数据，一个辅助栈用来当缓存。
push(x) – 将元素x插到队尾 - 将元素压入主栈即可
pop() – 将队首的元素弹出并返回该元素 - 将所有元素依次从主栈弹出压入辅助栈，弹出并返回辅助栈栈顶元素
peek() – 返回队首元素 - 类似pop，只是不弹出
empty() – 直接判断主栈是否为空

*/
class MyQueue {
public:

 	stack<int>	stk, cache;

    /** Initialize your data structure here. */
    MyQueue() {

    }

    //将a栈元素都压回b栈
    void exchange(stack<int> &a, stack<int>& b){
    	while (a.size()){
    		b.push(a.top());
    		a.pop();
    	}
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        exchange(stk, cache);
        int ans = cache.top();
        cache.pop();
        exchange(cache, stk);  
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        exchange(stk, cache);
        int ans = cache.top();
        exchange(cache, stk);  
        return ans;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */