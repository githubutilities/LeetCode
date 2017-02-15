// Time:  O(n * 4^n / n^(3/2)) ~= Catalan numbers
// Space: O(n)

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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return generateTreesHelper(1, n);
    }

private:
    vector<TreeNode *> generateTreesHelper(int start, int end) {
        vector<TreeNode *> result;
        if (start > end) {
            result.emplace_back(nullptr);
            return result;
        }

        for (int i = start; i <= end; ++i) {
            vector<TreeNode *> leftSubTrees = generateTreesHelper(start, i - 1);
            vector<TreeNode *> rightSubTrees = generateTreesHelper(i + 1, end);
            for (const auto& left : leftSubTrees) {
                for (const auto& right : rightSubTrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = clone(left);
                    root->right = clone(right);
                    result.emplace_back(root);
                }
            }

        }
        return result;
    }

    TreeNode *clone(TreeNode *root) {
        TreeNode *newRoot = nullptr;

        if (root) {
            newRoot = new TreeNode(root->val);
            newRoot->left = clone(root->left);
            newRoot->right = clone(root->right);
        }

        return newRoot;
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
    vector<TreeNode *> dfs(int l, int r) {
      if (l > r) return vector<TreeNode *>({nullptr});
      vector<TreeNode *> res;
      for (int i = l; i <= r; ++ i) {
        vector<TreeNode *> left = dfs(l, i - 1), right = dfs(i + 1, r);
        for (const auto &l : left) {
          for (const auto &r : right) {
            TreeNode *current = new TreeNode(i);
            current->left = l;
            current->right = r;
            res.push_back(current);
          }
        }
      }
      return res;
    }
    vector<TreeNode *> generateTrees(int n) {
      return dfs(1, n);
    }
};
