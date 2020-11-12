/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-11-05 23:08:52
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
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* tail = NULL;
    quickSort(head, tail);
    return head;
  }


  void swap(ListNode* &a, ListNode* &b) {
    int t = a->val;
    a->val = b->val;
    b->val = t;
  }

  void quickSort(ListNode* &head, ListNode* &tail) {
    if (head == tail) return;
    ListNode* mid = partition(head, tail);
    quickSort(head, mid);
    quickSort(mid->next, tail);
  } 

  ListNode* partition(ListNode* head, ListNode* tail) {
    int x = head->val;
    ListNode* p = head;
    ListNode* q = head->next;
    while (q) {
      if (q->val < x) {
        p = p->next;
        swap(p,q);
      }
      q = q->next;
    }
    swap(p, head);
    return p;
  }
};