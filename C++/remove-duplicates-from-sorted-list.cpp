// Time:  O(n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto iter = head;
        while (iter) {
            auto runner = iter->next;
            while (runner && runner->val == iter->val) {
                runner = runner->next;
            }
            iter->next = runner;
            iter = runner;
        }
        return head; 
    }
};
-e 
// -----JF-----

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
      for (ListNode *current = head, *last = NULL; current; last = current, current = current->next) {
        if (!last) continue;
        if (current->val == last->val) {
          last->next = current->next;
          delete current;
          current = last;
        }
      }
      return head;
    }
};
