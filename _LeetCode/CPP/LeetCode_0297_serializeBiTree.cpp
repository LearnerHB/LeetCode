/*    二叉树的序列化和反序列化

序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，
同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，
你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 思路： DFS 递归
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "X,";
        }
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + "," + left + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> list = split(data, ',');
        TreeNode* ans = buildTree(list);
        return ans;
    }

    TreeNode* buildTree(list<string> &strList) {
        string strtmp = strList.front();
        strList.pop_front();
        if (strtmp == "X") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(strtmp));
        node->left = buildTree(strList);
        node->right = buildTree(strList);
        return node;
    }
    
    list<string> split(string& str, char c) {
        list<string> ans;
        for (int lastpos = -1, pos = 0; pos < str.size(); pos++) {
            if (str[pos] == c) {
                ans.push_back(str.substr(++lastpos, pos - lastpos));
                lastpos = pos;
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
