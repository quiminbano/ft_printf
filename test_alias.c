#include <stdio.h>
#include "ft_printf_bonus.h"

int	main(void)
{
	int	test = 123;

	printf("STRING:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20sworld\n", "HELLO"), ft_printf("%20sworld\n", "HELLO")); // Output printf: "               HELLOworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%-10sworld\n", "HELLO"), ft_printf("%-10sworld\n", "HELLO")); // Output printf: "HELLO     world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%.4sworld\n", "HELLO"), ft_printf("%.4sworld\n", "HELLO")); // Output printf: "HELLworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%.sworld\n", "HELLO"), ft_printf("%.sworld\n", "HELLO")); // Output printf: "world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20-10sworld\n", "HELLO"), ft_printf("%20-10sworld\n", "HELLO")); // Output printf: "HELLO     world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20.-10sworld\n", "HELLO"), ft_printf("%20.-10sworld\n", "HELLO")); // Output printf: "         world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%020sworld\n", "HELLO"), ft_printf("%020sworld\n", "HELLO")); // Output printf: "000000000000000HELLOworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%-010sworld\n", "HELLO"), ft_printf("%-010sworld\n", "HELLO")); // Output printf: "HELLO     world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%020-010sworld\n", "HELLO"), ft_printf("%020-010sworld\n", "HELLO")); // Output printf: "HELLO     world"
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%-.-.-10sworld\n", "HELLO"), ft_printf("%-.-.-10sworld\n", "HELLO")); // Output printf: "          world"
//NOW WITH DIGITS
	printf("DIGIT:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20dworld\n", 123), ft_printf("%20dworld\n", 123)); // Output: "                 123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%-10dworld\n", 123), ft_printf("%-10dworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%.4dworld\n", 123), ft_printf("%.4dworld\n", 123)); // Output: "0123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%.dworld\n", 123), ft_printf("%.dworld\n", 123)); // Output: "123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20-10dworld\n", 123), ft_printf("%20-10dworld\n",123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20.-10dworld\n", 123), ft_printf("%20.-10dworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%020dworld\n", 123), ft_printf("%020dworld\n", 123)); // Output: "00000000000000000123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%-010dworld\n", 123), ft_printf("%-010dworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%020-010dworld\n", 123), ft_printf("%020-010dworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%-.-.-10dworld\n", 123), ft_printf("%-.-.-10dworld\n", 123)); // Output: "123       world"
//NOW WITH UNSIGNED DIGITS
	printf("UNSIGNED DIGIT:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20uworld\n", 123), ft_printf("%20uworld\n", 123)); // Output: "                 123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%-10uworld\n", 123), ft_printf("%-10uworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%.4uworld\n", 123), ft_printf("%.4uworld\n", 123)); // Output: "0123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%.uworld\n", 123), ft_printf("%.uworld\n", 123)); // Output: "123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20-10uworld\n", 123), ft_printf("%20-10uworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20.-10uworld\n", 123), ft_printf("%20.-10uworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%020uworld\n", 123), ft_printf("%020uworld\n", 123)); // Output: "00000000000000000123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%-010uworld\n", 123), ft_printf("%-010uworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%020-010uworld\n", 123), ft_printf("%020-010uworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%-.-.-10uworld\n", 123), ft_printf("%-.-.-10uworld\n", 123)); // Output: "123       world"
