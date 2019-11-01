//assume only lower case
//use bit vector to reduce space

package Chk_String_all_unique_char_bit_vector;

import java.util.Scanner;

public class Chk_String_all_unique_char_bit_vector {    
    
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
        int chk = 0;
        for (int i = 0; i < st.length(); i++) {
            int val = st.charAt(i) - 'a';
            if((chk & (1<<val))>0)
                return false;
            chk = chk | (1<<val);
            //chk |= (1<<val);
        }
        return true;
    }
    
}
