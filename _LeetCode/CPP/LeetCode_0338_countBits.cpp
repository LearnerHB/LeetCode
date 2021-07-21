/*  比特位计数

给定一个非负整数num。对于0 ≤ i ≤ num 范围中的每个数字i，
计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:
输入: 2
输出: [0,1,1]

示例2:
输入: 5
输出: [0,1,1,2,1,2]

进阶:
给出时间复杂度为O(n*sizeof(integer))的解答非常容易。
但你可以在线性时间O(n)内用一趟扫描做到吗？
要求算法的空间复杂度为O(n)。
你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数
如 C++ 中的__builtin_popcount）来执行此操作。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/counting-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// Sol 1: 推导规律
// 数字分为奇数偶数，二进制表示中奇数一定比前一个偶数多一个1，偶数中1的个数一定和除以2之后的那个数一样多
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        res[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                res[i] = res[i-1] + 1;
            }
            else {
                res[i] = res[i/2];
            }
        }
        return res;
    }
};