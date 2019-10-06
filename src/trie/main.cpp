#include <stdio.h>
#define MAX_RESULT_SIZE 500
#define MAX_STRING_SIZE 20

extern void init();
extern void add(char str[]);
extern int find(char str[]);
extern void list(char res[][MAX_STRING_SIZE], int &resIdx);

int nstrlen(const char *str)
{
	int cnt = 0;
	while (str[cnt] != '\0')
	{
		cnt++;
	}
	return cnt;
}

int nstrcmp(const char *source, char *target)
{
	int idx = 0;
	while (source[idx] != '\0')
	{
		if (source[idx] != target[idx]) return 1;
		idx++;
	}
	if (source[idx] != target[idx]) return 2;
	return 0;
}


int main(void)
{
	const int input = 15;
	int score = 0;
	char string[input][MAX_STRING_SIZE] = { "a", "b", "c", "d", "dock", "doctor", "document", "data", "database", "date", "duck", "education", "fan", "z", "zoo"}; // input = 15 strings.
	char wrongstr[5][MAX_STRING_SIZE] = { "f", "doctors", "e", "documents", "cup" };
	char res[MAX_RESULT_SIZE][MAX_STRING_SIZE];
	int res_index = 0;
	char findPatten[12][2] = { {1,2}, {1,6}, {0,4}, {0,1}, {1,7}, {0,2}, {0,0}, {1,8}, {0,3}, {1,0}, {1,11}, {1,14} };
	unsigned int solution = 0b0000111010010011;//		
	
	init();

	for (int i = 0; i < input; i++)
	{
		add(string[i]);
	}

	unsigned int mask = 1;
	unsigned int resultbit = 0;
	for (int i = 0; i < 12; i++)
	{
		int result;
		if (findPatten[i][0]) {
			result = find(string[findPatten[i][1]]);
		}
		else
		{
			result = find(wrongstr[findPatten[i][1]]);
		}

		if (i != 0)
			mask <<= 1;
		if (result)
			resultbit += mask;
	}
	if (solution == resultbit) score += 1;
	
	list(res, res_index);

	if (res_index == input)
	{

		if (!nstrcmp(res[0], string[0])) score += 1;
		if (!nstrcmp(res[1], string[1])) score += 1;
		if (!nstrcmp(res[2], string[2])) score += 1;
		if (!nstrcmp(res[3], string[3])) score += 1;
		if (!nstrcmp(res[4], string[7])) score += 1;
		if (!nstrcmp(res[5], string[8])) score += 1;
		if (!nstrcmp(res[6], string[9])) score += 1;
		if (!nstrcmp(res[7], string[4])) score += 1;
		if (!nstrcmp(res[8], string[5])) score += 1;
		if (!nstrcmp(res[9], string[6])) score += 1;
		if (!nstrcmp(res[10], string[10])) score += 1;
		if (!nstrcmp(res[11], string[11])) score += 1;
		if (!nstrcmp(res[12], string[12])) score += 1;
		if (!nstrcmp(res[13], string[13])) score += 1;
		if (!nstrcmp(res[14], string[14])) score += 1;

	}
	
	if (score == 16)
		printf("TC# result : pass (score. %d)\n",score);
	else
		printf("TC# result : fail (score. %d)\n", score);

	return 0;
}
