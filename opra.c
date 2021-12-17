#include<stdio.h>
int main()
{
	int nfr,npg,fr[10],pg[30],temp[10],flag1,flag2,flag3,i,j,k,pos,max,faults=0;
	printf("Enter no. of frames: ");
	scanf("%d",&nfr);
	printf("Enter no. of pages: ");
	scanf("%d",&npg);
	printf("Enter page reference string: ");
	for(i=0;i<npg;i++)
	{
		scanf("%d",&pg[i]);
	}
	for(i=0;i<nfr;i++)
	{
		fr[i]=-1;
	}
	for(i=0;i<npg;i++)
	{
		flag1=flag2=0;
		for(j=0;j<nfr;j++)
		{
			if(fr[j]==pg[i])
			{
				flag1 = flag2 = 1;
				break;
			}
		}
		if(flag1==0)
		{
			for(j=0;j<nfr;j++)
			{
				if(fr[j]==-1)
				{
					faults++;
					fr[j]=pg[i];
					flag2=1;
					break;
				}
			}
		}
		if(flag2==0)
		{
			flag3=0;
			for(j=0;j<nfr;j++)
			{
				temp[j]=-1;
				for(k=i+1;k<npg;k++)
				{
					if(fr[j]==pg[k])
					{
						temp[j]=k;
						break;
					}
				}
			}
			for(j=0;j<nfr;j++)
			{
				if(temp[j]==-1)
				{
					pos=j;
					flag3=1;
					break;
				}
			}
			if(flag3==0)
			{
				max=temp[0];
				pos=0;
				for(j=1;j<nfr;j++)
				{
					if(temp[j]>max)
					{
						max=temp[j];
						pos=j;
					}
				}
			}
			fr[pos]=pg[i];
			faults++;
		}
		printf("\n");
		for(j=0;j<nfr;j++)
		{
			printf("%d\t",fr[j]);
		}
	}
	printf("\n\nTotal Page Faults = %d",faults);
	return 0;


	
}

/*
Enter no. of frames: 3
Enter no. of pages: 7
Enter page reference string: 1 2 3 5 2 3 4

1       -1      -1
1       2       -1
1       2       3
5       2       3
5       2       3
5       2       3
4       2       3

Total Page Faults = 5
*/
