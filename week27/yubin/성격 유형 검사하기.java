import java.util.*;

class Solution {
    public String solution(String[] survey, int[] choices) {
        String answer = "";

        Map<Character, Integer> map = new HashMap<>();
        map.put('R', 0);
        map.put('T', 0);
        map.put('C', 0);
        map.put('F', 0);
        map.put('J', 0);
        map.put('M', 0);
        map.put('A', 0);
        map.put('N', 0);

        for(int i=0; i<survey.length; i++){
            String string = survey[i];
            if(choices[i] > 4) {
                map.put(string.charAt(1), map.get(string.charAt(1)) + choices[i] - 4);
            } else if(choices[i] < 4){
                map.put(string.charAt(0), map.get(string.charAt(0)) + Math.abs(choices[i]-4));
            }
        }

        StringBuilder sb = new StringBuilder();

        if(map.get('R') > map.get('T')){
            sb.append("R");
        } else if(map.get('R') < map.get('T')){
            sb.append("T");
        } else{
            sb.append("R");
        }

        if(map.get('C') > map.get('F')){
            sb.append("C");
        } else if(map.get('C') < map.get('F')){
            sb.append("F");
        } else{
            sb.append("C");
        }

        if(map.get('J') > map.get('M')){
            sb.append("J");
        } else if(map.get('J') < map.get('M')){
            sb.append("M");
        } else{
            sb.append("J");
        }

        if(map.get('A') > map.get('N')){
            sb.append("A");
        } else if(map.get('A') < map.get('N')){
            sb.append("N");
        } else{
            sb.append("A");
        }

        return sb.toString();
    }
}
