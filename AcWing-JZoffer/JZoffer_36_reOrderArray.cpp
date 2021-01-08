/**	调整数组顺序使奇数位于偶数前面

输入一个整数数组，实现一个函数来调整该数组中数字的顺序。
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分。

样例
输入：[1,2,3,4,5]
输出: [1,3,5,2,4]

思路
(双指针扫描)O(n)
用两个指针分别从首尾开始，往中间扫描。
扫描时保证第一个指针前面的数都是奇数，第二个指针后面的数都是偶数。

每次迭代时需要进行的操作：
1. 第一个指针一直往后走，直到遇到第一个偶数为止；
2. 第二个指针一直往前走，直到遇到第一个奇数为止；
3. 交换两个指针指向的位置上的数，再进入下一层迭代，直到两个指针相遇为止；

*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
         int l = 0, r = array.size() - 1;
         while (l < r){
         	//注意下面这里如果不加l<r这部分条件，有可能会越界，死循环
         	while (l < r && array[l]%2==1)	l++;
         	while (l < r && array[r]%2==0)	r--;
         	swap(array[l], array[r]); 
         }
    }
};