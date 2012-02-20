#include <stdio.h>

struct person {
	char name[256];
	int  score;
};

int main(int argc, char *argv[]) {
	int n, i, j;
	FILE *fp;
	struct person p[128];
	struct person tmp;

	if (argc != 2) {
		printf("missing file argument\n");
		return 1;
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		printf("can't open %s\n", argv[1]);
		return 1;
	}


	for (i=0; fscanf(fp, "%s\t\t%d", p[i].name, &p[i].score) != EOF; i++)
	
	n = i;
	
	fclose(fp);

	for (i=0; i<n; i++) {
		for (j=n; j>i; j--) {
			if (p[j-1].score > p[j].score) {
				tmp    = p[j];
				p[j]   = p[j-1];
				p[j-1] = tmp;
			}
		}
	}
	
	for (i=0; i<n; i++) {
		printf("%s\t%d\n", p[i].name, p[i].score);
	}	

	return 0;
}
