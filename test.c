#include <stdio.h>

int	main(void)
{
	printf("STRING:\n\n");
	printf("%20sworld\n", "HELLO"); // Output: "               HELLOworld"
	printf("%-10sworld\n", "HELLO"); // Output: "HELLO     world"
	printf("%.4sworld\n", "HELLO"); // Output: "HELLworld"
	printf("%.sworld\n", "HELLO"); // Output: "world"
	printf("%20-10sworld\n", "HELLO"); // Output: "HELLO     world"
	printf("%20.-10sworld\n", "HELLO"); // Output: "         world"
	printf("%020sworld\n", "HELLO"); // Output: "000000000000000HELLOworld"
	printf("%-010sworld\n", "HELLO"); // Output: "HELLO     world"
	printf("%020-010sworld\n\n\n", "HELLO"); // Output: "HELLO     world"
//NOW WITH DIGITS
	printf("DIGIT:\n\n");
	printf("%20dworld\n", 123); // Output: "                 123world"
	printf("%-10dworld\n", 123); // Output: "123       world"
	printf("%.4dworld\n", 123); // Output: "0123world"
	printf("%.dworld\n", 123); // Output: "123world"
	printf("%20-10dworld\n", 123); // Output: "123       world"
	printf("%20.-10dworld\n", 123); // Output: "123       world"
	printf("%020dworld\n", 123); // Output: "00000000000000000123world"
	printf("%-010dworld\n", 123); // Output: "123       world"
	printf("%020-010dworld\n\n\n", 123); // Output: "123       world"
	return (0);
}
