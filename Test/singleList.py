
# 创建节点
class Node(object):

    # 初始化一个节点 一个节点包含一个数据 一个next节点指向下一个节点
    def __init__(self,data=None,next=None):
        self.data = data
        self.next = None
    
    def __repr__(self):
        return str(self.data)


# 创建单链表
class SingleList():
    def __init__(self):
        self.head = None
    

    # 初始化链表
    def initList(self,value:int):
        # 先让链表的头部指向空
        self.head = Node(value[0])
        # 创建一个游标，初始位置和head相同
        current = self.head
        # 再创建多个节点
            


    # 判断是否为空链表 ,如果头部为空的话，那就是空链表
    def isEmpty(self):
        if self.head == None:
            print("this list is empty")
            return True
        else:
            print("this list is not empty")
            return False
    # 循环链表
    # 1. 判断是否为空
    # 2. 建立一个游标
    def traverse(self):
        if self.isEmpty():
            return "this list is empty"
        
        curr = self.head
        while curr != None:
            print(curr.data)
            curr = curr.next


if __name__ == '__main__':
    # 创建一个节点
    node1 = Node(data=1)
    node2 = Node(data=2)
    node3 = Node(data=3)
    node4 = Node(data=4)

    # 把节点关联其阿里
    node1.next = node2
    node2.next = node3
    node3.next = node4

    
    

    