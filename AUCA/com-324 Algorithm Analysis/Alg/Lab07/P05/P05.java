import java.util.*;

public class P05
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
        int lft = 0;
        int rgt = a.length - 1;
        while (lft <= rgt)
        {
            int m = lft + (rgt - lft) / 2;
            if (a[m] == k)
            {
                return m;
            }
            else if (a[m] < k)
            {
                lft = m + 1;
            }
            else
            {
                rgt = m - 1;
            }
        }
        
        return -(lft + 1);
    }
}