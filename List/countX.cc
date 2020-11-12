/*
 * @Description: 统计值为x节点的个数
 * @Language: 
 * @Author: 
 * @Date: 2020-11-06 11:34:34
 */


struct ListNode {
  int val;
  ListNode *next;
};


int countX(ListNode *head, int x) {
  int res = 0;
  ListNode *p = head;
  while (p) {
    if (p->val == x) res ++;
    p = p->next;
  }
  return res;
}