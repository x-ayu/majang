#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include"masd.h"

struct names	 _Interface(void) {
	char RRWar[] = { "1.���˶�ս" };
	char RJWar[] = { "2.�˻���ս" };
	char Playback[] = { "3.��ʷ�ط�" };
	char Gane_end[] = { "4.�˳���Ϸ" };
	int Input1, Input2=0, Output1='\40', Output2=1;

	
	printf("ѡ����Ϸģʽ��\n");
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
			printf("ѡ����Ϸģʽ��\n");
			printf_s("%c", Output1);
			printf_s("%s\n", RRWar);
			printf_s("%s\n", RJWar);
			printf_s("%s\n", Playback);
			printf_s("%s\n", Gane_end);
		}break;
			
		case 2:{system("cls");
			printf("ѡ����Ϸģʽ��\n");
			printf_s("%s\n", RRWar);
			printf_s("%c", Output1);
			printf_s("%s\n", RJWar);
			printf_s("%s\n", Playback);
			printf_s("%s\n", Gane_end);
		}break;
		case 3: {system("cls");
			printf("ѡ����Ϸģʽ��\n");
			printf_s("%s\n", RRWar);
			printf_s("%s\n", RJWar);
			printf_s("%c", Output1);
			printf_s("%s\n", Playback);
			printf_s("%s\n", Gane_end);
		}break;
		case 4: {system("cls");
			printf("ѡ����Ϸģʽ��\n");
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
		printf("ѡ�������˶�ս\n�������1������");scanf_s("%s", &name.PlayersName1,24);
		printf("�������2������"); scanf_s("%s", &name.PlayersName2,24);
		printf("�������3������"); scanf_s("%s", &name.PlayersName3,24);
		printf("�������4������"); scanf_s("%s", &name.PlayersName4,24);	
	}
	if (Output2 == 2)   {
		system("cls");
		printf("ѡ�����˻���ս\n");
		char* nas[4] = { {"1"},{"2"},{"3"},{"4"} };
		
	Output1= ChOutput(nas, 4, 0, 0, 1, 3);
	while (Output1)
		{
		    system("cls");
			static int i =1 ;
			printf("�������%d������", i);
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
		printf("ѡ������ʷ�طţ�");
	}
	return name;
}

	