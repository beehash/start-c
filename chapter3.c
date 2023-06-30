#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Stack.c"
/**
 * 回文是指正读反读均相同的字符序列，如“abba” 和 “abdba” 均是回文，
 * 但 “good” 不是回文。试写一个算法判断给定的字符序列是否为回文。
 * （提示：将一半字符入栈）
 **/

bool isPalindromic(char* str) {
  int i = 0;
  int len = strlen(str);
  int mid = (len-1)/2;
  char str2[len/2];
  
  while(i < len) {
    if(len % 2 != 0 && i == mid + 1) {
      i++;
      continue;
    }
    if(i <= mid) {
      str2[i] = *(str+i);
    } else {
      if(*(str2+len-i-1) != *(str+i)) {
        return false;
      }
    }
    i++;
  }

  return true;
}

/**
 * 设从键盘输入一整数的序列：a1，a2，a3，..., an,
 * 试编写算法实现：用栈结构存储输入的整数，
 * 当ai != 1 时，将ai 进栈，当ai=-1时，输出栈顶整数并出栈。
 * 算法应对异常情况（入栈满等）给出响应的信息。
 * */
int InputStack() {
  int len, i;
  printf("请输入整数序列的长度：");
  scanf("%d", &len);
  StackL s = initStack(len);
  printf("请输入整数序列:");
  int num;
  while(scanf("%d", &num)) {
    if(num != 1) {
      int isFull = pushStack(s, num);
      if(isFull == INT_MIN) {
        printf("栈已满，无法入栈！");
        return 1;
      }
    }
    if(num == -1) {
      int isEmpty = popStack(s);
      if(isEmpty == INT_MIN) {
        printf("栈已空，无法删除！");
        return 1;
      }
    }
  }
  return 0;
}
/**
 * 从键盘上输入一个后缀表达式，试编写算法计算表达式的值。
 * 规定：后缀表达式的长度不超过一行，以“$” 作为输入结束，
 * 操作数之间用空格分割，操作符只可能有+、-、*、/四种运算。
 * 例如：23434 + 2 * $
 * 23 434 + 2 *$
 * 931-3*+102/+
 * 9+((3-1)*3)+10/2)
 * */
float compute(char optchar, float a, float b) {
  printf("optchar=%c, a=%f, b=%f \n", optchar, a, b);
  int result;
  switch(optchar) {
    case '+':
      result = a+b;
      break;
    case '-':
      result = a-b;
      break;
    case '*':
      result = a*b;
      break;
    case '/':
      result = a/b;
      break;
  }
  return result;
}
int isoptchar(char a) {
  if(a == '+' || a == '-' || a == '/' || a == '*') return true;
  return false;
}
char* getNumberStr(char *str, int len) {
  char *numberstr = (char *)malloc(len*sizeof(char));
  int i = 0;
  while(len--) {
    char curchar = *(str+i);
    if(isoptchar(curchar)) {
      return numberstr;
    } else {
      numberstr[i++]=curchar;
    }
  }
  return numberstr;
};

char *computeSuffixStr() {
  char *expressionstr = malloc(100*sizeof(char));
  int i = 0;
  int j = 0;
  char curchar;
  char leftnumstr[10];
  char rightnumstr[10];
  char resultstr[10];
  int left = 0;
  while((curchar = getchar()) != '$') {
    if(curchar == ' ') {
      if(i > 0 && j ==0) {
        left = 1;
      }
      if(i == 0 && j == 0) {
        left = 0;
      }
      
    } else if((curchar>= '0' && curchar <= '9') || curchar == '.'){
      if(left) {
        rightnumstr[j++] = curchar;
      } else {
        leftnumstr[i++] = curchar;
      }
    } else if(isoptchar(curchar)) {
      float result = compute(curchar, atof(leftnumstr), atof(rightnumstr));
      
      // 清空字符串
      memset(leftnumstr, 0, sizeof(leftnumstr));
      memset(rightnumstr, 0, sizeof(rightnumstr));
      i = 0;
      j = 0;

      // 赋值左边结果为左边字符串
      sprintf(leftnumstr, "%f", result);
      i = strlen(leftnumstr);
    }
  }
  printf("结果为：%s", leftnumstr);
}