//NOW WITH HEXA x
	printf("HEXA x:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20xworld\n", 123), ft_printf("%20xworld\n", 123)); // Output: "                  7bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%-10xworld\n", 123), ft_printf("%-10xworld\n", 123)); // Output: "7b        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%.4xworld\n", 123), ft_printf("%.4xworld\n", 123)); // Output: "007bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%.xworld\n", 123), ft_printf("%.xworld\n", 123)); // Output: "7bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20-10xworld\n", 123), ft_printf("%20-10xworld\n", 123)); // Output: "7b        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20.-10xworld\n", 123), ft_printf("%20.-10xworld\n", 123)); // Output: "7b        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%020xworld\n", 123), ft_printf("%020xworld\n", 123)); // Output: "0000000000000000007bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%-010xworld\n", 123), ft_printf("%-010xworld\n", 123)); // Output: "7b        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%020-010xworld\n", 123), ft_printf("%020-010xworld\n", 123)); // Output: "7b        world"
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%-.-.-10xworld\n", 123), ft_printf("%-.-.-10xworld\n", 123)); // Output: "7b        world"
//NOW WITH HEXA X
	printf("HEXA X:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20Xworld\n", 123), ft_printf("%20Xworld\n", 123)); // Output: "                  7Bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%-10Xworld\n", 123), ft_printf("%-10Xworld\n", 123)); // Output: "7B        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%.4Xworld\n", 123), ft_printf("%.4Xworld\n", 123)); // Output: "007Bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%.Xworld\n", 123), ft_printf("%.Xworld\n", 123)); // Output: "7Bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20-10Xworld\n", 123), ft_printf("%20-10Xworld\n", 123)); // Output: "7B        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20.-10Xworld\n", 123), ft_printf("%20.-10Xworld\n", 123)); // Output: "7B        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%020Xworld\n", 123), ft_printf("%020Xworld\n", 123)); // Output: "0000000000000000007Bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%-010Xworld\n", 123), ft_printf("%-010Xworld\n", 123)); // Output: "7B        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%020-010Xworld\n", 123), ft_printf("%020-010Xworld\n", 123)); // Output: "7B        world"
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%-.-.-10Xworld\n", 123), ft_printf("%-.-.-10Xworld\n", 123)); // Output: "7B        world"
//NOW WITH POINTERS
	printf("POINTERS:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20pworld\n", &test), ft_printf("%20pworld\n", &test)); // Output: "      0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%-10pworld\n", &test), ft_printf("%-10pworld\n", &test)); // Output: "0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%.4pworld\n", &test), ft_printf("%.4pworld\n", &test)); // Output: "0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%.pworld\n", &test), ft_printf("%.pworld\n", &test)); // Output: "0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20-10pworld\n", &test), ft_printf("%20-10pworld\n", &test)); // Output: "0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20.-10pworld\n", &test), ft_printf("%20.-10pworld\n", &test)); // Output: "0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%020pworld\n", &test), ft_printf("%020pworld\n", &test)); // Output: "0x0000007ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%-010pworld\n", &test), ft_printf("%-010pworld\n", &test)); // Output: "0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%020-010pworld\n", &test), ft_printf("%020-010pworld\n", &test)); // Output: "0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%-.-.-10pworld\n", &test), ft_printf("%-.-.-10pworld\n", &test)); // Output: "0x7ffee80bc708world"
