#include<stdio.h>//��׼�������
#include<stdlib.h>//��̬�ڴ�����
#include<conio.h>//����Ҫ�س���ֱ�ӻ�ȡ�ַ�

//ѧ����Ϣ
typedef struct _Student
{
	int stuNum;
	char name[20];
	int score;
}Student;

//����ڵ�
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
