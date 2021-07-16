/*  字母异位词分组

给定一个字符串数组，将字母异位词组合在一起。
可以按任意顺序返回结果列表。

字母异位词指字母相同，但排列不同的字符串。

示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

示例 2:
输入: strs = [""]
输出: [[""]]

示例 3:
输入: strs = ["a"]
输出: [["a"]]

提示：
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i]仅包含小写字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// Sol 1: 排序 O(nklogk) n字符串数量，k字符串最大长度 空间O(nk)
// 互为异位词的字符串排序后一样，可作为哈希表的键
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); it++){
            ans.emplace_back(it->second);
        }
        return ans;
    }
};