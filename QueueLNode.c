/*
 * @Author: Amelia
 * @email: zhangshan1@able-elec.com
 * @Date: 2023-02-22 16:23:29
 */
#include <stdbool.h>
#include <stdlib.h>
/**
 * 假设以带头结点的循环链表表示队列，
 * 并且只设一个指针指向队尾元素结点（注意：不设头指针），
 * 试编写相应的置空队列、判断队列是否为空、入队和出队等算法。 
**/
typedef struct Node {
  struct Node *next;
  int data;
} Node, *NodeL;
// 初始化空栈
NodeL initQueue() {
  NodeL node = (NodeL)malloc(sizeof(Node));
  node->next = node;
  return node;
}
// 入队
void pushQueue(NodeL queue, int e) {
  NodeL node = (NodeL)malloc(sizeof(Node));
  node->data = e;
  node->next = queue->next;
}
// 出队
void shfitQueue(NodeL queue) {
  NodeL tmp = queue->next;
  queue->next = queue->next->next;
  free(tmp);
}
// 判断空队列
bool isEmptyQueue(NodeL queue) {
  if(queue->next == queue->next->next) return true;
  return false;
}
// 清空队列
void clearQueue(NodeL queue) {
  while(queue->next != queue) {
    NodeL tmp = queue->next;
    queue->next = queue->next->next;
    free(tmp);
  }

  free(queue);
}