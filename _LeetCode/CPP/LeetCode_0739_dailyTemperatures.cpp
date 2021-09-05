/*    每日温度
请根据每日 气温 列表 temperatures ，请计算在每一天需要等几天才会有更高的温度。
如果气温在这之后都不会升高，请在该位置用 0 来代替。

示例
输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
*/    
// Sol 1: 单调栈
// 维护一个存储下标的单调栈，栈底到栈顶的下标对应的温度列表中的温度依次递减
// 正向遍历温度列表元素temp[i]，如果栈空则直接把i入栈，否则比较栈顶元素preIndex对应的温度temp[preIndex]
// 和当前temp[i]的大小。如果栈顶对应温度小于当前温度，将preIndex移除并且preIndex对应的等待天数置i-preIndex
// 重复上述操作直到栈为空或者栈顶温度大于等于当前温度，将i进栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};