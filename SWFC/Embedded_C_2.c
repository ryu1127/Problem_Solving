/**********************************************************/
// 2부. 고급 포인터 분석 및 설계
/**********************************************************/

/**********************************************************/
// [2-2-1] : 배열의 요소 타입
/**********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
   int* a;

   int *b1[4];
   int **b2[4];
   int b3[4];

   *b1[0] = a;
   b2[0] = &a;
   b3[0] = *a;
}

#endif

#if 0

#include <stdio.h>

void main(void)
{
   int(*p)[4];

   // 변수 선언

   int(*b1[4])[4];
   int(**b2[4])[4];
   int   b3[4];

   b1[0] = p;
   b2[0] = &p;
   b3[0] = (*p)[1];
}

#endif

#if 0

#include <stdio.h>

void main(void)
{
   int a[3];

   // 변수 선언

   int *b1[4];
   int(*b2[4])[3];
   int b3[4];

   b1[0] = a;
   b2[0] = &a;
   b3[0] = a[1];
}

#endif

#if 0

#include <stdio.h>

void main(void)
{
   int *a[3];

   // 변수 선언

   int** b1[4];
   int *(*b2[4])[3];
   int *b3[4];

   b1[0] = a;
   b2[0] = &a;
   b3[0] = a[1];
}

#endif

/**********************************************************/
// [2-2-2] : 함수의 리턴 타입
/**********************************************************/

#if 0

#include <stdio.h>

int *a;

int *f1(void)
{
   return a;
}

int **f2(void)
{
   return &a;
}

int f3(void)
{
   return *a;
}

void main(void)
{
   f1();
   f2();
   f3();
}

#endif

#if 0

#include <stdio.h>

int(*p)[4];

int(*f1(void))[4]
{
   return p;
}
int(**f2(void))[4]
{
   return &p;
}

int   f3(void)
{
   return (*p)[1];
}

void main(void)
{
   f1();
   f2();
   f3();
}

#endif

#if 0

#include <stdio.h>

int(*p)(int);

int(*f1(void))(int)
{
   return p;
}
int(**f2(void))(int)
{
   return &p;
}
int f3(void)
{
   return (*p)(3);
}

void main(void)
{
   f1();
   f2();
   f3();
}

#endif

/**********************************************************/
// [2-3-3] : 포인터 배열
/**********************************************************/

#if 0

#include <stdio.h> 

int x[4] = { 1,2,3,4 };

void main(void)
{
   int* a[4] = { x + 3, x + 2, x + 1, x };

   printf("%d\n", x[2]);

   // 배열 a를 이용하여 x[2]를 30으로


   //두가지 방법이 모두 가능
   *(a[1]) = 30;
   a[3][2] = 30;

   printf("%d\n", x[2]);
}

#endif

/**********************************************************/
// [2-3-7] : 문자열 바꾸기
/**********************************************************/

#if 0

#include <stdio.h> 
//char *p 가 아닌 **p 이다. &a 의 타입이 char ** 이기 떄문
void Swap(char **p,char ** q)
{
   char * tmp;
   tmp = *p;
   *p = *q;
   *q = tmp;
}

void main(void)
{
   char * a = "hello";
   char * b = "hi";

   printf("Before : %s, %s\n", a, b);
   Swap(&a,&b);
   printf("After : %s, %s\n", a, b);
}

#endif

/**********************************************************/
// [2-3-10] : 배열 포인터 연습
/**********************************************************/

#if 0

#include <stdio.h> 

void func(int (*p) [4])
{
   // main의 a[2]를 50으로

   (*p)[2] = 50;
}

void main(void)
{
   int a[4] = { 10,20,30,40 };

   printf("%d\n", a[2]);
   func(&a);
   printf("%d\n", a[2]);
}

#endif

/**********************************************************/
// [2-3-13] : 구조체 주소의 함수 전달
/**********************************************************/

#if 0

#include <stdio.h> 

struct math
{
   int id;
   char name[20];
   int score;
};

void cheat(struct math * test);

void main(void)
{
   struct math final = { 1, "Kim", 50 };
   cheat(&final);
   printf("%d\n", final.score);
}

