
public class MyArrays {
	public static void sort(int[] a) {
		for (int i = 0; i < a.length - 1; ++i) {
			int indexMin = i;
			for (int j = i + 1; j < a.length; ++j) {
				if (a[indexMin] > a[j]) {
					indexMin = j;
				}
			}
			int t = a[i];
			a[i] = a[indexMin];
			a[indexMin] = t;
		}
	}
	
	public static void sort(MyComparable[] a) {
		for (int i = 0; i < a.length - 1; ++i) {
			int indexMin = i;
			for (int j = i + 1; j < a.length; ++j) {
				if (a[indexMin].compareTo(a[j]) > 0) {
					indexMin = j;
				}
			}
			MyComparable t = a[i];
			a[i] = a[indexMin];
			a[indexMin] = t;
		}
	}
	
	public static void sort(Object[] a, MyComparator cmp) {
		for (int i = 0; i < a.length - 1; ++i) {
			int indexMin = i;
			for (int j = i + 1; j < a.length; ++j) {
				if (cmp.compare(a[indexMin], a[j]) > 0) {
					indexMin = j;
				}
			}
			Object t = a[i];
			a[i] = a[indexMin];
			a[indexMin] = t;
		}
	}
}
