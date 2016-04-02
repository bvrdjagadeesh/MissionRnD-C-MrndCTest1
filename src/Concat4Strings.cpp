/*
Given 4 strings, write a fucntion to get smallest string that consists all four strings. 
In Case of Multiple strings with smallest length,
Return the string which occurs alphabetically first .

Ex : (acat, tiger, silica, licaria) O/P: "silicariacatiger"
Ex : (def,abc,ghi,jkl)   O/P : “abcdefghijkl” (Alphabetically first )
Ex : (apple,pp,pineapple,nea) O/P: "pineapple";
Ex : (zzzabc,abcdef,yyyzzz,cabyyy) O/P: "cabyyyzzzabcdef" (Order Swapped )

Note : Each string given as input ,should be in the same format in the output string. 
Ie if input string is abcd ,it cannot be modified as bdca in the final string .

The Order of Strings in the Final string ,maynot be in the same order 
given in which they are given
Function Signatue : char * smallestword(char *s1,char *s2,char *s3,char *s4);

Note : You can use String.h functions .

Constraints : 
Length of each String will be less than 100 .

Difficulty : Hard
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char* concatinate(char*, char*, int, int);
int getlen(char*);
char * concat_4strings(char *s1, char *s2, char *s3, char *s4){
	//Return the new string created.
	if (s1==NULL||s2==NULL||s3==NULL||s4==NULL)
		return NULL;
	int len1 = getlen(s1);
	int len2 = getlen(s2);
	int len3 = getlen(s3);
	int len4 = getlen(s4);
	s1 = concatinate(s1, s2, len1, len2);
	s1 = concatinate(s1, s3, len1 + len2, len3);
	s1 = concatinate(s1, s4, len1 + len2 + len3, len4);
	return s1;
}
int getlen(char *s)
{
	int i = 0;
	for (i = 0; s[i] != '\0'; ++i);
	return i;
}
char* concatinate(char *s1, char *s2,int len1,int len2)
{
	int i, j;
	if (len1 > len2)
	{
		for (i = 0; s1[i] != '\0'; ++i);
		for (j = 0; s2[j] != '\0'; ++j, ++i)
		{
			s1[i] = s2[j];
		}
		s1[i] = '\0';
		return s1;
	}
	else if (len2 > len1)
	{
		for (i = 0; s2[i] != '\0'; ++i);
		for (j = 0; s1[j] != '\0'; ++j, ++i)
		{
			s2[i] = s1[j];
		}
		s2[i] = '\0';
		return s2;
	}
	else
	{
		if (s1>s2)
		{
			for (i = 0; s1[i] != '\0'; ++i);
			for (j = 0; s2[j] != '\0'; ++j, ++i)
			{
				s1[i] = s2[j];
			}
			s1[i] = '\0';
			return s1;
		}
		else{
			for (i = 0; s2[i] != '\0'; ++i);
			for (j = 0; s1[j] != '\0'; ++j, ++i)
			{
				s2[i] = s1[j];
			}
			s2[i] = '\0';
			return s2;
		}
	}
}