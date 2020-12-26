/**	序列化二叉树 🌟

请实现两个函数，分别用来序列化和反序列化二叉树。
您需要确保二叉树可以序列化为字符串，并且可以将此字符串反序列化为原始树结构。

样例

你可以序列化如下的二叉树
    8
   / \
  12  2
     / \
    6   4
为："[8, 12, 2, null, null, 6, 4, null, null, null, null]"

注意:
以上的格式是AcWing序列化二叉树的方式，你不必一定按照此格式，所以可以设计出一些新的构造方式。

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
class Solution {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs_s(root, res);
       	return res;
    }

    void dfs_s(TreeNode* root, string &res){
    	if (!root){
    		res += "null ";
    		return;
    	}
    	res += to_string(root->val) + ' ';
    	dfs_s(root->left, res);
    	dfs_s(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int cur = 0;	//保存当前字符串遍历的位置
        return dfs_d(data, cur);
    }

    TreeNode* dfs_d(string data, int &cur){	//注意这里的cur是传的引用，而不是值
    	if (cur == data.size())
    		return NULL;
    	int k = cur;	//k用来算出当前的数字的位数，以便跳到下一个数字(或null)
    	while (data[k] != ' ')	//跳出循环时候k位置在两个数字中间的空格
    		k++;
    	//若当前构造的是null节点，则直接返回，并继续遍历k+1位置的下一个节点
    	if (data[cur] == 'n'){	
    		cur = k+1;
    		return NULL;
    	}

    	int val = 0;	
    	//若当前构造的节点值为负数
    	if (data[cur] == '-'){	
    		for (int i = cur+1; i < k; i++)
    			val = val * 10 + data[i] - '0';
    		val = -val;
    	}
    	//若当前构造的节点值非负
    	else{
    		for (int i = cur; i < k; i++)
    			val = val * 10 + data[i] - '0';
    	}

    	cur = k + 1;	//以便之后继续遍历下一个数字

    	//根据算出的节点值构造节点
    	auto root = new TreeNode(val);
    	root->left = dfs_d(data, cur);	//依次构造左右节点，由于cur传递引用，所以这里的两个cur其实值会不一样
    	root->right = dfs_d(data, cur);
    	return root;
    }
};










