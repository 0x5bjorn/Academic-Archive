import java.util.*;

public class P01 {
	public static void main(String[] args) {
		int[] a = {3, 1, 2, 0, 1};
		
		quickSort(a);
		
		System.out.println(Arrays.toString(a));
	}
	
	static void quickSort(int[] a) {
		if (a == null) {
			return;
		}
		quickSortAux(a, 0, a.length-1);
	}
	
	static void quickSortAux(int[] a, int lft, int rgt) {
		if (lft < rgt) {
			int pivot = partition(a, lft, rgt);
			quickSortAux(a, lft, pivot-1);
			quickSortAux(a, pivot+1, rgt);
		}
	}
	
	static void partition(int[] a, int lft, int rgt) {
		int pivot = a[rgt];
		int k = lft - 1;
		for (int i = lft; i<rgt; ++i) {
			if (a[i] < pivot) {
				++k;
				int t = a[i];
				a[i] = a[k];
				a[k] = t;
			)
			
			
		}
	}
}