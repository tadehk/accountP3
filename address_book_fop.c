#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctype.h>

#include "address_book.h"

Status load_file(AddressBook *address_book)
{
	int ret;
	FILE* fp = fopen(DEFAULT_FILE, "r");
	if (ret == 0)
	{
		
		if (fp == NULL)
		{
			printf("Failed to open file!%s\n", DEFAULT_FILE);
			return;
		}
	}
	else
	{
		while (!feof(fp))
    	{	
        	if (addr_book->size >= addr_book->capacity)
        	{
            	ContactInfo* new_list = (ContactInfo*)malloc(sizeof(PersonInfo)*address_book->capacity);
				size_t i = 0;
				for (; i < address_book->count; ++i)
				{
					new_list[i] = address_book->list[i];             
				}
				free(address_book->list);        
				address_book->list = new_list;
			}
			size_t cur = address_book->count;
			fscanf(fp, "%s%s%s\n",
				address_book->list[cur].name,
				address_book->list[cur].phone_numbers,
				address_book->list[cur].email_addresses);
			++address_book->count;
		}
	

	return e_success;
}

Status save_file(AddressBook *address_book)
{
	
	address_book->fp = fopen(DEFAULT_FILE, "w");

	if (address_book->fp == NULL)
	{
		return e_fail;
	}
	size_t i = 0;
    for (; i < address_book->count; ++i)
    {
		fprintf(fp, "%s%s%s\n",
				address_book->list[i].name,
				address_book->list[i].phone_numbers,
				address_book->list[i].email_addresses);
	}

	

	fclose(address_book->fp);

	return e_success;
}
