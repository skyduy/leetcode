/**
 * @author Jun
 */

class Solution201 {
    private static final int INT32_BIT_LENGTH = 32;

    int rangeBitwiseAnd(int m, int n) {
        int flag = 0x7FFFFFFF;
        for (int pos = 0; pos < INT32_BIT_LENGTH; pos++) {
            int mask = 1 << pos;
            if ((m & mask) != 0) {
                int minContain = ((m >> (pos + 1)) + 1) << (pos + 1);
                
                // 溢出，高位不可能再改变
                if (minContain < 0) {
                    break;
                }
                if (n >= minContain) {
                    flag &= ~mask;
                }
            }
        }
        return m & flag;
    }

    int rangeBitwiseAndV2(int m, int n) {
        if (m == 0) {
            return 0;
        }
        int moveFactor = 1;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            moveFactor <<= 1;
        }
        return m * moveFactor;
    }
}
