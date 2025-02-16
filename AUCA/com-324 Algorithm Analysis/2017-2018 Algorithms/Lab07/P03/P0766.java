import java.util.*;

public class P0766
{
    static Random rnd = new Random();
    
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
        {
            a[i] = scan.nextInt();
        }
        
        quickSort(a);
        
        for (int e: a)
        {
            System.out.print(e + " ");
        }
        System.out.println();
    }
    
    static void quickSort(int[] a)
    {
        if (a == null)
        {
            return;
        }
        int counter = 0;
        
        for (int i = 0; i < a.length; ++i)
        {
            int j = rnd.nextInt(a.length);
            if (a[i] != a[j])
            {
                ++counter;
                swap(a, i, j);
            }
        }
        if (counter > 0)
        {
            quickSortAux(a, 0, a.length - 1);
        }
        else
        {
            insertSort(a);
        }
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
                swap(a, i, k);
            }
        }
        
        ++k;
        swap(a, k, rgt);
        
        return k;
    }
    
    static void swap(int[] a, int i, int j)
    {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
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
    