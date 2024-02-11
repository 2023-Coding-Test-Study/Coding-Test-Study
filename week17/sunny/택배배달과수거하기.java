class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        
        long answer = 0;
        int dSize = n, pSize = n;

        for (int i = dSize - 1; i >= 0; i--) {
            if (deliveries[i] > 0) break;
            dSize--;
        }
        for (int i = pSize - 1; i >= 0; i--) {
            if (pickups[i] > 0) break;
            pSize--;
        }
        long size = Math.max(dSize, pSize);

        while (size > 0) {
            // deliveries 뒤에서 부터 cap 만큼 제거
            int dCap = cap;
            for (int i = dSize - 1; i >= 0 && dCap > 0; i--) {
                if (deliveries[i] > 0) {
                    if (deliveries[i] >= dCap) {
                        deliveries[i] -= dCap;
                        break;
                    } else {
                        dCap -= deliveries[i];
                        deliveries[i] = 0;
                    }
                }
            }
            for (int i = dSize - 1; i >= 0; i--) {
                if (deliveries[i] > 0) break;
                dSize--;
            }

            // pickups 뒤에서 부터 cap 만큼 제거
            int pCap = cap;
            for (int i = pSize - 1; i >= 0 && pCap > 0; i--) {
                if (pickups[i] > 0) {
                    if (pickups[i] >= pCap) {
                        pickups[i] -= pCap;
                        break;
                    } else {
                        pCap -= pickups[i];
                        pickups[i] = 0;
                    }
                }
            }
            for (int i = pSize - 1; i >= 0; i--) {
                if (pickups[i] > 0) break;
                pSize--;
            }
            answer += size;
            size = Math.max(dSize, pSize);
        }
        return answer * 2;
    }
}