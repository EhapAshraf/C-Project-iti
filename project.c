#include <stdio.h>
#include"STD_TYPES.h"
#include <stdlib.h>
#include<string.h> 
typedef struct Student
{
	u32 ID;
	f32 GPA;
	u8 Name[20];
	u8 Phone[20];
	u8 BD[20];
	u8 Address[100];
	struct Student *Next;
}Student;
void Linkedlist_voidMainMenue(void);
void Linkedlist_voidInsertAtTail(u32 ID,f32 GPA,u8* Name,u8* Phone,u8* BD,u8* Address);
void Linkedlist_voidTraverse(void);
void Linkedlist_voidRank(void);
u8 Linkedlist_u8Delete(u32 ID);
u8 Linkedlist_u8CheckName(u8* Name);
void Linkedlist_voidEdit(u32 ID,f32 GPA,u8* Name,u8* Phone,u8* BD,u8* Address);
void Linkedlist_voidEditScore(u32 ID);
Student * HeadNode=NULL;
u8 count=0;
int main(void)
{


	u32 ID;
	f32 GPA;
	u8 Name[20];
	u8 Phone[20];
	u8 BD[20];
	u8 Address[100];
	u8 option;
	
		while(1)
		{
			Linkedlist_voidMainMenue();
			scanf("%d",&option);
			fflush(stdin);
			switch(option)
			{
				fflush(stdin);
				case 1: 
				printf("Enter The Student Name\n");
				gets(Name);
				printf("Enter The Student ID\n");
				scanf("%d",&ID);
				printf("Enter The Student GPA\n");
				scanf("%f",&GPA);
				fflush(stdin);
				printf("Enter The Student Date Of Birth\n");
				gets(BD);
				printf("Enter The Student Address\n");
				gets(Address);
				printf("Enter The Student Phone Number\n");
				gets(Phone);
				Linkedlist_voidInsertAtTail(ID,GPA,Name,Phone,BD,Address);
					count++;
					break;
				case 2:
				printf("please enter the student id you wanna delete: ");
				scanf("%d",&ID);
				Linkedlist_u8Delete(ID);
					count--;
					break;
				case 3: Linkedlist_voidTraverse();
					break;
				case 4: 
				printf("please enter the student Name you wanna Edit: ");
				gets(Name);
				if(!Linkedlist_u8CheckName(Name))
				{
				printf("Enter The New Student GPA\n");
				scanf("%f",&GPA);
				fflush(stdin);
				printf("Enter The New Student Date Of Birth\n");
				gets(BD);
				printf("Enter The New Student Address\n");
				gets(Address);
				printf("Enter The New Student Phone Number\n");
				gets(Phone);
				Linkedlist_voidEdit(ID,GPA,Name,Phone,BD,Address);
					break;
				}
				else 
				{
					break;
				}
				case 5: 
				Linkedlist_voidRank();
					break;
				case 6: 
				printf("Please Enter The ID Of Student you Wanna Change GPA\n");
				scanf("%d",&ID);
				Linkedlist_voidEditScore(ID);
					break;
				default: printf("You choose Wrong Number\n");
			}
			option=0;
		}

return 0;
}

/***************************************************
***************** Main Menue ***********************
****************************************************/

void Linkedlist_voidMainMenue(void)
{
	printf("-------------------------------\n");
	printf("*****Welcome To School*****\n");
	printf("Choose (1) To Add New Student\n");
	printf("Choose (2) To Dlete Student\n");
	printf("Choose (3) To View Student Info\n");
	printf("Choose (4) To Edit Student Info\n");
	printf("Choose (5) To Rank Students\n");
	printf("Choose (6) To Update GPA\n");
	printf("-------------------------------\n");
}


/***************************************************
***************** ADD Student **********************
****************************************************/

void Linkedlist_voidInsertAtTail(u32 ID,f32 GPA,u8* Name,u8* Phone,u8* BD,u8* Address)
{
	Student * NewNode=( Student *)malloc(sizeof(Student));
	NewNode->ID=ID;
	NewNode->GPA=GPA;
for(u8 i=0;i<20;i++)
	{
	NewNode->Name[i]=Name[i];
	}
	
	for(u8 i=0;i<20;i++)
	{
	NewNode->Phone[i]=Phone[i];
	}

	for(u8 i=0;i<20;i++)
	{
	NewNode->BD[i]=BD[i];
	}
	
	for(u8 i=0;i<20;i++)
	{
	NewNode->Address[i]=Address[i];
	}
	NewNode->Next=NULL;
	if(HeadNode==NULL)
	{
		HeadNode=NewNode;
	}
	else
	{
		Student *TempNode=HeadNode;
		while(TempNode->Next!=NULL)
		{
			TempNode=TempNode->Next;
		}
		TempNode->Next=NewNode;
	}

}


/***************************************************
***************** View All Students ****************
****************************************************/

void Linkedlist_voidTraverse(void)
{
	Student* CurrentNode=HeadNode;
	while(CurrentNode!=NULL)
	{
		printf("\nStudent Name is: %s\n",CurrentNode->Name);
		printf("Student Date Of Birth is: %s\n",CurrentNode->BD);
		printf("Student Address is: %s\n",CurrentNode->Address);
		printf("Student Phone Number is: %s\n",CurrentNode->Phone);
		printf("ID is: %d\n",CurrentNode->ID);
		printf("GPA is:  %.2f\n\n\n",CurrentNode->GPA);
		
		CurrentNode=CurrentNode->Next;
	}
}

/***************************************************
***************** Delete Student *******************
****************************************************/

