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
	printf ("За - Четене програмата от файл и запис на резултата във файл. - 1\n");
	printf ("За - Четене програмата от файл и извеждане на резултата на екрана. - 2\n");
	printf ("За - Четене на програмата от клавиатурата и запис на резултата във файл. - 3\n");
	printf ("За - Четене на програмата от клавиатурата и извеждане на резултата на екрана. - 4\n");
	k = scanf ("%d", &func);
// Проверка дали е въведен правилен символ
	if (k!=1)
	{
		printf ("Въвели сте грешен символ\n");
		exit(1);
	}
	fflush (stdin);


		if (func == 1)
		{
			comments = comment (0);
			cycles = cycle (0);
			printf ("Въведете адреса на файла, в който ще бъде записан резултатът: \n");
			fgets (fnameW, 1024, stdin);
			fnameW [strlen(fnameW) - 1] = '\0';
			Rfile = fopen (fnameW, "w");
// Проверка - дали файлът може да се отвори
			if (Rfile == NULL)
			{
				printf ("Файлът не може да се отвори за писане.\n");
				exit(1);
			}
			fprintf (Rfile, "%s %s %d\n", "Коментари","-", comments);
			fprintf (Rfile, "%s %s %d\n", "Цикли", "-", cycles);
			fclose (Rfile);
		}


		if (func == 2)
		{
			comments = comment (0);
			cycles = cycle (0);
			printf ("Броят на коментарите е - %d\n", comments);
			printf ("Броят на операторите за цикъл е - %d\n", cycles);
		}


		if (func == 3)
		{
			comments = Pcomment (0);
			cycles = Pcycle (0);
			printf ("Въведете адреса на файла, в който ще бъде записан резултатът: \n");
			fgets (fnameW, 1024, stdin);
			fnameW [strlen(fnameW) - 1] = '\0';
			Rfile = fopen (fnameW, "w");
// Проверка - дали файлът може да се отвори
			if (Rfile == NULL)
			{
				printf ("Файлът не може да се отвори за писане.\n");
				exit(1);
			}
			fprintf (Rfile, "%s %s %d\n", "Коментари","-", comments);
			fprintf (Rfile, "%s %s %d\n", "Цикли", "-", cycles);
			fclose (Rfile);
		}


		if (func == 4)
		{
			comments = Pcomment (0);
			cycles = Pcycle (0);
			printf ("Броят на коментарите е - %d\n", comments);
			printf ("Броят на операторите за цикъл е - %d\n", cycles);
		}
	return 0;
}
// Коментари от файл
int comment (int num)
{
	FILE *file;
	unsigned int i;
	int flag1 = 0, flag2 = 0;
	char fname [1024], fp [1024];
	printf ("Адрес на файла, от който ще се броят коментари:\n");
		fgets (fname, 1024, stdin);
		fname [strlen (fname) - 1] = '\0';
// Проверка за окончанието на файла
		if ((fname [strlen(fname) - 2] != '.') || (fname [strlen(fname) - 1] != 'c'))
		{
			printf ("Файлът не е с окончание \".c\"! \n");
			exit (1);
		}
		file = fopen (fname, "r");
// Проверка - отворен ли е файлът
	if (file == NULL)
	{
		printf ("Файлът не може да се отвори за четене.\n");
		exit(1);
	}
// Броене
	while ((fgets (fp, 1024, file)) != NULL)
	{
		for (i=0; i < strlen(fp); i++)
		{
// Изключава някой възможности
			if (!flag1 && !flag2 && fp [i] == '"' && fp [i-1] != '\\' && fp [i-1] != '\'' && fp [i+1] != '\'')
			{
				flag2 = 1;
			}
			else if (!flag1 && flag2 && fp [i] == '"' && fp [i-1] != '\\' && fp [i-1] != '\'' && fp [i+1] != '\'')
			{
				flag2 = 0;
			}
// Брой линейни коментари
			if (!flag2 && !flag1 && (fp [i] == '/' && fp [i+1] == '/') && ( fp [strlen(fp) - 1] == '\n'))
			{
				num++;
				break;
			}
// Брой блокови коментари
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

// Брой цикли от файл
int cycle (int count)
{
	FILE *file;
	unsigned int i;
	int flag1 = 0, flag2 = 0, flag3 = 0;
	char fname [1024], fp [1024];
	printf ("Адрес на файла, от който ще се броят цикли:\n");
		fgets (fname, 1024, stdin);
		fname [strlen (fname) - 1] = '\0';
// Проверка за окончанието
		if ((fname [strlen(fname) - 2] != '.') || (fname [strlen(fname) - 1] != 'c'))
		{
			printf ("Файлът не е с окончание \".c\"! \n");
			exit (1);
		}
		else
		file = fopen (fname, "r");
// Проверка - отворен ли е файлът
	if (file == NULL)
	{
		printf ("Файлът не може да се отвори за четене.\n");
		exit(1);
	}
	while ((fgets (fp, 1024, file)) != NULL)
	{
		for (i=0; i < strlen(fp); i++)
		{
// Изключване на някои възможности
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
// Брой цикли
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


// Броене на коментари от клавиатурата
int Pcomment (int num)
{
	unsigned int i;
	int flag1 = 0, flag2 = 0;
	char fp [1024];
	printf ("Въведете кода, от който ще се броят коментари:\n");
	while ((fgets (fp, 1024, stdin)) != NULL)
	{
		for (i=0; i < strlen(fp); i++)
		{
// Изключване на някой възможности
			if (!flag1 && !flag2 && fp [i] == '"' && fp [i-1] != '\\' && fp [i-1] != '\'' && fp [i+1] != '\'')
			{
				flag2 = 1;
			}
			else if (!flag1 && flag2 && fp [i] == '"' && fp [i-1] != '\\' && fp [i-1] != '\'' && fp [i+1] != '\'')
			{
				flag2 = 0;
			}
// Брой линейни коментари
			if (!flag2 && !flag1 && (fp [i] == '/' && fp [i+1] == '/') && ( fp [strlen(fp) - 1] == '\n'))
			{
				num++;
				break;
			}
// Брой блокови коментари
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


// Брой на цикли от клавиатурата
int Pcycle (int count)
{
	unsigned int i;
	int flag1 = 0, flag2 = 0, flag3 = 0;
	char fp [1024];
	printf ("Въведете кода, от който ще се броят цикли:\n");
	while ((fgets (fp, 1024, stdin)) != NULL)
	{
		for (i=0; i < strlen(fp); i++)
		{
// Изключване на някои възможности
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
// Брой цикли
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