//NOW WITH CHARS
	printf("CHARS:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20cworld\n", 'c'), ft_printf("%20cworld\n", 'c')); // Output: "                   cworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%-10cworld\n", 'c'), ft_printf("%-10cworld\n", 'c')); // Output: "c         world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%.4cworld\n", 'c'), ft_printf("%.4cworld\n", 'c')); // Output: "cworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%.cworld\n", 'c'), ft_printf("%.cworld\n", 'c')); // Output: "cworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20-10cworld\n", 'c'), ft_printf("%20-10cworld\n", 'c')); // Output: "c         world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%20.-10cworld\n", 'c'), ft_printf("%20.-10cworld\n", 'c')); // Output: "c         world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%020cworld\n", 'c'), ft_printf("%020cworld\n", 'c')); // Output: "0000000000000000000cworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%-010cworld\n", 'c'), ft_printf("%-010cworld\n", 'c')); // Output: "c         world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%020-010cworld\n", 'c'), ft_printf("%020-010cworld\n", 'c')); // Output: "c         world"
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%-.-.-10cworld\n", 'c'), ft_printf("%-.-.-10cworld\n", 'c')); // Output: "c         world"
//NOW WITH OTHER FLAGS
	printf("NOW TESTING #+ :\n\n\n");
	printf("STRING:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20sworld\n", "HELLO"), ft_printf("%# +20sworld\n", "HELLO")); // Output: "               HELLOworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +-10sworld\n", "HELLO"), ft_printf("%# +-10sworld\n", "HELLO")); // Output: "HELLO     world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +.4sworld\n", "HELLO"), ft_printf("%# +.4sworld\n", "HELLO")); // Output: "HELLworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +.sworld\n", "HELLO"), ft_printf("%# +.sworld\n", "HELLO")); // Output: "world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20-10sworld\n", "HELLO"), ft_printf("%# +20-10sworld\n", "HELLO")); // Output: "HELLO     world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20.-10sworld\n", "HELLO"), ft_printf("%# +20.-10sworld\n", "HELLO")); // Output: "         world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +020sworld\n", "HELLO"), ft_printf("%# +020sworld\n", "HELLO")); // Output: "000000000000000HELLOworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +-010sworld\n", "HELLO"), ft_printf("%# +-010sworld\n", "HELLO")); // Output: "HELLO     world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +020-010sworld\n", "HELLO"), ft_printf("%# +020-010sworld\n", "HELLO")); // Output: "HELLO     world"
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%# +-.-.-10sworld\n", "HELLO"), ft_printf("%# +-.-.-10sworld\n", "HELLO")); // Output: "          world"
//NOW WITH DIGITS
	printf("DIGIT:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20dworld\n", 123), ft_printf("%# +20dworld\n", 123)); // Output: "                 123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +-10dworld\n", 123), ft_printf("%# +-10dworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +.4dworld\n", 123), ft_printf("%# +.4dworld\n", 123)); // Output: "0123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +.dworld\n", 123), ft_printf("%# +.dworld\n", 123)); // Output: "123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20-10dworld\n", 123), ft_printf("%# +20-10dworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20.-10dworld\n", 123), ft_printf("%# +20.-10dworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +020dworld\n", 123), ft_printf("%# +020dworld\n", 123)); // Output: "00000000000000000123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +-010dworld\n", 123), ft_printf("%# +-010dworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +020-010dworld\n", 123), ft_printf("%# +020-010dworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%# +-.-.-10dworld\n", 123), ft_printf("%# +-.-.-10dworld\n", 123)); // Output: "123       world"
