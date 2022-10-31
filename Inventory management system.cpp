#include<stdlib.h>
#include<string.h>
#include<stdio.h>
# define max 5
struct Inventory
{
    int productid;
    int qty;
    char name[100];
    float price;
    struct Inventory *next;

}* head;

void insert(int productid, char* name, float price,int qty)
{

    struct Inventory * product = (struct Inventory *) malloc(sizeof(struct Inventory));
    product->productid = productid;
    strcpy(product->name, name);
    product->price = price;
    product->qty = qty;
    product->next = NULL;

    if(head==NULL){
        head = product;
    }
    else{
        product->next = head;
        head = product;
    }

}
void search(int productid)
{
    struct Inventory * temp = head;
    while(temp!=NULL){
        if(temp->productid==productid){
            printf("\n\tProduct ID: %d\n", temp->productid);
            printf("\n\tProduct name: %s\n", temp->name);
            printf("\n\tPrice: Rs.%.2f\n", temp->price);
            printf("\n\tQuantity: %d\n", temp->qty);
            return;
        }
        temp = temp->next;
    }
    printf("Product with id %d is not found !!!\n", productid);
}
void update(int productid)
{

    struct Inventory * temp = head;
    while(temp!=NULL){

        if(temp->productid==productid){
            printf("\n\tDetails with id %d Found !!!\n", productid);
            printf("\n\tEnter new name: ");
            scanf("%s", temp->name);
            printf("\n\tEnter new price: ");
            scanf("%f",&temp->price);
            printf("\n\tEnter new quantity: ");
            scanf("%d",&temp->qty);
            printf("\n\tChanged Successfully!!!\n");
            return;
        }
        temp = temp->next;

    }
    printf("\n\tProduct with id %d is not found !!!\n", productid);

}
void Delete(int productid)
{
    struct Inventory * temp1 = head;
    struct Inventory * temp2 = head;
    while(temp1!=NULL){

        if(temp1->productid==productid){

            printf("\n\tDetails with id %d Found !!!\n", productid);

            if(temp1==temp2){

                head = head->next;
                free(temp1);
            }
            else{

                temp2->next = temp1->next;
                free(temp1);
            }

            printf("\n\tProduct Deleted !!!\n");
            return;

        }
        temp2 = temp1;
        temp1 = temp1->next;

    }
    printf("\n\tProduct with id %d is not found !!!\n", productid);

}
void display()
{
    struct Inventory * temp = head;
    while(temp!=NULL){
        printf("\n\t-------------------------------");
        printf("\n\n\tProduct ID: %d\n", temp->productid);
        printf("\n\tProduct Name: %s\n", temp->name);
        printf("\n\tPrice: Rs.%0.2f\n", temp->price);
        printf("\n\tQuantity: %d\n", temp->qty);
        temp = temp->next;

    }
}

int insq(char queue[max][80], int *rear, char data[80])
{
      if(*rear == max -1)
            return(-1);
      else
      {
            *rear = *rear + 1;
            strcpy(queue[*rear], data);
            return(1);
      }
}
int delq(char queue[max][80], int *front, int *rear, char data[80])
{
      if(*front == *rear)
            return(-1);
      else
      {
            (*front)++;
            strcpy(data, queue[*front]);
            return(1);
      }
}

int main()
{
    head = NULL;
    int choice,front,rear,reply,ch,qty;
    char name[100],queue[max][80],data[80];
    int productid;
    float price;
    front=rear=-1;
    printf("\n\tINVENTORY MANAGEMENT SYSTEM");
    printf("\n\n\n\tMAIN MENU");
    printf("\n\n\t1.Add product\n\n\t2.Search product\n\n\t3.Remove product\n\n\t4.Change product details\n\n\t5.Display stocks\n\n\t6.Add Admin \n\n\t7.Remove Admin \n\n\t8.Exit");
    do
    {
        printf("\n\n\tEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\n\tEnter Product id: ");
                scanf("%d", &productid);
                printf("\n\tEnter Product Name: ");
                scanf("%s", name);
                printf("\n\tEnter Price: ");
                scanf("%f", &price);
                printf("\n\tEnter Quantity: ");
                scanf("%d", &qty);
                insert(productid, name,price,qty);
                break;
            case 2:
                printf("\n\tEnter Product ID to search: ");
                scanf("%d", &productid);
                search(productid);
                break;
            case 3:
                printf("\n\tEnter Product ID to remove: ");
                scanf("%d", &productid);
                Delete(productid);
                break;
            case 4:
                printf("\n\tEnter Product ID to change: ");
                scanf("%d", &productid);
                update(productid);
                break;
            case 5:
                display();
                break;
            case 6 :
                        printf("\n\n\tAdmin name : ");
                        scanf("%s",data);
                        reply = insq(queue, &rear, data);
                        if(reply == -1 )
                              printf("\n\n\tList full! \n");
                        else
                              printf("\n\n\tAdmin '%s' is added.\n\n",data);
                        break;
			case 7 :
                        reply = delq(queue, &front, &rear, data);
                        if( reply == -1 )
                              printf("\n\n\tNo admin present! \n");
                        else
                              printf("\n\n\tRemoved admin : %s\n", data);
                              printf("\n");
                        break;
			case 8:
			exit(0);
        }

    } while (choice != 0);
}
