/*
 * @lc app=leetcode.cn id=977 lang=java
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] ans = new int[nums.length];
        // 指向结果数组 ans 的最后一位，后面依次减小赋值
        int index = nums.length - 1;
        // 分别指向 nums 的前部和尾部
        int left = 0;
        int right = index;
        // 直到两者指向同一个数组的数
        while (left <= right) {
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];
            // 左边负数的平方大于右边正数的平方
            if (leftSq > rightSq) {     // 这里可写成 >=
                ans[index--] = leftSq;
                left++;
            } else {
                ans[index--] = rightSq;
                right--;
            }
        }
        return ans;
    }
}
// @lc code=end

