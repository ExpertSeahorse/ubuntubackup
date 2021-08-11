#include <stdio.h>


int main(int argc, char *argv[]){
	char color[31];
	int weight, count, tot_ct=0;
	
	if(argc == 2){
		FILE *fp = fopen(argv[1], "r");
		if (fp == NULL){
			printf("Error opening file.\n");
			return 1;
		}
		
		while(!feof(fp) && !ferror(fp)){		//feof- end of file; ferror- returns nonzero if error
			if(fscanf(fp, "%d%s%d", &weight, color, &count)==3){
				printf("%d\t%s\t%d\n", weight, color, count);
				tot_ct += count;
			}
		}
	}
	printf("There are %d dumbells\n", tot_ct);
	return 0;
}
