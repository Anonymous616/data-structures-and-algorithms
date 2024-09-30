// https : // leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *head = nullptr;

    if (!list1 && !list2)
      return nullptr;
    if (list1 == nullptr)
      return list2;
    if (list2 == nullptr)
      return list1;

    if (list1->val < list2->val) {
      head = list1;
      list1 = list1->next;
    } else if (list2 != nullptr) {
      head = list2;
      list2 = list2->next;
    }

    ListNode *p = head;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        p->next = list1;
        list1 = list1->next;
      } else {
        p->next = list2;
        list2 = list2->next;
      }

      p = p->next;
    }

    while (list1) {
      p->next = list1;
      list1 = list1->next;
      p = p->next;
    }

    while (list2) {
      p->next = list2;
      list2 = list2->next;
      p = p->next;
    }

    return head;
  }
};
