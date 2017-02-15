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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int n = 1;
        auto curr = head;
        for (; curr->next; curr = curr->next) {
            ++n;
        }
        curr->next = head;

        auto tail = curr;
        k = n - k % n;
        curr = head;
        for (int i = 0; i < k; curr = curr->next, ++i) {
            tail = curr;
        }

        tail->next = nullptr;
        return curr; 
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
    ListNode *rotateRight(ListNode *head, int k) {
      if (!head) return NULL;
      int len = 0;
      for (ListNode *current = head; current; current = current->next, ++ len);
      k = len - k % len;
      if (k == len) return head;
      ListNode *res = head, *tail = NULL;
      for (int i = 0; i < k; ++ i, res = res->next);
      for (tail = res; tail->next; tail = tail->next);
      tail->next = head;
      for ( ; head->next != res; head = head->next);
      head->next = NULL;
      return res;
    }
};
