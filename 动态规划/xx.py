"""
物品重量与价值对应关系：
w   v
2   3
3   4
5   8
9   10
背包容量：20
"""
import numpy as np


def func(pack, cap):
    max_value_arr = np.zeros([len(pack) + 1, cap + 1])
    # 第一列与第一排全为0，这样为后续能递推max_value_arr的值
    max_value_arr[:, 0] = 0
    max_value_arr[0, :] = 0
    # i代表pack物品的序号
    for i in range(1, len(pack) + 1):
        # j代表包中剩余的空间
        for j in range(1, cap + 1):
            # 第一种情况，包中剩余空间不足
            if j < pack[i - 1][0]:
                max_value_arr[i, j] = max_value_arr[i - 1, j]
            # 第二种情况，包中空间足够
            else:
                # a代表放入当前物品后包中总价值，w是当前物品的所占空间
                w = pack[i - 1][0]
                """
                下面这行是关键！！！为什么是i-1，这里必须用i-1才能推出当前的max_value_arr的值，
                然后再加上单独的value
                """
                a = max_value_arr[i - 1, j - w] + pack[i - 1][1]
                # b代表不放当前物品包中的总价值，两者求最大值
                b = max_value_arr[i - 1, j]
                max_value_arr[i, j] = max(a, b)

    print(max_value_arr[-1, -1])


if __name__ == '__main__':
    test_pack = [[2, 3],
                 [3, 4],
                 [4, 5],
                 [5, 8],
                 [9, 10]]
    func(test_pack, 20)
