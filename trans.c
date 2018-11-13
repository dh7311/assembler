#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		strcpy(mcode,"error");
		return 0;
	}
	char *ptr1, *ptr2 = NULL;
	if(strcmp(op,"mov")!=0)
	 	return 0;
	ptr1 = strtok(args,",");
	ptr2 = strtok(NULL,"\n");

	if(prtr1[0] == '%'){
	 	if(ptr2[0] == '%'){
	 		strcpy(mcode,"89");
		}
		if(ptr2[0] == '0'){
            strcpy(mcode,"a3");
        }
	}
	else if(ptr1[0] == '(' || ptr1[0] == '-') {
	 	if(ptr2[0] == '%') {
		 	strcpy(mcode,"8b");
		}
	}
	else if(ptr1[0] == '0') {
	 	if(ptr2[0] == '%') {
		 	strcpy(mcode,"a1");
		}
	}
	else if(ptr1[0] == '$' && ptr2[0] =='%') {
	 	if(ptr2[2] == 'a') {
		 	strcpy(mcode,"b8");
		}
		else if(ptr2[2] == 'b') {
		 	if(ptr2[3] == 'x') {
			 	strcpy(mcode,"bb");
			}
			else if(ptr2[3] == 'p') {
			 	strcpy(mcode,"bd");
			}
		}
		else if(ptr2[2] == 'c') {
		 	strcpy(mcode,"b9");
		}
		else if(ptr2[2] == 'd') {
		 	if(ptr2[3] == 'x') {
			 	strcpy(mcode,"ba");
			}
			else if(ptr2[3] == 'i') {
			 	strcpy(mcode,"bf");
			}
		}
		else if(ptr2[2] == 's') {
		 	strcpy(mcode,"bc");
		}
	}
	return 1;	
}
