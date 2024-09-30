// https://leetcode.com/problems/reorder-list/description/

class Solution {
public:
  ListNode *getSecondLastNode(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return nullptr;

    ListNode *p = head, *q;
    while (p->next != nullptr) {
      q = p;
      p = p->next;
    }

    return q;
  }
  void reorderList(ListNode *head) {
    if (head == nullptr)
      return;

    ListNode *p = head, *q = head->next;
    while (p != nullptr && p->next != nullptr) {
      q = p->next;

      ListNode *r = getSecondLastNode(q);
      if (r != nullptr) {
        r->next->next = q;
        p->next = r->next;
        r->next = nullptr;
      }

      p = q;
    }
  }
};
