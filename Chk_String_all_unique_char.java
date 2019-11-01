//for simplicity assume char set is ASCII else inc the storage size
//Time complexity=O(n) where n is the length of the string
//Space complexity = O(n)
//without using any data strucutres


package Chk_String_all_unique_char;

import java.util.Scanner;

public class Chk_String_all_unique_char {    
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while(true){
            String st = input.next();
            if(isUniqueChar(st)){
                System.out.println("All Characters Unique");
            }else{
                System.out.println("All Characters not unique");
            }
        }
    }   
    public static boolean isUniqueChar(String st){
        boolean[] char1 = new boolean[256];
        for (int i = 0; i < st.length(); i++) {
            int val = st.charAt(i);
            if(char1[val]){
                return false;
            }
            char1[val] = true;
        }
        return true;
    }
    
}
