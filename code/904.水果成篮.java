import java.lang.reflect.Array;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=904 lang=java
 *
 * [904] 水果成篮
 */

// @lc code=start
/**
 * 只需要找出数组中某个连续区间数组元素个数最多且数组元素只包含两种可能的情况
 * 那么这个区间的个数即所求
 * 滑动窗口
 */
class Solution {
    public int totalFruit(int[] fruits) {
        int left = 0;
        int right = 0;
        int result = 0;
        int ln = fruits[0]; // 1号篮子
        int rn = fruits[0]; // 2号篮子
        for (; right < fruits.length; right++) {
            // 如果右指针属于1或2号篮子就自增，并更新结果
            if (ln == fruits[right] || rn == fruits[right]) {
                result = Math.max(result, right - left + 1);
                continue;
            }
            // 如果不属于1或2号篮子，left=right-1，然后找到等于fruits[left]最前面的下标
            left = right - 1;
            ln = fruits[left];  // 更新1号篮子
            rn = fruits[right]; // 更新2号篮子
            while (left >= 1 && fruits[left - 1] == ln) {
                left--;
            }
            result = Math.max(result, right - left + 1);
        }
        return result;
    }
}
// @lc code=end
