#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// _Bool flag;
/* 
将编号为 0和1 的两个栈存放于一个数组空间V[m]中，栈底分别处于数组的两端。
当0号栈的栈顶指针top[0]等于-1时，该栈为空；
当1号栈的栈顶指针top[1]等于 m时，该栈为空；
两个栈均从两端向中间增长。
试编写双栈初始化判断栈空、 栈满、进栈和出栈等算法的函数。
双栈数据的结构定义如下：
typedef struct {
  int top[2],bot[2]; // 栈顶和栈底指针
  SElemType *V; // 栈数组
  int n; // 栈最大可容纳的元素个数
}
双栈的结构表示：
bot[0]————————————top[0]---------top[1]————————————————bot[1]

top[0]=bot[0]=-1 // 栈空？
top[0]=m-1; // 栈满？

top[1]=top[1]=m; // 栈空？
top[1]=0; // 栈满
*/
typedef struct {
  int top[2], bot[2];
  int *V;
  int MaxSize;
} Stack, *StackL;

static Stack initDoubleStack() {
  // StackL s = (StackL)malloc(sizeof(Stack));
  Stack s;
  s.MaxSize = 10;
  s.top[0] = s.bot[0] = -1;
  s.top[1] = s.bot[1] = s.MaxSize;
  s.V = (int *)malloc(s.MaxSize);
  return s;
}

static int isEmptyStack(StackL s) {
  if(s->top[0] == -1 && s->top[1] == s->MaxSize) return 0;
  return 1;
}

static int isFullStack(StackL s) {
  if(s->top[0] + 1 == s->top[1]) return 0; // 判断是否栈满
  return 1;
}

static int pushStack1(StackL s, int num) {
  if(isFullStack(s) == 0) return 1; // 判断是否栈满
  s->top[0]++; // 栈顶指针加 1
  s->V[s->top[0]] = num; // 将元素压入栈
  return 0;
}

static int pushStack2(StackL s, int num) {
  if(isFullStack(s) == 0) return 1;
  s->top[1]--; // 栈顶指针减1
  s->V[s->top[1]] = num; // 将元素压入栈
  return 0;
}

static int popStack1(StackL s) {
  if(isEmptyStack(s) == 0) return INT_MIN; // 判断是否是空栈  
  int *num = s->V + s->top[0]; // 保存元素指针
  s->top[0]--;
  printf("num: %d   ,    \n",  s->V[s->top[0]]);
  return *num;
}

static int popStack2(StackL s) {
  if(isEmptyStack(s) == 0) return INT_MIN;
  int num = s->V[s->top[1]]; // 保存元素指针
  s->top[1]++;
  return num;
}

/*
回文是指正读和反读均相同地字符序列,如 "abba" 和 "abdba" 均是回文,但 "good" 不是回文.
试写一个算法判定给定地字符序列是否为回文.(提示: 将一半字符入栈)
*/