//NOW WITH UNSIGNED DIGITS
	printf("UNSIGNED DIGIT:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20uworld\n", 123), ft_printf("%# +20uworld\n", 123)); // Output: "                 123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +-10uworld\n", 123), ft_printf("%# +-10uworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +.4uworld\n", 123), ft_printf("%# +.4uworld\n", 123)); // Output: "0123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +.uworld\n", 123), ft_printf("%# +.uworld\n", 123)); // Output: "123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20-10uworld\n", 123), ft_printf("%# +20-10uworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20.-10uworld\n", 123), ft_printf("%# +20.-10uworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +020uworld\n", 123), ft_printf("%# +020uworld\n", 123)); // Output: "00000000000000000123world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +-010uworld\n", 123), ft_printf("%# +-010uworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +020-010uworld\n", 123), ft_printf("%# +020-010uworld\n", 123)); // Output: "123       world"
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%# +-.-.-10uworld\n", 123), ft_printf("%# +-.-.-10uworld\n", 123)); // Output: "123       world"
//NOW WITH HEXA x
	printf("HEXA x:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20xworld\n", 123), ft_printf("%# +20xworld\n", 123)); // Output: "                  7bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +-10xworld\n", 123), ft_printf("%# +-10xworld\n", 123)); // Output: "7b        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +.4xworld\n", 123), ft_printf("%# +.4xworld\n", 123)); // Output: "007bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +.xworld\n", 123), ft_printf("%# +.xworld\n", 123)); // Output: "7bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20-10xworld\n", 123), ft_printf("%# +20-10xworld\n", 123)); // Output: "7b        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20.-10xworld\n", 123), ft_printf("%# +20.-10xworld\n", 123)); // Output: "7b        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +020xworld\n", 123), ft_printf("%# +020xworld\n", 123)); // Output: "0000000000000000007bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +-010xworld\n", 123), ft_printf("%# +-010xworld\n", 123)); // Output: "7b        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +020-010xworld\n", 123), ft_printf("%# +020-010xworld\n", 123)); // Output: "7b        world"
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%# +-.-.-10xworld\n", 123), ft_printf("%# +-.-.-10xworld\n", 123)); // Output: "7b        world"
//NOW WITH HEXA X
	printf("HEXA X:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20Xworld\n", 123), ft_printf("%# +20Xworld\n", 123)); // Output: "                  7Bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +-10Xworld\n", 123), ft_printf("%# +-10Xworld\n", 123)); // Output: "7B        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +.4Xworld\n", 123), ft_printf("%# +.4Xworld\n", 123)); // Output: "007Bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +.Xworld\n", 123), ft_printf("%# +.Xworld\n", 123)); // Output: "7Bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20-10Xworld\n", 123), ft_printf("%# +20-10Xworld\n", 123)); // Output: "7B        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20.-10Xworld\n", 123), ft_printf("%# +20.-10Xworld\n", 123)); // Output: "7B        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +020Xworld\n", 123), ft_printf("%# +020Xworld\n", 123)); // Output: "0000000000000000007Bworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +-010Xworld\n", 123), ft_printf("%# +-010Xworld\n", 123)); // Output: "7B        world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +020-010Xworld\n", 123), ft_printf("%# +020-010Xworld\n", 123)); // Output: "7B        world"
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%# +-.-.-10Xworld\n", 123), ft_printf("%# +-.-.-10Xworld\n", 123)); // Output: "7B        world"
//NOW WITH POINTERS
	printf("POINTERS:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20pworld\n", &test), ft_printf("%# +20pworld\n", &test)); // Output: "      0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +-10pworld\n", &test), ft_printf("%# +-10pworld\n", &test)); // Output: "0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +.4pworld\n", &test), ft_printf("%# +.4pworld\n", &test)); // Output: "0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +.pworld\n", &test), ft_printf("%# +.pworld\n", &test)); // Output: "0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20-10pworld\n", &test), ft_printf("%# +20-10pworld\n", &test)); // Output: "0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20.-10pworld\n", &test), ft_printf("%# +20.-10pworld\n", &test)); // Output: "0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +020pworld\n", &test), ft_printf("%# +020pworld\n", &test)); // Output: "0x0000007ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +-010pworld\n", &test), ft_printf("%# +-010pworld\n", &test)); // Output: "0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +020-010pworld\n", &test), ft_printf("%# +020-010pworld\n", &test)); // Output: "0x7ffee80bc708world"
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%# +-.-.-10pworld\n", &test), ft_printf("%# +-.-.-10pworld\n", &test)); // Output: "0x7ffee80bc708world"
// NOW WITH CHAR
	printf("CHARS:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%cworld\n", 'c'), ft_printf("%cworld\n", 'c')); // Output: "                   cworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20cworld\n", 'c'), ft_printf("%# +20cworld\n", 'c')); // Output: "                   cworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +-10cworld\n", 'c'), ft_printf("%# +-10cworld\n", 'c')); // Output: "c         world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +.4cworld\n", 'c'), ft_printf("%# +.4cworld\n", 'c')); // Output: "cworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +.cworld\n", 'c'), ft_printf("%# +.cworld\n", 'c')); // Output: "cworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20-10cworld\n", 'c'), ft_printf("%# +20-10cworld\n", 'c')); // Output: "c         world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +20.-10cworld\n", 'c'), ft_printf("%# +20.-10cworld\n", 'c')); // Output: "c         world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +020cworld\n", 'c'), ft_printf("%# +020cworld\n", 'c')); // Output: "0000000000000000000cworld"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +-010cworld\n", 'c'), ft_printf("%# +-010cworld\n", 'c')); // Output: "c         world"
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%# +020-010cworld\n", 'c'), ft_printf("%# +020-010cworld\n", 'c')); // Output: "c         world"
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%# +-.-.-10cworld\n", 'c'), ft_printf("%# +-.-.-10cworld\n", 'c')); // Output: "c         world"
	//EXTRA TESTS
	printf("EXTRA TESTS:\n\n");
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%08.4s\n", "HELLOOOO"), ft_printf("%08.4s\n", "HELLOOOO"));
	printf("return printf: %d. return ft_printf: %d\n\n", printf("%08.4u\n", 2), ft_printf("%08.4u\n", 2));
	printf("return printf: %d. return ft_printf: %d\n\n\n", printf("%*.**dworld\n", -1, -1, 5, 0), ft_printf("%*.**dworld\n", -1, -1, 5, 0));
	return (0);
}
