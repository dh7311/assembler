#include "myas.h"

int is_valid(char *op, char *args)
{
 	char *ptr1, *ptr2 = NULL;
	if(strcmp(op,"mov") != 0 )
	 	return 0;
	char temp[256] = {0};
	strcpy(temp,args);
	ptr1 = strtok(temp,",");
	ptr2 = strtok(NULL,"\n");

	if(ptr1[0] == '(' || ptr1[0] == '-' || ptr1[0] == '0')
	{
	 	if(ptr2[0] =='(' || ptr2[0] =='-' || ptr2[0] =='0')
		 	return 0;
	}
	else if(ptr1[0] == '$' && ptr2[0] == '$')
	 	return 0;
	else if(ptr2[0] == '$')
	 	return 0;

	return 1;
}
