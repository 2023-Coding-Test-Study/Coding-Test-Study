import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Map.Entry;

public class Main {

    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {-1, 0, 1, 0};

    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("src/input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(st.nextToken());
        for (int i = 0; i < T; i++) {
            st = new StringTokenizer(br.readLine());
            String string = st.nextToken();

            sb.append(move(string));
            sb.append("\n");
        }

        System.out.println(sb.toString());

    }

    static int move(String input) {

        int maxX = 0;
        int maxY = 0;
        int minX = 0;
        int minY = 0;

        int nowX = 0;
        int nowY = 0;
        int d = 0;

        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == 'F') {
                nowX += dx[d];
                nowY += dy[d];

                maxX = Math.max(maxX, nowX);
                maxY = Math.max(maxY, nowY);
                minX = Math.min(minX, nowX);
                minY = Math.min(minY, nowY);
            } else if (input.charAt(i) == 'B') {
                nowX -= dx[d];
                nowY -= dy[d];

                maxX = Math.max(maxX, nowX);
                maxY = Math.max(maxY, nowY);
                minX = Math.min(minX, nowX);
                minY = Math.min(minY, nowY);
            } else if (input.charAt(i) == 'L') {
                d--;
                if(d < 0) d = 3;
            } else {
                d++;
                if(d > 3) d = 0;
            }
        }

        return Math.abs(maxX - minX) * Math.abs(maxY - minY);
    }
}
