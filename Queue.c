#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
  int front; // 头指针
  int rear; // 尾指针
  int *base; //数组存储
  int Maxsize;
} Queue, *QueueL;

static QueueL initQueue() {
  QueueL q = (QueueL)malloc(sizeof(Queue));
  q->front = q->rear = 0;
  q->base = (int *)malloc(sizeof(int));
  q->Maxsize = 10;
  return q;
}

static bool isEmptyQueue(QueueL q) {
  return q->front == q->rear;
}

static bool isFullQueue(QueueL q) {
  return (q->rear + 1 - q->front) % q->Maxsize == 0;
}

static int pushQueue(QueueL q, int e) {
  if(isFullQueue(q)) return INT_MIN;
  q->base[q->rear] = e;
  q->rear = (q->rear + 1) % q->Maxsize;
  printf("q->front: %d   ", q->front);
  return 0;
}

static int shiftQueue(QueueL q) {
  if(isEmptyQueue(q)) return INT_MIN;
  int *el = q->base + q->front;
  int e = *(q->base+q->front);
  q->front = (q->front + 1) % q->Maxsize;
  free(el);
  return e;
}

static int getTop(QueueL q) {
  if(isEmptyQueue(q)) return INT_MIN;
  return q->base[q->front];
}

static int getRear(QueueL q) {
  if(isEmptyQueue(q)) return INT_MIN;
  return q->base[(q->rear-1+q->Maxsize)%q->Maxsize];
}
