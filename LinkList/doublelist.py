
# 创建节点


class Node(object):
    def __init__(self,data=None,next=None):
        self.data = data
        self.next = None
        self.pre = None
    
    def __repr__(self):
        return str(self.data)

# 创建链表
class DoubleList():
    def __init__(self):
        self.head = None
    # 判断是否为空
    def isEmpty(self):
        return self.head is None
    # 初始化双链表
    def InitList(self,value:int):
        self.head = Node(value)
        self.head.next = self.head
        self.head.pre = self.head

    
    # 追加节点 尾插法
    def AddList(self,value:int):
        # 创建节点
        newnode = Node(value)
        # 关联节点
        current = self.head
        # 由于双向链表的特殊性，尾插法的尾节点=self.head.pre
        while current.next != self.head:
            current = current.next
        current.next = newnode
        newnode.pre = current
        newnode.next = self.head
        self.head.pre = newnode

    # 获取链表长度
    def __len__(self):
        count = 1
        current = self.head
        while current.next != self.head:
            count +=1
            current = current.next
        print(count)
    # 循环输出节点
    def ConsoleElement(self):
        current = self.head
        while current.next != self.head:
            print(current.data)
            current = current.next
        print(current.data)


    # 删除节点
    def DelList(self,index:int):
        current = self.head
        if index < 0 or self.head == None:
            return 0
        while index:
            current = current.next
            index -=1
        
        tmpnode = current.next

        current.next = current.next.next
        current.next.pre = current
        tmpnode.next = None
        tmpnode.pre = None

    # 修改节点
    def getIndexList(self,index:int,value:int):
        current = self.head
        if index < 0 or self.head ==None:
            return 0
        while index :
            current = current.next
            index -=1
        current.data =  value

if __name__ == '__main__':
    dl = DoubleList()
    dl.InitList(20)
    dl.AddList(30)
    dl.AddList(30)
    dl.__len__()
    dl.DelList(1)
    dl.__len__()
    dl.ConsoleElement()
    dl.getIndexList(1,20)
    dl.ConsoleElement()

    