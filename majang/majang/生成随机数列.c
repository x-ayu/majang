#include<stdlib.h>
#include<time.h>
#include<stdio.h>

int* AloneRandom(int  number, int* Target) {
	int num1, num2 = 0, num3 = 0;
	int * numb1;//�㣿���������������𣿣�  num1? numb1?
	int i;
	int fg = 0;

	numb1 = (int*)malloc(sizeof(int)*number);

	if (numb1 == NULL) {
		//ע��:�뷵�ش�����Ϣ
		exit(1);
	}

	for (/*size_t*/ i = 0; i < number /*number - 1*/ /*����ط����Գ�ʼ�������ˣ�����һ��*/; i++) {
		/*(Target + i) = 1;*/Target[i] = 1;
	}

	srand(clock());

	for (fg = 0; number != -1; fg++)/*while (1)*/ /*for(;;)����ʹ�������*/
	{
		//static int fg = 0;ע��:�ں�����ͷ���������Ǹ����÷��

		//srand(clock());srand(clock())���������õģ���ϰһ������ĵ���

		if (number == 0) {
			num1 = 0;
			number--;
		}
		else {
			num1 = rand() % number + 1;//num1 = rand() / number + 1;��ȷ������%�ţ���
			number--;
		}//;����ķֺ�

		for (;;)/*while (1)*/ /*for(;;)����ʹ�������*/
		{
			num2 = num2 + numb1[num3] /**(numb1 + num3)*/;//�ڴ���ʴ��� //��:numb1����δ��ʼ�����������������ȴ��ʹ����
			num3++;

			//STRAT
			//��һ�����Լ����Ķ��𣿣���
			if (num2 == num1)//ע������
			{
				Target[fg] = num3;// *(Target + fg) = num3;
				numb1[num3];// *(numb1 + num3) = 0;
				num3 = 0;

				puts("ssaas");
				break;
			}
			//if (num2 == num1)break;//����б�Ҫ�𣿣�
			//END


		}
		//fg++;
		//if (number == -1)break;һ��for()���Խ����ĺܶ��鷳
	}

	//δ���malloc()������ڴ�

	return*Target;
}