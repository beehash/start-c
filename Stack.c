#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int MaxSize;
  int *base;
  int *top;
} Stack, *StackL;

static void initStack(StackL s) {
  s->MaxSize = 10;
  s->base=(int *)malloc(sizeof(int));
  s->top = s->base;
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
