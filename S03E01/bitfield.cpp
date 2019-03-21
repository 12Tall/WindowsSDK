#include <stdio.h>

struct Samp
{
	unsigned char m;
	unsigned char n : 4;
	unsigned char o : 4;
};
struct NSamp
{
	unsigned char m;
	unsigned char n;
};

int main(int argc, char* argv[])
{
	printf("%d\n", sizeof(Samp));
	// ���2 (�ӽ�)
	struct Samp samp = { 0x12,0x34,0x56 };
	// 64 12 ѹջ˳���Ժ���ǰ
	struct NSamp ns = { 0x12,0x34 };
	printf("m:%p;n:%p;\n", &ns.m,&ns.n);


	printf("m:%d;n:%d;o:%d\n", samp.m,samp.n,samp.o);
	// ���m:18;n:5;o:6
	void * p = &samp;
	unsigned char * c = (unsigned char*)p;
	printf("m:%d;n:%d\n", *c, *(c+1));
	// ���m:18;n:5;o:6
	return 0;
}
