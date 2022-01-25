# 在动态规划算法中有三要素，即最优子结构、边界和状态转移函数。
# 最优子结构：每个阶段的最优状态可以从之前某个阶段的某个或某些状态直接得到；
# 边界：问题最小子集的解；
# 状态转移函数：从一个阶段向另一个阶段过渡的具体模式，描述的是两个相邻子问题之间的关系。

# 最长上升子序列问题
# 给定一个无序的整数数组，找到其中最长上升子序列的长度。

# 1.示例
# 输入: [10,9,2,5,3,7,101,18]
#
# 输出: 4
#
# 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

# 提取关键字 
# 最长  上升 不连续
# 上升即递增 前者要小于后者 n < n+1
# 不要求连续，则会出现 [n...n+1...n+3] 等等内容

# 临界值
# n = 0  return 0
# n >= 1 return ?

# 追求子问题
# 求i个元素的数组的最长上升子序列的长度 i >= 0
# 设i个元素的数组的最长上升子序列的长度为f(i)
# 取其子区域
# 则 k个元素的数组的最长上升子序列的长度为f(k)  0<= K <= i

# 当 k = i 的时候，就是整个数组的长度 f(i) = f(k) = len(nums)
# 当 k < i 的时候, 就是0..k这个子区域部分的长度 f(k) + 1 # 为什么要加这个1呢 是因

# 转换方程式 
# 当 k = i 的时候, 最大长度为 dp[i]
# 当 k < i 的时候，最大长度为 dp[k] + 1

# 取最大值
# max(dp[i], dp[k] + 1)

from typing import Mapping


class Solution(object):
    def cal(self, nums) -> int:
        n = len(nums)
        if n == 0:
            return 0
        # 初始值
        dp = [0]*n
        
        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
                else:
                    pass

        # 记住还要加上自身的1
        return max(dp) + 1
    
    def lengthOfLIS(self, nums) -> int:
        if not nums:
            return 0
        dp = []
        for i in range(len(nums)):
            dp.append(1)
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
                else:
                    pass
        return max(dp)

if '__main__' == __name__:
    s = Solution()
    l = [10,9,2,5,3,7,101,18]
    l = [0,0,0,0,1,2,3,0,4]
    l = [1]
    print(s.cal(l))
    print(s.lengthOfLIS(l))
                        
    