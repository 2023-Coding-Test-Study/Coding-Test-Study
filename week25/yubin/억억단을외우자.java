import java.util.*;

class Solution {

    public static void main(String[] args) {
        Solution solution = new Solution();

        var result = solution.solution(8, new int[]{1, 3, 7});
        for (int i = 0; i < result.length; i++) {
            System.out.println(result[i]);
        }
    }

    public int[] solution(int e, int[] starts) {
        Pair[] pairs = new Pair[e + 1];
        for (int i = 0; i < pairs.length; i++) {
            pairs[i] = new Pair(i, 0);
        }

        for (int i = 1; i <= e; i++) {
            for (int j = i; j <= e; j+=i) {
                pairs[j].factorCount++;
            }
        }

        Arrays.sort(pairs, (o1, o2) -> {
            if(o1.factorCount < o2.factorCount) return 1;
            else if(o1.factorCount > o2.factorCount) return -1;
            else{
                if(o1.num > o2.num) return 1;
                else if(o1.num < o2.num) return -1;
                else return 0;
            }
        });

        int[] answer = new int[starts.length];
        for (int i = 0; i < starts.length; i++) {
            int s = starts[i];
            for (int j = 0; j < pairs.length; j++) {
                if (pairs[j].num >= s) {
                    answer[i] = pairs[j].num;
                    break;
                }
            }
        }

        return answer;

    }
}

class Pair {
    int num;
    int factorCount;

    public Pair(int num, int factorCount) {
        this.num = num;
        this.factorCount = factorCount;
    }
}
