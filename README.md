# Employees Program

My final exam for Fundamentals of Programming completed **17/0/2021**:

EWSS [100 marks]

On the 23rd July 2020, the Irish Government announced an Employment Wage Subsidy
Scheme (EWSS) to help employers impacted by the Covid-19 pandemic. The aim of this
scheme is to provide a flat-rate subsidy to qualifying employers to allow them to retain as
many employees as possible. When payroll figures are submitted to Revenue, their software
will calculate how much subsidy to pay to the employer. But the employer would like to know
when processing the wages for employees how much that subsidy will be.

For the payroll user, an EWSS calculator is required to alert them if the employer will get the
subsidy for an employee based on the employee’s earnings in the payroll period.

The employer will get a subsidy for weekly paid employees if the number of insurable weeks
is between 1 and 5 and their gross pay is greater than €151.50 per week. The amount of the
subsidy is then determined by the gross pay. If an employee’s wages are less than €203 the
subsidy amount is €203. For employees earning between €203 and €300 per week the
subsidy is €250. Between €300 and €400 per week, an employee would get a subsidy of
€300. Finally, if an employee earns more than €400 per week, and up to and including €1462
per week, they will be entitled to a subsidy of €350 per week.

You have been asked to provide a system (using the C programming language) for analysing
a list of employees. The employee details will be provided as a text file. An example of an
entry is given below:

100001 Bloggs Joe 5 411

The entry above gives the employees Employee Code, Employee Last Name, First Name,
Insurable Weeks and Gross Pay.

Below is a list of required functions for the system

Function 1: load_data [20 marks]

This function is automatically called when the program is started. It loads employee records
from the supplied file. If the file does not exist, notify the user, create a new file and display the main menu. Once the file is open, data is read into an array of structs by dynamically creating sufficient memory for each entry read from the file. The struct should include a “Subsidy Amount” float field, the amount of which is added for each employee after running their details through a calculator function.

Define a struct to represent the information for an employee, containing at least the
following fields:
• employee_code (int)

• employee_name (char[])

• insurable_weeks (int)

• gross_pay (float)

• subsidy (float)

Function 2: display_menu [5 marks]

After the application is started, use this function to print a list of options to the user using a numbered list. When the user selects an option, the system performs the required action, and returns to the menu, waiting for the user to select another option. Include an option to exit the system.

Your main menu system might resemble the following:

1. Add new employee
2. Delete employee
3. View all employees in the list
4. View only qualifying employees
5. View disqualified employees (and show reason)
6. Sort employees by name
7. Sort employees by subsidy amount
8. View total subsidy amount (total for all employees)
9. Exit

Function 3: add_new_employee [10 marks]

When the user selects the “Add new employee” menu item, prompt them for the data for
the new record. Append the new record to the array of current employees and notify the
user that the new record has been added successfully.

Function 4: delete_employee [10 marks]

When the user selects the “Delete employee” option, they are prompted for an
employee_code. This function then removes the relevant employee from the array and
notifies the user that it has been removed successfully.

Function 5: view_all_employees [5 marks]

When the user selects the “View all employees” option, this function prints a list of all
employees and their information on record. Make sure that the information is formatted
neatly with headers and appropriate tabs or spacing, not simply a list of raw information.
Function 6: view_qualifying_employees [8 marks]

When the user selects the “View only qualifying employees” option, this function prints a list
of all employees who qualify for the subsidy and their information on record. Make sure
that the information is formatted neatly with headers and appropriate tabs or spacing, not
simply a list of raw information.

Function 7: find_disqualified_employees [5 marks]

When the user selects the “View disqualified employees” option, this function prints a list of
all employees who do not qualify for the subsidy and includes a reason as to why they do not
qualify. Make sure that the information is formatted neatly with headers and appropriate
tabs or spacing, not simply a list of raw information.

Function 8: sort_employees_by_name [7 marks]

Give the user the option to sort employees by name. Store the sorted information in a file
and notify the user of the name of the file.

Function 9: sort_employees_by_subsidy_amount [5 marks]

When the user selects the “Sort employees by subsidy amount” menu option, this function
displays just the employees’ names and their subsidy amount sorted from highest to lowest.

Function 10: view_total_subsidy_amount [5 marks]

When the user selects the “View total subsidy amount” menu option, this function displays
the sum of all employee subsidies.

Function 11: save_data [20 marks]

This function is called when the user chooses to exit the system. Open a data file and write
out the information contained in the array.
