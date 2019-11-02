
package remove_duplicate_elements_from_String;

import java.util.Scanner;

public class remove_duplicate_elements_from_String {    
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        while(true){
            System.out.println("Please enter elements...");
            char[] a=sc.next().toCharArray();
            System.out.println("Array elements are : ");
            for (int i=0;i<a.length;i++)
                System.out.println(a[i]);
            removeDuplicate(a);
        }
    }   
    public static void removeDuplicate(char[] str){
        if(str == null)
            return ;
        if(str.length<2)
            return;
        int tail=1;
        for (int i = 1; i < str.length; ++i) {
            int j;
            for (j = 0; j < tail; ++j) {
                if(str[i]==str[j])
                    break;
            }
            if(j==tail){
                str[tail]=str[i];
                ++tail;
            }
        }
        str[tail]=0;
        System.out.println("\nAfter remove dublicates- ");
        for (int i=0;i<str.length;i++)
            System.out.println(str[i]);     
    }
    
}
