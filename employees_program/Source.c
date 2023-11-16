#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* global variable of the text file used in the program */
char data_file[] = "data.txt";

/* declare the employee struct to hold the data */
struct Employee {
	int code;
	char lastname[20];
	char firstname[20];
	int weeks;
	double pay;
	double subsidy;

} Employee;

struct Employee arr_employee[100];

/* function prototypes */

/* Function 1: load_data */
void load_data();

/* Function 2: display_menu*/
void display_menu();

/* Function 3: add_new_employee */
void add_new_employee(struct Employee[]);

/* Function 4: delete_employee */
void delete_employee(struct Employee[]);

/* Function 5: view_all_employees */
void view_all_employees(struct Employee[]);

/* Function 6: view_qualifying_employees */
void view_qualifying_employees(struct Employee[]);

/* Function 7: find_disqualified_employees */
void find_disqualified_employees(struct Employee[]);

/* Function 8: sort_employees_by_name */
void sort_employees_by_name(struct Employee[], int EmployeeCount);

/* Function 9: sort_employees_by_subsidy_amount*/
void sort_employees_by_subsidy_amount(struct Employee[], int EmployeeCount);

/* Function 10: view_total_subsidy_amount */
void view_total_subsidy_amount(struct Employee[]);

/* Function 11: save_data */
void save_data(struct Employee[]);

/* Extra function to calculate subsidy */
double calculate_subsidy(int w, double s);

/* the main function */

int main() {

	/* call the functions required at program start up */
	load_data();
	display_menu();

	return 0;
}

/* Function 1: load_data */
void load_data() {

	/* declare variables required */
	int i = 0;
	int file_end = 0, count = 0;
	int EmployeeCount = 0;

	/* creates pointer to a file for reading */
	FILE* file_pointer = fopen(data_file, "r");

	/* attempts to open the data file for reading */
	if (file_pointer != NULL) {

		/* informs the user the data file is opened */
		printf("\n-----------------------------\n");
		printf("**Employee data file opened successfully**");
		printf("\n-----------------------------\n");

		char lineVal[121];
		char* item;
		int file_end = 0;

		/* read data in as a string while not at the end of the file */
		while (fgets(lineVal, 120, file_pointer) && file_end != EOF) {

			/* populate the employee struct */
			item = strtok(lineVal, " ");
			arr_employee[EmployeeCount].code = atoi(item);

			item = strtok(NULL, " ");
			strcpy(arr_employee[EmployeeCount].lastname, item);

			item = strtok(NULL, " ");
			strcpy(arr_employee[EmployeeCount].firstname, item);

			item = strtok(NULL, " ");
			arr_employee[EmployeeCount].weeks = atoi(item);

			item = strtok(NULL, " ");
			arr_employee[EmployeeCount].pay = atof(item);

			arr_employee[EmployeeCount].subsidy = calculate_subsidy(arr_employee[EmployeeCount].weeks, arr_employee[EmployeeCount].pay);

			/* increment the employee count */
			EmployeeCount++;
		}

	}

	/* close the file */
	fclose(file_pointer);

}

/* Extra function to calculate subsiday */
double calculate_subsidy(int w, double s) {

	/* initialise subsidy to 0*/
	double subsidy = 0;

	/* if the weeks are valid */
	if (w >= 1 && w <= 5) {

		/* if the pay is less than 203 */
		if (s < 203) {

			subsidy = 230;
		}

		else if (s < 300) {

			subsidy = 250;

		}

		else if (s < 400) {

			subsidy = 300;

		}

		else if (s <= 1462) {

			subsidy = 350;

		}

		else {

			subsidy = 0;
		}

	}

	return subsidy;
}

/* Function 2: display_menu*/
void display_menu() {

	/* declare the variables required */
	int menu_item = 0, status;

	do {
		/* set of printf statements to display menu about the program */
		printf("\n-----------------------------\n");
		printf("** Employees Application **");
		printf("\n-----------------------------\n");
		printf("1. Add new employee\n");
		printf("2. Delete employee\n");
		printf("3. View all employees in the list\n");
		printf("4. View only qualifying employees\n");
		printf("5. View disqualified employees\n");
		printf("6. Sort employees by name\n");
		printf("7. Sort employees by subsidy amount\n");
		printf("8. View total subsidy amount\n");
		printf("9. Exit\n");

		printf("\nChoose an option (1-9): ");
		status = scanf("%d", &menu_item);

		if (status == 0 || menu_item < 1 || menu_item > 9) {
			printf("\n-----------------------------\n");
			printf("Invalid input, please choose an option (1-9)");
			printf("\n-----------------------------\n");
			/* clear the data buffer */
			while (getchar() != '\n');
		}
		else {

			/* switch function that controls on what happens next based upon the options */
			switch (menu_item)
			{

				/* call add_new_employee function */
			case 1:
				add_new_employee(arr_employee);
				break;

				/* call delete_employee function */
			case 2:
				delete_employee(arr_employee);
				break;

				/* call view_all_employees function */
			case 3:
				view_all_employees(arr_employee);
				break;

				/* call view_qualifying_employees function */
			case 4:
				printf("\nOption 4\n");
				break;

				/* call find_disqualified_employees function */
			case 5:
				printf("\nOption 5\n");
				break;

				/* call sort_employees_by_name function */
			case 6:
				printf("\nOption 6\n");
				break;

				/* call call sort_employees_by_subsidy_amount function */
			case 7:
				printf("\nOption 7\n");
				break;

				/* call view_total_subsidy_amount function */
			case 8:
				printf("\nOption 8\n");
				break;

				/* call save_data function */
			case 9:
				printf("\nOption 9\n");
				break;

			default:
				break;
			}

		}
	} while (menu_item != 9 || (status == 0 || menu_item < 1 || menu_item > 9));

	/* exit program */

	printf("\n-----------------------------\n");
	printf("** Program ended **");
	printf("\n-----------------------------\n");
}

