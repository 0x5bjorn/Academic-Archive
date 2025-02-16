
public class ArrayListInt {
	private static final int DEFAULT_CAPACITY = 10;
	private int[] data;
	private int length;
	
	public ArrayListInt() {
		data = new int[DEFAULT_CAPACITY];
		length = 0;
	}	
	
	public int size() {
		return length;
	}
	
	public int get(int index) {
		if (index < 0 || length <= index) {
			throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + length);
		}
		 
		return data[index];
	}
	
	public void set(int index, int value) {
		if (index < 0 || length <= index) {
			throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + length);
		}
		
		data[index] = value;
	}
	
	public void ensureCapacity() {
		if (length == data.length) {
			int[] temp = new int[data.length + data.length/2];
			for (int i = 0; i<data.length; ++i) {
				temp[i] = data[i];
			}
			data = temp;
		}
	}
	
	public void add(int e) {
		ensureCapacity();
		data[length] = e;
		++length;
	}
	
	public void add(int index, int value) {
		if (index < 0 || length < index) {
			throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + length);
		}
		
		ensureCapacity();
		
		for (int i = length; i > index; --i) {
			data[i] = data[i - 1];
		}
		data[index] = value;
		
		++length;
	}
	
	public void remove(int index) {
		if (index < 0 || length <= index) {
			throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + length);
		}
		
		for (int i = index + 1; i < length; ++i) {
			data[i - 1] = data[i];
		}
		
		--length;
	}
}
