#include <stdio.h>
#include <stdlib.h>


struct product{
	// Establishes the structure for the different products.
	// name: name of the product
	// price: price of the product
	// qty: quantity of the product
	char name[101];
	double price, qty;
};


int sort_products(const void *j, const void *k){
	// Sorts the list of products for qsort
	const struct product *p = j;
	const struct product *q = k;
	return (p->qty > q->qty) - (q->qty > p->qty);
}


int main(){
	// Read the input file
	int i=0, j;
	struct product list[100];
	FILE *fin = fopen("fruits_vegetables.txt", "r"), *fout = fopen("top5.txt", "w");
	if(fin == NULL){
		printf("Error opening products list.");
		return 1;
	}
	while(!feof(fin) && !ferror(fin)){
		if(fscanf(fin, "%s %lf %lf", list[i].name, &list[i].price, &list[i].qty)==3)
			i++;
	}

	// Sort the list
	qsort(list, i, sizeof(struct product), sort_products);

	//write to the output file
	for(j=i-1; j > i-6; j--)
		fprintf(fout, "%s    \t%.2lf   \t%.2lf\n", list[j].name, list[j].price, list[j].qty);
	fclose(fin);
	fclose(fout);

	return 0;
}
