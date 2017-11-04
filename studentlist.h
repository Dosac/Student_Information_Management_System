#include "linklist.h"

void studentlist_print(LinkList student_list);  // finished
void studentlist_modify_name(LinkList student_list, int n, char* str);  // finished
void studentlist_modify_gender(LinkList student_list, int n, Gender gender);  // finished
void studentlist_modify_ID(LinkList student_list, int n, char* str);  // finished
void studentlist_modify_QQ(LinkList student_list, int n, char* str);  // finished
void studentlist_modify_grade_Math(LinkList student_list, int n, float grade);  // finished
void studentlist_modify_grade_English(LinkList student_list, int n, float grade);  // finished

void studentlist_write(LinkList student_list, char* filename);  // finished
LinkList studentlist_read(char* filename);  // finished