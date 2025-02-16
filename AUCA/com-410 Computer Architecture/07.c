const char *input_format = "%d %d";
const char *output_format = "%d\n";

int a = 0;
int b = 0;

int main() {
	
	scanf(input_format, &a, &b);
	
	if (a > b) {
		printf(output_format, a);
	} else if (a < b) {
		printf(output_format, b);
	} else {
		puts("equals");
	}

	return 0;
}
