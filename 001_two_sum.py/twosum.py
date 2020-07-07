#!/hzj/myenv python3
# -*- encoding: utf-8 -*-
'''
@File    :   twosum.py
@Time    :   2020/06/24 12:02:46
@Author  :   hzjsea@ 
@Version :   1.0
@Contact :   hzjsea@gmail.com
@gayhub  :   hzjsea@github.com
@License :   (C)Copyright 2017-2018, Liugroup-NLPR-CASIA
@Desc    :   no tower gods, only  climb towers
'''
 
# dump your code 

# 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
# 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
# 示例:
# 给定 nums = [2, 7, 11, 15], target = 9
# 因为 nums[0] + nums[1] = 2 + 7 = 9
# 所以返回 [0, 1]
# 通过次数1,147,586提交次数2,352,024

class Solution(object):
    ## 两次循环直接求
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            # for j in range(len(nums)) ## 这里说到数组中的同一个元素不能使用两边,也就是说第二遍循环只要循环数组的下一个就行了
            # for j in range(len(nums[i+1,len(nums)])):
            for j in range(i+1,len(nums)):
                if nums[i]+nums[j] == target:
                    return [i,j] ## 题目说只对应一种答案，所以只要暴露一种结果就可以break了;
                    break
                else:
                    continue
    ## 单循环
    def twoSumSingleFor(self,nums,target):
        for i in range(len(nums)):
            another_nusm = target-nums[i]
            if another_nusm in nums:
                # 如果存在对应的数字，则返回下标
                j = nums.index(another_nusm)
                if i == j:
                    continue # 坐标不能重复
                else:
                    return i,j # 返回一组坐标即可
                    break;
            else:
                continue # 如果不存在则继续请求下一个

            

    ## 使用字典简化一次循环以及简化取值序号的步骤
    def twoSum2(self,nums,target):
        hashmap={}
        for index,num in enumerate(nums):
            another_num = target - num
            if another_num in hashmap: ## 判断是否存在，不存在就塞入,在一开始空字典的时候，将结果塞入 ,等到结果成为被减数的时候返回结果 
                return [hashmap[another_num],index]
            else:
                hashmap[num] = index

                    

if __name__ == '__main__':
    nums = [2,7,11,15]  
    target = 9

    sn = Solution()

    ## 双循环暴力解决
    res = sn.twoSum(nums,target)
    print(res)

    ## 单循环解决
    # res = sn.twoSumSingleFor(nums,target)
    # print(res)

    ## 字典解决
    # hashmap = sn.twoSum2(nums,target)
    # print(hashmap)
    

    