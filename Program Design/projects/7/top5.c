#include <stdio.h>


struct product{
	// Establishes the structure for the different products.
	// name: name of the product
	// price: price of the product
	// qty: quantity of the product
	char name[101];
	double price, qty;
};


void sort_products(struct product list[], int n){
	// Modified from selection sort to sort the list of object
	// list: a list of the prouducts created in main
	// n: the real number of objects in the list
	int i, largest = 0;
	struct product temp;

	if (n == 1)
		return;

	for (i = 1; i < n; i++)
		if (list[i].qty > list[largest].qty)
			largest = i;

	if (largest < n - 1) {
		temp = list[n-1];
		list[n-1] = list[largest];
		list[largest] = temp;
	}

	sort_products(list, n - 1);
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
		if(fscanf(fin, "%s %lf %lf", list[i].name, &list[i].price, &list[i].qty)==3){
			i++;
		}
	}
	
	// Sort the database
	sort_products(list, i);

	//write to the output file
	for(j=i-1; j > i-6; j--)
		fprintf(fout, "%s    \t%.2lf   \t%.2lf\n", list[j].name, list[j].price, list[j].qty);

	fclose(fin);
	fclose(fout);

	return 0;
}
