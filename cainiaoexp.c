//
// Created by 41018 on 2022/8/30.
//

#include "cainiaoexp.h"




#define MESSAGE "hello"

void ifdefinefn () { // ifndef ----- endif
    #ifndef MESSAGE
    #define MESSAGE "You wish!"
    #endif

    printf( "redefine Message : %s\n",  MESSAGE);
}

// 变量指针操作
void indexOpt() {
    int aa = 1;
    int *p2 = &aa;
    printf( "index is : %d\n",  *p2); // value
    printf( "index's address is : %p\n",  p2); // address
}

// union
void uionfn() {
    union DATA {
        int a;
        char b[30];
        float c;
        double d;
    };
    union DATA data;
    data.a = 1;
    strcpy(data.b, "11");
    data.c = 2;
    data.d = 2.3;

    printf( "Memory size occupied by data : %llu\n", sizeof(data));
    printf( "union.a's value is : %d\n",  data.a);
    printf( "union.b's value is : %s\n",  data.b);
    data.c = 12.001234;
    printf( "union.c's value is : %f\n",  data.c);
    printf( "union.d's value is : %f\n",  data.d);
}

// two numbers
void add() {
    int a, b;
    printf("please input two numbers, split with space:");
    scanf("%d%d", &a, &b);
    printf("sum is %d \n", a+b);

    double c = 1.2, d=2.345;
    printf("%lf * %lf = %lf", c, d, c*d);
}

// 枚举
void enumfn() {
    enum DAY {
        MON=1, TUE, WED, THU, FRI, SAT, SUN
    };
    enum DAY day;

    day = WED;

    printf( "today is : %d\n",  day);
}

// 比较大小
int vmax (int x, int y) {
    return x > y ? x : y;
}

// 函数指针操作
void indexfunc(int (*getmax)(int, int)) {
    /* p 是函数指针 */
    int (*p)(int, int) = &vmax; // &可以省略'

    int resultp = p(1, 2);
    int resultgetmax = getmax(3, 4);
    printf("resultp is: %d\n", resultp);
    printf("resultp is: %d\n", resultgetmax);
    printf( "index's address is : %p\n",  *p);
}

// 通过索引获取数组的值
void getItemByIndex() {
  int data[5] = {1,2,3,4,5 }, i;
  for(i=0; i<5; i++) {
    printf("data[%d] is: %d\n", i, *data+i);
  }
  printf("the length of data is: %llu\n", sizeof(data));
}

// 打印乘法表
void multiTables() {
    for(int i = 1; i< 10; i++) {
        for(int j = 1; j<=i; j++) {
            printf("%d * %d = %d ", j, i, i*j);
        }
        printf("\n");
    }
}

// 斐波那契数列
int fobocci(int n) {
    if(n == 0) return 0; // 是否是
    if(n == 1) return 1;
    return fobocci(n-1) + fobocci(n-2);
}

// 获取最大公约数
void getGreatestCommonDivsor1(int a, int b) {
    int r;
    for(int i = 1; i <=a && i <=b; i++) {
        if(a % i == 0 && b % i == 0) {
            r = i;
        }
    }
    printf("%d and %d the biggestcommon divsor number is: %d \n", a, b, r);
}

// 获取最大公倍数
void getGreatestCommonDivsor2(const int list[]) {
    int min = list[0];
    int len = 0;
    int r;
    printf("%d", &list[7] == NULL);
    for(int i = 0; &list[i] != NULL; i++) {
        if(min < list[i]) {
            min = list[i];
        }
        len++;
    }
    for(int i= 1; i<min; i++) {
        int count = 0;
        for(int j = 0; &list[j] != NULL; j++) {
            if(list[j] % i == 0) {
                count++;
            }
        }
        if(count == len) {
            r = i;
        }
    }
    printf("array's the biggestcommon divsor number is: %d \n", r);
}

/*
 * main 函数中调用
 *
 *  extern void ifdefinefn();
    extern int max();
    extern void indexOpt();
    extern void uionfn();
    extern void enumfn();
    extern void indexfunc(int (*p)(int, int));
    extern void getItemByIndex();
    extern void add();
    extern void multiTables();
    extern int fobocci();
    extern void getGreatestCommonDivsor1(int, int);
    extern void getGreatestCommonDivsor2(const int arr[]);
 * main() {
      indexOpt();
      uionfn();
      enumfn();
      ifdefinefn();
      indexfunc(max2);
      getItemByIndex();
      add();
      multiTables(); 0 1 1 2
      printf("the 4-digit output: %d\n", fobocci(4));
      getGreatestCommonDivsor1(12, 8);
   }
 *
 *
 * */