void cheat(struct math * test)
{
   //세가지 방법 모두 가능하다
   test->score= 100;
   (*test).score = 100;
}   test[0].score = 100;

#endif

/**********************************************************/
// [2-4-3] : 2차원배열의 전달
/**********************************************************/

#if 0

#include <stdio.h>
//int (*p)[3]
void draw_pixel(int y, int x, int value, int (*p)[3])
{
   p[y][x] = value;
}

void main(void)
{
   int a[2][3] = { 1,2,3,4,5,6 };

   printf("%d\n", a[1][2]);
   draw_pixel(1, 2, 10, a);
   printf("%d\n", a[1][2]);
}

#endif

/**********************************************************/
// [2-4-4] : 2차원배열의 리턴
/**********************************************************/

#if 0

#include <stdio.h>
//int (*func(void))[4]
int (*func(void))[4]
{
   static int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
   return a;
}

void main(void)
{//func()[1][2]
   printf("%d\n", func()[1][2]);
}

#endif

/**********************************************************/
// [2-4-5] : 배열 등가포인터 연습
/**********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
   int a[2][3][4];
   int(*b[3])[4];
   int *(*c[2])(int *);
   int *d[3][4];
   int(*(*e[5])(void))[4];

   // pa ~ pe 포인터 변수 선언
   // 아래에 pa ~ pe 까지 포인터를 선언한다
   // 컴파일시 단 하나의 경고도 발생하지 않아야 한다
   int(*pa)[3][4];
   int(**pb)[4];
   int * (**pc) (int *);
   int * (*pd)[4];
   //이거 해석 어떻게 하는거지?
   int(*(**pe)(void))[4];

   pa = a;
   pb = b;
   pc = c;
   pd = d;
   pe = e;
}

#endif

/**********************************************************/
// [2-4-8] : 배열의 액세스
/**********************************************************/

#if 0

#include <stdio.h>

int a[3][4] = { { 1,2,3,4 },{ 5,6,7,8 },{ 9,10,11,12 } };
int *b[3] = { a[2], a[1], a[0] };

void main(void)
{
   printf("%d\n", a[2][3]);

   //b를 이용하여 배열내의 숫자 12을 인쇄하시오
   printf("%d\n", b[0][3]);
   printf("%d\n", b[1][7]);
   printf("%d\n", b[2][11]);
   //왠지 모르겠지만 약간의 딜레이가 있다.
   printf("%d\n", b[3][-1]);
}

#endif

/**********************************************************/
// [2-4-9] : 환산법의 적용
/**********************************************************/

#if 0

#include <stdio.h>

int a[3][4] = { { 1,2,3,4 },{ 5,6,7,8 },{ 9,10,11,12 } };
int *p = a[0];
// int [4]
void main(void)
{
   printf("%d\n", a[2][3]);

   //p 변수만 이용하여 배열내의 숫자 12을 인쇄하시오
   //p가 a[0]를 가리키고 있으므로 거기서부터 11개 만큼 간 p[11]
   printf("%d\n", p[11]);
}

#endif

/***********************************************************/
// [2-4-10] : 함수 parameter의 직관적 설계
/***********************************************************/

#if 0

#include <stdio.h>

int a[2][3][4] = { { { 1,2,3,4 },{ 5,6,7,8 },{ 9,10,11,12 } },{ { 10,20,30,40 },{ 50,60,70,80 },{ 90,100,110,120 } } };

void f1(int *p)
{
   printf("%d\n",p[17]);
}
void f2(int (*p) [4])
{
   printf("%d\n", p[0][-3]);
   //printf("%d"\n",p[2][-11];
}

void f3(int (*p)[3][4])
{
   printf("%d\n",p[1][2][1]);
}

void f4(int (*p)[3][4])
{
   printf("%d\n",(p-3)[1][2][1]);
}

void f5(int (*p)[2][3][4])
{
   printf("%d\n", (*p)[1][2][1]);
}

void f6(int (*p)[2][3][4])
{
   printf("%d\n",(*(p+1))[1][2][1]);
}

