#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"masd.h"
#include <ctype.h>
void FaPi(SOUP namm[13],int as)
{
	for (int i = 0;; i++)
	{
		namm[i] = Distribute(as);
		if (i == 13)break;
	}
}
int main(void)
{
	int as[136];
	AloneRandom(136, as);
	 NAMES  WJ;
	WJ = _Interface();
	 SOUP pName1[13];
	 SOUP pName2[13];
	 SOUP pName3[13];
	 SOUP pName4[13];
	FaPi(pName1, as); FaPi(pName2, as); FaPi(pName3, as); FaPi(pName4, as); //为每个玩家发牌
	Sequence(pName1); Sequence(pName2);Sequence(pName3); Sequence(pName4); //调整手牌序列
	if (WJ.intMode == 1)
	{

	}
	return 0;
}
