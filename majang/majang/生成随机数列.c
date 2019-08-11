#include<stdlib.h>
#include<time.h>
#include<stdio.h>

int* AloneRandom(int  number, int* Target) {
	int num1, num2 = 0, num3 = 0;
	int * numb1;//你？？？这样命名的吗？？  num1? numb1?
	int i;
	int fg = 0;

	numb1 = (int*)malloc(sizeof(int)*number);

	if (numb1 == NULL) {
		//注意:请返回错误信息
		exit(1);
	}

	for (/*size_t*/ i = 0; i < number /*number - 1*/ /*这个地方明显初始化错误了，少了一个*/; i++) {
		/*(Target + i) = 1;*/Target[i] = 1;
	}

	srand(clock());

	for (fg = 0; number != -1; fg++)/*while (1)*/ /*for(;;)可以使代码更好*/
	{
		//static int fg = 0;注意:在函数开头声明变量是个良好风格

		//srand(clock());srand(clock())不是这样用的，复习一下随机的调用

		if (number == 0) {
			num1 = 0;
			number--;
		}
		else {
			num1 = rand() % number + 1;//num1 = rand() / number + 1;你确定不是%号？？
			number--;
		}//;多余的分号

		for (;;)/*while (1)*/ /*for(;;)可以使代码更好*/
		{
			num2 = num2 + numb1[num3] /**(numb1 + num3)*/;//内存访问错误 //答案:numb1内容未初始化，在这里这个数组却被使用了
			num3++;

			//STRAT
			//这一段你自己看的懂吗？？？
			if (num2 == num1)//注意缩进
			{
				Target[fg] = num3;// *(Target + fg) = num3;
				numb1[num3];// *(numb1 + num3) = 0;
				num3 = 0;

				puts("ssaas");
				break;
			}
			//if (num2 == num1)break;//这个有必要吗？？
			//END


		}
		//fg++;
		//if (number == -1)break;一个for()可以解决你的很多麻烦
	}

	//未清除malloc()申请的内存

	return*Target;
}