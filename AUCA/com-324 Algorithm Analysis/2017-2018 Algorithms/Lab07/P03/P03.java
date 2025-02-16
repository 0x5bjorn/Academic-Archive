import java.util.*;

public class P03
{
    public static void main(String[] args)
    {
        int[] a = {3, 1, 2, 0, 1};
        
        quickSort(a);
        
        System.out.println(Arrays.toString(a));
        
        int[] b = {3, 2, 1, 0, -1};
        
        quickSort(b);
        
        System.out.println(Arrays.toString(b));
        
        int[] c = {0, 1, 2, 3, 4};
        
        quickSort(c);
        
        System.out.println(Arrays.toString(c));
    }
    
    static void quickSort(int[] a)
    {
        if (a == null)
        {
            return;
        }
        quickSortAux(a, 0, a.length - 1);
    }
    
    static void quickSortAux(int[] a, int lft, int rgt)
    {
        if (lft < rgt)
        {
            int pivot = partition(a, lft, rgt);
            quickSortAux(a, lft, pivot - 1);
            quickSortAux(a, pivot + 1, rgt);
        }
    }
    
    static int partition(int[] a, int lft,  int rgt)
    {
        int pivot = a[rgt];
        int k = lft - 1;
        for (int i = lft; i < rgt; ++i)
        {
            if (a[i] < pivot)
            {
                ++k;
                int t = a[i];
                a[i] = a[k];
                a[k] = t;
            }
        }
        
        ++k;
        int t = a[k];
        a[k] = a[rgt];
        a[rgt] = t;
        
        return k;
    }
    
}
    