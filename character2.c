#include "LNode.c"

typedef struct QLIST {
  Book *elem; // 存储空间的基地址
  int length; // 图书表中当前图书个数
} SqList, *psqList; // 图书表的顺序存储结构类型为SqList

typedef struct DuLNode {
  Book data;
  struct DuLNode *prev;
  struct DuLNode *next;
} dulnode, *dulList;
/* 
题目：
将两个递增的有序链表合并为一个递增的有序链表。
要求链表仍然使用原来的两个链表的存储空间，不另外占用其他的存储空间。
表中不允许有重复的数据。
 */
static plnode mergesortedLNode(plnode node1, plnode node2) {
  plnode head1 = node1->next; // 获取首元结点
  plnode head2 = node2->next; // 获取首元结点
  plnode node = node1; // 新空链表
  plnode head = node; // 用来操作地址的 node
  plnode tmp; // 暂存结点 

  while(head1 != node1 && head2 != node2) {// 尾结点判断
    if(head1->data.price > head2->data.price) {// head2 <= head1 head->next = head2
      // head2 head1; head2++; 5, 4 
      head->next = head2; // head->next = head2, head的下一个指针 指向 head2 的当前结点位置

      head = head->next; // head 指针移动到下一个结点位置
      head2 = head2->next; // head2 指针指向下一个结点位置
    } else if(head1->data.price == head2->data.price) { // head1 == head2; head1++ next; head2 next;
      head->next = head1;
      head = head->next;

      head1 = head1->next; // head1  -next
      tmp = head2->next; // 暂存 head2->next
      free(head2); // 释放head2的结点
      head2 = tmp; // head1 -next
    } else {// head1 < head2 head->next = head1;
      head->next = head1; // head 的下一个指针指向 head1 的结点位置

      head = head->next; // head 指针指向下一个结点位置
      head1 = head1->next; // head1 指针指向下一个结点位置
    }
  }

  if(head1 == node1) { // head1 到结尾
    head->next = head2;
    while(head2->next != node2) {
      head2 = head2->next;
    }
    head2->next = node;
    
  } 
  if(head2 == node2) { // head2 到结尾
    head->next = head1;
    while(head1->next != node1) {
      head1 = head1->next;
    }
    head1->next = node;
  }

  return node->next;
}
/* 
题目：
将两个非递减的有序链表合并为一个非递增的有序链表。
要求结果链表仍使用原来两个链表的存储空间，不另外占用其他的存储空间
表中允许有重复的数据
*/
static plnode mergesortedLNode2(plnode node1, plnode node2) {
  plnode head1 = node1->next;
  plnode head2 = node2->next;
  plnode node = node1;
  plnode head = node;
  while(head1 != node1 && head2 != node2) {
    if(head1->data.price <= head2->data.price) { // head1 head2 ++head1
      head->next = head1;
      head1 = head1->next;
      head = head->next;
    } else { // head2 head1  ++head2
      head->next = head2;
      head2 = head2->next;
      head = head->next;
    }
  }

  if(head1 == node1) {
    head->next = head2;
    while(head2->next != node2) {
      head2 = head2->next;
    }
    head2->next = node1;
  }
  if(head2 == node2) {
    head->next = head1;
    while(head1->next != node1) {
      head1 = head1->next;
    }
  }

  return node->next;
}
/* 
题目：
已知两个链表A和B分别表示两个集合，其元素递增排列。
请设计一个算法，用于求出A与B的交际，并存放在A链表中。
*/
static plnode getSamePartLNode2(plnode node1, plnode node2) {
  plnode head1 = node1->next;
  plnode head2 = node2->next;
  plnode node = node1;
  while(head1 != node1 && head2 != node2) {
    if(head1->data.price == head2->data.price) {
      node->next = head1;
      node = node->next;

      head1 = head1->next;
      head2 = head2->next;

      node->next = node1;
    } else if(head1->data.price < head2->data.price) {
      head1 = head1->next;
    } else {
      head2 = head2->next;
    }
  }
  return node1->next;
}
/* 
题目：
已知两个链表A和B分别表示两个集合，其元素递增排列。
请设计算法求出两个集合A和B的差集（即仅由在A中出现而不在B中出现的元素所构成的集合）。
并以同样的形式存储，同时返回该集合的元素个数。
*/
static plnode getDiffLNode(plnode node1, plnode node2) {
  plnode head1 = node1->next;
  plnode head2 = node2->next;
  plnode node = node1;

  while(head1 != node1 && head2 != node2) {
    if(head1->data.price < head2->data.price) {
      node->next = head1;
      head1 = head1->next;
      node = node->next;
    } else if(head1->data.price > head2->data.price) {
      node->next = head1;
      head1 = head1->next;
      node = node->next;
      
      head2 = head2->next;
    } else {
      head1 = head1->next;
      head2 = head2->next;
    }
  }
  
  if(head2 == node2) {
    node->next = head1;
    while(head1->next != node1) {
      head1 = head1->next;
    }
    head1->next = node1;
  }

  return node1->next;
}
/* 
设计算法将一个带头结点的单链表A分解为两个具有相同结构的链表C和C，
其中B表的结点为A表中值小于零的结点，
而C表的结点为A表中大于零的结点。
(链表A中的元素为非零整数，要求B、C表利用A表的结点)
*/
static plnode splitLNode(plnode A) {
  plnode head = A->next;
  plnode node1 = InitLNode(); // 存储 <0 的结点
  plnode head1 = node1;

  plnode node2 = InitLNode(); // 存储 >0 的结点
  plnode head2 = node2;

  while(head != A) {
    if(head->data.price > 0) { // >0 的结点
      head2->next = head;
      head2 = head2->next;
    } else { // <0 的结点
      head1->next = head;
      head1 = head1->next;
    }
    head = head->next;
  }

  head1->next = A;
  head2->next = A;

  return node2;
}
/* 
题目：
设计一个算法，通过一趟遍历确定长度为n的单链表中值最大的结点，返回该结点的数据域。
*/
static Book getMaxData(plnode node) {
  plnode head = node->next;
  plnode max = head;
  while(head != node) {
    if(head->data.price > max->data.price) {
      max = head;
    }
    head = head->next;
  }
  return max->data;
}
/* 
题目：
设计一个算法，将链表中所有结点的链接方向“原地”逆转，
即要求仅利用原表的存储空间
换句话说，要求算法的空间复杂度为O(1)
*/
static plnode revertLNode(plnode node) {
  plnode head = node->next;
  plnode node1 = node;
  plnode head1 = node1;
  head1->next = head1;
  plnode tmp, tmp2;

  while(head != node) {// head head1; 123 21->next head1->next = 321;
    tmp = head->next;
    tmp2 = head1;

    head->next = head1->next;
    head1->next = head;

    head = tmp;
    head1 = tmp2;
  }

  return node1->next;
}
/* 
题目：
设计一个算法，删除递增有序链表中值大于mink且小于maxk的所有元素
(mink,maxk是给定的两个参数，其值可以和表中的元素相同，也可以不同)
*/
static plnode deleteLNodefromRange(plnode node, int mink, int maxk) {
  plnode head = node->next;
  plnode prevhead;
  while(head != node) { 
    if(head->data.price > mink && head->data.price < maxk) {
      prevhead->next = prevhead->next->next;
      head = head->next;
    }
    prevhead = head;
    head = head->next;
  }
  return node;
}
/* 
已知p指向双向循环链表中的一个结点，其结点结构为 data、prior、next 三个域，
写出算法 Exchange(p),交换p所指向的结点及其前驱结点的顺序 12 5 17 1
*/
static dulList Exchange(dulList p) {
  dulList head = p;
  dulList prevhead = p->prev;
  
  prevhead->prev->next = head; // p 的前驱结点的next 指向

  prevhead->prev = head; // 原前驱结点的 prev 指向
  prevhead->next = head->next; // 原前驱结点的next 指向

  head->prev = prevhead->prev; // p结点的prev指向
  head->next = prevhead; // p结点的next指向
  
  head->next->prev = prevhead; // 原后驱结点的prev指向
  
  return head;
}

