#include <stdlib.h>
typedef struct _scratchromsize
{
	unsigned char	scratchbuf[255];
} scratchromsize_s;

void RamCode(void)
{

}


void copyromtomem(void)
{
	unsigned char i;
	
	scratchromsize_s *src;
	scratchromsize_s *dest;	
	dest = malloc(1000);
	src = (scratchromsize_s *)(RamCode);

	for( i = 0; i < sizeof(scratchromsize_s); i++)
	{
		dest->scratchbuf[i] = src->scratchbuf[i];
	}
	free(dest);
}

void copyromtomem1(void)
{
	unsigned char i;
	
	unsigned char *src;
	unsigned char *dest;	
	dest = malloc(1000);
	src = (void *)(RamCode);

	for( i = 0; i < 255; i++)
	{
		//dest->scratchbuf[i] = src->scratchbuf[i];
		*dest = *src;
		dest++;
		src++;
	}
	free(dest);
}

int main(void)
{
	 copyromtomem();
	 copyromtomem1();
	 return 0;
}


