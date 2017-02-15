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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy{0};
        dummy.next = head;
        auto slow = &dummy;
        auto fast = &dummy;

        // fast is n-step ahead.
        while (n > 0) {
            fast = fast->next;
            --n;
        }

        // When fast reaches the end, slow must be nth to last node.
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        auto node_to_delete = slow->next;
        slow->next = slow->next->next;
        delete node_to_delete;

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
      ListNode **p = &head;
      ListNode *tail = head;
      while (n --) tail = tail->next;
      while (tail) {
        p = &(*p)->next;
        tail = tail->next;
      }
      ListNode *target = *p;
      *p = (*p)->next;
      delete target;
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
      ListNode *l = head, *r = head, *res = head;
      while (n --) r = r->next;
      if (r == NULL) {
        res = head->next;
        delete head;
        return res;
      }
      while (r->next) {
        l = l->next;
        r = r->next;
      }
      ListNode *next = l->next;
      l->next = next->next;
      delete next;
      return res;
    }
};
