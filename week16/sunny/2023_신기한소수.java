package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

// 백준 2023번: 신기한 소수
public class BOJ_2023 {

    static int N;
    static List<Integer> answer = new ArrayList<>();

    public static void dfs(int depth, int number) {
        if (depth == N) {
            if (isPrime(number)) answer.add(number);
            return;
        }
        for (int i = 1; i <= 9; i++) { // 0이 들어갈 순 없음! 왜냐하면 XX0 => 무조건 소수아님!
            if (depth == 0 && i == 1) continue; // 1로 시작하면 안됨! 왜냐하면 1은 소수가 아니기 때문.
            int newNumber = Integer.parseInt(new StringBuilder().append(number).append(i).toString());
            if (isPrime(newNumber)) {
                dfs(depth + 1, newNumber);
            }
        }
    }

    public static boolean isPrime(int number) {
        for (int i = 2; i < number; i++) {
            if (number % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        dfs(0, 0);
        StringBuilder sb = new StringBuilder();
        Collections.sort(answer);
        for (int str : answer) {
            sb.append(str).append("\n");
        }
        System.out.println(sb);
    }
}