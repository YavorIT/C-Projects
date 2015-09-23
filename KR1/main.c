#include <stdio.h>
#include <Windows.h>

int Pcomment (int num);
int comment (int num);
int Pcycle (int count);
int cycle (int count);
int main ()
{
	FILE *Rfile;
	int func, comments, cycles, k;
	char fnameW [1024];
	SetConsoleOutputCP(1251);
	printf ("�� - ������ ���������� �� ���� � ����� �� ��������� ��� ����. - 1\n");
	printf ("�� - ������ ���������� �� ���� � ��������� �� ��������� �� ������. - 2\n");
	printf ("�� - ������ �� ���������� �� ������������ � ����� �� ��������� ��� ����. - 3\n");
	printf ("�� - ������ �� ���������� �� ������������ � ��������� �� ��������� �� ������. - 4\n");
	k = scanf ("%d", &func);
// �������� ���� � ������� �������� ������
	if (k!=1)
	{
		printf ("������ ��� ������ ������\n");
		exit(1);
	}
	fflush (stdin);


		if (func == 1)
		{
			comments = comment (0);
			cycles = cycle (0);
			printf ("�������� ������ �� �����, � ����� �� ���� ������� ����������: \n");
			fgets (fnameW, 1024, stdin);
			fnameW [strlen(fnameW) - 1] = '\0';
			Rfile = fopen (fnameW, "w");
// �������� - ���� ������ ���� �� �� ������
			if (Rfile == NULL)
			{
				printf ("������ �� ���� �� �� ������ �� ������.\n");
				exit(1);
			}
			fprintf (Rfile, "%s %s %d\n", "���������","-", comments);
			fprintf (Rfile, "%s %s %d\n", "�����", "-", cycles);
			fclose (Rfile);
		}


		if (func == 2)
		{
			comments = comment (0);
			cycles = cycle (0);
			printf ("����� �� ����������� � - %d\n", comments);
			printf ("����� �� ����������� �� ����� � - %d\n", cycles);
		}


		if (func == 3)
		{
			comments = Pcomment (0);
			cycles = Pcycle (0);
			printf ("�������� ������ �� �����, � ����� �� ���� ������� ����������: \n");
			fgets (fnameW, 1024, stdin);
			fnameW [strlen(fnameW) - 1] = '\0';
			Rfile = fopen (fnameW, "w");
// �������� - ���� ������ ���� �� �� ������
			if (Rfile == NULL)
			{
				printf ("������ �� ���� �� �� ������ �� ������.\n");
				exit(1);
			}
			fprintf (Rfile, "%s %s %d\n", "���������","-", comments);
			fprintf (Rfile, "%s %s %d\n", "�����", "-", cycles);
			fclose (Rfile);
		}


		if (func == 4)
		{
			comments = Pcomment (0);
			cycles = Pcycle (0);
			printf ("����� �� ����������� � - %d\n", comments);
			printf ("����� �� ����������� �� ����� � - %d\n", cycles);
		}
	return 0;
}
// ��������� �� ����
int comment (int num)
{
	FILE *file;
	unsigned int i;
	int flag1 = 0, flag2 = 0;
	char fname [1024], fp [1024];
	printf ("����� �� �����, �� ����� �� �� ����� ���������:\n");
		fgets (fname, 1024, stdin);
		fname [strlen (fname) - 1] = '\0';
// �������� �� ����������� �� �����
		if ((fname [strlen(fname) - 2] != '.') || (fname [strlen(fname) - 1] != 'c'))
		{
			printf ("������ �� � � ��������� \".c\"! \n");
			exit (1);
		}
		file = fopen (fname, "r");
// �������� - ������� �� � ������
	if (file == NULL)
	{
		printf ("������ �� ���� �� �� ������ �� ������.\n");
		exit(1);
	}
// ������
	while ((fgets (fp, 1024, file)) != NULL)
	{
		for (i=0; i < strlen(fp); i++)
		{
// ��������� ����� �����������
			if (!flag1 && !flag2 && fp [i] == '"' && fp [i-1] != '\\' && fp [i-1] != '\'' && fp [i+1] != '\'')
			{
				flag2 = 1;
			}
			else if (!flag1 && flag2 && fp [i] == '"' && fp [i-1] != '\\' && fp [i-1] != '\'' && fp [i+1] != '\'')
			{
				flag2 = 0;
			}
// ���� ������� ���������
			if (!flag2 && !flag1 && (fp [i] == '/' && fp [i+1] == '/') && ( fp [strlen(fp) - 1] == '\n'))
			{
				num++;
				break;
			}
// ���� ������� ���������
			if (!flag2 && !flag1 && fp [i] =='/' && fp [i+1] == '*')
			{
				flag1 = 1;
			}
			if (!flag2 && flag1 && fp [i] == '*' && fp [i+1] == '/')
			{
				flag1 = 0;
				num++;
			}
		}
	}
	fclose (file);
	return num;
}

