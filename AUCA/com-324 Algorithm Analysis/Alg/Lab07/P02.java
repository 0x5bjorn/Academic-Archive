import java.util.*;

public class P01 {
	public static void main(String[] args) {
		int[] a = {3, 1, 2, 0, 1};
		
		mergeSort(a);
		
		System.out.println(Arrays.toString(a));
	}
	
	static void mergeSort(int[] a) {
		if (a == null) {
			return;
		}
		
		int[] t = new in[a.length];
		mergeSortAux(a, t, 0, length-1);
	}
	
	static void mergeSortAux(int[] a, int[] t, int lft, int rgt) {
		if (lft < rgt) {
			int m = lft + (rgt - lft) / 2;
			mergeSortAux(a, t, lft, m);
			mergeSortAux(a, t, m+1, rgt);
			merge(a, t, lft, m, rgt);
		}
	}
	
	static void merge(int[] a, int[] t, int lft, int m, int rgt) {
		int i = lft;
		int j = m+1;
		int k = 0;
		while (i <= m && j<=rgt) {
			if (a[i] <= a[j]) {
				t[k++] = a[i++];
			} else {
				t[k++] = a[j++];
			}
		}
		
		while (i <= m) {
			t[k++] = a[i++];
		}
		
		while (j <= rgt) {
			t[k++] = a[j++];
		}
		
		i = lft;
		j = 0;
		for (j < k) {
			a[i++] = t[j++];
		}
	}
}