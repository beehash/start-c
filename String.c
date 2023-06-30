/*
 * @Author: Amelia
 * @email: zhangshan1@able-elec.com
 * @Date: 2023-03-27 11:54:43
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
extern int printfArr(int *arr, int len);

// 串
// BF算法
static bool BFAlgorithum(char *str, char *tmp) {
  int i = 0, j = 0;
  while(!*(str+i) && !*(tmp+j)) {
    if(*(str+i) == *(tmp+j)) {
      i++; j++;
    } else {
      i = i-j+2;
      j = 0;
    }
  }
  return j >= strlen(tmp);
}

static int *KMPGetNext(char *tmp) {
  int i = 1, j = 0, len = strlen(tmp);
  int *next = (int *)malloc(sizeof(int) * (len + 1));
  next[0] = 0;
  while(i < len) {
    if(*(tmp+i) == *(tmp+j)) {
      next[i++] = ++j;
    } else if(j>0) {
      j = next[j-1];
    } else {
      next[i++] = 1;
    }
  }
  printfArr(next, len);
  return next;
}

// KMP算法
static bool KMPAlgorithum(char *str, char *tmp) {
  int *next = KMPGetNext(tmp);
  int i = 0, j = 0;
  next[0] = 0;
  while(*(str+i) && *(tmp+j)) {
    if(*(str+i) == *(tmp+j)) {
      i++;
      j++;
    } else if(j>0) {
      printf("%d \n", j);
      j = next[j-1];
    } else {
      i++;
    }
  }
}
/**
 * 已知模式串 t=“abcaabbabcab” 
 * 写出KMP法球的每个字符对应的next 和 nextval值。
 * */
static int *getNext2(char *t) {
  int i = 0, j = -1;
  int len = strlen(t);
  int *next = (int *)malloc(sizeof(int) * (len + 1));
  next[0] = -1;
  while(*(t+i)) {
    if(j == -1 || *(t+i) == *(t+j)) {
      next[++i] = ++j;
    } else{
      j = next[j];
    }
  }
  printf("next=:::\n");
  printfArr(next, len);
  return next;
}
static int *getnextval2(char *t) {
  int len = strlen(t);
  int *next = (int *)malloc(sizeof(int) * (len + 1));
  int i = 0, j = -1;
  next[0] = -1;

  while(*(t+i)) {
    if(j == -1 || *(t+i) == *(t+j)) {
      i++; j++;
      if (*(t+i) != *(t+j)) {
        next[i] = j;
      } else {
        next[i] = next[j];
      }
    }else {
      j = next[j];
    }
  }
  printf("\nnextval=:::\n");
  printfArr(next, len);
  return next;
}
/**
 * 设目标为t=“abcaabbabcaaacbacba”,
 * 模式为 p = “abcabaa”
 * 1. 计算模式p的nextval函数值；
 * 2. 画出利用KMP算法进行模式匹配时每一趟的匹配过程
 * */
// 略

/**
 * 数组A中，每个元素A[i,j]的长度均为32个二进位，行下标从-1到9，
 * 列下标从1到11，从首地址S开始连续存放主存储器中，主存储器字长为16位。
 * 求：
 * -1 ~ 9  , m= 9 , s = -1
 * 1 ~ 11  , n = 11, t = 1;
 * 元素字长：32位， 主存储器每个字包含的位数（字长）16
 * 单个元素存储的单元数= 32 / 16 = 2
 * 1，存放该数组所需多少单元？
 * = S + (11 * 11)L
 * = S + 121 * 2
 * = S + 242; 
 * 2, 存放数组第4列所有元素至少需多少单元？
 * = 11 * 2 = 22;
 * 3, 数组按行存放时，元素A[7,4]的起始地址是多少？
 * i = 7; j = 4;
 * = S + ((i - s) * ( n - t + 1) + (j - t)) * L（公式）
 * = S + 91L
 * = S + 182;
 * 4，数组按列存放时，元素A[4,7]的起始地址时多少？
 * i = 4, j = 7;
 * = S + ((j - t) * (m-s+1) + (i-s)) * L
 * = S + 71L
 * = S + 142;
 * */
