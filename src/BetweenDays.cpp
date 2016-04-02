/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int getday(struct node *);
int getmonth(struct node *);
int getyear(struct node *);
int between_days(struct node *date1head, struct node *date2head){
	if (date1head==NULL||date2head==NULL)
		return -1;
	int day1 = getday(date1head);
	int day2 = getday(date2head);
	int month1 = getmonth(date1head);
	int month2 = getmonth(date2head);
	int year1 = getyear(date1head);
	int year2 = getyear(date2head);
	int day = day2 - day1;
	int month = month2 - month1;
	int year = year2 - year1;
	return (day + month * 31 + year * 365)-1;
}
int getmonth(struct node *datehead)
{
	int i = 0;
	int month = 0;
	for (i = 0; datehead->next != NULL; i++)
	{
		if (i >= 2 && i<4)
		{
			month = month * 10 + datehead->data;
		}
		datehead = datehead->next;
	}
	return month;
}
int getday(struct node *datehead)
{
	int i = 0;
	int day=0;
	for (i = 0; i < 2; i++)
	{
		day =day*10+ datehead->data;
		datehead = datehead->next;
	}
	return day;
}

int getyear(struct node *datehead)
{
	int i;
	int year = 0;
	for (i = 0;datehead->next!=NULL; i++)
	{
		if (i >= 4)
		{
			year = year * 10 + datehead->data;
		}
		datehead = datehead->next;
	}
	year = year * 10 + datehead->data;
	return year;
}
