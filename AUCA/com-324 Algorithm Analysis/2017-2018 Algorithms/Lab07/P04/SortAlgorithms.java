class SortAlgorithms
{
    public static void insertionSort(int[] a)
    {
        for (int i = 1; i < a.length; ++i)
        {
            int key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > key)
            {
                a[j + 1] = a[j];
                --j;
            }
            a[j + 1] = key;
        }
    }
    
    
    public static void quickSort(int[] a)
    {
        quickSortAux(a, 0, a.length);
    }
    
    static void quickSortAux(int[] a, int left, int right)
    {
        if (right - left > 1)
        {
            int p = partition(a, left, right);
            quickSortAux(a, left, p);
            quickSortAux(a, p + 1, right);
        }
    }
    
    static int partition(int[] a, int left, int right)
    {
        int pivot = a[right - 1];
        int k = left - 1;
        int lim = right - 1;
        for (int i = left; i < lim; ++i)
        {
            if (a[i] < pivot)
            {
                ++k;
                int t = a[k];
                a[k] = a[i];
                a[i] = t;
            }
        }
    
        ++k;
        int t = a[k];
        a[k] = a[right - 1];
        a[right - 1] = t;
        
        return k;
    }
    
    public static void mergeSort(int[] a)
    {
        int[] t = new int[a.length];
        mergeSortAux(a, t, 0, a.length);
    }
    
    private static void mergeSortAux(int[] a, int[] t, int left, int right)
    {
        if (right - left > 1)
        {
            int m = left + (right - left) / 2;
            mergeSortAux(a, t, left, m);
            mergeSortAux(a, t, m, right);
            merge(a, t, left, m, right);
        }
    }
    
    private static void merge(int[] a, int[] t, int lft, int m, int rgt)
    {
        int i = lft;
        int j = m;
        int k = 0;
        while (i < m && j < rgt)
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
        while (i < m)
        {
            t[k++] = a[i++];
        }
        
        while (j < rgt)
        {
            t[k++] = a[j++];
        }
        
        for (i = 0; i < k; ++i)
        {
            a[lft + i] = t[i];
        }
    }
    
   
    public static int[] merge(int[] left, int[] right)
    {
        int[] res = new int[left.length + right.length];
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < left.length && j < right.length)
        {
            if (left[i] <= right[j])
            {
                res[k++] = left[i++];
            }
            else
            {
                res[k++] = right[j++];
            }
        }
        while (i < left.length)
        {
            res[k++] = left[i++];
        }
        
        while (j < right.length)
        {
            res[k++] = right[j++];
        }
        
        return res;
    }
}