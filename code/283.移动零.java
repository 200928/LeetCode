/*
 * @lc app=leetcode.cn id=283 lang=java
 *
 * [283] 移动零
 */

 /**
  * 使用双指针
  * 判断 nums[fast] 与 0 关系
  * 等于    slow 不动, fast 加 1
  * 不等于   nums[slow] = nums[fast]，然后 slow 加 1，fast 加 1
  */
// @lc code=start
class Solution {
    public void moveZeroes(int[] nums) {
        int slow = 0;
        int fast = 0;
        while (fast < nums.length) {
            if (0 != nums[fast]) {
                int tmp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = tmp;
                slow++;
            }
            fast++;
        }
        return;
    }
}
// @lc code=end

