#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int score[2][61]=
	{
		{00,
			55,19,84,98,19,48,87,04,98,37,
			84,06,77,48,39,29,80,95,82,55,
			83,28,96,07,73,10,38,99,35,70,
			47,92,95,75,18,49,68,70,44,99,
			64,53,59,17,45,48,06,82,27,90,
			88,79,84,96,88,99,29,86,83,100	
		},
		{0}
	};
	int i,j,temp;

	for (i=1;i<=60;i++)
	{
		for (j=i+1;j<=60;j++)
		{
			if (score[0][j]>score[0][i])
			{
				temp=score[0][j];
				score[0][j]=score[0][i];
				score[0][i]=temp;
			}
		}
	}
	score[1][1]=1;
	for (i=2;i<=60;i++)
	{
		if (score[0][i]==score[0][i-1])
		{
			score[1][i]=score[1][i-1];
		}
		else
		{
			score[1][i]=i;
		}
	}

	for (i=1;i<=60;i++)
	{
		cout << setw(3) << score[0][i] << setw(3) << score[1][i] << endl;
	}

	return 0;
}
