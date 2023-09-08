#include<stdio.h>
int d1,d2,m1,m2,y1,y2,d,m,y;
int month[13]; 

void Year(int year) 
{
    if ((year % 400 == 0) || (year % 4 == 0))
	{
        month[2] = 29;
    } else if (year % 100 == 0) 
	{
        month[2] = 28;
    } else 
	{
        month[2] = 28;
    }
}

void Month() 
{
	month[1] = month[3] = month[5] = month[7] = month[8] = month[10] = month[12] = 31;
	month[2] = 28;
	month[4] = month[6] = month[9] = month[11] = 30; 
}

void luckydates(int D1, int M1, int Y1, int D2, int M2, int Y2) 
{
    Month();
    int result = 0;
    while (1) 
	{
        int x = D1;
        x = x * 100 + M1;
        x = x * 10000 + Y1;
        if (x % 4 == 0 || x % 7 == 0) 
		{
            result = result + 1;
        }
        if (D1 == D2 && M1 == M2 && Y1 == Y2) 
		{
            break;
        }
      Year(Y1);
        D1 = D1 + 1;
        if (D1 > month[M1]) 
		{
            M1 = M1 + 1;
            D1 = 1;
            if (M1 > 12) 
			{
                Y1 = Y1 + 1;
                M1 = 1;
            }
        }
    }
    printf("%d",result);
}
inline void str(char day[])
{
	int i;
		if(day[0] == '0')
    {
    	for( i = 0; day[i] != '\0'; i++)
    	{
    		day[i] = day[i+1];			   		
		}
		d = day[0] - 48;
		m = (day[2] - 48)*10 + (day[3] - 48);
		y = (day[5] - 48) * 1000 + (day[6]-48) * 100 + (day[7]-48)*10 + (day[8] - 48);					
	}
	else
	{
		d = (day[0] - 48)*10 + day[1]-48;
		m = (day[3] - 48)*10 + (day[4] - 48);
		y = (day[6] - 48)*1000 + (day[7]-48) * 100 + (day[8]-48)*10 + (day[9] - 48);
	}
}
int main()
{
	char day1[10];
    char day2[10];
    int i,count=0;
    scanf("%s",day1);
    scanf("%s",day2);  
	str(day1);
	d1 = d;
	m1 = m;
	y1 = y;
	str(day2);
	d2 = d;
	m2 = m;
	y2 = y;
	luckydates(d1,m1,y1,d2,m2,y2);
	
	//printf("%d %d %d %d %d %d",d1,m1,y1,d2,m2,y2);
}
