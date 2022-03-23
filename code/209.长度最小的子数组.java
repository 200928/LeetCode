/*
 * @lc app=leetcode.cn id=209 lang=java
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
/**
 * 暴力解法
 * 双重循环，内循环的起始位置为外循环遍历到的位置
 * 然后内循环遍历，对后面的求和，如果大于 target，算出该位置与初始位置的距离
 * 然后比较与保存结果的 result 的大小，小于则更新 result，否则不更新
 */
/* class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int result = Integer.MAX_VALUE; // 保存结果
        int sum = 0; // 子序列和
        int subLength = 0; // 子序列长度
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            sum = 0;
            for (int j = i; j < len; j++) {
                sum += nums[j];
                if (sum >= target) {
                    subLength = j - i + 1; // 计算满足条件子序列长度
                    result = result > subLength ? subLength : result;
                    break;
                }
            }
        }
        return result == Integer.MAX_VALUE ? 0 : result;
    }
} */

/**
 * 滑动窗口(while写法)
 * 区间 [left, right] 之间元素小于 target，left 不动，right++
 * 区间 [left, right] 之间元素大于等于 target，left++，right 不动
 */
/* class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int result = Integer.MAX_VALUE;
        int left = 0;
        int right = 0;
        int subLength = 0; 
        int sum = nums[0];  // 初始为 nums[0] 因为 nums.length >= 1
        while (right < nums.length) {
            if (sum < target) {
                right++;
                if (right == nums.length) {
                    break;
                }
                sum += nums[right];
            } else {
                subLength = right - left + 1;
                result = result > subLength ? subLength : result;
                sum -= nums[left];
                left++;
            }
        }
        return result == Integer.MAX_VALUE ? 0 : result;
    }
} */

/**
 * 滑动窗口(for写法)
 */
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int result = Integer.MAX_VALUE;
        int left = 0;
        int right = 0;
        int subLength = 0;
        int sum = 0;
        for (; right < nums.length; right++) {
            sum += nums[right];
            while (sum >= target) {
                subLength = right - left + 1;
                result = Math.min(result, subLength);
                sum -= nums[left++];
            }
        }
        return result == Integer.MAX_VALUE ? 0 : result;
    }
}
// @lc code=end
