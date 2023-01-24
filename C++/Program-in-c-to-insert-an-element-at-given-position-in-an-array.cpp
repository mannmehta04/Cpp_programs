#include<stdio.h>
int main()
{
	int a[20],i,n,ele,pos;
	printf("Enter the Number of Elements: ");
	scanf("%d",&n);
	printf("\nEnter the elements of array :\n");
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	printf("\nArray enter by user are :\n");
	for(i=1;i<=n;i++)
	printf("%d\t",a[i]);
	
	printf("\nEnter the position you want to enter :");
	scanf("%d",&pos);
	printf("\nEnter the element you want to enter :");
	scanf("%d",&ele);
	for(i=n+1;i>0+1;i--)
	{
		if(i>pos)
		a[i]=a[i-1];
		else
		{
			if(i==pos)
			a[i]=ele;
			else
			a[i]=a[i];
		}
		
		
		
	}
	printf("\nArray After Inserting element :\n");
	for(i=1;i<=n+1;i++)
	printf("%d\t",a[i]);
	printf("\n\n");
	return 0;
}
