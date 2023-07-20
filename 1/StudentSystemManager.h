#include<stdio.h>//标准输入输出
#include<stdlib.h>//动态内存申请
#include<conio.h>//不需要回车，直接获取字符

//学生信息
typedef struct _Student
{
	int stuNum;
	char name[20];
	int score;
}Student;

//链表节点
typedef struct _Node
{
	Student student;
	struct _Node* next;
}Node;

void welcome();

void inputstudent(Node* head);

void printstudent(Node* head);

void countStudent(Node* head);

void findstudent(Node* head);

void savestudent(Node* head);

void loadstudent(Node* head);

void modifystudent(Node* head);

void deletestudent(Node* head);

void sortstudent(Node* head);
