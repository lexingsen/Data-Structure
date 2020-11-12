/*
 * @Description: 单链表插入排序
 * @Language: 
 * @Author: 
 * @Date: 2020-11-05 22:25:25
 */
#include <bits/stdc++.h>
using namespace std;



struct ListNode {
  ListNode *next;
  int val;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      if (!head || !head->next) return head;
      ListNode* L = new ListNode(0);
      L->next = head;
      ListNode* p, *pre, *q;
      p = L->next->next;
      L->next->next = nullptr;
      while (p) {
        q = p->next;
        pre = L;
        while (pre->next && pre->next->val <= p->val) pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = q;
      }

      return L->next;
    }
};