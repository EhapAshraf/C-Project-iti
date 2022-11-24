#include <stdio.h>
#include"STD_TYPES.h"
#include <stdlib.h>
typedef struct Node
{
	u8 Data;
	struct Node *Next;
}Node;

void Linkedlist_voidInsertAtHead(u8 copy_u8UserData);
void Linkedlist_voidInsertAtTail(u8 copy_u8UserData);
void Linkedlist_voidTraverse(void);
u8 Linkedlist_voidDelete(u8 copy_u8UserData);

Node * HeadNode=NULL;

void main(void)
{
		Linkedlist_voidInsertAtTail(3);
		Linkedlist_voidInsertAtTail(4);
		Linkedlist_voidInsertAtTail(5);
		Linkedlist_voidDelete(4);
		Linkedlist_voidTraverse();
}

void Linkedlist_voidInsertAtHead(u8 copy_u8UserData)
{
	Node * NewNode=(Node *)malloc(sizeof(Node));
	NewNode->Data=copy_u8UserData;
	NewNode->Next=HeadNode;
	HeadNode=NewNode;
	
}
void Linkedlist_voidInsertAtTail(u8 copy_u8UserData)
{
	Node * NewNode=( Node *)malloc(sizeof(Node));
	NewNode->Data=copy_u8UserData;
	NewNode->Next=NULL;
	if(HeadNode==NULL)
	{
		HeadNode=NewNode;
	}
	else
	{
		Node *TempNode=HeadNode;
		while(TempNode->Next!=NULL)
		{
			TempNode=TempNode->Next;
		}
		TempNode->Next=NewNode;
	}
}
void Linkedlist_voidTraverse(void)
{
	Node* CurrentNode=HeadNode;
	while(CurrentNode!=NULL)
	{
		printf("%d\n",CurrentNode->Data);
		CurrentNode=CurrentNode->Next;
	}
}
u8 Linkedlist_voidDelete(u8 copy_u8UserData)
{
	Node* CurrentNode=HeadNode;
	Node* PreviousNode=HeadNode;
	 CurrentNode = HeadNode;
    if(CurrentNode == NULL)
    {
        printf("The Linked List Is Empty, Please Insert Some Data\n");
        return 2;
    }
    else
    {
        while( (CurrentNode != NULL) && (CurrentNode -> Data != copy_u8UserData) )
        {
            PreviousNode = CurrentNode;
            CurrentNode = CurrentNode -> Next;
        }
        if(CurrentNode == NULL)
        {
            printf("The Entered Data \"%d\" Does Not Exists\n", copy_u8UserData);
            return 1;
        }
        else
        {
            if(copy_u8UserData == HeadNode -> Data)
            {
                HeadNode = HeadNode -> Next;
                free(CurrentNode);
            }
            else
            {
                PreviousNode -> Next = CurrentNode -> Next;
                free(CurrentNode);
            }
            printf("The Entered Data Has Been Deleted Successfully \n");
            return 0;
        }
    }
}
