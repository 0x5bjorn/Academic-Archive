import java.lang.reflect.Array;
import java.util.*;

public class Lab07Problem01 {

	public static void main(String[] args) throws Exception {
		int[] a = {5, 1, 2, 4, 3, 6, 8};
		Arrays.sort(a);
		for (int e: a) {
			System.out.print(e + " ");
		}
		System.out.println();
		
		String[] b = {"Java", "C++", "C", "C#"};
		Arrays.sort(b);
		for (String e: b) {
			System.out.print(e + " ");
		}
		System.out.println();
		
		Rational[] c = {new Rational(3, 2),
						new Rational(1, 2),
						new Rational(0, 1)};
		Arrays.sort(c);
		for (Rational e: c) {
			System.out.print(e + " ");
		}
		System.out.println();
		
		Student[] d = {new Student("B", 21, 2.3),
				 	   new Student("A", 23, 3.1),
				 	   new Student("C", 17, 3.7),};
		
		Arrays.sort(d, new CmpByName());
		for (Student e: d) {
			System.out.print(e + " ");
		}
		System.out.println();
		
		Arrays.sort(d, new CmpByAge());
		for (Student e: d) {
			System.out.print(e + " ");
		}
		System.out.println();
		
		Arrays.sort(d, new CmpByGpa());
		for (Student e: d) {
			System.out.print(e + " ");
		}
		System.out.println();
	}
}

class CmpByName implements Comparator {

	@Override
	public int compare(Object o1, Object o2) {
		Student s1 = (Student)o1;
		Student s2 = (Student)o2;
		return s1.getName().compareTo(s2.getName());
	}
}

class CmpByAge implements Comparator {

	@Override
	public int compare(Object o1, Object o2) {
		Student s1 = (Student)o1;
		Student s2 = (Student)o2;
		return s1.getAge() - s2.getAge();
	}
}

class CmpByGpa implements Comparator {

	@Override
	public int compare(Object o1, Object o2) {
		Student s1 = (Student)o1;
		Student s2 = (Student)o2;
		if (s1.getGpa() < s2.getGpa()) return -1;
		if (s1.getGpa() > s2.getGpa()) return 1;
		return 0;
	}
}