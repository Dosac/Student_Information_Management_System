#include "studentlist.h"

int main()
{
	// LinkList student_list = linklist_creat(5);

	// studentlist_modify_name(student_list, 0, "Bing-Hui WANG");
	// studentlist_modify_gender(student_list, 0, male);
	// studentlist_modify_ID(student_list, 0, "140141423");
	// studentlist_modify_QQ(student_list, 0, "2772138353");
	// studentlist_modify_grade_Math(student_list, 0, 95.5);
	// studentlist_modify_grade_English(student_list, 0, 100);

	// studentlist_print(student_list);
	LinkList student_list = studentlist_read("1.txt");
	studentlist_print(student_list);
	return 0;
}