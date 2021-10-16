#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "abk_fileops.h"
#include "abk_log.h"
#include "abk_menus.h"
#include "abk.h"


int get_option(int type, const char *msg)
{
	/*
	 * Mutilfuction user intractions like
	 * Just an enter key detection
	 * Read an number
	 * Read a charcter
	 */ 

	printf(msg);
	if(type=="NUM"){
		int opt;
		scanf("%d", opt);
		switch(opt)
		{
			case 1:
				return e_add_contact;
				break;
			case 2:
				return e_search_contact;
				break;
			case 3:
				return e_edit_contact;
				break;
			case 4:
				return e_delete_contact;
				break;
			case 5:
				return e_list_contacts;
				break;
			case 6:
				return e_save;
				break;
			case 0:
				return e_exit;
				break;
		}
	}
	if(type=="CHAR"){
		char opt;
		scanf("%s", &opt);
		switch(opt)
		{
			case 'Y':
				return 'Y';
				break;
			case 'N':
				return 'N';
				break;
			default:
				printf("Invalid Response\n");
				break;
		}
	}
	/* Fill the code to add above functionality */
}

Status save_prompt(AddressBook *address_book)
{
	char option;

	do
	{
		main_menu();

		option = get_option(CHAR, "\rEnter 'N' to Ignore and 'Y' to Save: ");

		if (option == 'Y')
		{
			save_file(address_book);
			printf("Exiting. Data saved in %s\n", DEFAULT_FILE);

			break;
		}
	} while (option != 'N');

	free(address_book->list);

	return e_success;
}

Status list_contacts(AddressBook *address_book, const char *title, int *index, const char *msg, Modes mode)
{
	/* 
	 * Add code to list all the contacts availabe in address_book.csv file
	 * Should be menu based
	 * The menu provide navigation option if the entries increase the page size
	 */ 
	/*if(address_book == NULL)
	{
		printf("There are no names in the address book.");
		return;
	}*/
	for(; i < *address_book -1; i++)
	{
		printf("\nPhone Book Entries (%d):", *address_book);
		printf("\n%s\t%s\t%s", address_book->list->contactInfo->name[i],address_book->list->contactInfo->phone_numbers[i], address_book->list->contactInfo->email_addresses[i]);
	}
	
	return e_success;
}

void menu_header(const char *str)
{
	fflush(stdout);

	system("clear");

	printf("#######  Address Book  #######\n");
	if (str != '\0')
	{
		printf("#######  %s\n", str);
	}
}

void main_menu(void)
{
	menu_header("Features:\n");

	printf("0. Exit\n");
	printf("1. Add Contact\n");
	printf("2. Search Contact\n");
	printf("3. Edit Contact\n");
	printf("4. Delete Contact\n");
	printf("5. List Contacts\n");
	printf("6. Save\n");
	printf("\n");
	printf("Please select an option: ");
}

Status menu(AddressBook *address_book)
{
	ContactInfo backup;
	Status ret;
	int option;

	do
	{
		main_menu();

		option = get_option(NUM, "");

		if ((address_book-> count == 0) && (option != e_add_contact))
		{
			get_option(NONE, "No entries found!!. Would you like to add? Use Add Contacts");

			continue;
		}

		switch (option)
		{
			case e_add_contact:
				/* Add your implementation to call add_contacts function here */
				add_contacts(address_book);
				break;
			case e_search_contact:
				search_contact(address_book);
				break;
			case e_edit_contact:
				edit_contact(address_book);
				break;
			case e_delete_contact:
				delete_contact(address_book);
				break;
			case e_list_contacts:
				list_contacts(address_book);
				break;
				/* Add your implementation to call list_contacts function here */
			case e_save:
				save_file(address_book);
				break;
			case e_exit:
				break;
		}
	} while (option != e_exit);

	return e_success;
}

Status add_contacts(AddressBook *address_book)
{
	/* Add the functionality for adding contacts here */
	//address_book -> count;
	printf("Please enter your name.");
	scanf("%s", address_book -> list[NAME_COUNT][NAME_LEN].name);
	printf("Please enter your phone number.");
	scanf("%s",address_book -> list[PHONE_NUMBER_COUNT][NUMBER_LEN].phone_numbers);
	printf("Please enter your email address.");
	scanf("%s", address_book -> list[EMAIL_ID_COUNT][EMAIL_ID_LEN].email_addresses);
}

Status search(const char *str, AddressBook *address_book, int loop_count, int field, const char *msg, Modes mode)
{
	/* Add the functionality for adding contacts here */
}

