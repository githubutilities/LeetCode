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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy{0};
        dummy.next = head;
        auto curr = &dummy;
        while (curr->next && curr->next->next) {
            auto next_one = curr->next;
            auto next_two = next_one->next;
            auto next_three = next_two->next;
            curr->next = next_two;
            next_two->next = next_one;
            next_one->next = next_three;
            curr = next_one;
        }
        return dummy.next; 
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
    ListNode *swapPairs(ListNode *head) {
      ListNode **p = &head;
      while (*p) {
        if ((*p)->next == nullptr) break;
        ListNode *left = *p, *right = (*p)->next;
        left->next = right->next;
        right->next = left;
        *p = right;
        p = &(left->next);
      }
      return head;
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
    ListNode *swapList(ListNode *current) {
      if (current == NULL) return NULL;
      if (current->next == NULL) return current;
      ListNode *l = current, *r = current->next, *next = r->next;
      r->next = l;
      l->next = swapList(next);
      return r;
    }
    ListNode *swapPairs(ListNode *head) {
      return swapList(head);
    }
};
