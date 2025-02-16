const char* input_format = "%d";
const char* output_format = "%d + %d = %d\n";

int a = 0;
int b = 0;

int main() {
	scanf(input_format, &a, &b);
	int sum = a + b;
	printf(output_format, a, b, sum);

	return 0;
}
