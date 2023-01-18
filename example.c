/*
 * @Author: Amelia
 * @email: zhangshan1@able-elec.com
 * @Date: 2022-10-08 13:07:59
 */
//
// Created by 41018 on 2022/10/8.
//
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <string.h>

void printfFn() {
  printf("float 存储最大字节数 : %zd \n", sizeof(float));
  printf("Size of int: %zd bytes\n",sizeof(int));
  printf("Size of double: %zd bytes\n",sizeof(double));
  printf("Size of char: %zd byte\n",sizeof(char));

  printf("float 最小值: %E\n", FLT_MIN );
  printf("float 最大值: %E\n", FLT_MAX );
  printf("精度值: %d\n", FLT_DIG );


  int i = 2; // 定义整型
  printf("int i is %d \n", i);

  float f;
  f = 12.001234;       // 定义浮点数变量
  printf("f 的值为 %.6f \n", f);

  double d = 12.0012346;       // 定义双精度变量
  printf("double d is %lf\n", d);

  char c = 'A'; // 定义字符
  printf("%c 的 ASCII 为 %d", c, c);

  long int ld = 1;
  printf("long int ld is %ld", ld);

  long long lld = 1;
  printf("long long lld is %lld", lld);

  unsigned long long unlld = 1;
  printf("unsigned long long unlld is %llu", unlld);

  char time[10];
  sprintf(time, "number=%d", 31);
  printf("%s", time);

  printf("F-A等于:%c, %c", 9+'0', 'a'+5);
}

void scanerFn() {
 int number;

 printf("输入一个数字: ");
 scanf("%d", &number);
 printf("你输入的是%d\n", number);

 if(number <= 0) {
   if(number == 0) {
    printf("你输入的是0\n");
   } else {
    printf("你输入的是负数\n");
   }
 } else {
  printf("你输入的是正数\n");
 }
}
void getSum() {
  int number, sum;
  printf("请输入数字：");
  scanf("%d", &number);
  printf("你输入的是%d\n", number);

  for(int i = 1; i <= number; i++) {
    sum += i;
  }
  printf("从1到%d相加得：%d\n", number, sum);
}
void multiTable() {
  for(int i = 1; i < 10; i++) {
    for(int j = 1; j <= i; j++) {
      int val = i * j;
      if(val < 10) {
        printf("%d*%d=%d   ", j, i, val);
      } else {
        printf("%d*%d=%d  ", j, i, val);
      }
    }
    printf("\n");
  }
}

int factorial() {
  int number;
  unsigned long long factorial = 1;
  printf("请输入一个数字：");
  scanf("%d", &number);
  if(number <0 ){
    printf("负数没有阶乘");
    return 0;
  }
  
  for(int i = 1; i <= number; i++) {
    factorial *= i;
  }
  printf("%d的阶乘是%d", number, factorial);
  return 0;
}
void printChar() {
  char c;
  for(c = 'a'; c <= 'z'; ++c) {
    printf("%c ", c);
  }
}
// 二进制转十进制
void convertBinaryToDecimal() {
  long long number;
  printf("请输入你想转为十进制的二进制数：");
  scanf("%d", &number);
  int number1 = number;

  int decimalNum = 0, i = 0;
  while (number!=0) {
    decimalNum += (number % 10) * pow(2, i);
    number /= 10;
    ++i;
  }

  printf("%lld的十进制为：%d\n", number1, decimalNum);
}

// 十进制转二进制
void convertDecimalToBinary() {
  int number;
  printf("请输入你想转为二进制的十进制数：");
  scanf("%d", &number);
  int number1 = number;

  long long binaryNum = 0, i = 1;
  while(number!= 0) {
    printf("setp: %d, number: %d, 余数：%d, %d\n", i,number, number % 2);
    binaryNum += (number % 2) * i;
    number = number / 2;
    i *= 10;
  }
  printf("%d 的二进制为：%lld\n", number1, binaryNum);
}
// 十进制转八进制
void convertDecimalTo() {
  int number, number1, octalNumber=0, i = 1, type;
  printf("请输入要转换的结果进制：");
  scanf("%d", &type);
  printf("请输入一个十进制数:");
  scanf("%d", &number);
  number1 = number;
  while(number!=0) {
    octalNumber += (number % type) * i;
    number = number / type;
    i *= 10;
  }
  printf("%d的%d进制为：%d\n", number1, type, octalNumber);
}
// 八进制转十进制
void convertToDecimal() {
  int number, number1, decimalNum, i = 0, type;
  printf("请输入要转换的进制：");
  scanf("%d", &type);
  printf("请输入一个%d进制数:", type);
  scanf("%d", &number);
  number1 = number;
  while(number != 0) {
    decimalNum += (number % 10) * pow(type, i);
    number = number / 10;
    i++;
  }
  printf("%d的%d进制为：%d", number1, type, decimalNum);
}

