import java.util.*;

public class P06
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        
        int n = scan.nextInt();
        int m = scan.nextInt();
        
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
        {
            a[i] = scan.nextInt();
        }
        
        for (int i = 0; i < m; ++i)
        {
            int k = scan.nextInt();
            
            int index = myBinarySearch(a, k);
            if (index >= 0)
            {
                System.out.println(a[index]);
            }
            else
            {
                index = -(index + 1);
                if (index == 0)
                {
                    System.out.println(a[0]);
                }
                else if (index == n)
                {
                    System.out.println(a[n - 1]);
                }
                else if (Math.abs(k - a[index - 1]) <= Math.abs(a[index] - k))
                {
                    System.out.println(a[index - 1]);
                }
                else
                {
                    System.out.println(a[index]);
                }
            }
        }
    }
    
    static int myBinarySearch(int[] a, int k)
    {
        return binarySearchAux(a, 0, a.length - 1, k);
    }
    
    static int binarySearchAux(int[] a, int lft, int rgt, int k)
    {
        if (lft > rgt)
        {
            return -(lft + 1);
        }
  
        int m = lft + (rgt - lft) / 2;
        
        if (a[m] == k)
        {
            return m;
        }
        
        if (a[m] < k)
        {
            return binarySearchAux(a, m + 1, rgt, k);
        }
        
        return binarySearchAux(a, lft, m - 1, k);
    }
}