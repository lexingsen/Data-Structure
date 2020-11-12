/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-11-05 22:43:42
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
      ListNode* p = nullptr;
      bool isChange = true;
      while (p != head->next && isChange) {
        ListNode* q = head;
        isChange = false;
        for(; q->next && q->next != p; q=q->next) {
          if (q->val > q->next->val) {
            isChange = true;
            swap(q->val, q->next->val);
          }
        }
        p = q;
      }

      return head;
    }
};