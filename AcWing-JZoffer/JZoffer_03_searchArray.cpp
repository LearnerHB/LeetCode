/** 二维数组中的查找

在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

样例
输入数组：
[
  [1,2,8,9]，
  [2,4,9,12]，
  [4,7,10,13]，
  [6,8,11,15]
]
如果输入查找数值为7，则返回true，
如果输入查找数值为5，则返回false。

思路：
以数组的右上角的数字为突破口，这个数字本行左边的数都比自己小，本列下方的数都比自己大
每次均判断数组右上角的数字，等于target则直接返回；小于target则可以排除该行；大于target则可以排除该列
排除整行的方法就是让枚举点横坐标（行标）加一，排除整列的方法就是让枚举点纵坐标（列标）减一
*/
class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        if (array.empty() || array[0].empty())	//前者表示是零行数组，后者表示是零列数组
        	return false;
        int i = 0, j = array[0].size() - 1;
        while (i < array.size() && j >= 0)
        {
        	if (array[i][j] == target)	return true;
        	if (array[i][j] > target)	j--;
        	else i++;
        }
        return false;
    }
};