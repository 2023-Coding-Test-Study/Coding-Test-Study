class Solution {
    public boolean solution(int[][] key, int[][] lock) {
        int offset = key.length - 1;
        for (int r = 0; r < offset + lock.length; r++) {
            for (int c = 0; c < offset + lock.length; c++) {
                for (int rot = 0; rot < 4; rot++) {
                    /**
                     * 이차원 배열에 key배열만큼 테두리를 둘러쌈
                     */
                    int[][] arr = new int[58][58];
                    for (int i = 0; i < lock.length; i++) {
                        for (int j = 0; j < lock.length; j++) {
                            arr[offset + i][offset + j] = lock[i][j];
                        }
                    }


                    rotate(rot, r, c, arr, key);


                    boolean flag = true;
                    for (int i = 0; i < lock.length; ++i) {
                        for (int j = 0; j < lock.length; ++j) {
                            // 1이 아니라면 자물쇠와 열쇠가 모두 홈부분이거나 돌기 부분끼리 만난 것
                            if (arr[offset + i][offset + j] != 1) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (flag) return true;
                }
            }
        }
        return false;
    }

    void rotate(int rot, int r, int c, int[][] arr, int[][] key) {
        int n = key.length;
        // 자물쇠 값이 0이면 홈, 1이면 돌기
        // 자물쇠에 열쇠값을 더해주어 딱 맞았다면 그 값이 1인지만 판단
        switch (rot) {
            case 0:
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        arr[r + i][c + j] += key[i][j];
                    }
                }
                break;
            case 1:
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        arr[r + i][c + j] += key[n - 1 - j][i];
                    }
                }
                break;
            case 2:
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        arr[r + i][c + j] += key[n - 1 - i][n - 1 - j];
                    }
                }
                break;
            case 3:
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        arr[r + i][c + j] += key[j][n - 1 - i];
                    }
                }
                break;
        }
    }
}