void convertOxtoDecimal() {
  char s[50], s1[50];
  int decimal=0;
  printf("请输入一个十六进制数:");
  scanf("%s", s);
  strcpy(s1, s);
  for (int i = 0, l = strlen(s); i < l; i++) {
    if(s[i] >= 'A' && s[i] <= 'Z')
      s[i] = (int)(s[i] - 'A') + 10 + '0';
    else if(s[i] >= 'a' && s[i] <= 'z')
      s[i] = (int)(s[i] - 'a') + 10 + '0';

     decimal += (s[i]-'0') * pow(16, l-i-1);// l - i - 2 321, 3/2 12 
  }
  printf("%s的十进制为:%d", s1, decimal);
}
void convertDecimaltoOx() {
  int number,number1, i=0;
  char *oxchar = "0123456789abcdef";
  char s[50];
  printf("请输入一个十进制数：");
  scanf("%d", &number);
  number1 = number;
  while(number != 0) {
    int remainder = number % 16;
    s[i++] = oxchar[remainder];
    number = number / 16;
  }
  printf("%d的十六进制为:%s\n", number1, s);
}
/* 
  @description {字符串反转}
  @runner code {
    printf("输入一个字符串: ");
    reverseSentence();
  }
*/
void reverseSentence() {
  char c;
  scanf("%c", &c);
  if(c != '\n') {
    reverseSentence();
    printf("%c",c);
  }
}
// 数组遍历
// extern int pointerGetArr(int *, int);
// int arr[] = {1,2,3,4,5,6};
// pointerGetArr(arr, sizeof(arr) / sizeof(arr[0]));
void pointerGetArr(int arr[], int len) {
  for(int i = 0; i< len; i++) {
    printf("数组第%d个元素的值为：%d\n", i, *(arr + i));
  }
  int arr2[5] = {1, 2, 6, 3, 5};
  int *tmp = arr2;
  int j = 0;
  while(*tmp) {
    printf("数组第%d个元素的值为：%d\n", j, *tmp);
    j++;
    tmp++;
  }
  printf("i=%d, j=%d\n", 6, j);
}
// 输入输出
void putsgets() {
  char c;
  // getchar & putchar
  printf("enter a value:");
  c = getchar();
  printf( "\nYou entered: ");
  putchar(c); // 输出到控制台

  // gets & puts
  char str[100];
  printf("\nput a sentence :");
  gets(str);

  printf("\nyour entered sentence:");
  puts(str);

  // printf & scanf
  int i;
  printf("Enter a number :");
  scanf("%d", &i);
  printf("\nyou've entered:%d\n", i);
}
// 将字符写入文件
void writeFile() {
  char sentence[1000];
  FILE *filex;
  filex = fopen("E:\\private.c\\start-p\\runoob.txt", "w");

  if(filex == NULL) {
    printf("Error!");
    exit(1);
  }
  
  // -----------------------------fgets & fputs------------------------------------
  printf("输入字符串:\n");
  // 将从 stdin(控制台) 的地方读取到的 数据，存入 缓冲区sentence
  fgets(sentence, (sizeof sentence / sizeof sentence[0]), stdin);
  // 把字符串 sentence 写入到 filex 所指向的输出流中
  fputs(sentence, filex);
  // fclose(filex);

  
  // ------------------------------------fgetc & fputc-------------------------------------------
  // filex = fopen("E:\\private.c\\start-p\\runoob.txt", "w");
  printf("输入一个字符");
  char c;
  // fgetc(stdin); 从控制台中读取一个字符
  c = fgetc(stdin);
  // fputc('c', filex); 写入一个字符到文件中去
  fputc(c, filex);
  fclose(filex);


  // --------------------------------------------fscanf & fprintf----------------------------------------
  // filex = fopen("E:\\private.c\\start-p\\runoob.txt", "w");
  printf("\n请输入一个字符串:\n");
  // fscanf: 从 stdin (控制台) 读取一个字符串到 缓冲区 sentence 但遇到第一个空格和换行符会停止读取
  fscanf(stdin, "%s", sentence);
  // fprintf：将 sentence 字符串内容 写入到 文件 filex 所指向的 输出流中去
  fprintf(filex, "%s", sentence);
  fclose(filex);

  // -----------------------------------------------fwrite & fread---------------------------------------------
  filex = fopen("E:\\private.c\\start-p\\runoob.txt", "wb");
  char str[1000];
  sentence[0] = '\0';
  printf("请输入字符串：%s1111111111\n", sentence);
  // 从stdin (终端) 读取一个字符串到 缓冲区 str，遇到空格和换行符不会停止，直至长度用完
  fread(str, sizeof(char)+1, 10, stdin);
  printf("你输入的字符长度为：%d, char: %d,sentence: %s", strlen(str), sizeof(char), str);
  // 将缓冲区 str 的内容写入 filex 所指向的输出流
  fwrite(str, strlen(str) + 1, 1, filex);

  fclose(filex);
}

