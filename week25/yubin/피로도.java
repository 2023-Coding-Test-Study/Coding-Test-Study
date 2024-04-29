import java.util.*;

class Solution {

    int max = 0;
    int k;
    int[][] dungeons;

    public static void main(String[] args) {
        Solution solution = new Solution();

        System.out.println(solution.solution(80, new int[][]{{80,20},{50,40},{30,10}}));
    }

    public int solution(int k, int[][] dungeons) {
        this.k = k;
        this.dungeons = dungeons;
        int[] arr = new int[dungeons.length];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i;
        }

        permutatate(arr, new int[dungeons.length], new boolean[dungeons.length], 0, dungeons.length, dungeons.length);

        return max;
    }

    public void permutatate(int[] arr, int[] result, boolean[] visited, int depth, int n, int r) {
        if (depth == r) {
            calculate(result);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                result[depth] = arr[i];
                permutatate(arr, result, visited, depth + 1, n, r);
                visited[i] = false;
            }
        }
    }

    public void calculate(int[] result) {
        int count = 0;
        int currentFatigue = k;

        for (int i = 0; i < result.length; i++) {
            int index = result[i];
            int minFatigue = dungeons[index][0];
            int costFatigue = dungeons[index][1];

            if (currentFatigue >= minFatigue) {
                currentFatigue -= costFatigue;
                count++;
            }
        }

        max = Math.max(max, count);
    }
}
