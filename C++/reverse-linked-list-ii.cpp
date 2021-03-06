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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy{0};
        dummy.next = head;

        auto *prev = &dummy;

        for (int i = 0; i < m - 1; ++i) {
            prev = prev->next;
        }

        auto *head2 = prev;

        prev = prev->next;
        auto *cur = prev->next;

        for (int i = m; i < n; ++i) {
            prev->next = cur->next;  // Remove cur from the list.
            cur->next = head2->next; // Add cur to the head.
            head2->next = cur;       // Add cur to the head.
            cur = prev->next;        // Get next cur.
        }

        return dummy.next;
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
class Solution {
  public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
      ListNode **p = &head;
      for (int i = 0; i < m - 1; ++ i) p = &((*p)->next);
      ListNode *current = (*p)->next, *begin = *p;
      for (int i = m; i < n; ++ i) {
        ListNode *next = current->next;
        current->next = *p;
        *p = current;
        current = next;
      }
      begin->next = current;
      return head;
    }
};

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
      ListNode dummy(-1);
      dummy.next = head;
      ListNode *prev = &dummy, *mid;
      for (int i = 0; i < m - 1; ++ i) prev = prev->next;
      mid = prev;
      prev = prev->next;
      ListNode *current = prev->next;
      for (int i = m; i < n; ++ i) {
        prev->next = current->next;
        current->next = mid->next;
        mid->next = current;
        current = prev->next;
      }
      return dummy.next;
    }
};

//---------

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
    ListNode *reverse(ListNode *head) {
      if (!head) return NULL;
      if (!head->next) return head;
      ListNode *last = head, *current = head->next;
      head->next = NULL;
      while (current) {
        ListNode *next = current->next;
        current->next = last;
        last = current;
        current = next;
      }
      return last;
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
      ListNode *left = NULL, *right = head, *current = head;
      for (int i = 1; i < n; ++ i) {
        if (i < m) left = current;
        right = right->next;
        current = current->next;
      }
      ListNode *next = NULL;
      if (right) {
        next = right->next;
        right->next = NULL;
      }
      ListNode *res;
      if (!left) res = reverse(head);
      else {
        res = head;
        left->next = reverse(left->next);
      }
      for (current = res; current->next; current = current->next);
      current->next = next;
      return res;
    }
};
