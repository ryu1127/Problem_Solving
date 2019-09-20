//색종이 -> 강사님 코드
#if 0
#include <stdio.h>

#define SIZE_PAPER (100)

int paper[SIZE_PAPER][SIZE_PAPER];

void Mark_Paper(int sr, int sc)
{
	int r, c;
	for (r = sr; r < sr + 10; r++)
	{
		for (c = sc; c < sc + 10; c++)
		{
			paper[r][c] = 1;
		}
	}
}


void Input_Data(void)
{
	int N;
	int i, sc, sr;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &sc, &sr);
		Mark_Paper(sr, sc);
	}

}

void Make_Height_Info(void)
{
	int r, c;
	for (r = 1; r < SIZE_PAPER; r++)
	{
		for (c = 0; c < SIZE_PAPER; c++)
		{
			if (paper[r][c] == 1) paper[r][c] = paper[r - 1][c] + 1;
		}
	}
}

int Get_Max_Area(void)
{
	int area;
	int max_area = 0;
	int r, sc, ec, h;

	for (r = 0; r < SIZE_PAPER; r++)
	{
		for (sc = 0; sc < SIZE_PAPER; sc++)
		{
			h = 0x7fffffff;
			for (ec = sc; ec < SIZE_PAPER; ec++)
			{
				if (h > paper[r][ec]) h = paper[r][ec];
				if (h == 0) break;
				area = h * (ec - sc + 1);
				if (max_area < area) max_area = area;
			}
		}
	}
	return max_area;
}


int main(void)
{
	Input_Data();

	Make_Height_Info();

	printf("%d\n", Get_Max_Area());

	return 0;
}



#endif


//불쾌한 날 -> internet코드
#if 0
#include <stdio.h>
#include <stdlib.h>

void main() {

	unsigned long a, i, j;
	unsigned long count = 0;
	unsigned long arr[80000];

	scanf("%lu", &a);


	i = 0;

	for (i = 0; i < a; i++) {
		scanf("%lu", &arr[i]);
		if (i > 0) {
			while (arr[i] >= arr[i - 1] && i > 0)
			{
				arr[i - 1] = arr[i];
				count = count + i - 1;
				a--;
				i--;
			}
		}
	}
	// 내림차순된 배열에서 소 키 구하기
	count += a * (a - 1) / 2;
	printf("%lu", count);


}



#endif

//불쾌한 날 -> 강사님 코드
#if 0
#include <stdio.h>

#define MAX_N (80000)

int N;
int stack[MAX_N];
int sp = -1;


int main(void)
{
	int i;
	int h;
	long long sum = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &h);
		while (sp >= 0 && stack[sp] <= h) sp--;
		stack[++sp] = h;
		sum += sp;
	}

	printf("%lld\n", sum);
	return 0;
}



#endif


//히스토그램에서 가장 큰 직사각형 -> 내코드
#if 0
#include<stdio.h>

int a[100000];
int stack[100000];
int i = 0;
int n;
int ans=0;
int left = 0;
int height = 0;
int width = 0;
int sp=-1;

int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++) {
		left = i;
		while (sp != -1 && a[sp] > a[i]) {
			height = a[stack[sp]];
			sp--;
			width = i;
			if (sp != -1) width = (i - stack[sp] - 1);
			if (ans < width*height) ans = width * height;
		}
		stack[++sp] = i;
	}
	
}


#endif


//히스토그램에서 가장 큰 직사각형 -> 강사님 코드
#if 0
#include <stdio.h>

#define MAX_N (100000)

typedef struct
{
	int h;
	int x_start;
}BLOCK;

BLOCK stack[MAX_N];
int sp = -1;

int N;
int height[MAX_N];

int Input_Data(void)
{
	int i;
	scanf("%d", &N);
	if (N == 0) return 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &height[i]);
	}
	return 1;
}

long long int Get_Max_Area(void)
{
	long long int area, max_area = 0;
	int x_start;
	int x_left;
	for (x_start = 0; x_start < N; x_start++)
	{
		x_left = x_start;
		while (sp >= 0 && stack[sp].h >= height[x_start])
		{
			area = (long long int)stack[sp].h * (x_start - stack[sp].x_start);
			if (max_area < area) max_area = area;
			x_left = stack[sp].x_start;
			sp--;
		}
		stack[++sp].h = height[x_start]; stack[sp].x_start = x_left;
	}

	while (sp >= 0)
	{
		area = (long long int)stack[sp].h * (N - stack[sp].x_start);
		if (max_area < area) max_area = area;
		sp--;
	}

	return max_area;
}



int main(void)
{
	while (Input_Data())
	{
		printf("%lld\n", Get_Max_Area());
	}
	return 0;
}

#endif


//도약 - 내코드
#if 0

#include<stdio.h>
#define swap(a,b) {int tmp; tmp = *a; *a = *b; *b = tmp;}

