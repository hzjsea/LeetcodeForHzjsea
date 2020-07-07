#!/hzj/myenv python3
# -*- encoding: utf-8 -*-
'''
@File    :   Reverse_Integer.py
@Time    :   2020/06/24 13:52:26
@Author  :   hzjsea@ 
@Version :   1.0
@Contact :   hzjsea@gmail.com
@gayhub  :   hzjsea@github.com
@License :   (C)Copyright 2017-2018, Liugroup-NLPR-CASIA
@Desc    :   no tower gods, only  climb towers
'''

# Desc:===================

# 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

# Code:===================
class Solution(object):
    ## 方法1 使用标记确定
    def reverse(self, x: int):
        # 判断两个取绝对值后的两个数值是否相等，如果不相等则让flag =true
        flag = False if abs(x) == x else  True
        # 或者判断原数是否小于0
        # flag = True if x < 0 else False
        
        str_num = str(abs(x))[::-1] # 从后往前   
        if flag == True:
            return int("-"+str_num)
        else:
            return int(str_num)
            

        
if __name__ == '__main__':
    x = -123
    # result = 321

    sn = Solution()
    res = sn.reverse(x)

    print(res)
    