/* 
题目：
已知长度为 n 的线性表 A 采用顺序存储结构，
请写一个时间复杂度为 O(n)，空间复杂度为 O(1) 的算法，
该算法课删除线性表中所有值为 item 的数据元素
*/
static psqList deleteListByValue(psqList list, int item) {
  Book *elems = list->elem;
  int len = list->length;
  int flag = 0;
  for(int i = 0; i < len; i++) {
    if(elems[i].price == item) {
      elems[i] = elems[i+1];
      flag++;
    }
    if(flag > 0) {
      elems[i] = elems[i+flag];
    }
  }
  list->length = len;
  return list;
}
/* 
题目：
已知一个带有表头结点的单链表，结点结构为（data，link），
假设该链表只给出了头指针list。
在不改变链表的前提下，请设计一个尽可能高效的算法
查找链表中倒数第k个位置上的结点（k为正整数）。
若查找成功，算法输出该结点的data域的值，并返回1，否则，只返回0。
*/
static int findLNodebyIndex(plnode node, int k) {
  plnode head = node->next;
  plnode head2 = head;
  int j = 0, i= 0;
  while(head != node) {
    j++;
    head = head->next;
  }
  while(i < j - k) {
    i++;
    head2 = head2->next;
  }

  printf("倒数第%d个结点的值data.price为：%.f\n", k, head2->data.price);
  return  0;
}
/* 
题目：
设将 n（n>1）个整数存放到一维数组 R 中。
试设计一个在时间和空间两方面都尽可能高效的算法。
将 R 中保存的序列循环左移 p（0<p<n）个位置，
即将 R 中的数据由（x0， x1，...，xn-1）变换为
（ xp，xp+1，···xn-1，x0，x1， ···，xp-1）。
思路分析：
根据题目可得：采用顺序数据结构
左移p个位置，那么，倒数第p个位置的变为数组第一个，数组第0个，变为数组第p个，数组最后一个变为 第 length-p+1
空间复杂度：O(1),时间复杂度：O(n);
*/
static SqList moveNumList(SqList list, int p) {
  int l = list.length; int j = 0;
  Book tmp[p];

  for(int i = 0; i < l; i++) {
    if (i < p) { // list2 移动至首端
      tmp[i] = list.elem[i];
      list.elem[i] = list.elem[l-p+i]; // [0] = old[1] [1] = old[2] [2] = old[3]
    } else { // list1 移动至尾部
      list.elem[i] = i-p < p ? tmp[i-p] : list.elem[i-p]; // [3] = old[1]
    }
  }

  return list;
}
/* 
题目：
一个长度为L（L>=1）的升序序列S，处在第[L/2]个位置的数称为S的中位数。
例如：若序列S1 = {11， 13，15，17，19}，则S1的中位数是15。
两个序列的中位数是含它们所有元素的升序序列的中位数。
例如：若S2 = {2，4，6，8，20}，则S1和S2的中位数是11。
现有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，
找出两个序列A和B的中位数。
*/
static int findMidNum(int list1[], int list2[]) {
  int len1 = sizeof(list1[0]) / sizeof(int);
  int len2 = sizeof(list2[0]) / sizeof(int);
  int i = 0, j = 0, k = (len1 + len2) / 2;// 4+ 4=10; 5
  while(i < len1 && j < len2) {
    if(i+j == k) {
      break;
    }
    if(list1[i] < list2[j]) {
      i++;
    } else {
      j++;
    }
  }
  
  printf("%d, %d", list1[i], list2[j]);
  return 0;
}
/* 
题目：(好好看答案)
假定采用带头结点的单链表保存单词，
当两个单词有相同的后缀时候，则可共享相同的存储空间。
例如：“loading”和“being”的存储映像：
设str1 和 str2 分别指向两个单词所在单链表的头结点，
链表结点结构为（data，next），请设计一个时间上尽可能高效的算法，
找出由str1和str2所指的两个链表共同后缀的起始位置
（如图中字符i所在结点的位置p）。时间复杂度：O(n^2)  空间复杂度：O(n)
*/
static plnode getSameSuffixPosition(plnode str1, plnode str2) {
  plnode head1 = str1->next;
  plnode head2 = str2->next;

  while(head1->next != str1) {
    head1 = head1->next;
  }
  while(head2->next != str2) {
    head2 = head2->next;
  }
  // printf("position: node1: %p, node2: %p \n", head1, head2);
  int tmp = strcmp(head1->data.no, head2->data.no);

  if(tmp != 0) {
    printf("position: node1: %p, node2: %p \n", str1->data.no, str2->data.no);
    return str1;
  }
  return getSameSuffixPosition(head1, head2);
}
/* 
题目：
用单链表保存 m 个整数，结点的结构为（data,link）,且|data|<= n（n为正整数）。
现要设计一个时间复杂度尽可能高效的算法，对于链表中 data 的绝对值相等的结点，
仅保留第一次出现的结点而删除其余绝对值相等的结点。
例如：若给定的单链表head如图2.3（a）所示，则删除结点后的 head如图2.3（b）所示。
*/
static plnode deleteAbsSameLNode(plnode node, int n) {
  plnode head = node->next;
  plnode tmp;
  int first = 1;
  while(head != node) {
    if(head->next->data.price == n || head->next->data.price == -n) {
      if(first > 1) {
        tmp = head->next;
        head->next = head->next->next;
        free(tmp);
      } else {
        head = head->next;
      }
      first++;
    } else {
      head = head->next;
    }
  }
  return node->next;
}
/* 
题目：（困难）
已知由n(n>=2)个正整数构成的集合A={ak}（0<=k<n），
将其划分为两个不相交的子集A1和A2，
元素个数分别是n1 和n2，A1和A2中元素之和分别为S1和S2.设计一个尽可能高效的划分算法，
满足|n1-n2|最小且|S1-S2|最大。要求：
时间复杂度: O(n)
空间复杂度：O(1)
*/
static int splitTwoLists(int list[], int len) {
  int diff1 = len, diff2 = 0, diff = 0;
  int sum = 0, s1 = 0, s2 = 0, s = 0;
  int m = 0, n1 = 0, n2 = 0, n = 0;
  
  for(int i = 0; i < len; i++) {
    sum += list[i];
  }
  printf("list's summary is %d\n", sum);
  for(int i = 0; i < len - 1; i++) {
    n1 = len - i - 1; 
    n2 = i + 1;
    n = n2 - n1 > 0 ? n2 - n1 : n1 - n2; // |n2 - n1|
    s1 += list[i];
    s2 = sum - s1;
    int s = s2 - s1 > 0 ? s2 - s1 : s1 - s2; // |s2 - s1|

    if(diff2 < s) { // 最大
      diff2 = s;
    }
    
    if(n < diff1) { // 最小
      diff1 = n;
    }

    if(diff2 - diff1 > diff) { // |s2 - s1| - |n1 - n2|
      diff = diff2 - diff1;
      m = i;
    }
  }

  printf("m：%d, list[m]：%d\n", m, list[m]);// A1 {6, 5, 4, 2} A2 {8, 3, 1, 7, 9}

}
/**
  Book book1 = { "wf", "book", 2 };
  Book book2 = { "wf2", "book2", 5 };
  Book book3 = { "wf3", "book3", 6 };
  Book book9 = { "wf3", "book3", 12 };
  plnode node1 = InitLNode();
  LNodeInsert(node1, 0, book1);
  LNodeInsert(node1, 1, book2);
  LNodeInsert(node1, 2, book3);
  LNodeInsert(node1, 3, book9);

  Book book4 = { "wf", "book", 1 };
  Book book5 = { "wf2", "book2", 4 };
  Book book6 = { "wf3", "book3", 7 };
  Book book7 = { "wf3", "book3", 8 };

  plnode node2 = InitLNode();
  LNodeInsert(node2, 0, book4);
  LNodeInsert(node2, 1, book5);
  LNodeInsert(node2, 2, book6);
  LNodeInsert(node2, 3, book7);

  node1 = mergesortedLNode(node1, node2);
  node1 = mergesortedLNode2(node1, node2);
  printf("%.f, %.f, %.f, ", node1->data.price, node1->next->data.price, node1->next->next->data.price);
  node2 = node1->next->next->next;
  printf("%.f, %.f, %.f, ", node2->data.price, node2->next->data.price, node2->next->next->data.price);
  node1 = node2->next->next->next;
  printf("%.f, %.f", node1->data.price, node1->next->data.price);


  SqList list = createList();

  Book book1 = { "wf", "book", 1 };
  Book book2 = { "wf2", "book2", 5 };
  Book book3 = { "wf3", "book3", 17 };
  Book book4 = { "wf3", "book3", 12 };

  ListInsert(&list, 0, book1);
  ListInsert(&list, 1, book2);
  ListInsert(&list, 2, book3);
  ListInsert(&list, 3, book4);

  printf("%.f, %.f, %.f, %.f\n", list.elem[0].price, list.elem[1].price, list.elem[2].price, list.elem[3].price);
  deleteListByValue(&list, 5);
  printf("%.f, %.f, %.f, %p", list.elem[0].price, list.elem[1].price, list.elem[2].price, list.elem[3]);
 */