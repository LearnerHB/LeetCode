/*	查找常用字符

给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的
全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，
但不是 4 次，则需要在最终答案中包含该字符 3 次。
你可以按任意顺序返回答案。

示例 1：
输入：["bella","label","roller"]
输出：["e","l","l"]

示例 2：
输入：["cool","lock","cook"]
输出：["c","o"]
 
提示：
1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] 是小写字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-common-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> minfreq(26, INT_MAX);
        vector<int> freq(26);
        for (const string& word: A) {
            fill(freq.begin(), freq.end(), 0);
            for (char ch: word) {
                ++freq[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                minfreq[i] = min(minfreq[i], freq[i]);
            }
        }

        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minfreq[i]; ++j) {
                ans.emplace_back(1, i + 'a');
            }
        }
        return ans;
    }
};