/**
 * 假设以 I 和 O 分别表示入栈和出栈操作。栈的初态和中泰均为空，
 * 入栈和出栈的操作序列可表示为仅由 I 和 O 组成的序列，
 * 称可以操作的序列为合法序列，否则称为非法序列。
 * (1)下面所示的序列中哪些是合法的？
 * A. IOIIOIOO  B.  IOOIOIIO   C. IIIOIOIO   D. IIIOOIIOO
 * 通过对（1）的分析，写出一个算法，判断所给的序列的操作序列是否合法。
 * 若合法，返回true，否则返回false（假定被判定的操作序列已存入一维数组中）
**/
bool isLegalSequence(char *str) {
  int len = strlen(str);
  int i = 0;
  int j = 0;
  char list[len+1];
  while(*str != '\0') {
    if(*str == 'I') {
      list[j++] = *str;
    } else if(*str == 'O') {
      list[j--] = '\0';
    }
    *str++;
  }
  return j == 0;
}
/**
 * 假设以数组Q[m]存放循环队列中的元素，同时设置一个标志tag，
 * 以tag == 0 和tag == 1 来区别再队头指针（front）和队尾指针（rear）相等时，队列状态为“空”还是“满”。
 * 试编写与此结构相应的插入 （EnQueue）和删除（DeQueue）算法。
**/
typedef struct {
  int *Q;
  int tag;
  int front;
  int rear;
  int m;
} Queue, *QueueL;
void EnQueue(QueueL queue, int e) {
  if(queue->front == queue->rear && queue->tag == 1) {
    printf("队满！");
    exit(0);
  }
  queue->Q[queue->rear] = e;
  queue->rear = (queue->rear+1) % queue->m;
  queue->tag = queue->front == queue->rear ? 1 : 0;
}

int DeQueue(QueueL queue) {
  if(queue->front == queue->rear && queue->tag == 0) {
    printf("队空！");
    return -1;
  }
  int elem = queue->Q[queue->front];
  queue->front = (queue->front + 1) % queue->m;
  queue->tag = queue->front == queue->rear ? 0 : 1;
  return elem;
}
/**
 * 如果允许在循环队列的两端都可以进行插入和删除操作。
 * 要求：
 * （1）写出循环队列的类型定义；
 * （2）写出“从队尾删除”和“从队头插入”的算法
**/
typedef struct Queue {
  int front;
  int rear;
  int *Q;
  int size;
} QueueC, *QueueCL;

// 从队尾删除
int popQueue(QueueCL queue) {
  if(queue->front == queue->rear) {
    printf("队空！");
    return -1;
  }
  queue->rear = queue->rear - 1 + queue->size;
  int elem = queue->Q[queue->rear - 1 + queue->size];
  return elem;
}
// 从队头入队
void unshfitQueue(QueueCL queue, int e) {
  if((queue->rear - queue->front) % queue->size == 0) {
    printf("队满！");
    exit(0);
  }
  // 循环队列的减法： queue->front - 1+ queue->size;
  queue->front = (queue->front - 1 + queue->size) % queue->size;
  queue->Q[queue->front] = e;
}
/**
 * 已知Ackermann函数定义如下：
 * Ack(m,n) = 
 *    - n+1,                      当 m = 0 时，
 *    - Ack(m-1, 1),              当 m != 0，n = 0 时，
 *    - Ack(m-1, Ack(m, n-1)),    当 m != 0, n !=0 时，
 * （1）写出计算Ack(m, n)的递归算法，并根据此算法给出 Ack(2, 1) 的计算过程.
 * （2）写出计算Ack(m, n)的非递归算法。
 * 计算过程如下：
 * Ack(2,1)
 *  = Ack(1, Ack(2, 0))
 *  = Ack(1, Ack(1, 1))
 *  = Ack(1, Ack(0, Ack(1, 0)))
 *  = Ack(1, Ack(0, Ack(0, 1)))
 *  = Ack(1, Ack(0, 2))
 *  = Ack(1, 3)
 *  = Ack(0, Ack(1, 2))
 *  = Ack(0, Ack(0, Ack(1, 1)))
 *  = Ack(0, Ack(0, Ack(0, Ack(1, 0))))
 *  = Ack(0, Ack(0, Ack(0, Ack(0, 1))))
 *  = Ack(0, 4)
 *  = 5
**/
int Ack(int m, int n) {
  if(m == 0) {
    return n+1;
  } else if(n == 0) {
    return Ack(m-1, 1);
  } else {
    return Ack(m-1, Ack(m, n-1)); // n-- =0, m-1, 1; m-1-1, 1; m--=0, 1+m+n
  }
}
int Ack2(int m, int n) {
  int result[100];
  int i = 0;
  if(m == 0) return n+1;
  while(m != 0) {
    if(n == 0) {
      m--;
      n = 1;
    } else {
      n = m + n;
      m--;
    }
  }
  return n+1;
}
/**
 * 已知f为单链表的表头指针，链表中存储的都是整型数据，
 * 试写出实现下列运算的递归算法：
 * （1）求链表中的最大整数；
 * （2）求链表中的结点个数；
 * （3）求所有整数的平均值；
**/
typedef struct Node {
  struct Node *next;
  int data;
} lnode, *lnodep;
// 求最大整数
int getMaxInt(lnodep node) {
  int curdata = node->data;
  int nextdata = getMaxInt(node->next);
  return curdata < nextdata ? nextdata : curdata;
}
// 计算结点数
int countNode(lnodep node) {
  int count = 0;
  if(node == NULL) {
    return 0;
  }
  return 1 + countNode(node->next);
}
int getSum2(lnodep node, int *count) {
  return 10;
}
// 求平均数
int getEvenNum(lnodep node) {
  lnodep head = node;
  int curdata = node->data;
  int *count = 0;
  int sum = getSum2(node, count);
  return sum / *count;
}
// 获取头部字符串
int getHead(int a, int b) {
  return a+b;
}

