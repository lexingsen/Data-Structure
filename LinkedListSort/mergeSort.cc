/*
 * @Description: 单链表快速排序 
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-26 09:29:23
 */
#include <bits/stdc++.h>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;

  ListNode(int val):val(val) {

  }
};

ListNode* sortList(ListNode *head) {
  int n = 0;
  for (auto p=head; p; p=p->next) n ++;
  auto dummy = new ListNode(-1);
  dummy->next = head;
  for (int i=1; i<n; i*=2) {
    auto cur = dummy;
    for (int j=0; j+i<n; j+=i*2) {
      auto left = cur->next, right = cur->next;
      for (int k=0; k<i; ++k) right = right->next;
      int l=0, r=0;
      while (l<i && r<i && right) {
        if (left->val <= right->val) {
          cur->next = left;
          cur = left;
          left = left->next;
          l ++;
        } else {
          cur->next = right;
          cur = right;
          right = right->next;
          r ++;
        }
      }

      while (l < i) {
        cur->next = left;
        cur = left;
        left = left->next;
        l ++;
      }

      while (r < i && right) {
        cur->next = right;
        cur = right;
        right = right->next;
        r ++;
      }
      cur->next = right;
    }
  }
  return dummy->next;
}


void merge(int *a, int l, int m, int r) {

}


void mergeSort(int *a, int n) {
  for (int i=1; i<n; i*=2) {
    for (int j=0; j+i<n; j+=i*2) {
      merge(a, j, j+i, min(j+i+i-1, n-1));
    }
  }
}


class Solution {
public:
  ListNode* mergeSort(ListNode *head) {
    if (!head || !head->next) 
      return head;
    else {
      ListNode *fast=head, *slow=head;
      while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
      }
      // 此时slow指向的节点就是中间节点
      fast = slow;
      slow = slow->next;
      fast->next = nullptr;
      fast = mergeSort(head);
      slow = mergeSort(slow);
      return merge(fast, slow);
    }
  } 

  ListNode* merge(ListNode *left, ListNode *right) {
    if (!left) return right;
    if (!right) return left;
    if (left->val <= right->val) {
      left->next = merge(left->next, right);
      return left;
    } else {
      right->next = merge(left, right->next);
      return right;
    }
  }

  ListNode* merge(ListNode* left, ListNode* right) {
    
  }
};

int main() {
  
}