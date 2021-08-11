#include <stdio.h>
#include <ctype.h>
#include <string.h>
// Reads the user's input and unpacks ranges, ex. "[a-d]" -> "abcd"
// David Feldman

int read_line(char *str, int n){
// Reads string input from user as provided
// str -> output string
// n -> expected size of the string
// return i -> number of characters stored
        int i=0, ch;
        while ((ch=getchar()) != '\n')
                if(i < n){
                        *str++= ch;
                        i++;
                }
        *str = '\0';            // terminates string
        return i;               //num char stored
}


int replace(char *s1, char *s2){
// Finds where a range is in the string and replaces it with the values the range describes
// s1 -> input string
// s2 -> output string
// return: 1 if there was a range, 0 if not

	char *p, start='\0', end='\0';
	int ran_flag=0, wrk_flag=0;	// ran_flag: If logic ran; wrk_flag: If running logic
	for (p=s1; *p != '\0'; p++){
		// Fills the new string with the values from the range
		if (wrk_flag){
			if (!start)
				start = *p;
			else if (start && *p != '-' && *p != ']')
                                end = *p;
                        else if (*p == ']'){
				wrk_flag=0;
                                int len = end - start, i;
				for (i=0; i<=len; i++)
					*s2++ = start + i;
			}
		}
		// Starts the above chunk of code to unpack the range
		else if (*p == '['){
                        ran_flag=1;
                        wrk_flag=1;
                }
		// Adds the normal characters into the new string
                else{
                	*s2++ = *p;
		}
        }
	// Terminates the new string
	*s2= '\0'; 
	
	// Sets the function's output based on if a range was replaced
	if (ran_flag)
                return 1;
        else
                return 0;
}




int main(){
// Reads input and prints output
        int num_chars, n=100, ran;
        char str[n+1];

        printf("Enter a sentence:\n");
        num_chars = read_line(str, n);

	char str2[n];
	
	ran = replace(str, str2);
	
	if (ran)
		printf("Output: %s", str2);
	else
		printf("There is no range in the input");
	
 	printf("\n");
	return 0;
}	
