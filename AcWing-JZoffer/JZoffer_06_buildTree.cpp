/**	重建二叉树

输入一棵二叉树前序遍历和中序遍历的结果，请重建该二叉树。

注意:
二叉树中每个节点的值都互不相同；
输入的前序遍历和中序遍历一定合法；

样例

给定：
前序遍历是：[3, 9, 20, 15, 7]
中序遍历是：[9, 3, 15, 20, 7]

返回：
[3, 9, 20, null, null, 15, 7, null, null, null, null]
返回的二叉树如下所示：
    3
   / \
  9  20
    /  \
   15   7

Tips:
- 前序遍历就是（根节点|左子树|右子树）；中序遍历就是（左子树|根节点|右子树）
- 可以用哈希表来记录每个值在中序遍历中的位置，这样在递归到每个节点时，在中序遍历中找到该值只需要O(1)

思路：利用递归建立整棵二叉树，先递归创建左右子树，然后创建根节点，将左右子树指向根节点
1. 前序遍历找到根节点：前序遍历的第一个数，也就是根节点
2. 中序遍历中找到对应的根节点k，则k左边是左子树的节点，右边是右子树的节点
3. 假设左子树长度l，则在前序遍历中根节点后面的l个数就是左子树的前序遍历，剩下的是右子树的前序遍历
4. 有了左右子树的前序遍历和中序遍历，可以递归创建出左右子树，然后创建根节点

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

	unordered_map<int, int> pos;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
       	for (int i = 0; i < n; i++){
       		pos[inorder[i]] = i;	//中序遍历中某值的位置
       	}

       	return dfs(preorder, inorder, 0, n-1, 0, n-1);
    }

    //pre和in为原始输入的两个遍历顺序；pl为前序遍历中该子树位置起点，pr为前序遍历中该子树位置终点
    TreeNode* dfs(vector<int>& pre, vector<int>& in, int pl, int pr, int il, int ir){
    	if (pl > pr)	
    		return NULL;
    	int k = pos[pre[pl]] - il;	//k为中序遍历下，该子树的根节点在该子树中的位置
    	TreeNode* root = new TreeNode(pre[pl]);	//创建根节点
    //左子树：在前序中，（根节点位置pl），左子树始于pl+1, 终于pl+k；在中序中，根节点il+k，左子树始于il, 终于il+k-1;
    	root->left = dfs(pre, in, pl+1, pl+k, il, il+k-1);	
	//右子树：在前序中，（根节点位置pl），右子树始于pl+k+1, 终于pr； 在中序中，根节点il+k，右子树始于il+k+1，终于ir;
    	root->right = dfs(pre, in, pl+k+1, pr, il+k+1, ir);
    	return root;
    }
};








