#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

void display(struct node *head)
{
	int c = 0;
	if(head==NULL)
	{
		printf("\nLinked list empty!\n");
        return;
	}
	struct node *p = NULL;
	p=head;
	
    printf("\nList is : \n");
	while(p!=NULL)
	{
		c++;
		printf("%d\n",p->data);
		p = p->link;
	}
	printf("\nNo of nodes = %d\n",c);
}

int count(struct node *head)
{
	int c = 0;
	if(head==NULL)
	{
		return 0;
	}
	struct node *p = NULL;
	p=head;
	
	while(p!=NULL)
	{
		c++;
		p = p->link;
	}
	return c;
}

struct node* initialize(struct node *head, int d)
{
    head = (struct node *)malloc(sizeof(struct node));
    head->data = d;
    head->link = NULL;
    return head;
}

struct node* createlist(struct node *head, int n)
{
	int d;
	
    if(n!=0)
    {
        printf("\nEnter Element : ");
        scanf("%d",&d);
        head = initialize(head,d);
        n--;    

        while(n--)
        {
            printf("\nEnter Element : ");
            scanf("%d",&d);

            struct node *p,*t;
            p = head;
            t = (struct node*)malloc(sizeof(struct node));
            
            t->data = d;
            t->link = NULL;
            
            while(p->link != NULL)
            {
                p = p->link;
            }
            p->link = t;

        }

    }
    else
    {
        head=NULL;
    }
	return head;
}

struct node* add_beg(struct node* head, int d)
{
	struct node *p = malloc(sizeof(struct node));
	p->data = d;
	p->link = NULL;
	p->link = head;
	head = p;
	return head;
}

void add_end(struct node *head, int d)
{
	struct node *p,*t;
	p = head;
	t = (struct node*)malloc(sizeof(struct node));
	
    if(head!=NULL)
    {
	    t->data = d;
        t->link = NULL;
        
        while(p->link!=NULL)
        {
            p = p->link;
        }
        p->link = t;
    }
    else
    {
        printf("\nNo linked list.!\n");
    }
}

void add_pos(struct node* head, int pos, int d)
{
	struct node *p = head;
	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = d;
	newnode->link = NULL;
    if(pos==0)
    {
        printf("\nNot a valid position\n");
        return;
    }

	if(pos==1)
	{
		printf("\nUse another function\n");
	}
	else
	{
	
		if(count(head)<pos)
		{
			printf("\nNot enough nodes\n");
		}
		
		else
		{
			pos--;
		
			while(pos != 1)
			{
				p = p->link;
				pos--;
			}
			
			newnode->link = p->link;
			p->link = newnode;
		}
	}
	
}

struct node* del_beg(struct node* head)
{
	if(head==NULL)
	{
		printf("\nAlready Empty\n");
	}
	else
	{
		struct node *p = head;
		head = head->link;
		free(p);
	}
	
	return head;
}


struct node* del_end(struct node* head)
{
	if(head==NULL)
	{
		printf("\nList is empty");
	}
	else if(head->link==NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		struct node *p = head;
		struct node *t = head;
		
		while(p->link != NULL)
		{
			t = p;
			p = p->link;
		}
		
		t->link = NULL;
		free(p);
		p=NULL;
		
	}
	return head;
}

void del_pos(struct node **head, int pos)
{
	struct node *current = *head;
	struct node *prev = *head;

    if(pos==0 || count(*head)<pos)
    {
        printf("\nNot a valid position.!!\n");
        return;
    }
	
	if(*head==NULL)
	{
		printf("\nList is empty\n");
	}
	else if(pos==1)
	{
		*head = current->link;
		free(current);
		current = NULL;
	}
	else
	{
		while(pos != 1)
		{
			prev = current;
			current = current->link;
			pos--;
		}
		
		prev->link=current->link;
		free(current);
		current = NULL;
	}
}

