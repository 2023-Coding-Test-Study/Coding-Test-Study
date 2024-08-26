import java.util.*;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();

        int answer = 0;
        int i = 0;

        for (int j = 0; j < s.length(); j++) {

            if (!set.contains(s.charAt(j))) {
                set.add(s.charAt(j));
                answer = Math.max(answer, j - i + 1);
            } else {
                while (s.charAt(i) != s.charAt(j)) {
                    set.remove(s.charAt(i));
                    i++;
                }

                set.remove(s.charAt(i));
                i++;
                set.add(s.charAt(j));
            }
        }

        return answer;
    }
}
