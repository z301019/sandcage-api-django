#include<stdio.h>
#include<stdbool.h>
int main()
{
	char s[14];
	const char ranks[13] = "23456789tjqka";
	char suits[4] = "cdsh";
	char rank[5],suit[5];
	int x=0,flag=0,ranknumber=0,pairs=0,count=0,temp;
	int rank_num[13],rankindex[5], suitindex[5],ranksuitindex[5];
	bool Illegal_card = false, Duplicate_card = false, flush = false, straight = false,four=false,three=false;
	while (gets(s))
	{
		x = 0; flag = 0; Illegal_card = false; Duplicate_card = false, flush = false, straight = false, four = false, three = false,count = 0,pairs=0;
		for (int i = 0; i < 13; i++)
			rank_num[i] = 0;
		for (int i = 0; i < 14; i += 3)
		{
			rank[x] = s[i];
			x++;
		}
		x = 0;
		for (int i = 0; i < 14; i += 3)
		{
			suit[x] = s[i+1];
			x++;
		}
		for (int i = 0; i < 5; i++)//轉小寫
		if (rank[i] == 'T' || rank[i] == 'J' || rank[i] == 'Q' || rank[i] == 'K' || rank[i] == 'A')
			rank[i] = rank[i] + 32;
		for (int i = 0; i < 5; i++)//轉小寫
			if (suit[i] == 'C' || suit[i] == 'D' || suit[i] == 'S' || suit[i] == 'H')
				suit[i] = suit[i] + 32;
		for (int i = 0; i < 5; i++)//判斷非法數字
		{
			flag = 0;
			for (int j = 0; j < 13; j++)
			{
				if (rank[i] == ranks[j])
				{
					rankindex[i] = j;
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				Illegal_card = true;
				break;
			}
		}
		flag = 0; count = 0;
		for (int i = 0; i < 5; i++)//判斷非法花色
		{
			for (int j = 0; j < 4; j++)
			{
				flag = 0;
				if (suit[i] == suits[j])
				{
					suitindex[i] = j;
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				Illegal_card = true;
				break;
			}
		}
		for (int i = 0; i < 5; i++)//判斷重複牌
		{
			for (int j = i + 1; j < 5; j++)
			{
				if (rank[i] == rank[j] && suit[i] == suit[j])
				{
					Duplicate_card = true;
					break;
				}
			}
		}
		if (Illegal_card&&Duplicate_card)
			printf("Illegal and Duplicate cards\n");
		else if(Illegal_card||Duplicate_card)
		{
			if (Illegal_card)
				printf("Illegal card\n");
			if (Duplicate_card)
				printf("Duplicate card\n");
		}
		else//檢查牌型
		{
			for (int i = 0; i < 5; i++)
			{
				if (rank[i] == '2')
				{
				    ranknumber = 0; rank_num[ranknumber]++;
				}
				if (rank[i] == '3')
				{
					ranknumber = 1; rank_num[ranknumber]++;
				}
				if (rank[i] == '4')
				{
					ranknumber = 2; rank_num[ranknumber]++;
				}
				if (rank[i] == '5')
				{
					ranknumber = 3; rank_num[ranknumber]++;
				}
				if (rank[i] == '6')
				{
					ranknumber = 4; rank_num[ranknumber]++;
				}
				if (rank[i] == '7')
				{
					ranknumber = 5; rank_num[ranknumber]++;
				}
				if (rank[i] == '8')
				{
					ranknumber = 6; rank_num[ranknumber]++;
				}
				if (rank[i] == '9')
				{
					ranknumber = 7; rank_num[ranknumber]++;
				}
				if (rank[i] == 't')
				{
					ranknumber = 8; rank_num[ranknumber]++;
				}
				if (rank[i] == 'j')
				{
					ranknumber = 9; rank_num[ranknumber]++;
				}
				if (rank[i] == 'q')
				{
					ranknumber = 10; rank_num[ranknumber]++;
				}
				if (rank[i] == 'k')
				{
					ranknumber = 11; rank_num[ranknumber]++;
				}
				if (rank[i] == 'a')
				{
					ranknumber = 12; rank_num[ranknumber]++;
				}
			}
			for (int i = 0; i < 4; i++)//檢查同花
			{
				if (suit[i] == suit[i + 1])
					count++;
				if (count == 4)
					flush = true;
			}
			ranknumber = 0; count = 0;
			while (rank_num[ranknumber] == 0) ranknumber++;//檢查順子
			for (; rank_num[ranknumber] > 0; ranknumber++)
				count++;
			if (count == 5)
				straight = true;
			for (int i = 0; i < 13; i++)
			{
				if (rank_num[i] == 4) { four = true; break; }
				if (rank_num[i] == 3) three = true;
				if (rank_num[i] == 2) pairs++;
			}
			if (straight && flush) printf("Straight Flush ");
			else if (four) printf("Four-Of-A-Kind ");
			else if (three && pairs == 1) printf(" Full House ");
			else if (flush) printf("Flush ");
			else if (straight) printf("Straight ");
			else if (three) printf("Three-Of-A-Kind ");
			else if (pairs == 2) printf("Two Pairs ");
			else if (pairs == 1) printf("Pair ");
			else printf("High Card ");
			for (int i = 0; i < 5; i++)
				ranksuitindex[i] = rankindex[i]*100+ suitindex[i];
			for (int i = 0; i < 5; i++)
			{
				for (int j = i; j < 5; j++)
				{
					if (ranksuitindex[i] > ranksuitindex[j])
					{
						temp = rank[i];
						rank[i] = rank[j];
						rank[j] = temp;
						temp = suit[i];
						suit[i] = suit[j];
						suit[j] = temp;
						temp = ranksuitindex[i];
						ranksuitindex[i] = ranksuitindex[j];
						ranksuitindex[j] = temp;
					}
				}
			}
			for (int i = 0; i < 5; i++)
			{
				if(i == 4)
				printf("%c%c\n", rank[i], suit[i]);
				else
				printf("%c%c ", rank[i], suit[i]);
			}
		}
	}
    return 0;
}

