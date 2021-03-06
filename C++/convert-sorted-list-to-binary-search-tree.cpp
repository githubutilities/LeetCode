// Time:  O(n)
// Space: O(logn)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        auto curr = head;
        int n = 0;
        while (curr) {
            curr = curr->next;
            ++n;
        }
        return BuildBSTFromSortedDoublyListHelper(&head, 0, n);
    }

    TreeNode * BuildBSTFromSortedDoublyListHelper(ListNode **head, int s, int e) {
        if (s == e) {
            return nullptr;
        }

        int m = s + ((e - s) / 2);
        auto left = BuildBSTFromSortedDoublyListHelper(head, s, m);
        auto curr = new TreeNode((*head)->val);

        *head = (*head)->next;
        curr->left = left;
        curr->right = BuildBSTFromSortedDoublyListHelper(head, m + 1, e);
        return curr;
    }
};

// -----JF-----

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *build(int low, int upp, ListNode **head, TreeNode *current) {
      int mid = (low + upp) >> 1;
      if (low < mid) {
        current->left = new TreeNode(0);
        build(low, mid - 1, head, current->left);
      }
      current->val = (*head)->val;
      *head = (*head)->next;
      if (mid < upp) {
        current->right = new TreeNode(0);
        build(mid + 1, upp, head, current->right);
      }
    }
    TreeNode *sortedListToBST(ListNode *head) {
      int len = 0;
      for (ListNode *current = head; current; current = current->next) ++ len;
      if (!len) return NULL;
      TreeNode *res = new TreeNode(0);
      build(1, len, &head, res);
      return res;
    }
};

//-----------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *build(ListNode *low, ListNode *upp) {
      if (!low || low == upp) return NULL;
      int length = 0;
      ListNode *current;
      for (current = low; current != upp; current = current->next) ++ length;
      int mid = length >> 1;
      current = low;
      for (int i = 0; i < mid; ++ i, current = current->next);
      TreeNode *res = new TreeNode(current->val);
      res->left = build(low, current);
      res->right = build(current->next, upp);
      return res;
    }
    TreeNode *sortedListToBST(ListNode *head) {
      return build(head, NULL);
    }
};
