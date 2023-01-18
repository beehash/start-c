#include <stdbool.h>
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
  StackL s = initStack(len/2);
  
  while(i < len) {
    if(len % 2 != 0 && i == mid + 1) {
      i++;
      continue;
    }
    if(i <= mid) {
      pushStack(s, *(str+i));
    } else {
      printf("%d ", *(s->top-1));
      if(GetTop(s) == *(str+i)) {
        popStack(s);
      }
    }
    i++;
  }

  return isEmptyStack(s);
}

/**
 * 设从键盘输入一整数的序列：a1，a2，a3，..., an,
 * 试编写算法实现：用栈结构存储输入的整数，
 * 当ai != 1 时，将ai 进栈，当ai=-1时，输出栈顶整数并出栈。
 * 算法应对异常情况（入栈满等）给出响应的信息。
 * */
// static int InputStack() {
//   int len, i;
//   printf("请输入整数序列的长度：%d", &len);
//   StackL s = initStack(len);
//   printf("请输入整数序列:");
//   for(i = 0; i<len; i++) {
//     int num;
//     scanf("%d", &num);
//     if(num != 1) {
//       num = pushStack(s, num);
//       if(num == INT_MIN) {
//         printf("栈已满，无法入栈！");
//       }
//     }
//     if(num == -1) {
//       num = popStack(s);
//       if(num == INT_MIN) {
//         printf("栈已空，无法删除！");
//       }
//     }
//   }
//   return 0;
// }