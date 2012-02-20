#include <stdio.h>

int main(void)
{
	char str[256];
	int i, f;
	int len;

	puts("input string");
	scanf("%s", str);

	len = printf("%s", str);
	puts("");

	f = 1;
	for (i=0; i<len; i++) {
		if (str[i] != str[len-i-1]) {
			f = 0;
		}
	}

	if (f) {
		puts("kaibun");
	} else {
		puts("not kaibun");
	}

	return 0;
}
