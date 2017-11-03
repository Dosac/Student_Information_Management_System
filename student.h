#include <string.h>

typedef enum Gender
{
	male = false,
	female = true
}Gender;

typedef struct Student
{
	char* name = NULL;
	Gender gender = male;
	char* ID = NULL;
	char* QQ = NULL;
	float grade_math = 0;
	float grade_English = 0;
	Student* link = NULL;
}Student;

typedef Student LinkNode;