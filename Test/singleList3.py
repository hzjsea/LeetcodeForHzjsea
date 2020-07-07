#!/hzj/myenv python3
# -*- encoding: utf-8 -*-
'''
@File    :   singleList3.py
@Time    :   2020/07/07 10:41:21
@Author  :   hzjsea@ 
@Version :   1.0
@Contact :   hzjsea@gmail.com
@gayhub  :   hzjsea@github.com
@License :   (C)Copyright 2017-2018, Liugroup-NLPR-CASIA
@Desc    :   no tower gods, only  climb towers
'''

# Desc:===================
# 单链表实例
# Code:===================


# 创建一个节点的模板
# 包含一个val数据以及一个_next 指针


class Node(object):
    def __init__(self,value):
        self.val = value
        self._next = None


class singleList(object):
    def __init__(self):
        # 初始化头部 值为0
        self.head = Node(0)
    
    # 在头部插入数据
    def InsertAtHead(self,value:int) -> None:
        """insert Node at Head
        """
        # 创建一个新的节点
        newNode = Node(value)
        # 使得newNode所指向的下一个地址和head一样
        newNode._next = self.head._next
        # 让head的所指向的节点指向新的节点
        self.head._next = newNode

    # 在尾部插入数据
    def InsertAtTail(self,value:int) -> None:
        """insert Node at Tail
        因为单链表是一条线上的，所以无法直接找到末尾的结点，需要遍历
        """
        # 创建一个游标，用来定位
        current = self.head # 初始位置和head位置相同
        while current._next  is not None:
            current = current._next
        # 到最后一位的时候，指向一个新的节点
        # 新的节点默认指向空，即None
        current._next = Node(value)

    # 在链表中间插入 ??? 这里有问题
    def InsertAtAnywhere(self,value:int,index:int) -> None:
        """insery Node at anywhere
        """
        # 创建游标
        current = self.head
        # 判断链表是否为空
        if self.head is None:
            current = Node(value)

        # 遍历
        # 需要判断index是否超出了链表的长度
        for i in range(index):
            if current is None:
                return
            current = current._next
        # 找到插入位置以后
        # 创建一个新的节点
        NewNode = Node(value)
        NewNode._next = current._next
        current._next = NewNode

    # 删除节点
    def DeleteAtAnywhere(self,value:int,index:int) -> None:
        """delete Node at anywhere
        """

        current = self.head

        if self.head is None:
            return current

        for i in range(index):
            if current is None:
                return
            current = current._next

        if current._next is not None:
            current._next = current._next._next

    # 获取节点
    def get(self,index)->int:

        if index < 0:return -1

        current = self.head
        for _ in range(index+1):
            if current is not None:current = current._next
            else: return -1
        print(current.val)
        return current.val

    def test(self) -> int:
        """desc for this function
        """

if __name__ == '__main__':
    object = singleList()
    object.InsertAtHead(1)
    object.InsertAtHead(2)
    object.InsertAtTail(3)

    object.get(0)
    object.get(1)
    object.get(3)

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)