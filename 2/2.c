#include <stdio.h>

int main(void)
{
	char str1[256], str2[256];
	int i, j, f;

	puts("input string 1");
	scanf("%s", str1);

	puts("input string 2");
	scanf("%s", str2);
	
	for (i=0; str1[i] != '\0'; i++) {
		f = 1;
		for (j=0; str2[j] != '\0'; j++) {
			if (str1[i] == str2[j]) {
				f = 0;
				break;
			}
		}
		if (f) {
			printf("%c", str1[i]);
		}
	}

	puts("");

	return 0;
}
