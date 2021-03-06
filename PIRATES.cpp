#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

void SetCount(int iDivider) {
	outp(0x43, 0xB6); 
	long kd = 1193180 / iDivider; 
	outp(0x42, kd % 256); 
	outp(0x42, (long)(kd / 256)); 
	return;
}
int main() {
	int i;
	printf("Ready\n");
	delay(500);
	unsigned int D_note = 587;
	int DT[25] = {270, 125, 270, 125, 270, 125, 125, 125, 125, 270, 125, 270, 125, 270, 125, 125, 125, 125, 270, 125, 270, 125, 270, 125, 125};
	for ( i = 0; i < 25; i++) {
		SetCount(D_note);
		outp(0x61, inp(0x61) | 0x03);
		delay(DT[i]);
		outp(0x61, inp(0x61) & 0xFC);
		delay(DT[i] / 10);
	}

	int first[16] = { 440, 523, 587, 587, 587, 659, 698, 698, 698, 784, 659, 659, 587, 523, 523, 587};
     	int first_t[16] = { 125, 125, 270, 270, 125, 125, 270, 270, 125, 125, 270, 270, 125, 125, 125, 270};
	for (i = 0; i < 16; i++) 
	{
		SetCount(first[i]);
		outp(0x61, inp(0x61) | 0x03);
		delay(first_t[i]); 
		outp(0x61, inp(0x61) & 0xFC);
		delay(first_t[i] / 10);
	}delay(120);

	int second[15] = { 440, 523, 587, 587, 587, 659, 698, 698, 698, 784, 659, 659, 687, 523, 587};
      int second_t[15] = { 125, 125, 270, 270, 125, 125, 270, 270, 125, 125, 270, 270, 125, 125, 270};
	
	for (i = 0; i < 15; i++) 
	{
		SetCount(second[i]);
		outp(0x61, inp(0x61) | 0x03);
		delay(second_t[i]); 
		outp(0x61, inp(0x61) & 0xFC);
		delay(second_t[i] / 10);
	}delay(70);

	int third[30] = { 440, 523, 587, 587, 587, 698, 784, 784, 784, 880, 932, 932, 880, 784, 880, 587, 587, 659, 698, 698, 784, 880, 587, 587, 698, 659, 659, 698, 587, 659 };
      int third_t[30] = { 270, 125, 270, 270, 125, 125, 270, 270, 125, 125, 270, 270, 125, 125, 125, 270, 125, 125, 270, 270, 270, 125, 270, 125, 125, 270, 270, 125, 125, 270};

	for (i = 0; i < 30; i++) 
	{
		SetCount(third[i]);
		outp(0x61, inp(0x61) | 0x03);
		delay(third_t[i]); 
		outp(0x61, inp(0x61) & 0xFC);
		delay(third_t[i] / 10);
		if (i == 16 || i == 23) delay(125);
	}delay(50);



	int forth[16] = { 880, 1047, 1175, 1175, 1175, 1319, 1397, 1397, 1397, 1568, 1319, 1319, 1175, 1047, 1047, 1175 };
      int forth_t[16] = { 270, 125, 270, 270, 125, 125, 270, 270, 125, 125, 270, 270, 125, 125, 125, 270};

	for (i = 0; i < 16; i++) 
	{
		SetCount(forth[i]);
		outp(0x61, inp(0x61) | 0x03);
		delay(forth_t[i]); 
		outp(0x61, inp(0x61) & 0xFC);
		delay(forth_t[i] / 10);
		if (i == 16 || i == 23) delay(125);
	}delay(50);

	int fifth[45] = { 880, 1047, 1175, 1175, 1175, 1319, 1397, 1397, 1397, 1568, 1319, 1319, 1175, 1047, 1175, 880, 1047, 1175, 1175, 1175, 1397, 1568, 1568, 1568, 1720, 1865, 1865, 1720, 1568, 1720, 1175, 1175, 1319, 1397, 1397, 1568, 1720, 1175, 1175, 1397, 1319, 1319, 1175, 1047, 1175 };
      int fifth_t[45] = { 125, 125, 270, 270, 125, 125, 270, 270, 125, 125, 270, 270, 125, 125, 270, 125, 125, 270, 270, 125, 125, 270, 270, 125, 125, 270, 270, 125, 125, 125, 270, 125, 125, 270, 270, 270, 125, 270, 125, 125, 270, 270, 125, 125, 270 };

	for (i = 0; i < 45; i++) 
	{
		SetCount(fifth[i]);
		outp(0x61, inp(0x61) | 0x03);
		delay(fifth_t[i]); 
		outp(0x61, inp(0x61) & 0xFC);
		delay(fifth_t[i] / 10);
		if (i == 15) delay(270);
		if (i == 31 || i == 38) delay(125);
	}

        int sixth[18] = { 1175, 1319, 1397, 1397, 1397, 1568, 1720, 1397, 1175, 880, 1865, 1865, 1568, 1175, 932, 587, 587, 554 };
      int sixth_t[18] = { 270, 270, 270, 125, 125, 270, 570, 125, 125, 570, 270, 270, 125, 125, 570, 450, 450, 570 };

	for (i = 0; i < 18; i++) 
	{
		SetCount(sixth[i]);
		outp(0x61, inp(0x61) | 0x03);
		delay(sixth_t[i]); 
		outp(0x61, inp(0x61) & 0xFC);
		delay(sixth_t[i] / 10);
		if (i == 10 || i == 14) delay(120);
	}delay(70);
	return 0;
}

	