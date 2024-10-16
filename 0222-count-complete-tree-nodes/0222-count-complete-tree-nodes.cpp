/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void InOrder(TreeNode* root,int &ans)
    {
        if(root==NULL)return;
        ans++;
        if(root->left)InOrder(root->left,ans);
        if(root->right)InOrder(root->right,ans);
    }
    int countNodes(TreeNode* root) {
        int ans=0;
        InOrder(root,ans);
        return ans;
    }
};