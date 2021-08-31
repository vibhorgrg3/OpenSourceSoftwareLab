#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *first=NULL;

void create_LL(int a[]);
void display(struct node *first_ref);
void count_elements(struct node *first);
void sum_elements(struct node *);
void _max(struct node *);
void _linear_search(struct node *);



int main(int argc, char const *argv[])
{
	int a[]={1,2,4,5,6,3,43,3};
	create_LL(a);
	display(first);
	count_elements(first);
	sum_elements(first);
	_max(first);
	_linear_search(first);
	return 0;
}

void create_LL(int a[]){
	struct node * new, *temp;
	int count=0;
	for(int i=0; i<8; i++){
		new=(struct node *)malloc(sizeof(struct node));
		if(count==0){
			first=new;
			temp=new;
			new->data=a[i];
			new->next=NULL;
			count++;
			// printf("%d",i);
		}
		else{

			new->data=a[i];
			new->next=NULL;
			temp->next=new;
			temp=new;
			// printf("%d",i);
		}
	}
}


void display(struct node *first_ref){
	struct node *p;
	p=first_ref;
	while(p->next!=NULL){
		printf("%d\n", p->data );
		p=p->next;
	}
}


void count_elements(struct node * first){
	struct node *p;
	p=first;
	int count1=1;// coz the loop stop when n next is null hence last element's count is missed
	while(p->next!=NULL){
		count1++;
		p=p->next;
	}
	printf("\nCOUNT IS %d : \n",count1);
}


void sum_elements(struct node * first){
	struct node *p;
	p=first;
	int sum1=0;// coz the loop stop when n next is null hence last element's count is missed
	while(p!=NULL){
		sum1=sum1+p->data;
		p=p->next;
	}
	printf("\nSUM IS %d : \n",sum1);

}


void _max(struct node * first){
	struct node * p;
	p=first;
	int max=p->data;
	while(p!=NULL){
		if(p->data>max){
			max=p->data;
		}
		p=p->next;
	}
	printf("\nMAX IS %d : \n",max);
}



void _linear_search(struct node *first){
	struct node *p;
	int key;
	p=first;
	printf("\nENTER ELEMNET TO SEARCH : ");
	scanf("%d",&key);
	while(p){
		if(key==p->data){
			printf("\nFOUND!!\n");
			return;
		}
		p=p->next;
	}
//	printf("\nNot Found :( :( \n");
}
