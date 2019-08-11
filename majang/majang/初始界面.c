#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include"masd.h"

struct names	 _Interface(void) {
	char RRWar[] = { "1.人人对战" };
	char RJWar[] = { "2.人机对战" };
	char Playback[] = { "3.历史回放" };
	char Gane_end[] = { "4.退出游戏" };
	int Input1, Input2=0, Output1='\40', Output2=1;

	
	printf("选择游戏模式：\n");
	printf_s("%c", Output1);
	printf_s("%s\n", RRWar);
	printf_s("%s\n", RJWar);
	printf_s("%s\n", Playback);
	printf_s("%s\n", Gane_end);
	for (;;)
	{
		for(;;)
		{
			Input1 = _getch();
			if (Input1 == 13) break;
			Input2 = _getch(); 
			if (Input1 == 224) { if ((Input2 == 72) || (Input2 == 80))break; }
		}
		if (Input1 == 13)break;
		if ((Input2==80)&&Output2<4)
		{
			Output2++;
		}
		else if ((Input2 == 72)&&Output2>0) {
			Output2--;
		}
		switch(Output2)
		{
		case 0:;
		case 1: {
			system("cls");
			printf("选择游戏模式：\n");
			printf_s("%c", Output1);
			printf_s("%s\n", RRWar);
			printf_s("%s\n", RJWar);
			printf_s("%s\n", Playback);
			printf_s("%s\n", Gane_end);
		}break;
			
		case 2:{system("cls");
			printf("选择游戏模式：\n");
			printf_s("%s\n", RRWar);
			printf_s("%c", Output1);
			printf_s("%s\n", RJWar);
			printf_s("%s\n", Playback);
			printf_s("%s\n", Gane_end);
		}break;
		case 3: {system("cls");
			printf("选择游戏模式：\n");
			printf_s("%s\n", RRWar);
			printf_s("%s\n", RJWar);
			printf_s("%c", Output1);
			printf_s("%s\n", Playback);
			printf_s("%s\n", Gane_end);
		}break;
		case 4: {system("cls");
			printf("选择游戏模式：\n");
			printf_s("%s\n", RRWar);
			printf_s("%s\n", RJWar);
			printf_s("%s\n", Playback);
			printf_s("%c", Output1);
			printf_s("%s\n", Gane_end);
		}break;
		}
		
	}
	struct  names name;
	name.Mode = Output2;
	if (Output2 == 1) {
		system("cls");
		printf("选择了人人对战\n输入玩家1姓名：");scanf_s("%s", &name.PlayersName1,24);
		printf("输入玩家2姓名："); scanf_s("%s", &name.PlayersName2,24);
		printf("输入玩家3姓名："); scanf_s("%s", &name.PlayersName3,24);
		printf("输入玩家4姓名："); scanf_s("%s", &name.PlayersName4,24);	
	}
	if (Output2 == 2)   {
		system("cls");
		printf("选择了人机对战\n");
		char* nas[4] = { {"1"},{"2"},{"3"},{"4"} };
		
	Output1= ChOutput(nas, 4, 0, 0, 1, 3);
	while (Output1)
		{
		    system("cls");
			static int i =1 ;
			printf("输入玩家%d姓名：", i);
			if (i == 1)
				scanf_s("%s", &name.PlayersName1, 24);
			if (i == 2)
				scanf_s("%s", &name.PlayersName2, 24);
			if (i == 3)
				scanf_s("%s", &name.PlayersName3, 24);
			if (i == 4)
				scanf_s("%s", &name.PlayersName4, 24);
			i++;
			Output1--;
		}
	}
	if (Output2==3)
	{
		system("cls");
		printf("选择了历史回放：");
	}
	return name;
}

	