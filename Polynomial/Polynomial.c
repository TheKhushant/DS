#include<stdio.h>
#include<conio.h>
#define max 10
struct item
{
	int coeff;
	int exp;
};
struct poly
{
	struct item Ply[max];
	int terms;
};
struct poly create_poly();
void display_poly(struct poly);
void poly add_poly(struct poly, struct poly);
void main()
{
	struct poly P;
	int i,n;
	clrscr();
	P = create_poly();
	Q = create_poly();
	printf("first Poly : ");
	display_poly(P);
	printf("second Poly : ");
	display_poly(Q);
	R = add_poly(P,Q);
	printf("\nResultant Poly : ");
	display_poly(R);
}
struct poly create_poly(void)
{
	struct poly P;
	int i,n;
	printf("enter no. of term of polynomial : ");
	scanf("%d",&n);
	P.terms=n;
	printf("Enter %d terms of polynomial : ",n);
	for(i = 0; i<n;i++)
	{
		printf("\nenter %d term coefficient and exponent vlue : ",i+1);
		scanf("%d%d",&P.Ply[i].coeff,&P.Ply[i].exp);
	}
	return(P);
}
void display_poly(struct poly P)
{
	int i;
	for(i=0;i<P.terms;i++)
	{
		if(P.Ply[i].exp>0)
		{

			if(P.Ply[i].coeff==0)
				continue;
			else if(P.Ply[i].coeff<0)
			{
			   printf("\b\b");
			   printf("%dx^%d + ",P.Ply[i].coeff,P.Ply[i].exp);
			}
			else
			{
				printf("%dx^%d + ",P.Ply[i].coeff,P.Ply[i].exp);
			}
		}
		else if(P.Ply[i].coeff<0)
		{
			printf("\b\b");
			printf("%d",P.Ply[i].coeff);
		}
		else if(P.Ply[i].coeff>0)
		{
			printf("%d",P.Ply[i].coeff);
		}
		else
		{
			printf("\b\b");
		}
	}
	if(P.Ply[P.terms-1].exp!=0)
		printf("\b\b ");
	getch();
}
struct poly add_poly(struct poly X, struct poly Y)
{
	struct poly Z;
	int i,j,k,s;
	i=j=k=0;
	while(i<X.terms && j<Y.terms)
	{
		if(X.Ply[i].exp>Y.Ply[j].exp)
		{
			Z.Ply[k].coeff=X.Ply[i].coeff;
			Z.Ply[k].exp=X.Ply[i].exp;
			i++; k++;
		}
		else if(X.Ply[i].exp<Y.Ply[j].exp)
		{
			Z.Ply[k].coeff=Y.Ply[j].coeff;
			Z.Ply[k].exp=Y.Ply[j].exp;
			j++; k++;
		}
		else
		{
			s = X.Ply[i].coeff=Y.Ply[j].coeff;
			if(s!=0)
			{
				Z.Ply[k].coeff=s;
				Z.Ply[k].exp=X.Ply[i].exp;
				k++;
			}
			i++;j++;
		}
	}
	while(i<X.tems)
	{
		Z.Ply[k].coeff=X.Ply[i].coeff;
		Z.Ply[k].exp=X.Ply[i].exp;
		i++;k++;
	}
	while(j<Y.terms)
	{
		Z.Ply[k].coeff=Y.Ply[j].coeff;
		Z.Ply[k].exp=Y.Ply[j].exp;
		j++;k++;
	}
	Z.terms = k;
	return Z;
}