int n;
int a[1001];
int i;
int cnt = 0;
int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	//sort
	int j;
	int size = n;
	for (i = 0; i < size-1; i++) {
		for (j = i; j < size; j++) {
			if (a[i] > a[j]) swap(&a[i], &a[j]);
		}
	}


	int k;
	int lower, upper;
	for (i = 0; i < n-2; i++) {
		for(j=i+1;j<n-1;j++){
			//Binary
			lower = Binary_Search_Lower()
			for (k = j + 1; k < n; k++) {
				if ((a[j] - a[i]) > (a[k] - a[j])) continue;
				if (((a[j] - a[i]) * 2) < (a[k] - a[j])) continue;
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}


#endif


//도약 - 강사님 코드
#if 0
#include <stdio.h>

#define MAX_N (1000)

int N;
int pos[MAX_N];
int tmp[MAX_N];

void Input_Data(void)
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &pos[i]);
	}
}

void Merge_Sort(int s, int e)
{
	int m, idx1, idx2, idxtmp;

	if (s >= e) return;

	m = (s + e) / 2;
	Merge_Sort(s, m);
	Merge_Sort(m + 1, e);

	idx1 = s; idx2 = m + 1; idxtmp = s;
	while (idx1 <= m && idx2 <= e)
	{
		if (pos[idx1] < pos[idx2])
			tmp[idxtmp++] = pos[idx1++];
		else
			tmp[idxtmp++] = pos[idx2++];
	}

	while (idx1 <= m) tmp[idxtmp++] = pos[idx1++];
	while (idx2 <= e) tmp[idxtmp++] = pos[idx2++];

	for (idxtmp = s; idxtmp <= e; idxtmp++) pos[idxtmp] = tmp[idxtmp];
}

int Binary_Search_Lower(int s, int e, int d)
{
	int m, sol = -1;

	while (s <= e)
	{
		m = (s + e) / 2;
		if (pos[m] >= d)
		{
			sol = m;
			e = m - 1;
		}
		else s = m + 1;
	}
	return sol;
}

int Binary_Search_Upper(int s, int e, int d)
{
	int m, sol = -1;

	while (s <= e)
	{
		m = (s + e) / 2;
		if (pos[m] <= d)
		{
			sol = m;
			s = m + 1;
		}
		else e = m - 1;
	}
	return sol;
}



int Get_Solution(void)
{
	int s1, s2, s3;
	int jump;
	int rs, re;
	int cnt = 0;
	int lower, upper;
	for (s1 = 0; s1 < N; s1++)
	{
		for (s2 = s1 + 1; s2 < N; s2++)
		{
			jump = pos[s2] - pos[s1];
			rs = pos[s2] + jump;
			re = pos[s2] + 2 * jump;

			//Binary_Search_Lower(int s,int e,int d)
			lower = Binary_Search_Lower(s2 + 1, N - 1, rs);
			if (lower != -1 && pos[lower] <= re)
			{
				upper = Binary_Search_Upper(s2 + 1, N - 1, re);
				cnt += (upper - lower + 1);
			}

		}
	}
	return cnt;
}

int main(void)
{
	Input_Data();

	Merge_Sort(0, N - 1);

	printf("%d\n", Get_Solution());

	return 0;
}

#endif




//나무 자르기 -> 내코드
#if 0

#include<stdio.h>

int n, m;
int tree[1000001];
int i = 0;
int max = 0;
int mid;
int s, e;


void input() {
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &tree[i]);
		if (tree[i] > max) max = tree[i];
	}
	e = max;
}
int isGood(int mid) {
	int i;
	int cnt=0;
	for (i = 0; i < n; i++) {
		if ((tree[i] - mid) > 0) cnt += tree[i] - mid;
	}
	//그냥 정확히 찾았을때 
	if (cnt == m) return 2;
	//범위 안에 들때
	if (cnt >= m) return 1;
	//범위에 없을때
	else return 0;
}

void Binary_Search(int s, int e) {
	while (s <= e) {
		mid = (s + e) / 2;
		if (isGood(mid) == 2) return;
		//만족하므로 더 위로 잘라야한다.
		if (isGood(mid)) {
			Binary_Search(mid, e);
		}
		//만족하지 못하므로 아래로 탐색
		else {
			Binary_Search(s, mid);
		}
	}
	return;
}
void output() {
	printf("%d\n", mid);
}

int main() {
	input();
	Binary_Search(0,max);
	output();
	return 0;
}




#endif


//나무 자르기 - 강사님 코드
#if 0

#endif

#if 0

#include <stdio.h>
#define MAX_TREE 1000000
int N;
long long int M;
int tree[MAX_TREE];
int max_h;
int ans;

void Input_Data()
{
	\
		scanf("%d%lld", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tree[i]);
		max_h = max_h < tree[i] ? tree[i] : max_h;
	}
}

int Cut(int h)
{
	long long int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (tree[i] > h)
			sum += tree[i] - h;
	}

	if (sum >= M)
	{
		ans = ans > h ? ans : h;
		return 1;
	}
	return 0;

}

void Solve(int s, int e)
{
	if (s > e)
		return;
	int m = (s + e) / 2;
	if (Cut(m))
		Solve(m + 1, e);
	else
		Solve(s, m - 1);
}

int main()
{

	Input_Data();

	Solve(0, max_h);
	printf("%d\n", ans);
}


#endif