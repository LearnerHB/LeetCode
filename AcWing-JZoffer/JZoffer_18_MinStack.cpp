/** 包含min函数的栈

设计一个支持push，pop，top等操作并且可以在O(1)时间内检索出最小元素的堆栈。

push(x)–将元素x插入栈中
pop()–移除栈顶元素
top()–得到栈顶元素
getMin()–得到栈中最小元素

样例
MinStack minStack = new MinStack();
minStack.push(-1);
minStack.push(3);
minStack.push(-4);
minStack.getMin();   --> Returns -4.
minStack.pop();
minStack.top();      --> Returns 3.
minStack.getMin();   --> Returns -1.

思路
1. 直观思路是另外维护一个存储最小值的栈，仅当新数值小于等于当前该栈的栈顶元素的时候才压入栈；
出栈的时候仅当原栈出栈元素值和最小栈栈顶元素相等才对最小栈进行出栈
2. 骚操作：仅使用一个栈
只开一个普通栈和一个min_value记录最小值。栈中存放当前元素与当前最小值的差值
进栈时，如果栈空，插入当前元素，更新最小值；栈非空，则插入x-min_value，更新最小值
出栈时，如果栈顶元素小于0，则栈顶元素为当前最小值，需要回滚上一次最小值，出栈
取栈顶元素时，如果栈中仅一个元素，直接返回；否则，若栈顶元素大于0，则原元素非当前最小值，通过差值计算找到最小值；若栈顶元素小于0，直接返回最小值
返回最小值时，直接返回min_value
整数运算可能会溢出，需要用long long

*/


//  方法1 另外维护一个单调的栈，压入栈时仅压入比栈顶元素小的元素
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stackValue;
    stack<int> stackMin;

    MinStack() {
        

    }
    
    void push(int x) {
        stackValue.push(x);
        if (stackMin.empty() || stackMin.top()>=x)
            stackMin.push(x);
    }
    
    void pop() {
        if (stackMin.top() == stackValue.top())
            stackMin.pop();
        stackValue.pop();
    }
    
    int top() {
        return stackValue.top();
    }
    
    int getMin() {
        return stackMin.top();
    }
};

//  方法2：仅使用一个栈
class MinStack {
public:
    /** initialize your data structure here. */
    stack<long long> st;
    long long min_value;

    MinStack() {
        
    }
    
    void push(int x) {
        if (st.empty()){
            st.push(x);
            min_value = x;
        }
        else {
            st.push(x - min_value);
            min_value = min(min_value, (long long)(x));
        }
    }
    
    void pop() {
        if (st.top() < 0)
            min_value -= st.top();
        st.pop();
    }
    
    int top() {
        if (st.size() == 1)
            return st.top();
        else if (st.top() > 0)
            return st.top() + min_value;
        else
            return min_value;
    }
    
    int getMin() {
        return min_value;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
