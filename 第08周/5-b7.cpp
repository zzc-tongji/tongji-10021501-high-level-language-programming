#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	int score[2][1001]={0};
	
	ifstream input;
	input.open("score.dat",ios::in);
	if (input==NULL)
	{
		cout << "鎵撳紑鏂囦欢澶辫触!!" << endl;
		return -1;
	}

	int i,j,used,temp;
	for (i=1;;i++)
	{
		input >> score[0][i];
		if (score[0][i]==-1)
		{
			used=i-1;
			break;
		}
	}
	input.close();

	for (i=1;i<=used;i++)
	{
		for (j=i+1;j<=used;j++)
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
	for (i=2;i<=used;i++)
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

	for (i=1;i<=used;i++)
	{
		cout << setw(3) << score[0][i] << setw(4) << score[1][i] << endl;
	}

	return 0;
}
