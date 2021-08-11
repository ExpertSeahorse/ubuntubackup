#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "request.h"
#include "readline.h"

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



struct request *append_to_list(struct request *list){
        // Initializes the list or adds a new student to the end and returns the list
        // ########## GENERATING THE NODE ##########
        struct request *n_req, *p, *prev;          //"new request"
        n_req = malloc(sizeof(struct request));

        // Gathers input
        printf("Enter the classroom: ");
        scanf("%s", n_req->classroom);
        printf("Enter the first name: ");
        scanf("%s", n_req->first);
        printf("Enter the last name: ");
        scanf("%s", n_req->last);
        
	// Searches the list for a duplicate entry
        for (p = list; p != NULL; p = p->next)
                if (!strcmp(p->classroom, n_req->classroom) && !strcmp(p->first, n_req->first) && !strcmp(p->last, n_req->last)){
                        printf("Please use the update function to update the classroom");
                        return list;
                }
        // Gathers more input
        printf("Enter the phone number: ");
        scanf("%s", n_req->phone);

	// ########## PLACING THE NODE IN THE LIST ##########

        // If this is the first entry, the whole list is this first node
        if(list == NULL){
		n_req->next = NULL;
                return n_req;
	}
	int flag=0;
	// If new classroom is before the first entry:
	if (strcmp(n_req->classroom, list->classroom) < 0)
		flag = 1;
	// If the classrooms are the same...
	if (strcmp(n_req->classroom, list->classroom) == 0){
		// But the new last name comes before the existing last name:
		if (strcmp(n_req->last, list->last) < 0)
			flag = 1;
		// But the last names are the same...
		if (strcmp(n_req->last, list->last) == 0){
			// And the new first name comes before the existing first name:
			if(strcmp(n_req->first, list->first) < 0)
				flag = 1;
		}
	}
	if(flag){
		n_req->next = list;
		return n_req;
	}
        // Finds the location of where the entry should go
        for (p=list, prev=NULL; p!=NULL; prev=p, p=p->next){
		// if the new classroom is before the current classroom:
		if(strcmp(n_req->classroom, p->classroom) < 0){
			flag = 1;  break;
		}

		// if the new classroom is the same as the existing classroom...
		if(strcmp(n_req->classroom, p->classroom) == 0){
			// and the new last name is before the existing last name:
			if (strcmp(n_req->last, p->last) < 0){
				flag = 1;  break;
			}
			// and the new last name is the same as the existing last name...
			if (strcmp(n_req->last, p->last) == 0){
				// and the new first name is before the existing first name:
				if (strcmp(n_req->first, p->first) < 0){
					flag = 1;  break;
				}
			}
		}
	}
	if(flag){
		n_req->next = prev->next;
		prev->next = n_req;
		return list;
	}
		
	// if the classroom belongs at the end of the list:
	prev->next = n_req;
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


struct request* delete_from_list(struct request *list){
	// looks through list for a student matching the description given and removes them from the list
	struct request *target, *p, *prev=NULL;
	target = malloc(sizeof(struct request));
	if(target== NULL)
	{
        	printf("malloc failed");
		return list;
	}

	printf("Enter the child's classroom: ");
        scanf("%s", target->classroom);
        printf("Enter the first name: ");
        scanf("%s", target->first);
        printf("Enter the last name: ");
        scanf("%s", target->last);

	for(p=list; p!=NULL; p=p->next){
		if (!strcmp(p->classroom, target->classroom) && !strcmp(p->first, target->first) && !strcmp(p->last, target->last)){
			if (!prev)
				list = list->next;
			else
				prev->next = p->next;

			printf("%s %s has been deleted", p->first, p->last);
			free(p);
			free(target);
			return list;
		}
		prev = p;
	}
	printf("Student not found");
	return list;
}
