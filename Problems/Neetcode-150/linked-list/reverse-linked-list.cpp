// https://leetcode.com/problems/reorder-list/

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode *p = nullptr, *q = head, *r = head->next;

    while (q != nullptr) {
      r = q->next;
      q->next = p;
      p = q;
      q = r;
    }

    return p;
  }
};
