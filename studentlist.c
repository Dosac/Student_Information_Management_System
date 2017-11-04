#include "studentlist.h"

void studentlist_print(LinkList student_list)
{
	printf("%-17s%-8s%-12s%-15s%-12s%-12s\n\n", "Name", "Gender", "ID", "QQ", "Math Grade", "English Grade");

	LinkNode* p = student_list.head;
	p = p->link;
	while(p)
	{
		printf("%-17s", p->name);
		switch(p->gender)
		{
			case 0: printf("%-8s", "Male"); break;
			case 1: printf("%-8s", "Female"); break;
		}
		printf("%-12s", p->ID);
		printf("%-15s", p->QQ);
		printf("%-12.1f", p->grade_Math);
		printf("%-12.1f\n", p->grade_English);

		p = p->link;
	}
}

void studentlist_modify_name(LinkList student_list, int n, char* str_name)
{
	if(n < 0 || n >= student_list.length)
	{
		return position_warning(n, student_list.length, "void studentlist_modify_name(LinkList list, int n, char* str_name)");
	}

	LinkNode* student = linklist_getnode(student_list, n);
	if(student->name)
	{
		free(student->name);
	}
	strcpy(student->name, str_name);
}

void studentlist_modify_gender(LinkList student_list, int n, Gender gender)
{
	if(n < 0 || n >= student_list.length)
	{
		return position_warning(n, student_list.length, "void studentlist_modify_gender(LinkList list, int n, Gender gender)");
	}

	LinkNode* student = linklist_getnode(student_list, n);
	student->gender = gender;
}

void studentlist_modify_ID(LinkList student_list, int n, char* str_ID)
{
	if(n < 0 || n >= student_list.length)
	{
		return position_warning(n, student_list.length, "void studentlist_modify_gender(LinkList list, int n, Gender gender)");
	}

	LinkNode* student = linklist_getnode(student_list, n);
	if(student->ID)
	{
		free(student->ID);
	}
	strcpy(student->ID, str_ID);
}

void studentlist_modify_QQ(LinkList student_list, int n, char* str_QQ)
{
	if(n < 0 || n >= student_list.length)
	{
		return position_warning(n, student_list.length, "void studentlist_modify_QQ(LinkList list, int n, char* str)");
	}

	LinkNode* student = linklist_getnode(student_list, n);
	if(student->QQ)
	{
		free(student->QQ);
	}
	strcpy(student->QQ, str_QQ);
}

void studentlist_modify_grade_Math(LinkList student_list, int n, float grade)
{
	if(n < 0 || n >= student_list.length)
	{
		return position_warning(n, student_list.length, "void studentlist_modify_grade_Math(LinkList list, int n, float grade)");
	}

	LinkNode* student = linklist_getnode(student_list, n);
	student->grade_Math = grade;
}

void studentlist_modify_grade_English(LinkList student_list, int n, float grade)
{
	if(n < 0 || n >= student_list.length)
	{
		return position_warning(n, student_list.length, "void studentlist_modify_grade_Math(LinkList list, int n, float grade)");
	}

	LinkNode* student = linklist_getnode(student_list, n);
	student->grade_English = grade;
}

bool studentnode_isempty(LinkNode* p)
{
	return (!p->name && !p->gender && !p->ID && !p->QQ && !p->grade_Math && !p->grade_English);
}

void studentlist_write(LinkList student_list, char* filename)
{
	FILE* fptr = fopen(filename, "a");

	LinkNode* p = student_list.head;
	p = p->link;
	while(p)
	{
		if(!studentnode_isempty(p))
		{
			fprintf(fptr, "%-17s", p->name);
			switch(p->gender)
			{
				case 0: fprintf(fptr, "%-8s", "Male"); break;
				case 1: fprintf(fptr, "%-8s", "Female"); break;
			}
			fprintf(fptr, "%-12s", p->ID);
			fprintf(fptr, "%-15s", p->QQ);
			fprintf(fptr, "%-12.1f", p->grade_Math);
			fprintf(fptr, "%-12.1f\n", p->grade_English);
		}

		p = p->link;
	}
	fclose(fptr);
}

char* substr(char* str_initial, int i_begin, int i_end)
{
	char* str_result = (char*)malloc( (i_end - i_begin + 2) * sizeof(char) );
	for(int i = i_begin; i <= i_end; i++)
	{
		str_result[i-i_begin] = str_initial[i];
	}
	str_result[i_end-i_begin+1] = '\0';

	return str_result;
}

LinkList studentlist_read(char* filename)
{
	LinkList student_list = linklist_creat(0);
	FILE* fptr = fopen(filename, "r"); 
	char line[100];  
	int filesize; 
	if(!fptr)
	{  
		printf("Failed to open file!\n");  
		exit(-1);
	}  

	fseek(fptr, 0, SEEK_END);   

	filesize = ftell(fptr);

	rewind(fptr);
	while( (fgets(line, 100, fptr)) != NULL )
	{  
		int i = 2;
		int i_left = 0;
		int index = 0;
		char* element;

		Student student;
		while(line[i+1] != '\n')
		{
			if(line[i-2] == ' ' && line[i-1] == ' ' && line[i] != ' ')
			{
				i_left = i;
			}
			if(line[i-1] != ' ' && line[i] == ' ' && line[i+1] == ' ')
			{
				element = substr(line, i_left, i-1);
				switch(index)
				{
					case 0: strcpy(student.name, element); break;
					case 1:
					{
						if(!strcmp(element, "Male"))
						{
							student.gender = male;
						}
						else
						{
							student.gender = female;
						}

						break;
					}
					case 2: strcpy(student.ID, element); break;
					case 3: strcpy(student.QQ, element); break;
					case 4: student.grade_Math = atof(element); break;
					case 5: student.grade_English = atof(element); break;
					default: break;
				}

				index++;
			}

			i++;
		}
		linklist_push_back(student_list, student);
	}
	fclose(fptr);

	return student_list; 
}