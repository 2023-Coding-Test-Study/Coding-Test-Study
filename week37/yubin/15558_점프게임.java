import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    static long sum = 0;
    static Set<Character> vowels = new HashSet<>(List.of('A', 'E', 'I', 'O', 'U'));
    static int N;
    static int k;
    static int[][] arr;

    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("src/input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        arr = new int[N+1+k][2];

        String temp = br.readLine();
        for (int i = 0; i < temp.length(); i++) {
            arr[i][0] = temp.charAt(i) - '0';
        }
        temp = br.readLine();
        for (int i = 0; i < temp.length(); i++) {
            arr[i][1] = temp.charAt(i) - '0';
        }
        for (int i = temp.length(); i <arr.length; i++) {
            arr[i][0] = 1;
            arr[i][1] = 1;
        }

        Queue<Unit> queue = new LinkedList<>();
        if (arr[0][0] == 0) {
            System.out.println("0");
        } else {

            queue.add(new Unit(0, 0, 0));
            arr[0][0] = 0;

            boolean clearable = false;
            while (!queue.isEmpty()) {
                Unit unit = queue.poll();

                if (unit.index >= N) {
                    clearable = true;
                    break;
                }

                if (arr[unit.index+1][unit.line] == 1) {
                    arr[unit.index+1][unit.line] = 0;
                    queue.add(new Unit(unit.line, unit.index + 1, unit.time + 1));

                }

                if ( unit.time < unit.index - 1 && arr[unit.index - 1][unit.line] == 1) {
                    arr[unit.index-1][unit.line] = 0;
                    queue.add(new Unit(unit.line, unit.index - 1, unit.time + 1));

                }

                if (arr[unit.index + k][1 - unit.line] == 1) {
                    arr[unit.index+k][1-unit.line] = 0;
                    queue.add(new Unit(1-unit.line, unit.index + k, unit.time + 1));
                }
            }
            if (clearable) {
                System.out.println("1");
            } else {
                System.out.println("0");
            }
        }




    }

    public static class Unit{
        int line;
        int index;
        int time;

        public Unit(int line, int index, int time) {
            this.line = line;
            this.index = index;
            this.time = time;
        }
    }

}


