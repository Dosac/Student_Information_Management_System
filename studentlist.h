#include "linklist.h"

void studentlist_print(LinkList student_list);
void studentlist_modify_name(LinkList student_list, int n, char* str);
void studentlist_modify_gender(LinkList student_list, int n, Gender gender);
void studentlist_modify_ID(LinkList student_list, int n, char* str);
void studentlist_modify_QQ(LinkList student_list, int n, char* str);
void studentlist_modify_grade_Math(LinkList student_list, int n, float grade);
void studentlist_modify_grade_English(LinkList student_list, int n, float grade);

void studentlist_write(LinkList student_list, char* filename);
LinkList studentlist_read(char* filename);