void main(void)
{
   f1(*(a[0] + 1));
   f2(*(a + 2));
   f3(a);
   f4(a + 3);
   f5(&a);
   f6(&a - 1);
}

#endif

/***********************************************************/
// [2-4-11] : 함수 리턴의 직관적 설계
/***********************************************************/

#if 0

#include <stdio.h>

int a[2][3] = { { 1,2,3 },{ 4,5,6 } };
int b[2][3] = { { 10,20,30 },{ 40,50,60 } };
int(*c[2])[3] = { b, a };
int(**p)[3] = c;

int (*f1(void))[3]
{
   return c[1];
}

int (**f2(void))[3]
{
   return c + 1;
}

int *f3(void)
{
   return a[0] - 1;
}

int (**f4(void))[3]
{
   return p;
}
int (* (*f5(void)) [2]) [3]
{
   return &c;
}

void main(void)
{
   printf("6=%d\n", f1());
   printf("6=%d\n", f2());
   printf("6=%d\n", f3());
   printf("6=%d\n", f4());
   printf("6=%d\n", f5());
}

#endif

/***********************************************************/
// [2-5-1] : 함수 등가포인터의 실행
/***********************************************************/

#if 0

#include <stdio.h>

int add(int a, int b)
{
   return a + b;
}

void f1(void)
{
   printf("func\n");
}

int * f2(void)
{
   static int a[4] = { 1,2,3,4 };

   return a;
}

void main(void)
{
   // p, q, r 선언
   int(*p)(int a, int b);
   void(*q)(void);
   int* (*r)(void);


   // p, q, r에 대응 함수 대입
   p = add;
   q = f1;
   r = f2;

   printf("%d\n", add(3, 4));
   f1();
   printf("%d\n", f2()[2]);

   // 위와 동일한 결과가 나오도록 p, q, r로 실행
   printf("%d\n", p(3, 4));
   q();
   printf("%d\n", r()[2]);


}

#endif

/***********************************************************/
// [2-5-2] : 함수를 함수에 전달하자
/***********************************************************/

#if 0

#include <stdio.h> 

int add(int a, int b)
{
   return a + b;
}

int sub(int a, int b)
{
   return a - b;
}

void func(int (*p) (int, int))
{
   printf("%d\n", p(3, 4));
}

void main(void)
{
   func(add);
   func(sub);
}

#endif

/***********************************************************/
// [2-5-3] : Parameter 미지정형
/***********************************************************/

#if 0

#include <stdio.h> 

int add(int a, int b)
{
   return a + b;
}

int sqr(int a)
{
   return a * a;
}

int func(void)
{
   return 100;
}

// add, sqr, func에 공통적인 함수 등가포인터 p 설계
int(*p)();

void main(void)
{
   p = add;
   printf("%d\n", p(3, 4));

   p = sqr;
   printf("%d\n", p(3));

   p = func;
   printf("%d\n", p());
}

#endif

/***********************************************************/
// [2-5-5] : 함수 Lookup table
/***********************************************************/

#if 0

#include <stdio.h> 
#include <stdlib.h> 

int add(int a, int b)
{
   return a + b;
}

int sub(int a, int b)
{
   return a - b;
}

int mul(int a, int b)
{
   return a * b;
}

int get_key(void)
{
   static int r = 0;
   int ret = r;

   r = (r + 1) % 3;
   return ret;
}

int(*fa[3])(int, int) = { add, sub, mul };

int op(int a, int b)
{
   return fa[get_key()](a, b);
}

void main(void)
{
   printf("%d\n", op(3, 4));
   printf("%d\n", op(3, 4));
   printf("%d\n", op(3, 4));
   printf("%d\n", op(3, 4));
   printf("%d\n", op(3, 4));
   printf("%d\n", op(3, 4));
   printf("%d\n", op(3, 4));
}

#endif

/***********************************************************/
// [2-5-6] : 함수를 받고 함수를 리턴하는 함수
/***********************************************************/

#if 0

#include <stdio.h> 
#include <stdlib.h> 

int add(int a, int b)
{
   return a + b;
}

int sub(int a, int b)
{
   return a - b;
}

