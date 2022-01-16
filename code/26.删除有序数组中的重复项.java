/*
 * @lc app=leetcode.cn id=26 lang=java
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
/**
 * 双指针，因为数组是有序的
 * 判断 nums[slow] 与 nums[fast] 关系
 * 等于     slow 不动，fast 加 1
 * 不等于    slow 先加 1，然后 nums[fast] 赋值给 nums[slow]  
 */
class Solution {
    public int removeDuplicates(int[] nums) {
        int slow = 0;
        int fast = 0;
        int len = nums.length;
        while (fast < len) {
            if (nums[slow] != nums[fast]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
}
// @lc code=end

