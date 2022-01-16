/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/* class Solution {
public:
    // 中序遍历将数保存到数组中
    void inord(TreeNode* node, vector<int>& v) {
        if (node == nullptr) {
            return;
        }
        inord(node->left, v);
        v.push_back(node->val);
        inord(node->right, v);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inord(root, v);
        TreeNode* head = new TreeNode(-1);
        TreeNode* cur = head;
        vector<int>::iterator it;
        for (it = v.begin(); it != v.end(); it++) {
            cur->right = new TreeNode(*it);
            cur = cur->right;
        }
        return head->right;
    }
}; */
/*
Accepted
37/37 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 52.31 % of cpp submissions (7.7 MB)
*/

class Solution {
public:
    TreeNode* cur;

    void inorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cur->right = node;
        node->left = nullptr;
        cur = node;
        inorder(node->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = new TreeNode(-1);
        cur = head;
        inorder(root);
        return head->right;
    }
};
// @lc code=end
