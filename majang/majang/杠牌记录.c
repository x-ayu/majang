#include"masd.h"
void GangRecord(char *szBarRecord, SOUP TEMPORARCARDS)
{
	for(int intLS = 0; intLS<9; intLS++)
	{
		if (szBarRecord[intLS]=='\0')
		{
			szBarRecord[intLS - 1] = TEMPORARCARDS.inSerial+'0';
			szBarRecord[intLS] = TEMPORARCARDS.chSign;
			szBarRecord[intLS + 1] = '\040';
			szBarRecord[intLS + 2] = '\0';
			break;
		}
	}
}