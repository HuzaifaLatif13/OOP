#include"Teacher.h"

Teacher::Teacher(const char *arr,int n)
{
    name=new char[30];
    int i=0;
    while(arr[i]!='\0')
    {
        name[i]=arr[i];
        i++;
    }
    name[i]='\0';
    oen=n;
}