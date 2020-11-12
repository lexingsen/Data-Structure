/*
 * @Description: 单链表选择排序
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-30 00:51:28
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
};


void selectSort(int *a, int n) {
  for (int i=0; i<n; ++i) {
    int minIndex=i;
    for (int j=i+1; j<n; ++j) {
      if (a[j] < a[minIndex]) {
        minIndex = j;
      }
    }
    if (i != minIndex) swap(a[i], a[minIndex]);
  }
}

class Solution {
public:
  ListNode *selectSort(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode* dummy = new ListNode();
    dummy->next = head;

    ListNode* p = head;
    while (p) {
      ListNode* tmp = p;
      ListNode* min = p;
      while (tmp) {
        if (tmp->val < min->val) {
          min = tmp;
        }
        tmp = tmp->next;
      }
      int t = p->val;
      p->val = min->val;
      min->val = t;

      p = p->next;
    }
    return dummy->next;
  }  
};






