/**	和为S的连续正数序列		🌟🌟

输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、4～6和7～8。

样例
输入：15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]

思路
 双指针

*/


class Solution {
public:
    vector<vector<int> > findContinuousSequence(int sum) {
      	vector<vector<int>>	ans;
      	for (int i = 1, j = 1, s = 1; i <= sum/2; i++) {
      		while (s < sum)	s += (++j);
      		if (s == sum && j > i) {
      			vector<int> line;
      			for (int k = i; k <= j; k++)	line.push_back(k);
      			ans.push_back(line);
      		}
      		s -= i;
      	}
      	return ans;
    }
};