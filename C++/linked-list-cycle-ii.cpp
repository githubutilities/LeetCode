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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next, fast = fast->next->next;
            if (slow == fast) {  // There is a cycle.
                slow = head;
                // Both pointers advance at the same time.
                while (slow != fast) {
                    slow = slow->next, fast = fast->next;
                }
                return slow;  // slow is the begin of cycle.
            }
        }
        return nullptr;  // No cycle.
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
    ListNode *hasCycle(ListNode *head) {
      ListNode *l = head, *r = head;
      while (l && r) {
        l = l->next;
        r = r->next;
        if (!r) return NULL;
        else r = r->next;
        if (l == r) break;
      }
      return r;
    }
    ListNode *detectCycle(ListNode *head) {
      if (!head) return NULL;
      ListNode *reach = hasCycle(head);
      if (!reach) return NULL;
      for (; head != reach; head = head->next, reach = reach->next);
      return head;
    }
};
