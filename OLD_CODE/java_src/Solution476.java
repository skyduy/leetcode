/**
 * @author Jun
 */
public class Solution476 {
    public int findComplement(int num) {
        int mask = ~0;
        while ((num & mask) != 0) {
            mask <<= 1;
        }
        return ~mask & ~num;
    }

    public int findComplementOld(int num) {
        int notNum = ~num;
        int zeroCount = -1;
        while ((num & 0x80000000) == 0) {
            zeroCount++;
            num <<= 1;
        }
        return notNum & (0x7FFFFFFF >> zeroCount);
    }
}
