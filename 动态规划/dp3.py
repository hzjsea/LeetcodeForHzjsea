# 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
# 影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
# 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
# 示例1
# 输入：[1,2,3,1]
# 输出：4
# 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
#      偷窃到的最高金额 = 1 + 3 = 4 。
#
# 示例2
# 输入：[2,7,9,3,1]
# 输出：12
# 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
#      偷窃到的最高金额 = 2 + 9 + 1 = 12 。


# 提取关键点
# 关键点1
# 不能相邻 也就是之能隔2去取
# 2 4 6 8 10 或者 1 3 5 7 9
# 关键点2
# 提取子问题， 子问题就是主问题的缩小版
# 主问题 在n个房间内取最大值  f(n)
# 子问题 在k个房间里取最大值 f(k) k <= n

# 整合
# 需要相邻 则有两种方式 从k+2开始取 或者从 k+1 开始取 (k==0)

# 倒着来
# 从 k-1 开始 或者从 k-2

# 边界值
# 当k=0 时候 没有房子 return 0
# 当k=1 时候 只有一个房子 return f(1)


# 在很多教程中都会写，动态规划有两种计算顺序，一种是自顶向下的、使用备忘录的递归方法，
# 一种是自底向上的、使用 dp 数组的循环方法。
# 不过在普通的动态规划题目中，99% 的情况我们都不需要用到备忘录方法，所以我们最好坚持用自底向上的 dp 数组。
# 发现每个f(k) 依赖 f(k−1) 和 f(k−2)。也就是说，dp[k] 依赖 dp[k-1] 和 dp[k-2]

# https://blog.csdn.net/ximen_zhou/article/details/117227525

class Solution(object):
    def rob(self, nums) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[1]
        # 子问题：
        # f(k) = 偷 [0..k) 房间中的最大金额

        # f(0) = 0
        # f(1) = nums[0]
        # f(k) = max{ rob(k-1), nums[k-1] + rob(k-2) }

        N = len(nums)
        dp = [0] * (N + 1)
        dp[0] = 0
        dp[1] = nums[0]
        for k in range(2, N + 1):
            dp[k] = max(dp[k - 1], nums[k - 1] + dp[k - 2])
        return dp[N]

    # 空间优化
    def rob2(self, nums) -> int:
        prev = 0
        curr = 0

        # 每次循环，计算“偷到当前房子为止的最大金额”
        for i in nums:
            # 循环开始时，curr 表示 dp[k-1]，prev 表示 dp[k-2]
            # dp[k] = max{ dp[k-1], dp[k-2] + i }
            prev, curr = curr, max(curr, prev + i)
            # 循环结束时，curr 表示 dp[k]，prev 表示 dp[k-1]

        return curr


if __name__ == '__main__':
    nums = [1, 2, 3, 4, 5]
    s = Solution()
    print(s.rob(nums))
    print(s.rob2(nums))
