/**
 * @author Jun
 */
public class Solution485 {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ans = 0;
        int cur = 0;
        for(int num: nums){
            if(num == 0){
                ans = Math.max(ans, cur);
                cur = 0;
            } else {
                cur ++;
            }
        }
        ans = Math.max(ans, cur);
        return ans;
    }
}
