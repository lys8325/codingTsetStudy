import java.util.*;

class Solution {
    public ArrayList<ArrayList<Integer>> parse(String s){
        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();

        String strList[] = s.split("[}][,][{]");
        Arrays.sort(strList, (a, b) -> a.length() - b.length());
        
        for(String str : strList){
            String intList[] = str.split("[,]");
            ArrayList<Integer> intArr = new ArrayList<>();
            for(String i : intList){
                intArr.add(Integer.valueOf(i));
            }
            ret.add(intArr);
        }

        return ret;
    }
    
    public int[] solution(String s) {
        int[] answer = {};
        ArrayList<ArrayList<Integer>> list = parse(s.substring(2, s.length()-2));
        HashSet<Integer> set = new HashSet<>();
        ArrayList<Integer> ans = new ArrayList<>();
        
        for(ArrayList<Integer> tmp : list){
            for(Integer i : tmp){
                if(!set.contains(i)){
                    ans.add(i);
                    set.add(i);
                }
            }
        }

        answer = new int[ans.size()];
        for(int i=0;i<ans.size();++i){
            answer[i] = ans.get(i);
        }
        
        return answer;
    }
}