// 从文件中读取
void readFilex() {
  printf("readFilex: 11111");
  FILE *filex;
  filex = fopen("E:\\private.c\\start-p\\runoob.txt", "r");
  if(filex == NULL) {
    printf("error");
    exit(1);
  }
  char sentence[1000];

  // --------------------------------fgets 读取文件-------------------------------
  fgets(sentence, 1000, filex);
  printf("fgets 读取到的内容是：\n%s\n", sentence);
  fclose(filex);
  
  
  // -------------------------------fgetc 读取文件----------------------------------------
  filex = fopen("E:\\private.c\\start-p\\runoob.txt", "r");
  char c;
  c = fgetc(filex);
  printf("\nfgetc 读取到的字符是：%c\n", c);
  fclose(filex);

  
  // --------------------------------fscanf 读取文件------------------------------------
  filex = fopen("E:\\private.c\\start-p\\runoob.txt", "r");
  fscanf(filex, "%s", sentence);
  printf("fsanf 读取到的内容是：\n%s\n", sentence);
  fclose(filex);

  // --------------------------------fgets读取整个文件内容------------------------------------------
  filex = fopen("E:\\private.c\\start-p\\runoob.txt", "r");
  // 将文件指针指向末尾
  fseek(filex, 0, SEEK_END);
  // 获取指针到文件头的偏移字节数
  int filesize = ftell(filex);
  char *str;
  // 动态分配 str 内存
  str = (char *)malloc(filesize);
  str[0] = 0;//清空字符串
  rewind(filex);

  while(fgets(sentence, 1000, filex) != NULL) {
    strcat(str, sentence);
  }
  printf("整个文件的内容：\n%s\n", str);
  fclose(filex);
  // ------------------------------------fgetc读取整个文件-----------------------------------------
  printf("fgetc读取整个文件:\n");
  filex = fopen("E:\\private.c\\start-p\\runoob.txt", "r");
  do {
    c=fgetc(filex);
    putchar(c);
  }while(c != EOF);
  putchar(c);
  fclose(filex);
  printf("\nfgetc读取整个文件结束\n");
  // -------------------------------fread 读取文件--------------------------------------------
  
  filex = fopen("E:\\private.c\\start-p\\runoob.txt", "r");
  // str[0] = 0;
  char *str2;
  str2 = (char *)malloc(filesize);
  // memset(str2, 0, filesize);
  rewind(filex);
  // fread(str, sizeof(char)+1, 10, stdin);
  fread(str2, filesize, 1, filex);
  str2[filesize-2] = '\0';
  printf("fread 读取的文件内容：\n%s\n filesize: %d", str2, filesize);

  fclose(filex);
}
// 获取控制台输入的整数序列
void getintegerListByConsole() {
  int i,n;
  printf("请输入整数序列的长度:");
  scanf("%d",&n);
  int array[n];
  printf("请输入整数序列:");
  for(i=0;i<n;i++) 
   scanf("%d",&array[i]);
}
// 约瑟夫生死游戏
void lifeGame() {
  int i = 1; int j = 1, k=0; int a[30]= { 0 };
  while(i <= 31) {
    if(i == 31) {
      i = 1;
    }
    if(j == 9) {
      if(!a[i]) {
        printf("第%d号下船了, a[j]: %d\n", i, a[i]);
        a[i] = 1;
        j = 0;
        k++;
      } else {
        j--;
        continue;
      }
    }
    if(k == 15) {
      break;
    }

    j++;
    i++;
  }
}