int mul(int a, int b)
{
   return a * b;
}

int get_key(void)
{
   static int r = 0;
   int ret = r;

   r = (r + 1) % 3;
   return ret;
}

int(*fa[3])(int, int) = { add, sub, mul };
//이해안됨!!!!
int (*op(int(*fp)(void))) (int,int)
{
   return fa[fp()];
}

void main(void)
{
   printf("%d\n", op(get_key)(3, 4));
   printf("%d\n", op(get_key)(3, 4));
   printf("%d\n", op(get_key)(3, 4));
   printf("%d\n", op(get_key)(3, 4));
   printf("%d\n", op(get_key)(3, 4));
   printf("%d\n", op(get_key)(3, 4));
   printf("%d\n", op(get_key)(3, 4));
}

#endif

/***********************************************************/
// [2-5-8] : typedef을 이용한 가독성의 증대
/***********************************************************/

#if 0

#include <stdio.h> 
#include <stdlib.h> 

int add(int a, int b)
{
   return a + b;
}

int sub(int a, int b)
{
   return a - b;
}

int mul(int a, int b)
{
   return a * b;
}

int get_key(void)
{
   return rand() % 3;
}

typedef int(*FPTR) ();

FPTR fa[3] = { add, sub, mul };

FPTR op(FPTR fp)
{
   return fa[fp()];
}

void main(void)
{
   printf("%d\n", op(get_key)(3, 4));
   printf("%d\n", op(get_key)(3, 4));
   printf("%d\n", op(get_key)(3, 4));
   printf("%d\n", op(get_key)(3, 4));
   printf("%d\n", op(get_key)(3, 4));
   printf("%d\n", op(get_key)(3, 4));
   printf("%d\n", op(get_key)(3, 4));
}

#endif

/***********************************************************/
// [2-5-9] : 직관적 코드 설계 예제 1
/***********************************************************/

// 직접 선언

#if 0

#include <stdio.h> 

int (*f2(void)) [4]
{
   static int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

return a;
}
int (*(*f1(void))(void))[4]
{
   return f2;
}

void main(void)
{
   printf("%d\n", f1()()[1][2]);
}

#endif

// typedef 사용

#if 0

#include <stdio.h> 

typedef int(*FP2)[4];
typedef FP2 (*FP1) (void);

FP2 f2(void)
{
   static int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

   return a;
}

FP1 f1(void)
{
   return &f2;
}

void main(void)
{
   //왜 *f1()()[1][2]이게 아닌가?
   printf("%d\n", f1()()[1][2]);
}

#endif

/***********************************************************/
// [2-5-10] : 직관적 코드 설계 예제 2
/***********************************************************/

#if 0

#include <stdio.h> 

int(*f2(void))[4]
{
   static int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

return a;
}
int *f1(void)
{
   return f2()[2];
}

void main(void)
{
   printf("%d\n", f1()[-2]);
}

#endif

/***********************************************************/
// [2-5-11] : 직관적 코드 설계 예제 3
/***********************************************************/

#if 0

#include <stdio.h> 

int (*f2(void)) [3][4]
{
   static int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

return &a;
}
int (*f1(void))[4]
{
   return f2()[0];
}

void main(void)
{
   printf("%d\n", f1()[1][2]);
}

#endif

/***********************************************************/
// [2-5-12] : 직관적 코드 설계 예제 4
/***********************************************************/

#if 0

#include <stdio.h> 

struct _st
{
   int num;
   char * name;
};

//f2(void)                     // [1]
struct _st (*f2(void))[3]
{
   static struct _st a[2][3] = { { { 1,"KIM" },{ 2,"SONG" },{ 3, "KI" } },{ { 4, "KANG" },{ 5, "PARK" },{ 6, "LEW" } } };
return a;
}


struct _st *f1(int num)
{
   return f2()[num];
}

void main(void)
{
   printf("%s\n", f1(0)[4].name+1);   // [3]
}

#endif

/***********************************************************/
// [2-5-13] : 직관적 코드 설계 예제 5
/***********************************************************/

#if 0

#include <stdio.h>

