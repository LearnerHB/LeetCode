/* 盛最多水的容器

给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点(i,ai) 。
在坐标内画 n 条垂直线，垂直线 i的两个端点分别为(i,ai) 和 (i, 0) 。
找出其中的两条线，使得它们与x轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
// 解法1：双指针  时间O(n) 空间O(1)
// 头尾两个指针，一边求出容纳量，一边向内移动二者中较小的指针直到重合，过程中可以求最大容纳
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 0)
            return 0;
        int ans = 0;
        int i = 0, j = height.size() - 1;
        while (i != j) {
            int cur = (j - i) * min(height[i], height[j]);
            ans = max(cur, ans);
            if (height[i] >= height[j])
                j--;
            else
                i++;

        }
        return ans;
    }
};