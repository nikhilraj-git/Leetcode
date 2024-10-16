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
    void buildMap(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (!node) return;
        mp[node] = parent;
        buildMap(node->left, node, mp);
        buildMap(node->right, node, mp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        unordered_map<TreeNode*, bool> vis;

        buildMap(root, nullptr, mp);

        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int dist = 0;

        while (!q.empty()) {
            if (dist == k) {
                vector<int> ans;
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    q.push(node->left);
                    vis[node->left] = true;
                }

                if (node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right] = true;
                }

                if (mp[node] && !vis[mp[node]]) {
                    q.push(mp[node]);
                    vis[mp[node]] = true;
                }
            }
            ++dist;
        }

        return {};
    }
};