u8 Linkedlist_u8Delete(u32 ID)
{
	Student* CurrentNode=HeadNode;
	Student* PreviousNode=HeadNode;
    if(CurrentNode == NULL)
    {
        printf("The List Is Empty, Please Insert Some Data\n");
        return 2;
    }
    else
    {
        while( (CurrentNode != NULL) && (CurrentNode -> ID != ID) )
        {
            PreviousNode = CurrentNode;
            CurrentNode = CurrentNode -> Next;
        }
        if(CurrentNode == NULL)
        {
            printf("The Entered Data \"%d\" Does Not Exist\n", ID);
            return 1;
        }
        else
        {
            if(ID == HeadNode -> ID)
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

/***************************************************
***************** Check Name ***********************
****************************************************/

u8 Linkedlist_u8CheckName(u8* Name)
{
	Student* NewNode=HeadNode;
    if(NewNode == NULL)
    {
        printf("The List Is Empty, Please Insert Some Data\n");
        return 2;
    }
    else
    {
		
		while( (NewNode != NULL) && ((strcmp(NewNode -> Name,Name))!=0) )
		{
			NewNode = NewNode -> Next;
		}
		
		if(NewNode == NULL)
		{
			printf("The Name \"%s\" Does Not Exist\n", Name);
			return 1;
		}	
		else
		{
			return 0;
		}
	}

}

/***************************************************
***************** Edit Student Info ****************
****************************************************/

void Linkedlist_voidEdit(u32 ID,f32 GPA,u8* Name,u8* Phone,u8* BD,u8* Address)
{
	Student* NewNode=HeadNode;
	 NewNode = HeadNode;
        while(((strcmp(NewNode -> Name,Name))!=0) )
			{
				NewNode = NewNode -> Next;
			}
			
			NewNode->GPA=GPA;
			for(u8 i=0;i<20;i++)
			{
			NewNode->Name[i]=Name[i];
			}
			
			for(u8 i=0;i<20;i++)
			{
			NewNode->Phone[i]=Phone[i];
			}

			for(u8 i=0;i<20;i++)
			{
			NewNode->BD[i]=BD[i];
			}
			
			for(u8 i=0;i<20;i++)
			{
			NewNode->Address[i]=Address[i];
			}
			printf("The Entered Data Has Been Updated Successfully \n");
						
}

/***************************************************
********** Rank All Student Based On GPA ***********
****************************************************/

void Linkedlist_voidRank(void)
{
	Student* CurrentNode=HeadNode;
	Student* NextNode=HeadNode;
	Student TempNode;

    if(CurrentNode == NULL)
    {
        printf("No Data To be Ranked, Please Insert Some Data\n");
       
    }
    else
    {
			
			for(u8 j=0;j<count;j++)
			{
				
				
				NextNode=CurrentNode->Next;
				while( (NextNode != NULL)  )
				{
					if(NextNode -> GPA > CurrentNode-> GPA)
					{

						TempNode.ID=NextNode->ID;
						TempNode.GPA=NextNode->GPA;
						
							for(u8 i=0;i<20;i++)
							{
								TempNode.Name[i]=NextNode->Name[i];
							}
							
							for(u8 i=0;i<20;i++)
							{
								TempNode.Phone[i]=NextNode->Phone[i];
							}

							for(u8 i=0;i<20;i++)
							{
								TempNode.BD[i]=NextNode->BD[i];
							}
							
							for(u8 i=0;i<20;i++)
							{
								TempNode.Address[i]=NextNode->Address[i];
							}
							
							
							NextNode->ID=CurrentNode->ID;
							NextNode->GPA=CurrentNode->GPA;
							for(u8 i=0;i<20;i++)
							{
								NextNode->Name[i]=CurrentNode->Name[i];
							}
							
							for(u8 i=0;i<20;i++)
							{
								NextNode->Phone[i]=CurrentNode->Phone[i];
							}

							for(u8 i=0;i<20;i++)
							{
								NextNode->BD[i]=CurrentNode->BD[i];
							}
							
							for(u8 i=0;i<20;i++)
							{
								NextNode->Address[i]=CurrentNode->Address[i];
							}
							CurrentNode->ID=TempNode.ID;
							CurrentNode->GPA=TempNode.GPA;
							for(u8 i=0;i<20;i++)
							{
								CurrentNode->Name[i]=TempNode.Name[i];
							}
							
							for(u8 i=0;i<20;i++)
							{
								CurrentNode->Phone[i]=TempNode.Phone[i];
							}

							for(u8 i=0;i<20;i++)
							{
								CurrentNode->BD[i]=TempNode.BD[i];
							}
							
							for(u8 i=0;i<20;i++)
							{
								CurrentNode->Address[i]=TempNode.Address[i];
							}
							
							
							NextNode=NextNode->Next;
					}
					else 
					{
						
						NextNode=NextNode->Next;
					}
				}
				CurrentNode=CurrentNode->Next;
			}
		
		printf("\nSuccessfully\n");
        
    }
}

/***************************************************
********** Update Score Of All Students ************
****************************************************/

void Linkedlist_voidEditScore(u32 ID)
{

	Student* CurrentNode=HeadNode;
	Student*PreviousNode=HeadNode;

    if(CurrentNode == NULL)
    {
        printf("No Data To be Edited, Please Insert Some Data\n");
       
    }
    else
    {
		
		while( (CurrentNode != NULL) && (CurrentNode -> ID != ID) )
        {
            CurrentNode = CurrentNode -> Next;
        }
        if(CurrentNode == NULL)
        {
            printf("The Entered Data \"%d\" Does Not Exist\n", ID);

        }
        else
		{
			f32 new;
			printf("You Choose The Student %s and Has GPA = %.2f \n",CurrentNode->Name,CurrentNode->GPA);
			printf("please Enter New GPA\n");
			scanf("%f",&new);
			CurrentNode -> GPA=new;

		
		printf("\nSuccessfully\n");
	   
			
        }
    }

	
}