Status search_contact(AddressBook *address_book)
{
<<<<<<< HEAD
	/* Add the functionality for search contacts here */
=======
	if (address_book == NULL)                   
    {
        printf("address_book is null\n");
        return;
    }
    char name[200] = { 0 };
    printf("Please enter the name of the contact you want to find:");           
    scanf("%s", &name);
    size_t i = 0;
    for (; i < address_book->count; ++i)
    {
        if (strcmp(address_book->list[i].name, name) == 0)
        {
            printf("This person's information is:\n full name:%s ,Telephone:%s ,Address:%s\n",
                address_book->list[i].name,
                address_book->list[i].phone_numbers,
                address_book->list[i].email_addresses);
            return;
        }

		if (strcmp(address_book->list[i].phone_numbers, name) == 0)
        {

            printf("This person's information is:\n full name:%s\n ,Telephone:%s\n ,Address:%s\n",
                address_book->list[i].name,
                address_book->list[i].phone_numbers,
                address_book->list[i].email_addresses);
            return;
        }
		
		if (strcmp(address_book->list[i].email_addresses, name) == 0)
        {
            printf("This person's information is:\n full name:%s\n ,Telephone:%s\n ,Address:%s\n",
                address_book->list[i].name,
                address_book->list[i].phone_numbers,
                address_book->list[i].email_addresses);
            return;
        }
    }
    if (i == address_book->count)
    {
        printf("This person is not in this address book.\n");
		printf("Please search for a different person.\n");
        return;
    }

>>>>>>> 2d55725b8d3ce9df36b7fd2a149dfa22d87645b1
}

Status edit_contact(AddressBook *address_book)
{
	/* Add the functionality for edit contacts here */
	printf("Search Contact to Edit by:/n
		0.Back/n
		1.Name/n
		2.Phone No/n
		3.Email ID/n
		Please select an option: ");
	int num;
	scanf("%d", num);
	switch(num)
	{
		case 1:
			char name[200] = { 0 };
			printf("Enter the Name: ");
			scanf("%s", &name);
    			size_t i = 0;
    			for (; i < address_book->count; ++i)
    			{
        			if (strcmp(address_book->list[i].name, name) == 0)
        			{
            			printf("What would you like to change the name to?: ");
				scanf("%s", address_book -> list[i][NAME_LEN].name);
        			}
    			}
    			if (i == address_book->count)
    			{
        			printf("Name not found\n");
       
			}
			break;
		case 2:
			char phone[200] = { 0 };
			printf("Enter the Phone Number: ");
			scanf("%s", &phone);
    			size_t i = 0;
    			for (; i < address_book->count; ++i)
    			{
        			if (strcmp(address_book->list[i].phone_numbers, phone) == 0)
        			{
            			printf("What would you like to change the phone number to?: ");
				scanf("%s", address_book -> list[i][NUMBER_LEN].phone_numbers);
        			}
    			}
    			if (i == address_book->count)
    			{
        			printf("Phone number not found\n");
       
			}
			break;
		case 3:
			char email[200] = { 0 };
			printf("Enter the Email ID: ");
			scanf("%s", &email);
    			size_t i = 0;
    			for (; i < address_book->count; ++i)
    			{
        			if (strcmp(address_book->list[i].email_addresses, email_addresses) == 0)
        			{
            			printf("What would you like to change the email address to?: ");
				scanf("%s", address_book -> list[i][EMAIL_ID_LEN].name);
        			}
    			}
    			if (i == address_book->count)
    			{
        			printf("Email ID not found\n");
       
			}
			break;
		case 0:
			printf("Exiting\n");
			return e_back;
			break;
		default:
			printf("Invalid number\n");
			break;
	}
	return e_success;
}

Status delete_contact(AddressBook *address_book)
{	
	int i = 0;
	char name[200];
	int deleteContact = -1;
	printf("You chose to delete a contact.\n");
	printf("Please enter the full name of the contact would you like to delete:");
	scanf("%s", &name);
	for(i = 0; i<*address_book; i++)
	{
		if((strcmp(address_book->list[i].name,)==0)
		{
			deleteContact =i;
			break;
		}
	}
		if(deleteContact ==-1)
		{
			printf("Contact not found\n");
		}
		else{
			int i=0
			for(i=deleteContact; i<address_book-1;i++)
			{
				strcpy(address_book->list[i].name);
				strcpy(address_book->list[i].phone_numbers);
				strcpy(address_book->list[i].email_addresses);
			}
			(*address_book)--;
			printf("Contact deleted from phone book\n");
		}

}