int *f1(void)
{
   static int a[4] = { 1,2,3,4 };
   return a;
}

int *f2(void)
{
   static int a[4] = { 10,20,30,40 };
   return a;
}

int *(*fa[2])() = { f1, f2 };


int f4(void)
{
   return 1;
}
//func1(void)     // [1]
int *(**func1(void))()
{
   return fa;
}

   // [2]
int (*func2(int (*p)(void)))()
{
   return func1()[p()];
}

void main(void)
{
   //이거 안됨!! 왜 안되지
   printf("%d\n", func2(f4)()[3]);   // [3]
}

#endif

/***********************************************************/
// [2-8-1] : Type casting 연습 1
/***********************************************************/

#if 0

#include <stdio.h>

void func(int x)
{
   printf("%f\n", ((double *)x)[0]);
   printf("%f\n", ((double *)x)[1]);
   printf("%f\n", ((double *)x)[2]);
}

void main(void)
{
   double d[3] = { 3.14, 5.125, -7.42 };

   func((int)d);
}

#endif

#if 0

#include <stdio.h>

void func(int x)
{
   int i;

   for (i = 0; i<3; i++)
   {
      printf("%f\n", ((double *)x)[i]);
   }
}

void main(void)
{
   double d[3] = { 3.14, 5.125, -7.42 };

   func((int)d);
}

#endif

/***********************************************************/
// [2-8-2] : Type casting 연습 2
/***********************************************************/

#if 0

#include <stdio.h>

void func(void * p)
{
   int i;

   for (i = 0; i<3; i++)
   {
      //타입을 일단 맞춰주고 &p였으니까 *을 통해서 접근
      printf("%f\n", (*(double **)p)[i]);
   }
}

void main(void)
{
   double d[3] = { 3.14, 5.125, -7.42 };
   void *p = d;

   func(&p);
}

#endif

/***********************************************************/
// [2-8-3] :  Type casting 연습 3
/***********************************************************/

#if 0

#include <stdio.h>

void func(void *p)
{
   printf("%s\n", (*(char**)p));
}

void main(void)
{
   char * p = "Willtek";
   func(&p);
}

#endif

/***********************************************************/
// [2-8-4] : Type casting 연습 4
/***********************************************************/

#if 0

#include <stdio.h>

struct st
{
   int i;
   char c;
};

void func(long long int a)
{
   printf("%d\n",((struct st*)&a)->i);
   printf("%c\n", ((struct st*)&a)->c);
   printf("%d\n", (*(struct st*)&a).i);
   printf("%c\n", (*(struct st*)&a).c);
}

void main(void)
{
   struct st x = { 100, 'A' };

   func(*(long long int *)&x);
}

#endif

/***********************************************************/
// [2-8-5] : int 변수로 함수 실행하기
/***********************************************************/

#if 0

#include <stdio.h>

int func(int a, int b)
{
   return a + b;
}

void main(void)
{
   int a = (int)func;

   printf("%d\n", func(3, 4));
   printf("%d\n", );
}

#endif

/***********************************************************/
// [2-8-6] : Type casting 연습 5
/***********************************************************/

#if 0

#include <stdio.h>

void func(void * p)
{
   printf("%d\n",(*(int (**)(int,int))p)(3,4));
   //printf("%d\n",(*(int (**)(int,int))p)(3,4))
}
//p int (**) (int, int)
int add(int a, int b)
{
   return a + b;
}

void main(void)
{
   void *p = (void *)add;
   func(&p); //(void **)
}

#endif

/***********************************************************/
// [2-8-8] : 가변의 인수전달
/***********************************************************/

#if 0

#include <stdio.h>

int my_add(int cnt, ...)
{
   int i, sum = 0;

   for (i = 1; i <= cnt; i++)
   {
      //cnt가 첫번째 요소의 주소라는 것을 잊지 말자!
      sum += *(&cnt + i);
   }
   return sum;
}

void main(void)
{
   printf("%d\n", my_add(3, 7, 5, 4));
   printf("%d\n", my_add(5, 1, 2, 6, 9, 10));
}

#endif

/***********************************************************/
// [2-8-9] : 가변인자의 access
/***********************************************************/

