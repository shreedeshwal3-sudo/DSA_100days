/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20
*/
#include<stdio.h>
#include<string.h>

int main()
{
    int n,i,size=0;
    int pq[100];

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        char op[10];
        scanf("%s",op);

        if(strcmp(op,"insert")==0)
        {
            int x;
            scanf("%d",&x);

            int j=size-1;

            while(j>=0 && pq[j]>x)
            {
                pq[j+1]=pq[j];
                j--;
            }

            pq[j+1]=x;
            size++;
        }

        else if(strcmp(op,"delete")==0)
        {
            if(size==0)
                printf("-1\n");
            else
            {
                printf("%d\n",pq[0]);

                for(int k=0;k<size-1;k++)
                    pq[k]=pq[k+1];

                size--;
            }
        }

        else if(strcmp(op,"peek")==0)
        {
            if(size==0)
                printf("-1\n");
            else
                printf("%d\n",pq[0]);
        }
    }

    return 0;
}