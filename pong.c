#include <stdio.h>

#define shirina 79
#define visota 24
int D = 1;
int Y = 1;
char pole[visota][shirina];
void clrscr();
void init_pole();
void put_raketka1(int k);
void put_raketka2(int k);
void  mb(int x, int y);
void risuem_pole();
char read_a();
int f1(int x);
int f2(int y, int x);

int main()
{ int score1, score2;
score1 = 0;
score2 = 0;
int i1 = 0;
int i2 = 0;
int x = 10;
int y = 40;
char a;
do
{clrscr();
init_pole();
put_raketka1(i1);
put_raketka2(i2);
mb(x, y);
risuem_pole();
a = read_a();
if (a == ' ') {x = f1(x);
y = f2(y, x);
} else {if (a == 'a') {if (i1 > -10) i1--;
x = f1(x); y = f2(y, x);
}
if (a == 'z') {if (i1 < 10) i1++;
x = f1(x); y = f2(y, x);
}
if (a == 'k') {if (i2 > -10) i2--;
x = f1(x);
y = f2(y, x);
}
if (a == 'm') {if (i2 < 10) i2++;
x = f1(x);
y = f2(y, x);
}
}
if(y == 78 || y == 1) {if (y == 1) score2++;
if(y == 78) score1++;
x = 10; y = 40;
}
} while (a != 'q' && score1 < 7 && score2 < 7);
if(score1 > score2) {printf("LEFT PLAYER WIN %d - %d", score1, score2);
} else {printf("RIGHT PLAYER WIN %d - %d", score1, score2);
}
return 0;
}
char read_a()
{char a;
a = getchar();
return a;
}
int f1(int x) {if (x == 1) D = 1;
if (x == 23) D = -1;
return x = x + D;
}
int f2(int y, int x) {char p = pole[x][78];
char w = pole[x][1];
if (w == '@' && y == 2) Y = 1;
if (p == '@' && y == 77) Y = -1;
return y = y + Y;
}
void mb(int x, int y)
{pole[x][y] = '*';
}
void clrscr(void)
{char a[80];
printf("\033[2J");
printf("\033[0;0f");
}
void init_pole()
{for(int i = 0; i <= shirina; i++)
{pole[0][i] = '#';
pole[visota][i] = '#';
}
for(int i = 1; i <= visota; i++)
{pole[i][0] = '#';
pole[i][shirina] = '#';
}
for(int i1 = 1; i1 < visota; i1++)
for(int i2 = 1; i2 < shirina; i2++)
pole[i1][i2] = ' ';
}
void put_raketka1(int i1) {
pole[(visota-13) + i1][ 1 ] = '@';
pole[(visota-13) + i1 + 1][ 1 ] = '@';
pole[(visota-13) + i1 + 2][ 1 ] = '@';
}
void put_raketka2(int i2) {
pole[(visota-13)+i2][78] = '@';
pole[(visota-13)+i2+1][78] = '@';
pole[(visota-13)+i2+2][78] = '@';
}
void risuem_pole()
{for(int i1=0; i1 <= visota; i1++) {
for(int i2=0; i2 <= shirina; i2++)
{printf("%c", pole[ i1 ][ i2 ]);
}printf("\n");
}
}