/**
 * 请将香蕉banana 用工具H()-Head(), 
 * T - Tail() 从 L 中取出
 * L = (apple, (orange, (strawberry,(banana)), peach), pear);
 * H-H-T-H-T-H-T
**/
/**
 * 写一个算法，统计在输入字符串中各个不通过字符出现的频度
 * （字符串中的合法字符为A-Z这26个字母和0-9这10个数字）
 * A-Z 65 - 90
 * a-z 97 - 122
 * 0-9 48 - 57
**/
typedef struct {
  int num;
  int word;
  int Word;
} unWordTotal;
static int findBadWord(char *str) {
  int len = strlen(str);
  int i = 0, j = 0,k = 0;
  int wordcount[36] = {0};
  while(*(str+i)) {
    int item1 = (int)*(str+i) >= 48 && (int)*(str+i)<= 57;
    int item2 = (int)*(str+i) >= 65 && (int)*(str+i) <= 90;
    if(item1) {
      j++;
    } else if(item2) {
      k++;
    }
    i++;
  }
  return j;
}
/**
 * 写一个递归算法来实现字符串逆序存储,
 * 要求不另设存储空间
**/
static void revertString(char *str, int start, int end) {
  if(start >= end) {
    return;
  }
  char tmpchar = *(str+start); 
  *(str+start) = *(str+end);
  *(str+end) = tmpchar;
  revertString(str, start+1, end-1);
}
static void revertString2(char *str) {
  static int  i = 0; char c;
  c = *(str+i);
  if(c) {
    i++;
    revertString2(str);
    printf("%d, %c, %s", i, c, str);
    *(str+i) = c;
  }
  printf("11111 = %d , %c\n", i, c);
  *(str+i) = '\0';
}
/**
 * 编写算法，实现下面函数的功能。
 * 函数 void Insert(char *s, char *t, int pos) 
 * 将字符串t插入到字符串s中，插入位置为pos 
 * 假设分配给字符串s得空间足够让字符串t插入。
 * 不得使用任何库函数。
**/
static char *Insert(char *s, char *t, int pos) {
  int slen = strlen(s);
  int tlen = strlen(t);
  int i = 0;
  char *str = (char *)malloc(sizeof(s) + sizeof(t));
  while(i<(slen+tlen)) {
    if(i < pos) {
      *(str+i) = *(s+i);
    } else if(i == pos) {
      *(str+i) = *t;
    } else if(i > pos && i< pos+tlen) {
      *(str+i) = *(t+i-pos);
    } else if(i >= pos+tlen) {
      *(str+i) = *(s+i-pos-tlen);
    }
    i++;
  }
  *(str+i) = '\0';
  return str;
}
/**
 * 已知字符串s1中存放一段英文，写出算法 Format(s1, s2, s3, n);
 * 将其按给定的长度n 格式化成两端对齐的字符串s2
 * （即长度为n且首位字符不得为空格字符），
 * 其余字符为s3
**/ 
static void Format(char *s1, char *s2, char *s3, int n) {
  int len = strlen(s1);
  int i = 0; int j = 0;char c;
  while(c = *(s1+i)) {
    if(c == ' ' && (!*s2 || !*(s2+n-1))) {
      j++;
      i++;
      continue;
    }
    if(!*(s2+7)) {
      *(s2+i-j) = c;
      if(i-j == 7) {
        *(s2+8) = '\0';
      }
    } else {
      *(s3+i-j-n) = c;
    }
    i++;
  }
}
/**
 * 设二维数组a[1,...,m,1,...n]含有m * n个整数
 * 写一个算法判断a中所有元素是否互不相同？输出相关信息 （yes/no）
 * 试分析算法的时间复杂度。 O(n*m*m*n)
**/
static bool hasSameInDarr(int darr[][10], int m, int n) {
  int i; int j, k=0;
  int *arr=(int *)malloc(sizeof(int) * m * n);

  for(i = 0;i < m;i++) {
    for(j = 0;j < n;j++) {
      for(int o = 0; o < k; o++) {
        if(arr[o] == darr[i][j]) {
          free(arr);
          return true;
        }
      }
      arr[k++] = darr[i][j];
    }
  }

  free(arr);
  return false;
}
/**
 * 设任意n个整数存放于数组A(1:n)中，试编写算法
 * 将所有正数排在所有负数前面
 * （要求算法复杂度为O(n)）
 **/
static void sortInt(int arr[], int len) {
  int start = 0, end = len-1;
  for(start = 0; start<end; start++) {
    if(*(arr+start) > 0) {
      while(*(arr+end) > 0) {
        end--;
      }
      int tmp = *(arr+start);
      *(arr+start) = *(arr+end);
      *(arr+end) = tmp;
      end--;
    }
  }
  printfArr(arr, len);
}

/**
 * 
 * 
**/