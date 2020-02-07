import java.util.Arrays;

/**
 * @author Jun
 */
public class Solution475 {
    public int findRadius(int[] houses, int[] heaters) {
        int result = 0;
        Arrays.sort(heaters);
        for (int house : houses) {
            int index = Arrays.binarySearch(heaters, house);
            if (index < 0) {
                // 效果等同于 index = -(index + 1); 因为取负值就是各位取反末尾加一
                index = ~index;
                int leftDist = index - 1 >= 0 ? house - heaters[index - 1] : Integer.MAX_VALUE;
                int rightDist = index < heaters.length ? heaters[index] - house : Integer.MAX_VALUE;
                result = Math.max(result, Math.min(leftDist, rightDist));
            }
        }
        return result;
    }
}
