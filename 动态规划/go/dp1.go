package main

import "fmt"

/*

Given a string s, return the longest palindromic substring in s
求最长的回文字符串

1. 提取关键字
最长的  回文字符串

什么是回文字符串 比如 ababa 就是一个回文字符串 其中 aba  aba ababa 都是回文字符串

2. 将主问题缩放成子问题
这里是找最长的回文字符串， 那我们可以先找局部内的最小字符串 ok，这样知道之后我们就可以来找局部内的规则了

那现在我们只要找到最小范围的就行了
(情况1)  回文字符串 只要保证 abc 这个字符串那种 a==c 就是一个回文字符串 要比较两个值
(情况2)  前后两个字符串相等
所以我们假设 dp[i][j] 表示在 i..j的这个范围内是一个回文字符串
状态转移方程式就是 dp[i][j] = (s[i] == s[j] ) && (j-i<3) || dp[i+1][j-1]

3. 临界值
当字符串长度为1的时候， 回文字符串就是本身
当字符串长度为2的时候， 只要比较前后两个字符串是否相等
当字符串长度为3以上的时候， 只要比较 aba 1和3的内容是否相等就可以
时间复杂度 O(n^2)，空间复杂度 O(n^2)。
*/

// https://books.halfrost.com/leetcode/ChapterFour/0001~0099/0005.Longest-Palindromic-Substring/

func longestPalindrome(s string) string {
	if len(s) < 2 {
		return s
	}

	newS := make([]rune, 0)
	newS = append(newS, '#')
	for _, c := range s {
		newS = append(newS, c)
		newS = append(newS, '#')
	}

	fmt.Println(newS)
	return ""

}

func min(x, y int) int {

	if x < y {
		return x
	}
	return y
}

func main() {
	longestPalindrome("ss")
}
