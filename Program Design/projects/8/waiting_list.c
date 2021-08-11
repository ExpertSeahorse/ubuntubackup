#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ROOM_LEN 100
#define NAME_LEN 30
#define PHONE_LEN 15

struct request{
	char classroom[ROOM_LEN];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char phone[PHONE_LEN+1];;

	struct request *next;
};


struct request *append_to_list(struct request *list);
void update(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct request *wait_list = NULL;  
  printf("Operation Code: a for appending to the list, u for updating a book"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': wait_list = append_to_list(wait_list);
                break;
      case 'u': update(wait_list);
                break;
      case 'p': printList(wait_list);
                break;
      case 'q': clearList(wait_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

struct request *append_to_list(struct request *list){
	// Initializes the list or adds a new student to the end and returns the list
	struct request *n_req;		//"new request"
	struct request *p;
	n_req = malloc(sizeof(struct request));
	
	// Gathers input
	printf("Enter the classroom: ");
	scanf("%s", n_req->classroom);
	printf("Enter the first name: ");
	scanf("%s", n_req->first);
	printf("Enter the last name: ");
	scanf("%s", n_req->last);
	// Because this is going at the end, nxet=NULL to terminate
	n_req->next = NULL;
	
 	// Searches the list for a duplicate entry
	for (p = list; p != NULL; p = p->next)
		if (!strcmp(p->classroom, n_req->classroom) && !strcmp(p->first, n_req->first) && !strcmp(p->last, n_req->last)){
			printf("Please use the update function to update the classroom");
			return list; 
		}
	// Gathers more input
	printf("Enter the phone number: ");
	scanf("%s", n_req->phone);

	// If this is the first entry, the whole list is this first node
	if(list == NULL)
		return n_req;

	// Appends the node to the end of the list
	p = list;
	while (p->next != NULL) 
	        p = p->next; 
	p->next = n_req; 
	return list;
}


void update(struct request *list){
	// Changes the classroom of a student
	struct request *node;
        struct request *p;
	node = malloc(sizeof(struct request));

	//Gathers input
	printf("Enter the current classroom: ");
        scanf("%s", node->classroom);
        printf("Enter the first name: ");
        scanf("%s", node->first);
        printf("Enter the last name: ");
        scanf("%s", node->last);

	// Searches the list for an entry that matches the inputs and changes the classroom
	for (p = list; p != NULL; p = p->next)
		if (!strcmp(p->classroom, node->classroom) && !strcmp(p->first, node->first) && !strcmp(p->last, node->last)){
                        printf("Enter the new classroom: ");
                        scanf("%s", p->classroom);
			return;
                }
	printf("Student not found, please use append to add a new one or check the spelling.");
}


void printList(struct request *list){
	// Prints every element in the list
	struct request *p;
	//Structure
	printf("Classroom\tFirst Name\tLast Name\tPhone Number\n");
	//Reads through the list and prints out every node
	for (p = list; p != NULL; p = p->next)
		printf("%s\t%s\t%s\t%s\n", p->classroom, p->first, p->last, p->phone);
}


void clearList(struct request *list){
	// Frees the entire list
	struct request *p;
	while(list != NULL){
		p = list;
		list = list->next;
		if( p!= NULL)
			free(p);
	}
	printf("List cleared, have a nice day.\n");
}


int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}
