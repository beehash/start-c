#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct SElementType {
  int;
  char;
  bool;
};

typedef struct {
  int MaxSize;
  int *base;
  int *top;
} Stack, *StackL;

static StackL initStack(int MaxSize) {
  StackL s = (StackL)malloc(sizeof(Stack));
  s->MaxSize = MaxSize;
  s->base=(SElementType *)malloc(sizeof(SElementType));
  s->top = s->base;


  return s;
}

static bool isEmptyStack(StackL s) {
  if(s->base == s->top) return true; 
  return false;
}

static bool isFullStack(StackL s) {
  if(s->top - s->base == s->MaxSize) return true;
  return false;
}

static int pushStack(StackL s, int num) {
  if(isFullStack(s)) return INT_MIN;
  *s->top++ = num;
  return 0;
}

static int popStack(StackL s) {
  if(isEmptyStack(s)) return INT_MIN;
  int num = *--s->top;
  return num;
}

static int GetTop(StackL s) {
  if(isEmptyStack(s)) return INT_MIN;
  return *(s->top-1);
}
