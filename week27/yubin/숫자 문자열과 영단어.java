import java.util.*;
class Solution {
    public static void main(String[] args) {
        System.out.println(solution("one4seveneight"));
    }
    public static int solution(String s) {
        int answer = 0;
        List<Integer> list = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        map.put("zero", 0);
        map.put("one", 1);
        map.put("two", 2);
        map.put("three", 3);
        map.put("four", 4);
        map.put("five", 5);
        map.put("six", 6);
        map.put("seven", 7);
        map.put("eight", 8);
        map.put("nine", 9);

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<s.length(); i++){
            if((int) s.charAt(i) > 96){
                sb.append(s.charAt(i));
                if(map.containsKey(sb.toString())){
                    list.add(map.get(sb.toString()));
                    sb = new StringBuilder();
                }
            } else{
                list.add(Integer.parseInt(String.valueOf(s.charAt(i))));
            }
        }

        // 1 1 2 3
        int size = list.size()-1;
        for(int i=0; i<list.size(); i++){
            System.out.println(list.get(i));
            answer += Math.pow(10, size) * list.get(i);
            size--;
        }
        return answer;
    }
}
