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
        void reorderList(ListNode *head) {
        if (!head) {
            return;
        }

        auto slow = head, fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split into two lists.
        auto tmp = slow->next;
        slow->next = nullptr;
        slow = tmp;

        merge(head, reverse(slow));
    }

private:
    ListNode *reverse(ListNode *head) {
        ListNode dummy{0};

        while (head) {
            auto tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }

        return dummy.next;
    }

    ListNode *merge(ListNode *list1, ListNode *list2) {
        ListNode dummy{0};
        auto ptr = &dummy;

        while (list1 && list2) {
            auto tmp = list1->next;

            ptr->next = list1;
            ptr = ptr->next;
            ptr->next = list2;
            ptr = ptr->next;

            list1 = tmp;
            list2 = list2->next;
        }

        if (list1) {
            ptr->next = list1;
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
    ListNode *reverse(ListNode *head) {
      ListNode **p = &head;
      ListNode *begin = *p, *current = head;
      while (current) {
        ListNode *next = current->next;
        current->next = *p;
        *p = current;
        current = next;
      }
      begin->next = nullptr;
      return head;
    }
    void mergeList(ListNode *left, ListNode *right) {
      while (left->next != nullptr) {
        ListNode *next = left->next;
        left->next = right;
        right = right->next;
        left->next->next = next;
        left = next;
      }
      left->next = right;
    }
    void reorderList(ListNode *head) {
      if (head == nullptr || head->next == nullptr) return;
      ListNode *fast = head, *slow = head, *prev = head;
      while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
      }
      prev->next = nullptr;
      mergeList(head, reverse(slow));
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
      if (!head->next) return head;
      ListNode *last = head, *current = head->next;
      last->next = NULL;
      while (current) {
        ListNode *next = current->next;
        current->next = last;
        last = current;
        current = next;
      }
      return last;
    }
    void merge(ListNode *l, ListNode *r) {
      ListNode *current = l;
      l = l->next;
      current->next = NULL;
      int col = 0;
      while (l || r) {
        col ^= 1;
        if (col && r) {
          current->next = r;
          r = r->next;
        } else {
          current->next = l;
          l = l->next;
        }
        current = current->next;
        current->next = NULL;
      }
    }
    void reorderList(ListNode *head) {
      if (!head || !head->next) return;
      int length = 1;
      for (ListNode *current = head; current; current = current->next) ++ length;
      ListNode *current = head, *last = NULL;
      for (int i = 0; i < length / 2; ++ i) {
        last = current;
        current = current->next;
      }
      last->next = NULL;
      ListNode *l = head, *r = current;
      r = reverse(r);
      merge(l, r);
    }
};