#if 0

#include <stdio.h>

void my_ellipsis(int a, ...)
{
   printf("%d\n", a);
   printf("%u\n",*(int *)(&a+1));
   printf("%c\n",*(int *)(&a+2));
   printf("%f\n",*(double *)(&a+3));
   printf("%f\n",*(double *)(&a+5));
}

void main(void)
{
   int a = 10;
   unsigned char b = 100;
   unsigned char c = 'A';
   float d = 3.14f;
   double e = 5.125;

   my_ellipsis(a, b, c, d, e);
}

#endif

/***********************************************************/
// [2-8-10] : 재도전 - 실수의 인쇄
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
   float f = 3.5f;

   printf("%f\n",f );
}

#endif

#if 0 

#include <stdio.h>

void main(void)
{
   float f = 3.1f;

   printf("%#x\n", f);
}

#endif

/***********************************************************/
// [2-8-11] : 실수의 메모리 내용 dump
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
   float a = 3.5f;
   double b = 3.5;

   printf("float : %#.8x\n", *(unsigned int *)&a);

   printf("double: %#.8x : %.8x\n\n",((unsigned int *)&b)[1] , ((unsigned int *)&b)[0]);
}

#endif


/***********************************************************/
// [2-8-12] : 간이 format 지시자의 이용
/***********************************************************/

#if 1

#include <stdio.h>

void my_printf(char * fmt, ...)
{
   int *ap = (int *)&fmt + 1;

   while (*fmt)
   {
      switch (*fmt++)
      {
      case 'u': printf("%u\n",*(int *)ap++); break;
      case 'd': printf("%d\n", *ap++); break;
      case 'c': printf("%c\n", *(unsigned char *)ap++); break;
      case 'f': printf("%f\n", ); break;
      case 's': printf("%s\n", ); break;
      }
   }
}

void main(void)
{
   int a = 10;
   unsigned char b = 100;
   unsigned char b2 = 'A';
   float c = 3.14f;
   double d = 5.125;

   my_printf("ducffsd", a, b, b2, c, d, "Keyseek", 100);
   my_printf("fdsc", -10.75, 100, "Willtek", 'B');
}

#endif

/***********************************************************/
// [2-8-14] : my_add 함수의 재설계
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdarg.h>

int my_add(int cnt, ...)
{
   int i, sum = 0;



   for (i = 1; i <= cnt; i++)
   {

   }


   return sum;
}

void main(void)
{
   printf("%d\n", my_add(3, 7, 5, 4));
   printf("%d\n", my_add(5, 1, 2, 6, 9, 10));
}

#endif

/***********************************************************/
// [2-8-16] : Data Parsing 연습 1
/***********************************************************/

#if 0

#include <stdio.h>

struct _st
{
   int i;
   char c;
};

void my_test(char c, ...)
{
   printf("%c\n", c);
   printf("%d\n", );
   printf("%c\n", );
   printf("%s\n", );
   printf("%f\n", );
   printf("%f\n", );
   printf("%f\n", );
   printf("%d\n", );
}

int add(int a, int b)
{
   return a + b;
}

void main(void)
{
   char a = 'A';
   struct _st x = { 100, 'B' };
   double d[3] = { 3.14, 5.19, -7.42 };

   my_test(a, x, "Song", d, add);
}

#endif

/***********************************************************/
// [2-8-17] : Data Parsing 연습 2
/***********************************************************/

#if 0

#include <stdio.h>

void my_test(int a, ...)
{
   // [1] 넘어온 3.14 인쇄
   printf("f => %.2f\n", );
   // [2] 넘어온 배열을 이용하여 f1 함수를 간접호출하여 문자열 BIN 출력
   printf("%s", );
   // [3] 넘어온 배열을 이용하여 f2 함수를 간접호출하여 문자열 GO 출력
   printf("%s\n", );
}

char * f1(void)
{
   return "CABIN";
}

char * f2(void)
{
   return "LOGO";
}

void main(void)
{
   double d = 3.14;
   char * (*fa[2])() = { f1, f2 };

   my_test(1, &d, fa);
}

#endif