class Solution {
    int N;
    int[] selected;
    boolean[] visited;
    int[][] info;
    int answer = -1;
    int K;

    public int solution(int k, int[][] dungeons) {
        N = dungeons.length;
        selected = new int[N];
        visited = new boolean[N];
        info = dungeons;
        K = k;
        dfs(0);
        return answer;
    }

    public void dfs(int depth) {
        if (depth == N) {
            answer = Math.max(answer, check());
            return;
        }
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                selected[depth] = i;
                dfs(depth + 1);
                visited[i] = false;
            }
        }
    }

    public int check() {
        int i = 0;
        int p = K;
        for (; i < N; i++) {
            int[] dungeon = info[selected[i]];
            if (p >= dungeon[0]) {
                p -= dungeon[1];
            } else {
                break;
            }
        }
        return i;
    }
}