/* Function 3: add_new_employee */
void add_new_employee(struct Employee e[]) {

	/* set up variables needed */
	int code;
	char lastname[20];
	char firstname[20];
	int weeks;
	double pay;

	/* this should be dynamic */
	int EmployeeCount = 40;


	/* I'll get the user input validated later */

	printf("\n\n-----------------------------\n");
	printf("** New employee form **");
	printf("\n-----------------------------\n");
	printf("Enter new employee code: ");
	scanf("%d", &code);

	printf("\nEnter new employee last name: ");
	scanf("%s", &lastname);

	printf("\nEnter new employee first name: ");
	scanf("%s", &firstname);

	printf("\nEnter new employee insurable weeks: ");
	scanf("%d", &weeks);

	printf("\nEnter new employee gross pay: ");
	scanf("%lf", &pay);
	printf("\n-----------------------------\n");

	printf("\n\n-----------------------------\n");
	printf("** Employee added successfully! **");
	printf("\n-----------------------------\n");

	arr_employee[EmployeeCount + 1].code = code;
	strcpy(arr_employee[EmployeeCount + 1].lastname, lastname);
	strcpy(arr_employee[EmployeeCount + 1].firstname, firstname);
	arr_employee[EmployeeCount + 1].weeks = weeks;
	arr_employee[EmployeeCount + 1].pay = pay;
	arr_employee[EmployeeCount + 1].subsidy = calculate_subsidy(weeks, pay);

}

/* Function 4: delete_employee */
void delete_employee(struct Employee e[]) {

	int delete_code = 0, i = 0;
	int EmployeeCount = 0;

	/* get employee code to be deleted */
	printf("\nEnter employee code for employee to be deleted\n");
	scanf("%d", &delete_code);

	for (i = 0; i < EmployeeCount; i++)
	{
		/* if the delete code matches a code from the array */
		if (delete_code == e[i].code) {

			/* could ask the user here if they are sure they want to delete user */

				/* remove the code from the array */
			for (i = delete_code - 1; i < EmployeeCount - 1; i++)
			{
				e[i].code = e[i + 1].code;
				strcpy(e[i + 1].lastname, e[i].lastname);
				strcpy(e[i + 1].firstname, e[i].firstname);
				e[i].weeks = e[i + 1].weeks;
				e[i].pay = e[i + 1].pay;

			}

			/* Decrement array size by 1 */
			EmployeeCount--;

			/* print success message*/
			printf("\n\n-----------------------------\n");
			printf("** Employee deleted **");
			printf("\n-----------------------------\n");

		}

		/* if the code was not within the array but was an integer */
		else {

			printf("\nEmpployee number not found\n");
		}

	}

}

/* Function 5: view_all_employees */
void view_all_employees(struct Employee e[]) {

	/* declare variables required */
	int i = 0;
	int EmployeeCount = 41;

	/* print column headers */
	printf("\n%13s%15s%13s%19s%13s%12s\n", "EMPLOYEE CODE", "SURNAME", "FORENAME", "INSURABLE WEEKS", "GROSS PAY", "SUBSIDY");

	/* loop through all the employees currently in the array */
	for (i = 0; i < EmployeeCount; i++)
	{
		/* print the contents of the array */
		printf("\n%13d%15s%13s%19d%13.2f%12.2f", e[i].code, e[i].lastname, e[i].firstname, e[i].weeks, e[i].pay, e[i].subsidy);
	}

	/* print spacing */
	printf("\n\n");
}

/* Function 6: view_qualifying_employees */
void view_qualifying_employees(struct Employee e[]) {

	/* declare variables required */
	int i;
	int EmployeeCount = 0;

	/* print column headers */
	printf("\n%13s%15s%13s%19s%13s%12s\n", "EMPLOYEE CODE", "SURNAME", "FORENAME", "INSURABLE WEEKS", "GROSS PAY", "SUBSIDY");

	/* loop through all the employees currently in the array */
	for (i = 0; i < EmployeeCount; i++)
	{
		/* if the employee has a subsidy greater than 0 and therefore qualifies for the subsidy*/
		if (e[i].subsidy > 0)
		{
			/* print the qualifying employees */
			printf("\n%13d%15s%13s%19d%13.2f%12.2f", e[i].code, e[i].lastname, e[i].firstname, e[i].weeks, e[i].pay, e[i].subsidy);

		}
	}

}

