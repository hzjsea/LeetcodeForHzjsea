# 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
# 数组中的每个元素代表你在该位置可以跳跃的最大长度。
# 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
# 假设你总是可以到达数组的最后一个位置。
# 输入: nums = [2,3,1,1,4]
# 输出: 2
# 解释: 跳到最后一个位置的最小跳跃数是 2。
#      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

# 输入: nums = [2,3,0,1,4]
# 输出: 2

# 提取关键字
# 使用最少的跳跃次数到达数组的最后一个位置
# 最少 数组的最后的一个位置 没有连续的要求


# class Solution(object):
#     def jump(self, nums):
#         length=len(nums)
#         x=[0]*length
#         for i in range(length):
#             for j in range(i+1,length):
#                 if(nums[i]>=j-i):
#                     if(x[j]>0):
#                         x[j]=min(x[j],x[i]+1)
#                     else:
#                         x[j]=x[i]+1
#         return x[length-1]

# if __name__ == "__main__":
#     s = Solution()
    
#     nums = [2,3,1,1,4]
#     # nums = [2,3,0,1,4]
#     nums = [0,0,0,0,1]
#     print(s.jump(nums=nums))
    