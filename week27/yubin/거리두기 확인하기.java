import java.util.*;

class Solution {

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.solution(new String[][]{{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}});
    }
    public int[] solution(String[][] places) {
        int[] answer = new int[5];
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};

        for(int i=0; i<5; i++){
            boolean isSafe = true;
            String[] arr = places[i];
            char[][] chars = new char[5][5];

            for(int j=0; j<5; j++){
                String string = arr[j];
                System.out.println("string = " + string);
                for(int k=0; k<string.length(); k++){
                    chars[j][k] = string.charAt(k);
                }
            }

            for (int j = 0; j < chars.length; j++) {
                for (int k = 0; k < chars[j].length; k++) {
                    System.out.print(chars[j][k] + " ");
                }
                System.out.println();
            }

            for(int j=0; j<5 && isSafe; j++){
                for(int k=0; k<5 && isSafe; k++){
                    if(chars[j][k] == 'P'){
                        for(int l=0; l<4; l++){
                            int nx = j + dx[l];
                            int ny = k + dy[l];


                            if(nx < 0 || ny < 0 || nx > 4 || ny > 4) continue;
                            System.out.println("nx = " + nx + ", ny = " + ny);
                            if(chars[nx][ny] == 'P') {
                                isSafe = false;
                                System.out.println("j = " + j + ", k = " + k);
                            }

                        }
                    } else if(chars[j][k] == 'O'){
                        int count = 0;
                        for(int l=0; l<4; l++){
                            int nx = j + dx[l];
                            int ny = k + dy[l];
                            if(nx < 0 || ny < 0 || nx > 4 || ny > 4) continue;
                            if(chars[nx][ny] == 'P') count++;
                        }
                        if(count >1) {
                            isSafe = false;
                            System.out.println("j = " + j + ", k = " + k);
                        }
                    }
                }
            }

            if(isSafe) answer[i] = 1;
            else answer[i] = 0;
            System.out.println();
        }

        return answer;
    }
}
