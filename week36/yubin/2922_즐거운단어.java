import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    static long sum = 0;
    static Set<Character> vowels = new HashSet<>(List.of('A', 'E', 'I', 'O', 'U'));
    static int N;
    public static char[] arr;

    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("src/input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        String input = st.nextToken();
        N = input.length();
        arr = input.toCharArray();
        dfs(false, 0, 0, 0, 1,1);
//        dfs(false, 0, 0, 0, 0,0);

        System.out.println(sum);
    }

    private static void dfs(boolean containL, int continuousConsonant, int continuousVowel, int index,
                            int consonantCount, int vowelCount) {

        if (continuousConsonant == 3 || continuousVowel == 3) {
            return;
        }
        if (index == N) {
            if (containL) {
                sum += (long) vowelCount * consonantCount;
            }
            return;
        }

        if (arr[index] == '_') {
            // vowel
            dfs(containL, 0, continuousVowel + 1, index + 1, consonantCount, vowelCount * 5);

            // consonant
            dfs(containL, continuousConsonant + 1, 0, index + 1, consonantCount * 20, vowelCount);


            // L
            dfs(true, continuousConsonant+1, 0, index + 1, consonantCount, vowelCount);
        } else {
            if (vowels.contains(arr[index])) {
                dfs(containL, 0, continuousVowel + 1, index + 1, consonantCount, vowelCount);
            } else {
                if (arr[index] == 'L') {
                    dfs(true, continuousConsonant + 1, 0, index + 1, consonantCount, vowelCount);
                } else {
                    dfs(containL, continuousConsonant + 1, 0, index + 1, consonantCount, vowelCount);
                }
            }
        }

    }

}