/* Function 7: find_disqualified_employees */

void find_disqualified_employees(struct Employee e[]) {

	/* declare variables required */
	int i;
	int EmployeeCount = 0;
	char weeks_reason[] = "Not enough weeks";
	char pay_reason[] = "Not enough salary";

	/* print column headers */
	printf("\n%13s%15s%13s%19s%13s%12s%12s\n", "EMPLOYEE CODE", "SURNAME", "FORENAME", "INSURABLE WEEKS", "GROSS PAY", "SUBSIDAY", "REASON");

	/* loop through all of the employees in the array*/
	for (i = 0; i < EmployeeCount; i++)
	{
		/* if the employee has no subsiday and their weeks are out of qualification */
		if (e[i].subsidy == 0 && (e[i].weeks < 1 || e[i].weeks > 5)) {

			/* print the disqualified employees due to weeks */
			printf("\n%13d%15s%13s%19d%13.2f%12.2f%12s", e[i].code, e[i].lastname, e[i].firstname, e[i].weeks, e[i].pay, e[i].subsidy, weeks_reason);
		}

		/* if the employee has no subsiday and their pay is out of qualification */
		if (e[i].subsidy == 0 && (e[i].pay < 151.50 || e[i].pay > 1462)) {

			/* print the disqualified employees due pay */
			printf("\n%13d%15s%13s%19d%13.2f%12.2f%12s", e[i].code, e[i].lastname, e[i].firstname, e[i].weeks, e[i].pay, e[i].subsidy, pay_reason);
		}
	}
}



/* Function 8: sort_employees_by_name */
void sort_employees_by_name(struct Employee e[], int EmployeeCount) {

	/* declare variables required */
	int i, compare;

	/* declare temporary struct to hold swapping */
	struct Employee temp;

	/* for all of the employees in the file */
	for (--EmployeeCount; EmployeeCount > 0; --EmployeeCount) {

		for (i = 0; i < EmployeeCount; ++i) {

			/* compare two strings in the array*/
			compare = strcmp(e[i].lastname, e[i + 1].lastname);

			/* if the lastnames are > 0 they are in the wrong order*/
			if (compare > 0) {
				/* swap the lastnames */
				temp = e[i];

				e[i] = e[i + 1];

				e[i + 1] = temp;
			}
		}
	}
}

/* Function 9: sort_employees_by_subsidy_amount*/
void sort_employees_by_subsidy_amount(struct Employee e[], int EmployeeCount) {

	/* declare variables required */
	int i, compare;

	/* declare temporary struct to hold swapping */
	struct Employee temp;

	/* for all of the employees in the file */
	for (--EmployeeCount; EmployeeCount > 0; --EmployeeCount) {

		for (i = 0; i < EmployeeCount; ++i) {

			/* compare subsidy amounts */
			if (e[i].subsidy <= e[i + 1].subsidy) {

				/* call the swap function */
				temp = e[i];

				e[i] = e[i + 1];

				e[i + 1] = temp;
			}
		}
	}
}

/* Function 10: view_total_subsidy_amount */
void view_total_subsidy_amount(struct Employee e[]) {

	/* declare variables required */
	int i = 0;
	int EmployeeCount = 0;
	double sum = 0;

	/* loop through the employees currently in the array */
	for (i = 0; i < EmployeeCount; i++) {

		/* sum all of the employee subsidies */
		sum += arr_employee[i].subsidy;

	}

	/* print the total subsidy amount */
	printf("\n\n-----------------------------\n");
	printf("** Total subsidy amount is: %f **", sum);
	printf("\n-----------------------------\n");

}

/* Function 11: save_data */
void save_data(struct Employee e[]) {

	/* declare variables required */
	int i;

	int EmployeeCount = 0;

	/* declare file pointer to open new file */
	FILE* file_pointer = fopen("new_file.txt", "w");

	/* if a file has been created */
	if (file_pointer != NULL) {

		/* loop through the employees currently in the array */
		for (i = 0; i < EmployeeCount; i++)
		{
			/* print the contents of array to the file*/
			fprintf(file_pointer, "%d %s %s %d %f %f\n", arr_employee[i].code, arr_employee[i].lastname, arr_employee[i].firstname, arr_employee[i].weeks, arr_employee[i].pay, arr_employee[i].subsidy);
		}

		/* inform the user the file has been saved successfully */
		printf("\n\n-----------------------------\n");
		printf("** File saved **");
		printf("\n-----------------------------\n");

	}
	/* inform user of error */
	else
	{
		printf("Error in writing file");
	}

	/* close the file */
	fclose(file_pointer);

}