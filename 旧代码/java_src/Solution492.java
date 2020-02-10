/**
 * @author Jun
 */
public class Solution492 {
    public int[] constructRectangle(int area) {
        int width = (int)Math.sqrt(area);
        if(width * width == area){
            return new int[]{width, width};
        }
        while(area % width != 0){
            width --;
        }
        return new int[]{area/width, width};
    }
}
