#include <stdio.h>
#define N 100

//структура
struct abonent
{
	char name[10];
	char second_name[10];
	char tel[10];
};

//вывод главному меню
void Func_PrintMainMenu()
{
	printf("1) Добавить абонента\n");
	printf("2) Удалить абонента\n");
	printf("3) Поиск абонентов по имени\n");
	printf("4) Вывод всех записей\n");
	printf("5) Выход\n");
	printf("Выберите действие: ");
}

//после создания массива зануляем
void Func_ResetArray(struct abonent *p)
{
	int i, j;
	for(i=0; i<N; i++)
	{
		for(j=0; j<10; j++)
		{
			p[i].name[j]='\0';
			p[i].second_name[j]='\0';
			p[i].tel[j]='\0';
		}
	}
}

//функция для вывода элементов структуры
void Func_PrintElementStruct(char *p)
{
	int i;
	for(i=0; i<10; i++)
	{
		printf("%c", p[i]);
	}
	printf("\n");
}

//функция вывода всех записей
void Func_PrintArray(struct abonent *p)
{
	int i;
	char NoAbonents='t';
	for(i=0; i<N; i++)
	{
		if(p[i].name[0]!='\0')
		{
			printf("\n");
			printf("Name:\t");
			Func_PrintElementStruct(p[i].name);
			printf("Second Name:\t");
			Func_PrintElementStruct(p[i].second_name);
			printf("Telephone:\t");
			Func_PrintElementStruct(p[i].tel);
			NoAbonents='f';
		}
	}
	if(NoAbonents=='t')
	{
		printf("Список пуст!\n");
	}
	else
	{
		printf("\n");
	}
}


//функция возвращающая указатель на свободную структуру для записи нового абонента
struct abonent* Func_GetFreeElement(struct abonent **p)
{
	struct abonent *array=*p;
	struct abonent *ptr=NULL;
	int i, j;
	
	for(i=0; i<N; i++)
	{
		ptr=&array[i];
		for(j=0; j<10; j++)
		{
			if(array[i].name[j]!='\0')
			{
				ptr=NULL;
				break;
			}
		}
		if(ptr!=NULL)
		{
			break;
		}
	}
	return ptr;
}

//фуннкция заполняющая элементы структуры
void Func_InsertElementAbonent(char *p, int numberElement)
{
	int i;
	char c;
	switch(numberElement)
	{
		case 1:
			printf("\nВведите имя:\t");
			scanf("%c", &c);
		break;
		case 2:
			printf("\nВведите фамилию:\t");
		break;
		case 3:
			printf("\nВведите телефон:\t");
		break;
	}
	for(i=0; i<10; i++)
	{
		scanf("%c", &c);
		if(c=='\n')
		{
			break;
		} 
		else
		{
			p[i]=c;
		}
	}
}

//функция для добавления абонента
void Func_InsertAbonent(struct abonent *array)
{
	struct abonent *p=NULL;
	p=Func_GetFreeElement(&array);
	if(p!=NULL)
	{
		Func_InsertElementAbonent(p->name, 1);
		Func_InsertElementAbonent(p->second_name, 2);
		Func_InsertElementAbonent(p->tel, 3);
	}
	else
	{
		printf("Список заполнен!\n");
	}
}

//функция возвращаюся указатель на структуру с именем, которое ввел пользователь для удаления
struct abonent* Func_FindAbonentFromName(struct abonent **pp, char *p)
{
	struct abonent *array=*pp;
	struct abonent *ptr=NULL;
	int i, j;
	for(i=0; i<N; i++)
	{
		ptr=&array[i];
		for(j=0; j<10; j++)
		{
			if(array[i].name[j]!=p[j])
			{
				ptr=NULL;
				break;
			}
		}
		if(ptr!=NULL)
		{
			break;
		}
	}
	return ptr;
}

//функция зануляющая элементы структуры
void Func_DeleteElementAbonent(char *p)
{
	int i;
	for(i=0; i<10; i++)
	{
		p[i]='\0';
	}
}

//функция инициирующая удаление абонента
void Func_DeleteAbonent(struct abonent* array)
{
	struct abonent *p=NULL;
	char Find_Name[10]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char c;
	int i;
	char MoreOne='f';
	scanf("%c", &c);
	printf("Введите имя абонента для удаления:\t");
	for(i=0; i<10; i++)
	{
		scanf("%c", &c);

		if(c=='\n')
		{
			break;
		} 
		else
		{
			Find_Name[i]=c;
		}
	}
	while(1)
	{
		p=Func_FindAbonentFromName(&array, Find_Name);
		if(p!=NULL)
		{
			Func_DeleteElementAbonent(p->name);
			Func_DeleteElementAbonent(p->second_name);
			Func_DeleteElementAbonent(p->tel);
			MoreOne='t';
			printf("Абонент удален!\n");
		}
		else if(MoreOne=='t')
		{
			printf("Больше абонентов с таким именем нет!\n");
			break;
		}
		else
		{
			printf("Абонент не найден!\n");
			break;
		}
	}
	
}

//функция, которая находит записи с именем, которое ввел пользователь, и выводит на экран
void Func_FindAndPrintAbonentFromName(struct abonent **pp, char *p)
{
	struct abonent *array=*pp;
	struct abonent *ptr=NULL;
	int i, j;
	for(i=0; i<N; i++)
	{
		ptr=&array[i];
		for(j=0; j<10; j++)
		{
			if(array[i].name[j]!=p[j])
			{
				ptr=NULL;
				break;
			}
		}
		if(ptr!=NULL)
		{
			printf("\n");
			printf("Name:\t");
			Func_PrintElementStruct(ptr->name);
			printf("Second Name:\t");
			Func_PrintElementStruct(ptr->second_name);
			printf("Telephone:\t");
			Func_PrintElementStruct(ptr->tel);
		}
	}
	printf("\n");
}

//функция инициирующая поиск записей по имени
void Func_FindFromName(struct abonent *array)
{
	struct abonent *p=NULL;
	char Find_Name[10]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char c;
	int i;
	char MoreOne='f';
	scanf("%c", &c);
	printf("Введите имя абонента для поиска:\t");
	for(i=0; i<10; i++)
	{
		scanf("%c", &c);

		if(c=='\n')
		{
			break;
		} 
		else
		{
			Find_Name[i]=c;
		}
	}
	Func_FindAndPrintAbonentFromName(&array, Find_Name);
}

int main()
{
	struct abonent ListAbonents[N];
	Func_ResetArray(ListAbonents);
	int n=0;
	while(n!=5)
	{
		Func_PrintMainMenu();
		scanf("%d", &n);
		switch(n)
		{
			case 1:
				Func_InsertAbonent(ListAbonents);	
			break;
			case 2:
				Func_DeleteAbonent(ListAbonents);	
			break;
			case 3:
				Func_FindFromName(ListAbonents);	
			break;
			case 4:
				Func_PrintArray(ListAbonents);	
			break;
			case 5:
			break;
		}
	}
}
