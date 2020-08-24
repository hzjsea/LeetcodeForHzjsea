#!/hzj/myenv python3
# -*- encoding: utf-8 -*-
'''
@File    :   singlist.py
@Time    :   2020/07/19 10:00:37
@Author  :   hzjsea@
@Version :   1.0
@Contact :   hzjsea@gmail.com
@gayhub  :   hzjsea@github.com
@License :   (C)Copyright 2017-2018, Liugroup-NLPR-CASIA
@Desc    :   no tower gods, only  climb towers
'''

# Desc:===================
# Code:==================


# 定义一个节点

class Node:
    def __init__(self, val=None, next=None):
        self.data = val
        self.next = next

    def __str__(self):
        return str(self.data)


# 链表关系
# node1->node2->node3


# 创建一个链表
class LinkList(object):
    def __init__(self, head=Node(0, None)):
        self.head = head  # 头结点

    def __len__(self):
        # 功能：输入头节点，返回链表长度
        curr = self.head
        counter = 0
        while curr is not None:
            counter += 1
            curr = curr.next
        return counter

    def IsEmpty(self):
        if self.head is None:
            return None
        else:
            return self.head.data

    def InsertListTail(self, data):
        # 尾插法
        if data is None:
            return None
        curr = self.head
        while curr is not None:
            curr = curr.next
        newnode = Node(data, None)
        curr.next = newnode

    def InsertListHead(self, data):
        # 头插法
        if data is None:
            return None
        node = Node(data, self.head)
        self.head = node
        return node

    def LookList(self, data):
        if data is None:
            return None
        curr = self.head
        while curr is None:
            if curr.val == data:
                return curr
            curr = curr.next
        return None

    def DeleteList(self, data):
        if data is None:
            return None
        if self.head is None:
            return None
        if self.head.data == data:
            self.head = self.head.next
            return
        prev_node = self.head
        curr_node = self.head.next
        while curr_node is not None:
            if curr_node.data == data:
                prev_node.next = curr_node.next
            else:
                prev_node = curr_node
                curr_node = curr_node.next

    def DeleteList2(self):
        if self.head is None:
            return

        curr = self.head
        while curr.next is not None:
            curr.next = curr.next.next
            return
            curr = curr.next