// ���� ����� �� ����
int cycle (int count)
{
	FILE *file;
	unsigned int i;
	int flag1 = 0, flag2 = 0, flag3 = 0;
	char fname [1024], fp [1024];
	printf ("����� �� �����, �� ����� �� �� ����� �����:\n");
		fgets (fname, 1024, stdin);
		fname [strlen (fname) - 1] = '\0';
// �������� �� �����������
		if ((fname [strlen(fname) - 2] != '.') || (fname [strlen(fname) - 1] != 'c'))
		{
			printf ("������ �� � � ��������� \".c\"! \n");
			exit (1);
		}
		else
		file = fopen (fname, "r");
// �������� - ������� �� � ������
	if (file == NULL)
	{
		printf ("������ �� ���� �� �� ������ �� ������.\n");
		exit(1);
	}
	while ((fgets (fp, 1024, file)) != NULL)
	{
		for (i=0; i < strlen(fp); i++)
		{
// ���������� �� ����� �����������
				if (!flag1 && !flag2 && fp [i] == '"' && fp [i-1] != '\\' && fp [i-1] != '\'' && fp [i+1] != '\'')
				{
					flag2 = 1;
				}
			else if (!flag1 && flag2 && fp [i] == '"' && fp [i-1] != '\\' && fp [i-1] != '\'' && fp [i+1] != '\'')
				{
					flag2 = 0;
				}
				if (!flag1 && !flag2 && !flag3 && fp [i] == '/' && fp [i+1] == '/')
				{
					flag3 = 1;
				}
				if (!flag1 && !flag2 && !flag3 && fp [i] == '/' && fp [i+1] == '*')
				{
					flag3 = 1;
				}
			else if (!flag1 && !flag2 && flag3 && fp [i] == '*' && fp [i+1] == '/')
				{
					flag3 = 0;
				}
// ���� �����
				if (!flag2 && !flag1 && !flag3 && (fp [i] == 'f' && fp [i+1] == 'o' && fp [i+2] == 'r'))
				{
					count++;
				}
				if (!flag2 && !flag1 && !flag3 && (fp [i] == 'w' && fp [i+1] == 'h' && fp [i+2] == 'i' && fp [i+3] == 'l' && fp [i+4] == 'e'))
				{
					count++;
				}
		}
	}
	fclose (file);
	return count;
}


// ������ �� ��������� �� ������������
int Pcomment (int num)
{
	unsigned int i;
	int flag1 = 0, flag2 = 0;
	char fp [1024];
	printf ("�������� ����, �� ����� �� �� ����� ���������:\n");
	while ((fgets (fp, 1024, stdin)) != NULL)
	{
		for (i=0; i < strlen(fp); i++)
		{
// ���������� �� ����� �����������
			if (!flag1 && !flag2 && fp [i] == '"' && fp [i-1] != '\\' && fp [i-1] != '\'' && fp [i+1] != '\'')
			{
				flag2 = 1;
			}
			else if (!flag1 && flag2 && fp [i] == '"' && fp [i-1] != '\\' && fp [i-1] != '\'' && fp [i+1] != '\'')
			{
				flag2 = 0;
			}
// ���� ������� ���������
			if (!flag2 && !flag1 && (fp [i] == '/' && fp [i+1] == '/') && ( fp [strlen(fp) - 1] == '\n'))
			{
				num++;
				break;
			}
// ���� ������� ���������
			if (!flag2 && !flag1 && fp [i] =='/' && fp [i+1] == '*')
			{
				flag1 = 1;
			}
			if (!flag2 && flag1 && fp [i] == '*' && fp [i+1] == '/')
			{
				flag1 = 0;
				num++;
			}
		}
	}
	return num;
}


// ���� �� ����� �� ������������
int Pcycle (int count)
{
	unsigned int i;
	int flag1 = 0, flag2 = 0, flag3 = 0;
	char fp [1024];
	printf ("�������� ����, �� ����� �� �� ����� �����:\n");
	while ((fgets (fp, 1024, stdin)) != NULL)
	{
		for (i=0; i < strlen(fp); i++)
		{
// ���������� �� ����� �����������
				if (!flag1 && !flag2 && fp [i] == '"' && fp [i-1] != '\\' && fp [i-1] != '\'' && fp [i+1] != '\'')
				{
					flag2 = 1;
				}
			else if (!flag1 && flag2 && fp [i] == '"' && fp [i-1] != '\\' && fp [i-1] != '\'' && fp [i+1] != '\'')
				{
					flag2 = 0;
				}
				if (!flag1 && !flag2 && !flag3 && fp [i] == '/' && fp [i+1] == '/')
				{
					flag3 = 1;
				}
				if (!flag1 && !flag2 && !flag3 && fp [i] == '/' && fp [i+1] == '*')
				{
					flag3 = 1;
				}
			else if (!flag1 && !flag2 && flag3 && fp [i] == '*' && fp [i+1] == '/')
				{
					flag3 = 0;
				}
// ���� �����
				if (!flag2 && !flag1 && !flag3 && (fp [i] == 'f' && fp [i+1] == 'o' && fp [i+2] == 'r'))
				{
					count++;
				}
				if (!flag2 && !flag1 && !flag3 && (fp [i] == 'w' && fp [i+1] == 'h' && fp [i+2] == 'i' && fp [i+3] == 'l' && fp [i+4] == 'e'))
				{
					count++;
				}
		}
	}
	return count;
}
