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
	
}

Status search_contact(AddressBook *address_book)
{
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
            printf("eureka!\n");
            printf("This person's information is:\n full name:%s ,Telephone:%s ,Address:%s\n",
                address_book->list[i].name,
                address_book->list[i].phone_numbers,
                address_book->list[i].email_addresses);
            return;
        }
    }
    if (i == address_book->count)
    {
        printf("No one!\n");
        return;
    }

}

Status edit_contact(AddressBook *address_book)
{
	/* Add the functionality for edit contacts here */
}

Status delete_contact(AddressBook *address_book)
{
	int del = 0;
	char name[200] = {0};
	printf("You chose to delete a contact.\n");
	printf("Please enter the full name of the contact would you like to delete:");
	scanf("%s", &name);
	strcpy(address_book->list[i].name del);
	strcpy(address_book->list[i].phone_numbers, del);
	strcpy( address_book->list[i].email_addresses, del);
	printf("Contact deleted\n");
}
