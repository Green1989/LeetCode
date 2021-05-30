/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int nCount = 0;
        while (n > 0)
        {
            if (n&1 == 1)
            {
                nCount++;
            }
            n = n >> 1;
        }
        return nCount;
    }
};
// @lc code=end