void search(struct node *head, int s)
{
    int c = 0,found=0;
	if(head==NULL)
	{
		printf("\nLinked list empty!\n");
        return;
	}
	struct node *p = NULL;
	p=head;
	
	while(p!=NULL)
	{
        c++;
        if(p->data==s)
        {
            printf("\nThe element %d is found at position %d\n",s,c);
            found = 1;
            return;
        }
		p = p->link;
	}
    if(found==0)
    {
        printf("\nElement %d not present in the list\n",s);
    }
}

void oddeven(struct node *head)
{
    int even=0,odd=0;
	if(head==NULL)
	{
		printf("\nEven : 0\tOdd : 0\n");
        return;
	}
	struct node *p = NULL;
	p=head;
	
    printf("\nList is : \n");
	while(p!=NULL)
	{
		if(p->data%2==0)
        {
            even++;
        }
        else
        {
            odd++;
        }
		p = p->link;
	}
    printf("\nEven : %d\tOdd : %d\n",even,odd);
}

void maximum(struct node *head)
{
	int maxi=head->data;

	if(head==NULL)
	{
		printf("\nLinked list empty! No maximum!\n");
        return;
	}
	struct node *p = NULL;
	p=head;
	
	while(p!=NULL)
	{
        if(maxi<p->data)
        {
            maxi = p->data;
        }
		p = p->link;
	}
	printf("\nMaximum = %d\n",maxi);
}

void nonzero(struct node *head)
{
	int c = 0;
	if(head==NULL)
	{
        printf("\nList is empty so no non zero elements\n");
		return ;
	}
	struct node *p = NULL;
	p=head;
	
	while(p!=NULL)
	{
        if(p->data!=0)
        {
            c++;
        }
		p = p->link;
	}

    printf("\nThe number of non zero elements are : %d\n",c);
}


int main()
{
    struct node *head;
    int n;
    int c,thedata,thepos;
    head = NULL;

    printf("Create your list.!\n");
    printf("\nEnter the number of elements in the list : ");
    scanf("%d",&n);

    head = createlist(head,n);
    display(head);

    printf("\nOperations you wanna do with the list : \n");
    while(1)
    {
        printf("\n\n[+] 1.  Insert at beggining");
        printf("\n[+] 2.  Insert at end");
        printf("\n[+] 3.  Insert at position");
        printf("\n[+] 4.  Deletion at beggining");
        printf("\n[+] 5.  Deletion at end");
        printf("\n[+] 6.  Deletion at position");
        printf("\n[+] 7.  Search an element");
        printf("\n[+] 8.  Count the even and odd values");
        printf("\n[+] 9.  Get the max value");
        printf("\n[+] 10. Get the number of non zero elements\n\n");
        
        scanf("%d",&c);
        
        switch(c)
        {
            case 1:
                printf("\nEnter the data to be sent at the beggining : ");
                scanf("%d",&thedata);
                head = add_beg(head, thedata);
                break;

            case 2:
				printf("\nEnter the data to be sent at the end : ");
				scanf("%d",&thedata);
				add_end(head, thedata);
				break;
            
            case 3:
                printf("\nEnter the data to be sent at the position : ");
                scanf("%d",&thedata);
                printf("\nEnter the position number : ");
                scanf("%d",&thepos);
                add_pos(head, thepos, thedata);
                break;

            case 4:
                head = del_beg(head);
                printf("\nData at the beggining deleted\n");
                break;
					
            case 5:
                head = del_end(head);
                printf("\nData at the end deleted\n");
                break;

            case 6:
                printf("\nEnter the position to be deleted : ");
                scanf("%d",&thepos);
                del_pos(&head, thepos);
                break;

            case 7:
                printf("\nEnter the element you want to search for : ");
                scanf("%d",&thedata);
                search(head, thedata);
                break;

            case 8:
                oddeven(head);
                break;

            case 9:
                maximum(head);
                break;

            case 10:
                nonzero(head);
                break;
                
            default:
                printf("\nThat's rude\n");
                break;
        }
        
        printf("\nThe elements in the list are\n");
        display(head);
    }
    


    return 0;
}
