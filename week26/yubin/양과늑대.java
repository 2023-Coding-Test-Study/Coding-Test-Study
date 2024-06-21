import java.util.*;

class Solution {

    int[] info;
    int[][] edges;
    int max = 0;

    public static void main(String[] args) {
        Solution solution = new Solution();
        int solution1 = solution.solution(new int[]{0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1},
                new int[][]{{0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, {9, 10}, {9, 11}, {4, 3}, {6, 5}, {4, 6}, {8, 9}});
        System.out.println(solution1);
    }

    public int solution(int[] info, int[][] edges) {
        boolean[] visited = new boolean[info.length];
        this.info = info;
        this.edges = edges;

        dfs(0, visited, 0, 0);

        return max;
    }

    public void dfs(int index, boolean[] visited, int sheepCount, int wolfCount) {
        if (info[index] == 0) {
            sheepCount++;
            max = Math.max(max, sheepCount);
        } else {
            wolfCount++;
        }
        visited[index] = true;

        if (sheepCount <= wolfCount) return;

        for (int[] edge : edges) {
            if (visited[edge[0]] && !visited[edge[1]]) {
                dfs(edge[1], visited.clone(), sheepCount, wolfCount);
            }
        }
    }
}
