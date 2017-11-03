#include "studentlist.h"

int main(int argc, char **argv)
{
	LinkList student_list = linklist_creat(5);
	Gender gender = female;
	studentlist_modify(student_list, 2, 2, &gender);
	studentlist_print(student_list);
	return 0;
}