#include <string.h>

typedef enum Gender
{
	male = 0,
	female = 1
}Gender;

typedef struct Student
{
	char name[20];
	Gender gender;
	char ID[10];
	char QQ[15];
	float grade_Math;
	float grade_English;
	struct Student* link;
}Student;

typedef Student LinkNode;