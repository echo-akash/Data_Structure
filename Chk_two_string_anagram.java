
package Chk_two_string_anagram;

import java.util.Arrays;
import java.util.Scanner;

public class Chk_two_string_anagram {    
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        while(true){
            String st1 = sc.next();
            String st2 = sc.next();
            if(anagram_using_sorting(st1, st2)){
                System.out.println("Anagram");
            }else{
                System.out.println("Not Anagram");
            }
            if(anagram(st1, st2)){
                System.out.println("Anagram");
            }else{
                System.out.println("Not Anagram");
            }            
        }
    }   
    public static boolean anagram_using_sorting(String s1, String s2){
        char c1[] = s1.toCharArray();
        char c2[] = s2.toCharArray();
        Arrays.sort(c1);
        Arrays.sort(c2);
        s1 = new String(c1);
        s2 = new String(c2);
        return s1.equals(s2);
    }
    public static boolean anagram(String s1, String s2){
        if(s1.length()!=s2.length())
            return false;
        int[] letters = new int[255];
        int num_unique_char=0, num_completed_t=0;
        char[] s1_array = s1.toCharArray();
        for(char c:s1_array){   //count number of each characters in s1
            if(letters[c]==0)
                ++num_unique_char;
            ++letters[c];
        }
        for (int i = 0; i < s2.length(); i++) {
            int c = (int)s2.charAt(i);
            if(letters[c]==0){  //found char in s2 which are not present in s1
                return false;
            }
            --letters[c];
            if(letters[c]==0){
                ++num_completed_t;
                if(num_completed_t==num_unique_char){
                    return i == s2.length()-1;
                }
            }
        }
        return false;
    }
    
}
