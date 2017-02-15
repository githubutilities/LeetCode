// Time:  O(n)
// Space: O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// Morris Traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = nullptr;
        TreeNode *curr = root;
        while (curr) {
            if (!curr->left) {
                if (prev && prev->val >= curr->val) {
                    return false;
                }
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode *node = curr->left;
                while (node->right && node->right != curr) {
                    node = node->right;
                }
                if (!node->right) {
                    node->right = curr;
                    curr = curr->left;
                } else {
                    if (prev && prev->val >= curr->val) {
                        return false;
                    }
                    prev = curr;
                    node->right = nullptr;
                    curr = curr->right;
                }
            }
        }
                
        return true;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }

        if (!isValidBST(root->left)) {
            return false;
        }

        if (last && last != root && last->val >= root->val) {
            return false;
        }

        last = root;

        if (!isValidBST(root->right)) {
            return false;
        }

        return true;
    }

private:
    TreeNode *last = nullptr;
};

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
    bool isValid(TreeNode *root, int low, int upp) {
        if (root == nullptr) return true;
        return isValid(root->left, low, root->val) && isValid(root->right, root->val, upp)
        && root->val > low && root->val < upp;
    }
    bool isValidBST(TreeNode *root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
};

//---------

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
    void dfs(TreeNode *root, bool &res, bool &first, int &last) {
      if (!root) return;
      dfs(root->left, res, first, last);
      if (!first && last >= root->val) res = false;
      first = false;
      last = root->val;
      dfs(root->right, res, first, last);
    }
    bool isValidBST(TreeNode *root) {
      bool res = true, first = true;
      int last;
      dfs(root, res, first, last);
      return res;
    }
};
