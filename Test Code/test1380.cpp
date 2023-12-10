#include <stdio.h>

char* checkValidity(int r) {
	if (!r) return "YES";
	else return "NO";
}

char* checkNegativity(int n) {
	// Using bitwise operations to determine the sign of the number
	int sign = (n >> 31) | ((-n) >> 31);
	const char* signs[] = {"NEGATIVE", "ZERO", "POSITIVE"};
	return signs[sign + 1];
}

int main() {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("Validity check result: %s\n", checkValidity(num));
	printf("Negativity check result: %s\n", checkNegativity(num));
	return 0;
}
