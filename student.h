#include <string.h>

typedef enum Gender
{
	male = 0,
	female = 1
}Gender;

typedef struct Student
{
	char* name;
	Gender gender;
	char* ID;
	char* QQ;
	float grade_Math;
	float grade_English;
	struct Student* link;
}Student;

typedef Student LinkNode;