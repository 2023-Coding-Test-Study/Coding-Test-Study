import java.util.*;

class Solution {

    int defaultTime;
    int defaultFee;
    int unitTime;
    int unitFee;

    public static void main(String[] args) {
        Solution solution = new Solution();

//        System.out.println(solution.solution("()))((()"));
        var answer = solution.solution(new int[]{180, 5000, 10, 600},
                new String[]{"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN",
                        "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"});

        var result = new int[]{14600, 34400, 5000};

        boolean correct = true;
        for (int i = 0; i < answer.length; i++) {
            System.out.println(answer[i]);
        }
    }

    public int[] solution(int[] fees, String[] records) {
        defaultTime = fees[0];
        defaultFee = fees[1];
        unitTime = fees[2];
        unitFee = fees[3];

        Map<Integer, Integer> map = new HashMap<>();
        Map<Integer, Integer> duration = new HashMap<>();
        Map<Integer, Integer> answer = new TreeMap<>();

        for (int i = 0; i < records.length; i++) {
            String[] inputs = records[i].split(" ");
            if (inputs[2].equals("IN")) {
                map.put(Integer.parseInt(inputs[1]), calculateTime(inputs[0]));
            } else {
                int carNumber = Integer.parseInt(inputs[1]);
                int outTime = calculateTime(inputs[0]);
                Integer inTime = map.get(carNumber);

                Integer history = duration.getOrDefault(carNumber, 0);
                duration.put(carNumber, (outTime - inTime) + history);
                map.remove(carNumber);
            }
        }

        for (Map.Entry<Integer, Integer> entries : map.entrySet()) {
            int lastTime = 1439;
            int history = duration.getOrDefault(entries.getKey(), 0);
            int leftTime = lastTime - entries.getValue();
            duration.put(entries.getKey(), history + leftTime);
        }

        for (Map.Entry<Integer, Integer> entries : duration.entrySet()) {
            System.out.println("carNumber = " + entries.getKey());
            answer.put(entries.getKey(), calculateFee(entries.getValue()));
        }

        int[] ints = new int[answer.size()];
        int index = 0;
        for (Map.Entry<Integer, Integer> entries : answer.entrySet()) {
            ints[index] = entries.getValue();
            index++;
        }

        return ints;
    }

    public int calculateTime(String input) {
        String[] time = input.split(":");
        return Integer.parseInt(time[0]) * 60 + Integer.parseInt(time[1]);
    }

    public int calculateFee(int time) {
        System.out.println("time = " + time);

        if (time <= defaultTime) {
            return defaultFee;
        } else {
            int resultFee = 0;
            resultFee += defaultFee;

            int a = (time - defaultTime) / unitTime;
            if((time - defaultTime) % unitTime != 0) a++;
            System.out.println("a = " + a);
            resultFee += (a * unitFee);
            return resultFee;
        }

    }
}
