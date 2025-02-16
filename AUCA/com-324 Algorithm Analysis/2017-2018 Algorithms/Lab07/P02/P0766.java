import java.util.*;

public class P0766
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
        
        mergeSort(a);
        
        for (int e: a)
        {
            System.out.print(e + " ");
        }
        System.out.println();
    }
    
    static void mergeSort(int[] a)
    {
        if (a == null)
        {
            return;
        }
        int[] t = new int[a.length];
        mergeSortAux(a, t, 0, a.length - 1);
    }
    
    static void mergeSortAux(int[] a, int[] t, int lft, int rgt)
    {
        if (lft < rgt)
        {
            int m = lft + (rgt - lft) / 2;
            mergeSortAux(a, t, lft, m);
            mergeSortAux(a, t, m + 1, rgt);
            merge(a, t, lft, m, rgt);
        }
    }
    
    static void merge(int[] a, int[] t, int lft,  int m, int rgt)
    {
        int i = lft;
        int j = m + 1;
        int k = 0;
        while (i <= m && j <= rgt)
        {
            if (a[i] <= a[j])
            {
                t[k++] = a[i++];
            }
            else
            {
                t[k++] = a[j++];
            }
        }
        
        while (i <= m)
        {
            t[k++] = a[i++];
        }
        
        while (j <= rgt)
        {
            t[k++] = a[j++];
        }
        
        i = lft;
        j = 0;
        while (j < k)
        {
            a[i++] = t[j++];
        }
    }
}
    