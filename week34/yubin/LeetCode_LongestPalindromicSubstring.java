class Solution {

    int size;
    String answer = "";

    public String longestPalindrome(String s) {
        if(s.length() < 2) return s;
        size = s.length();
        for(int i=0; i<s.length(); i++){
            String tempA = iterate(s, i, i);
            String tempB = iterate(s, i, i+1);
            if(answer.length() < tempA.length()) {
                answer = tempA;
            }
            if(answer.length() < tempB.length()) {
                answer = tempB;
            }
        }

        return answer;
    }

    private String iterate(String s, int start, int end){

        while(true){
            if(start < 0 || end > size - 1 || s.charAt(start) != s.charAt(end)) {
                start++;
                end--;
                break;
            } else {
                start --;
                end++;
            }


        }

        return s.substring(start, end+1);
    }
}
