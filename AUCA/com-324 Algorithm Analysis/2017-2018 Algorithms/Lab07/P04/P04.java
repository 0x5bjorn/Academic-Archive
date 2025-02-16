import java.util.*;

public class P04
{
    
    public static void main(String[] args)
    {
        printSortResults(new InsertionSorter(), new RandomArrayGenerator(0), 1000, 8, 2);
        printSortResults(new MergeSorter(), new RandomArrayGenerator(0), 1000, 8, 2);
        printSortResults(new QuickSorter(), new RandomArrayGenerator(0), 1000, 8, 2);
               
        printSortResults(new InsertionSorter(), new IncreasingArrayGenerator(0), 1000, 8, 2);
        printSortResults(new MergeSorter(), new IncreasingArrayGenerator(0), 1000, 8, 2);
        printSortResults(new QuickSorter(), new IncreasingArrayGenerator(0), 1000, 8, 2);
    }

    static void printSortResults(Sorter sorter, ArrayGenerator arrayGenerator, int begValue, int nTimes, int k)
    {
        System.out.println("==================================");
        System.out.println(sorter.getName() + ": " + arrayGenerator.getNameOfOrder());
        System.out.printf("%10s %10s %10s%n", "Size", "Time", "Ratio");

        int n = begValue;
        long prevTime = 0;
        for (int i = 0; i < nTimes; ++i, n *= k)
        {
            int[] a = arrayGenerator.generate(n);
            long beg = System.currentTimeMillis();
            try
            {
                sorter.sort(a);    
            }
            catch (Exception e)
            {
                System.out.printf("%10d: Exception %s%n", n, e);
                continue;
            }
            catch (Error e)
            {
                System.out.printf("%10d: Error %s%n", n, e);
                continue;
            }
            
            long end = System.currentTimeMillis();

            long curTime = end - beg;
            String ratio = "-";
            if (prevTime != 0)
            {
                ratio = String.format("%10.4f",(double)curTime / prevTime);
            }
            System.out.printf("%10d %10d %10s%n", n, curTime, ratio);
            prevTime = curTime;
        }
        System.out.println("==================================");
    }
}

interface Sorter
{
    String getName();
    void sort(int[] a);
}

class InsertionSorter implements Sorter
{
    private String name = "InsertionSort";

    public String getName()
    {
        return name;
    }

    public void sort(int[] a)
    {
        SortAlgorithms.insertionSort(a);
    }
}

class MergeSorter implements Sorter
{
    private String name = "MergeSort";

    public String getName()
    {
        return name;
    }

    public void sort(int[] a)
    {
        SortAlgorithms.mergeSort(a);
    }
}

class QuickSorter implements Sorter
{
    private String name = "QuickSort";

    public String getName()
    {
        return name;
    }

    public void sort(int[] a)
    {
        SortAlgorithms.quickSort(a);
    }
}

interface ArrayGenerator
{
    String getNameOfOrder();
    int[] generate(int n);
}

class RandomArrayGenerator implements ArrayGenerator
{
    private String name = "Random Array";
    private Random rnd;

    public RandomArrayGenerator(int seed)
    {
        rnd = new Random(seed);
    }

    public String getNameOfOrder()
    {
        return name;
    }

    public int[] generate(int n)
    {
        int[] r = new int[n];
        for (int i = 0; i < n; ++i)
        {
            r[i] = rnd.nextInt();
        }
        return r;
    }
}

class IncreasingArrayGenerator implements ArrayGenerator
{
    private String name = "Sorted in Increasing Order Array";
    private Random rnd;

    public IncreasingArrayGenerator(int seed)
    {
        rnd = new Random(seed);
    }

    public String getNameOfOrder()
    {
        return name;
    }

    public int[] generate(int n)
    {
        int[] r = new int[n];
        r[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            r[i] = r[i - 1] + rnd.nextInt(2);
        }
        return r;
    }
}
