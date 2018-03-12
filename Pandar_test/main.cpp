#include "LidarTools.h"

#include <stdio.h>

int main(int argc , char** argv)
{
	unsigned char RGB[3];

	int i = 0;
	for(i = 0 ; i < 255 ; i++)
	{
		HS_getColorMapFromIntensity(i * 256 , RGB);
		printf("%03d R : %03d G : %03d , B : %03d\n", i, RGB[0] , RGB[1] , RGB[2]);
	}
	return 0;
}
