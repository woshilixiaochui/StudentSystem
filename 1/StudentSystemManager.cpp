#include"StudentSystemManager.h"
int main()
{
	//����ͷ���
	Node* head =(Node*) malloc(sizeof(Node));
	head->next = NULL;
	loadstudent(head);
	while (1)
	{
		welcome();

		char c = _getch();
		switch (c)
		{
		case '1': //¼��ѧ����Ϣ
			inputstudent(head);
			break;
		case '2': //��ӡѧ����Ϣ
			printstudent(head);
			break;
		case '3': //ͳ��ѧ������
			countStudent(head);
			break;
		case '4': //����ѧ����Ϣ
			findstudent(head);
			break;
		case '5': //�޸�ѧ����Ϣ
			modifystudent(head);
			break;
		case '6': //ɾ��ѧ����Ϣ
			deletestudent(head);
			break;
		case '7': //���ɼ�����
			sortstudent(head);
			break;
		case '8': //�˳�ϵͳ
			printf("see you!");
			exit(0);
			break;
		default:
			printf("���������룺");
			break;
		}
	}
	return 0;
}
void welcome()
{
	printf("*********************************\n");
	printf("*\tѧ���ɼ�����ϵͳ\t*\n");
	printf("*********************************\n");
	printf("*\t��ѡ�����б�\t\t*\n");
	printf("*********************************\n");
	printf("*\t1.¼��ѧ����Ϣ\t\t*\n");
	printf("*\t2.��ӡѧ����Ϣ\t\t*\n");
	printf("*\t3.ͳ��ѧ������\t\t*\n");
	printf("*\t4.����ѧ����Ϣ\t\t*\n");
	printf("*\t5.�޸�ѧ����Ϣ\t\t*\n");
	printf("*\t6.ɾ��ѧ����Ϣ\t\t*\n");
	printf("*\t7.���ɼ�����\t\t*\n");
	printf("*\t8.�˳�ϵͳ\t\t*\n");
	printf("*********************************\n");
}
void inputstudent(Node* head)
{
	Node* fresh = (Node*)malloc(sizeof(Node));
	fresh->next = NULL;
	printf("������ѧ����ѧ�ţ��������ɼ�");
	scanf("%d%s%d", &fresh->student.stuNum, fresh->student.name, &fresh->student.score);


	Node* move = head;
	while (move->next != NULL)
	{
		move = move->next;
	}
	//���뵽β��
	move->next = fresh;

	savestudent(head);
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void printstudent(Node* head)
{
	Node* move = head->next;
	while (move != NULL)
	{
		printf("ѧ�ţ�%d ������%s �ɼ���%d\n", move->student.stuNum, move->student.name, move->student.score);
		move = move->next;
	}
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void countStudent(Node* head)
{
	int count = 0;
	Node* move = head->next;
	while (move != NULL)
	{
		count++;
		move = move->next;
	}
	printf("ѧ��������Ϊ��%d\n", count);
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void findstudent(Node* head) 
{
	printf("������Ҫ���ҵ�ѧ����ѧ�ţ�");
	int stuNum;
	scanf("%d", &stuNum);
	Node* move = head->next;
	while (move != NULL)
	{
		if (stuNum == move->student.stuNum)
		{
			printf("ѧ�ţ�%d ������%s �ɼ�:%d\n", move->student.stuNum, move->student.name, move->student.score);
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ�ѧ����Ϣ\n");

	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void savestudent(Node* head)
{
	FILE* file = fopen("./stu.info", "w");
	if (file == NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	Node* move = head->next;
	while (move != NULL)
	{
		if (fwrite(&move->student, sizeof(Student), 1, file) != 1)
		{
			printf("д��ʧ��\n");
			return;
		}
		move = move->next;
	}
	fclose(file);
}
void loadstudent(Node* head)
{
	FILE* file = fopen("./stu.info", "r");
	if (!file)
	{
		printf("û��ѧ���ļ���������ȡ\n");
		return;
	}
	Node* fresh = (Node*)malloc(sizeof(Node));
	fresh->next = NULL;
	Node* move = head;
	while (fread(&fresh->student, sizeof(Student), 1, file) == 1)
	{
		move->next = fresh;
		move = fresh;
		fresh = (Node*)malloc(sizeof(Student));
		fresh->next = NULL;
	}
	free(fresh);
	fclose(file);
	printf("��ȡ�ɹ�\n");
}

void modifystudent(Node* head)
{
	printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	int stuNum;
	scanf("%d",&stuNum);
	Node* move = head->next;
	while (move != NULL)
	{
		if (move->student.stuNum == stuNum)
		{
			printf("������ѧ���������ɼ�\n");
			scanf("%s%d", move->student.name, &move->student.score);
			savestudent(head);
			printf("�޸ĳɹ���");
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ���ѧ����Ϣ");
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void deletestudent(Node* head)
{
	printf("������Ҫɾ����ѧ��ѧ�ţ�");
	int stuNum;
	scanf("%d", &stuNum);
	Node* move = head;
	while (move->next != NULL)
	{
		if (move->next->student.stuNum == stuNum)
		{
			Node* tmp = move->next;
			move->next = move->next->next;
			free(tmp);
			tmp = NULL;
			savestudent(head);
			printf("ɾ���ɹ���\n");
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ���ѧ����Ϣ");
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void sortstudent(Node* head)
{
	Node* save = NULL;
	Node* move = NULL;
	for (Node* turn = head->next; turn->next != NULL; turn = turn->next)
	{
		for (move = head->next; move->next != save; move = move->next)
		{
			if (move->student.score > move->next->student.score)
			{
				Student temp = move->student;
				move->student = move->next->student;
				move->next->student = temp;
			}
		}
		save = move;
	}
	printstudent(head);
}