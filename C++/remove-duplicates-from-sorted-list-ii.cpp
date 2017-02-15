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
        ListNode dummy{0};
        auto prev = &dummy;
        while (head) {
            if (head->next && head->next->val == head->val) {
                auto val = head->val;
                while (head && head->val == val) {
                    head = head->next;
                }
                prev->next = head;
            } else {
                prev->next = head;
                prev = head;
                head = head->next;
            }
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
    ListNode *deleteDuplicates(ListNode *head) {
      ListNode **p = &head;
      bool dup = false;
      while (*p) {
        if ((*p)->next != nullptr && (*p)->val == (*p)->next->val || dup) {
          dup = (*p)->next != nullptr && (*p)->val == (*p)->next->val;
          ListNode *current = *p;
          *p = (*p)->next;
          delete current;
        } else p = &((*p)->next);
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
    ListNode *deleteDuplicates(ListNode *head) {
      ListNode **p = &head;
      while (*p) {
        bool dup = false;
        while ((*p)->next != nullptr && (*p)->next->val == (*p)->val) {
          dup = true;
          ListNode *current = *p;
          *p = current->next;
          delete current;
        }
        if (dup) {
          ListNode *current = *p;
          *p = current->next;
          delete current;
        } else p = &((*p)->next);
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
    ListNode *deleteDuplicates(ListNode *head) {
      if (!head) return NULL;
      if (!head->next) return head;
      if (head->val == head->next->val) {
        for ( ; head->next && head->val == head->next->val; head = head->next);
        return deleteDuplicates(head->next);
      } else {
        head->next = deleteDuplicates(head->next);
        return head;
      }
    }
};
