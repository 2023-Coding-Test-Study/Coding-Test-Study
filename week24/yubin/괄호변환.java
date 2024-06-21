import java.util.*;

class Solution {

    public static void main(String[] args) {
        Solution solution = new Solution();

        System.out.println(solution.solution("()))((()"));
    }


    public String solution(String p) {
        String answer = "";
        if(p.isEmpty()){
            return p;
        }

        return recursive(p);
    }


    public String recursive(String input){
        //2. u, v 분리
        Pair pair = separate(input);
        String u = pair.u;
        String v = pair.v;
        if(input.isEmpty()){
            return input;
        }

        System.out.println();
        System.out.println("recursive");
        System.out.println("u = " + u);
        System.out.println("v = " + v);
        //3
        if(checkCorrect(u)){
            System.out.println("checkCorrect : true");
            return u + recursive(v);
        } else{
            System.out.println("checkCorrect : false");
            StringBuilder temp = new StringBuilder();
            temp.append('(');
            temp.append(recursive(v));
            temp.append(')');
            System.out.println("temp = " + temp.toString());
            String tempU = u.substring(1, u.length()-1);
            System.out.println("u = " + u);
            System.out.println("tempU = " + tempU);
            StringBuilder recursiveTempU = new StringBuilder();
            for(int i=0; i<tempU.length(); i++){
                if(tempU.charAt(i) == '('){
                    recursiveTempU.append(')');
                } else {
                    recursiveTempU.append('(');
                }
            }
            temp.append(recursiveTempU.toString());
            System.out.println("temp = " + temp.toString());
            return temp.toString();

        }
    }

    public Pair separate(String input){
        int left = 0;
        int right = 0;
        String u = "";
        String v = "";

        for(int i=0; i<input.length(); i++){
            if(input.charAt(i) == '('){
                left++;
            } else {
                right++;
            }

            if(left == right){
                u = input.substring(0, left+right);
                v = input.substring(left+right);
                break;
            }
        }

        return new Pair(u, v);
    }

    public boolean checkCorrect(String u){
        Stack<Character> stack = new Stack<>();

        for(int i=0; i<u.length(); i++){
            char c = u.charAt(i);
            if(c == '('){
                stack.push(c);
            } else {
                if(!stack.isEmpty()){
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        if(stack.isEmpty()) return true;
        else return false;
    }
}

class Pair {
    String u;
    String v;

    public Pair(String u, String v) {
        this.u = u;
        this.v = v;
    }
}
