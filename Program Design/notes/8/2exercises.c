/*selection_sort.c, project 5, Program Design
 */

#include <stdio.h>
#define N 100

void selection_sort(int a[], int n);

int main(){
	int i=0, j;
	int a[N];

	FILE *fp = fopen("numbers.txt", "r");
	if(fp==NULL){
		printf("Error opening file\n");
		return 1;
	}
	while(!feof(fp) && !ferror(fp)){
		if(fscanf(fp, "%d", &a[i])==1){
			printf("%d\n", a[i]);
			i++;}
	}
	FILE *fw = fopen("sorted_numbers.txt", "w");	
	
	selection_sort(a, i);

	for (j=0; j<i; j++){
		fprintf(fw, "%d\n", a[j]);
	}
	fclose(fp);
	fclose(fw);

	return 0;
}

void selection_sort(int a[], int n)
{
  int i, largest = 0, temp;

  if (n == 1)
    return;

  for (i = 1; i < n; i++)
    if (a[i] > a[largest])
      largest = i;

  if (largest < n - 1) {
    temp = a[n-1];
    a[n-1] = a[largest];
    a[largest] = temp;
  }

  selection_sort(a, n - 1);
}
