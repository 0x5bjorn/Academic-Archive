import java.util.*;

public class P01
{
    public static void main(String[] args)
    {
        int[] a = {3, 1, 2, 0, 1};
        
        insertSort(a);
        
        System.out.println(Arrays.toString(a));
        
        int[] b = {3, 2, 1, 0, -1};
        
        insertSort(b);
        
        System.out.println(Arrays.toString(b));
        
        int[] c = {0, 1, 2, 3, 4};
        
        insertSort(c);
        
        System.out.println(Arrays.toString(c));
    }
    
    static void insertSort(int[] a)
    {
        if (a == null)
        {
            return;
        }
        
        for (int i = 1; i < a.length; ++i)
        {
            int k = a[i];
            int j = i - 1;
            while (j > -1 && a[j] > k)
            {
                a[j + 1] = a[j];
                --j;
            }
            a[j + 1] = k;
        }
    }
}
    