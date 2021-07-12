/* h指数 2

给定一位研究者论文被引用次数的数组（被引用次数是非负整数），数组已经按照升序排列。编写一个方法，计算出研究者的 h 指数。
h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。
（其余的N - h篇论文每篇被引用次数不多于 h 次。）"

示例:
输入: citations = [0,1,3,5,6]
输出: 3 
解释: 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
由于研究者有 3 篇论文每篇至少被引用了 3 次，其余两篇论文每篇被引用不多于 3 次，所以她的 h 指数是 3。


说明:
如果 h 有多有种可能的值 ，h 指数是其中最大的那个。

进阶：
这是H 指数的延伸题目，本题中的citations数组是保证有序的。
你可以优化你的算法到对数时间复杂度O(logn)吗？
*/

// 解法1： 暴力解 时间O(n) 空间O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int temp = 1;
        int res = 0;
        for(int i=citations.size()-1;i>=0;i--)
        {
            if(citations[i]>=temp)
            {
                res++;
                temp++;
            }
            else{
                break;
            }
        }
        return res;
    }
};

// 解法2：二分查找 时间O(logn) 空间O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 取中点mid，有n - mid篇论文被引用了至少citations[mid]次
            // 若满足citations[mid] >= n - mid，则移动右边界，否则移动左边界
            if (citations[mid] >= n - mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return n - left;
    }
};