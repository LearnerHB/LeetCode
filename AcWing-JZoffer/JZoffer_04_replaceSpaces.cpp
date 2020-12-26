/**	替换空格

请实现一个函数，把字符串中的每个空格替换成"%20"。

你可以假定输入字符串的长度最大是1000。
注意输出字符串的长度可能大于1000。

样例

输入："We are happy."

输出："We%20are%20happy."

思路1：额外创建一个字符串
思路2：为了节省空间使用，还可以借助双指针。动态地将原来的数组扩大长度，然后利用双指针从后往前遍历

1.首先遍历一遍原数组，求出最终答案的长度length；
2.将原数组resize成length大小；
3.使用两个指针，指针i指向原字符串的末尾，指针j指向length的位置；
4.两个指针分别从后往前遍历，如果str[i] == ' '，则指针j的位置上依次填充'0', '2', '%'，
  这样倒着看就是"%20"；如果str[i] != ' '，则指针j的位置上填充该字符即可。


时间复杂度：两种解法均为O(n)
*/


// 解法1：额外创建一个字符串
class Solution_1 {
public:
    string replaceSpaces(string &str) {
        string s;
        for (int i = 0; i < str.size(); i++)
        {
        	if (str[i] == ' ')
        		s += "%20";
        	else 
        		s += str[i];
        }
        return s;
    }
};

// 解法2：采用双指针，减少空间的使用
class Solution_2 {
public:
    string replaceSpaces(string &str) {
    	int len = 0;
    	for (auto c : str)
    	{
    		if (c == ' ')
    			len +=3;
    		else 
    			len ++;
    	}
    	//两个指针分别开始遍历的位置
    	int i = str.size() - 1;
    	int j = len - 1;
    	str.resize(len);
    	while (i >= 0)
    	{
    		if (str[i] == ' ')
    		{
    			str[j--] = '0';
    			str[j--] = '2';
    			str[j--] = '%';
    		}
    		else
    			str[j--] = str[i];
    		i--;
    	}
    	return str;
    }
};




