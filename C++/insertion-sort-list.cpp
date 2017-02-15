// Time:  O(n^2)
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
        ListNode *insertionSortList(ListNode *head) {
        ListNode dummy{numeric_limits<int>::min()};

        auto curr = head;
        ListNode *position = nullptr;

        while (curr) {
            position = findInsertPosition(&dummy, curr->val);
            ListNode *tmp = curr->next;
            curr->next = position->next;
            position->next = curr;
            curr = tmp;
        }

        return dummy.next;
    }

    ListNode* findInsertPosition(ListNode *head, int x) {
        ListNode *prev = nullptr;
        for (auto curr = head; curr && curr->val <= x;
             prev = curr, curr = curr->next);
        return prev;
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
    ListNode *insertionSortList(ListNode *head) {
      ListNode *res = NULL;
      while (head) {
        ListNode **p = &res;
        ListNode *next = head->next;
        while (*p && (*p)->val < head->val) p = &((*p)->next);
        head->next = *p;
        *p = head;
        head = next;
      }
      return res;
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
    ListNode *insertionSortList(ListNode *head) {
      ListNode *res = NULL;
      while (true) {
        if (!head) break;
        ListNode *next = head->next;
        head->next = NULL;
        if (!res) res = head;
        else if (res->val > head->val) {
          head->next = res;
          res = head;
        } else {
          ListNode *current;
          for (current = res; current->next && current->next->val < head->val; current = current->next);
          if (!current->next) current->next = head;
          else {
            head->next = current->next;
            current->next = head;
          }
        }
        head = next;
      }
      return res;
    }
};
