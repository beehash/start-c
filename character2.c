#include "LNode.c"

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
  plnode tmp, tmp2;

  while(head != node) {// head head1; 123 21->next head1->next = 321; 
    tmp = head1->next; // head
    tmp2 = head->next; // 5 17 12
    head->next = tmp; // 5 1 head

    tmp->next = head; // head 5 1 head
    head1 = tmp;
    head = tmp2;
  }

  return node1;
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
 */