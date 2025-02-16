import java.util.*;

public class P0232
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
        {
            a[i] = scan.nextInt();
        }
        
        insertSort(a);
        
        for (int e: a)
        {
            System.out.print(e + " ");
        }
        System.out.println();
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
    