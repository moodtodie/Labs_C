// Lab7_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define PARTICIPANTS 30

struct member {
	char* country;
	char* team;
	char* fio;
	int numder;
	int age;
	int height;
	float weight;
};

struct team {
	char* country;
	char* team;
	int numbers = 0;
	float avg_age = 0;
	float avg_height = 0;
	float avg_weight = 0;
};

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	int k, num_teams = 4;
	struct member info[PARTICIPANTS];
	struct team info_team[4];

	char fio[] = "FIO";

	char rf[] = "Russia";
	char us[] = "USA";

	char team_A[] = "Alpha";
	char team_B[] = "Динамо";
	char team_C[] = "Alpha";
	char team_D[] = "Wild";

	printf("Введие кол-во участников:");
	scanf_s("%d", &k);

	for (int i = 0; i < k; i++)		//	Ввод информации о участниках
	{
		if ((rand() % 20) % 2 == 0) {
			info[i].country = rf;
		}
		else info[i].country = us;


		if (info[i].country == rf)
		{
			if ((rand() % 20) % 2 == 0) { info[i].team = team_A; }
			else info[i].team = team_B;
		}
		else {
			if ((rand() % 20) % 2 == 0) { info[i].team = team_C; }
			else info[i].team = team_D;
		}
		info[i].fio = fio;
		info[i].numder = (100 + rand() % 900);
		info[i].age = (22 + rand() % 29);
		info[i].height = (165 + rand() % 46);
		info[i].weight = ((double)(660 + rand() % 220)) / 10;
	}

	for (int i = 0; i < k; i++)		//	Вывод инворации о всех участниках
	{
		printf("Страна: %s\n", info[i].country);
		printf("Команда: %s\n", info[i].team);
		printf("ФИО: %.3s\n", info[i].fio);
		printf("Номер: %d\n", info[i].numder);
		printf("Возрост: %d\n", info[i].age);
		printf("Рост: %d\n", info[i].height);
		printf("Вес: %.1f\n", info[i].weight);
		printf("\n");
	}

	info_team[0].team = team_A; info_team[1].team = team_B;
	info_team[2].team = team_C; info_team[3].team = team_D;
	info_team[0].country = info_team[1].country = rf;
	info_team[2].country = info_team[3].country = us;

	//	---------------------------------------------------------------------------------------------------------

	for (int i = 0; i < k; i++)		//	Находим сумму возростов (и др.) и кол-во участников всех команд
	{
		for (int j = 0; j < num_teams; j++)
		{
			if (info[i].team == info_team[j].team && info[i].country == info_team[j].country) {
				info_team[j].avg_age += info[i].age;
				info_team[j].avg_height += info[i].height;
				info_team[j].avg_weight += info[i].weight;
				info_team[j].numbers++;
			}
		}
	}

	for (int i = 0; i < num_teams; i++) {			//	Нахождение средних покозателей
		info_team[i].avg_age /= info_team[i].numbers;
		info_team[i].avg_height /= info_team[i].numbers;
		info_team[i].avg_weight /= info_team[i].numbers;
	}

	float youngest_avg_age = info_team[0].avg_age;
	for (int i = 1; i < num_teams; i++)		//	Поиск самой молодой команды
	{
		if (youngest_avg_age > info_team[i].avg_age) youngest_avg_age = info_team[i].avg_age;
	}

	for (int i = 0; i < num_teams; i++)		//	Вывод инфорации о участниках самой молодой комманды
	{
		if (info_team[i].avg_age == youngest_avg_age) {
			printf("\n	Информация о самой молодой коммманде:\n");
			printf("Страна:		%s\n", info_team[i].country);
			printf("Команда:	%s\n", info_team[i].team);
			printf("Ср. возрост:	%.1f\n", info_team[i].avg_age);
			printf("Ср. рост:	%.1f\n", info_team[i].avg_height);
			printf("Ср. вес:	%.1f\n", info_team[i].avg_weight);
		}
	}

	_getch();
	return 0;
}