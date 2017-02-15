// Time:  O(n)
// Space: O(h), h is the height of the binary tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// Iterative solution.
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        // isSymmetricHelper(root->left, root->right)
        stack<TreeNode *> nodes;
        nodes.emplace(root->left);
        nodes.emplace(root->right);

        while (!nodes.empty())  {
            auto right = nodes.top();
            nodes.pop();
            auto left = nodes.top();
            nodes.pop();
            if (!left && !right) {
                continue;
            }
            if (!left || !right || left->val != right->val) {
                return false;
            }
            // isSymmetricHelper(left->right, right->left)
            nodes.emplace(left->right);
            nodes.emplace(right->left);

            // isSymmetricHelper(left->left, right->right)
            nodes.emplace(left->left);
            nodes.emplace(right->right);
        }
        return true;
    }
};


// Recursive solution.
class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isSymmetricHelper(root->left, root->right);
    }
    
    bool isSymmetricHelper(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        }
        if (!left || !right || left->val != right->val) {
            return false;
        }
        return isSymmetricHelper(left->left, right->right) &&
               isSymmetricHelper(left->right, right->left);
    }
};
-e 
// -----JF-----

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    bool isMirror(TreeNode *root_l, TreeNode *root_r) {
      if (!root_l && !root_r) return true;
      if (!root_l || !root_r) return false;
      if (root_l->val != root_r->val) return false;
      return isMirror(root_l->left, root_r->right) && isMirror(root_l->right, root_r->left);
    }
    bool isSymmetric(TreeNode *root) {
      if (!root) return true;
      return isMirror(root->left, root->right);
    }
};
