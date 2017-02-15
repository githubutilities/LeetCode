// Time:  O(m + n)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;
        ListNode *begin = nullptr, *tailA = nullptr, *tailB = nullptr;
        while (curA && curB) {
            if (curA == curB) {
                begin = curA;
                break;
            }
   
            if (curA->next) {
                curA = curA->next;
            } else if (!tailA) {
                tailA = curA;
                curA = headB;
            } else {
                break;
            }

            if (curB->next) {
                curB = curB->next;
            } else if (!tailB) {
                tailB = curB;
                curB = headA;
            } else {
                break;
            }
        }
        
        return begin;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode *tailA = headA, *tailB = headB;
        while (tailA->next != nullptr) tailA = tailA->next;
        while (tailB->next != nullptr) tailB = tailB->next;
        if (tailA != tailB) return nullptr;
        int lenA = 0, lenB = 0;
        for (ListNode *current = headA; current != nullptr; current = current->next) ++lenA;
        for (ListNode *current = headB; current != nullptr; current = current->next) ++lenB;
        for (int i = 0; i < lenA - lenB; ++i) headA = headA->next;
        for (int i = 0; i < lenB - lenA; ++i) headB = headB->next;
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
