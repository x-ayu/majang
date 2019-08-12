#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include"masd.h"

NAMES _Interface(void) {
	char szRRWar[] = { "1.人人对战" };
	char szRJWar[] = { "2.人机对战" };
	char szPlayback[] = { "3.历史回放" };
	char szGane_end[] = { "4.退出游戏" };
	int intInput1, intInput=0, intOutput1='\40', intOutput=1;
	NAMES name;
	char* nas[4] = { {"1"},{"2"},{"3"},{"4"} };
	
	printf("选择游戏模式：\n");
	printf_s("%c", intOutput1);
	printf_s("%s\n", szRRWar);
	printf_s("%s\n", szRJWar);
	printf_s("%s\n", szPlayback);
	printf_s("%s\n", szGane_end);

	for (;;)
	{
		for(;;)
		{
			intInput1 = _getch();
			if (intInput1 == 13) 
				break;

			intInput = _getch(); 

			if (intInput1 == 224) { 
				if ((intInput == 72) || (intInput == 80))
					break; 
			}
		}

		if (intInput1 == 13)
			break;

		if ((intInput==80)&&intOutput<4)
		{
			intOutput++;
		}
		else if ((intInput == 72)&&intOutput>0) {
			intOutput--;
		}

		switch(intOutput)
		{
			case 0:
			case 1: {
				system("cls");
				printf("选择游戏模式：\n");
				printf_s("%c", intOutput1);
				printf_s("%s\n", szRRWar);
				printf_s("%s\n", szRJWar);
				printf_s("%s\n", szPlayback);
				printf_s("%s\n", szGane_end);
				break;
			}
			case 2:{
				system("cls");
				printf("选择游戏模式：\n");
				printf_s("%s\n", szRRWar);
				printf_s("%c", intOutput1);
				printf_s("%s\n", szRJWar);
				printf_s("%s\n", szPlayback);
				printf_s("%s\n", szGane_end);
				break;
			}
			case 3: {
				system("cls");
				printf("选择游戏模式：\n");
				printf_s("%s\n", szRRWar);
				printf_s("%s\n", szRJWar);
				printf_s("%c", intOutput1);
				printf_s("%s\n", szPlayback);
				printf_s("%s\n", szGane_end);
				break;
			}
			case 4: {
				system("cls");
				printf("选择游戏模式：\n");
				printf_s("%s\n", szRRWar);
				printf_s("%s\n", szRJWar);
				printf_s("%s\n", szPlayback);
				printf_s("%c", intOutput1);
				printf_s("%s\n", szGane_end);
				break;
			}
			default: {
				fprintf(stderr, "游戏选择出错(1)");
				exit(1);
			}
		}
	}

	name.intMode = intOutput;

	if (intOutput == 1) {
		system("cls");
		printf("选择了人人对战\n输入玩家1姓名：");scanf_s("%s", &name.szPlayersName1,24);
		printf("输入玩家2姓名："); scanf_s("%s", &name.szPlayersName2,24);
		printf("输入玩家3姓名："); scanf_s("%s", &name.szPlayersName3,24);
		printf("输入玩家4姓名："); scanf_s("%s", &name.szPlayersName4,24);	
	}

	if (intOutput == 2)   {
		system("cls");
		printf("选择了人机对战\n");
		
		intOutput1= ChOutput(nas, 4, 0, 0, 1, 3);

		while (intOutput1)
		{
		    system("cls");
			static int i =1 ;

			printf("输入玩家%d姓名：", i);
			if (i == 1)
				scanf_s("%s", &name.szPlayersName1, 24);
			if (i == 2)
				scanf_s("%s", &name.szPlayersName2, 24);
			if (i == 3)
				scanf_s("%s", &name.szPlayersName3, 24);
			if (i == 4)
				scanf_s("%s", &name.szPlayersName4, 24);
			i++;
			intOutput1--;
		}
	}

	if (intOutput==3)
	{
		system("cls");
		printf("选择了历史回放：");
	}

	return name;
}