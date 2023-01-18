#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *front;
  Node *rear;
} Queue, *QueueL;

static QueueL initQueueNode() {
  QueueL q = (QueueL)malloc(sizeof(Queue));
  q->front = q->rear = NULL;
  return q;
}

// 链表队列，不需要判断队满的情况
static bool isEmptyQueue(QueueL q) {
  return q->front ? false : true;
}

static void pushQueue(QueueL q, int e) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->data = e;
  p->next = NULL;
  if(q->rear) {
    q->rear->next = p;
  }
  q->rear = p;
  
  if(!q->front) {
    q->front = q->rear;
  }
}

static int shiftQueue(QueueL q) {
  if(isEmptyQueue(q)) return INT_MIN;
  Node *tmp = q->front;
  int data = tmp->data;
  q->front = tmp->next;
  if(!q->front) {
    q->rear = NULL;
  }
  free(tmp);
  return data;
}

static int GETTOP(QueueL q) {
  if(isEmptyQueue(q)) return INT_MIN;
  return q->front->data;
}

static int GETREAR(QueueL q) {
  if(isEmptyQueue(q)) return INT_MIN;
  return q->rear->data;
}
