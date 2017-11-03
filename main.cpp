#include "studentlist.h"

int main(int argc, char **argv)
{
	StudentList student_list = studentlist_creat(5);
	studentlist_print(student_list);
	return 0;
}