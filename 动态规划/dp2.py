# 给定一个非负整数数组nums ，你最初位于数组的 第一个下标 。
#
# 数组中的每个元素代表你在该位置可以跳跃的最大长度。
#
# 判断你是否能够到达最后一个下标。
#
#
# 输入：nums = [2,3,1,1,4]
# 输出：true
# 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
#
# 输入：nums = [3,2,1,0,4]
# 输出：false
# 解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
#

# num[i] +i >= len(num)  True
# 不能这么写 之前我列的为
# dp[i]表示在i格时能跳的格数， 这样设是错误的

# 正确做法
# dp[i]在下标i处能够跳跃的最大值
# 对于dp[i]，它等于dp[i-1]在i-1处跳跃到达i处后剩余的步数，和nums[i]的最大值  dp[i]=max(dp[i-1]-1,nums[i])
# dp[0]=nums[0] dp[1] = nums[1]

# DP想不出来


# 贪心算法

class Solution:
    def canJump(self, nums) -> bool:
        n, rightmost = len(nums), 0
        for i in range(n):
            if i <= rightmost:
                rightmost = max(rightmost, i + nums[i])
                if rightmost >= n - 1:
                    return True
        return False


if __name__ == '__main__':
    nums = [1, 2, 3, 4]
    nums = [2, 3, 1, 1, 4]
    nums = [3, 2, 1, 0, 4]
    s = Solution()
    print(s.canJump(nums))
