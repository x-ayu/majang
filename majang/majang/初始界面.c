#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include"masd.h"

NAMES _Interface(void) {
	char szRRWar[] = { "1.���˶�ս" };
	char szRJWar[] = { "2.�˻���ս" };
	char szPlayback[] = { "3.��ʷ�ط�" };
	char szGane_end[] = { "4.�˳���Ϸ" };
	int intInput1, intInput=0, intOutput1='\40', intOutput=1;
	NAMES name;
	char* nas[4] = { {"1"},{"2"},{"3"},{"4"} };
	
	printf("ѡ����Ϸģʽ��\n");
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
				printf("ѡ����Ϸģʽ��\n");
				printf_s("%c", intOutput1);
				printf_s("%s\n", szRRWar);
				printf_s("%s\n", szRJWar);
				printf_s("%s\n", szPlayback);
				printf_s("%s\n", szGane_end);
				break;
			}
			case 2:{
				system("cls");
				printf("ѡ����Ϸģʽ��\n");
				printf_s("%s\n", szRRWar);
				printf_s("%c", intOutput1);
				printf_s("%s\n", szRJWar);
				printf_s("%s\n", szPlayback);
				printf_s("%s\n", szGane_end);
				break;
			}
			case 3: {
				system("cls");
				printf("ѡ����Ϸģʽ��\n");
				printf_s("%s\n", szRRWar);
				printf_s("%s\n", szRJWar);
				printf_s("%c", intOutput1);
				printf_s("%s\n", szPlayback);
				printf_s("%s\n", szGane_end);
				break;
			}
			case 4: {
				system("cls");
				printf("ѡ����Ϸģʽ��\n");
				printf_s("%s\n", szRRWar);
				printf_s("%s\n", szRJWar);
				printf_s("%s\n", szPlayback);
				printf_s("%c", intOutput1);
				printf_s("%s\n", szGane_end);
				break;
			}
			default: {
				fprintf(stderr, "��Ϸѡ�����(1)");
				exit(1);
			}
		}
	}

	name.intMode = intOutput;

	if (intOutput == 1) {
		system("cls");
		printf("ѡ�������˶�ս\n�������1������");scanf_s("%s", &name.szPlayersName1,24);
		printf("�������2������"); scanf_s("%s", &name.szPlayersName2,24);
		printf("�������3������"); scanf_s("%s", &name.szPlayersName3,24);
		printf("�������4������"); scanf_s("%s", &name.szPlayersName4,24);	
	}

	if (intOutput == 2)   {
		system("cls");
		printf("ѡ�����˻���ս\n");
		
		intOutput1= ChOutput(nas, 4, 0, 0, 1, 3);

		while (intOutput1)
		{
		    system("cls");
			static int i =1 ;

			printf("�������%d������", i);
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
		printf("ѡ������ʷ�طţ�");
	}

	return name;
}