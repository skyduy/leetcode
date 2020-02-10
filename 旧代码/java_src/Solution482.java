/**
 * @author Jun
 */
public class Solution482 {
    public String licenseKeyFormatting(String S, int K) {
        StringBuilder sb = new StringBuilder();
        int counter = 0;
        for (int i = S.length() - 1; i >= 0; i--) {
            char c = S.charAt(i);
            if (c != '-') {
                sb.append(Character.toUpperCase(c));
                counter++;
                if (counter % K == 0) {
                    sb.append('-');
                }
            }
        }
        if (sb.length() == 0) {
            return "";
        }
        if (sb.charAt(sb.length() - 1) == '-') {
            sb.deleteCharAt(sb.length() - 1);
        }
        return sb.reverse().toString();
    }
}
