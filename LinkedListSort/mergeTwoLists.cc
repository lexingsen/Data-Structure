/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-11-06 09:26:08
 */
#include <bits/stdc++.h>
using namespace std;



struct ListNode {
  ListNode *next;
  int val;
  ListNode(int x) : val(x), next(NULL) {}
};

// 递归
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  if (!l1) return l2;
  if (!l2) return l1;
  if (l1->val <= l2->val) {
    l1->next = mergeTwoLists(l1->next, l1);
    return l1;
  } else {
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }
}

// 迭代
ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {  
  ListNode* dummy = new ListNode(-1), *p=dummy;
  while (l1 && l2) {
    if (l1->val <= l2->val) {
      p->next = l1;
      l1 = l1->next;
    } else{
      p->next = l2;
      l2 = l2->next;
    }
    p = p->next;
  }
  if (!l1) p->next = l2;
  if (!l2) p->next = l1;
  return dummy->next;
}


