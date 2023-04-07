#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int element;
  struct node *next;
} ;

typedef struct node* PointerToNode;
typedef PointerToNode List;
typedef PointerToNode Position;

// Function Prototypes (or signatures)
int IsEmpty(myLinkedlist L);//done
int IsLast(Position P);

List createHeaderNode(int value);

void insert(struct node* p, int n);
void deleteN(int x, List L);

Position Find(int x, List LL);
Position FindPrevious(int x, List LL);

void printLinkedList(List L);

int main(int argc, char *argv[])
{

  List myLinkedList;
  myLinkedList = createHeaderNode(0);

  printLinkedList(myLinkedList);

  printf("\n -+- \n");

  for (int i = 1; i < 6; i++)
  {
    insert(myLinkedList,i);
    printLinkedList(myLinkedList);
  }

  printf("\n --- \n");

  for (int i = 1; i < 6; i += 2)
  {
    deleteN(i, myLinkedList);
    printLinkedList(myLinkedList);
  }

  printf("\n -*- \n");

  printLinkedList(myLinkedList);

  return 0;
}

void printLinkedList(List L)
{
  List P = L;

  if (P->next == NULL)
  {
    printf("<Empty List>\n");
    return;
  }

  P = P->next;

  while (P != NULL)
  {
    printf("%d ", P->element);
    P = P->next;
  }

  printf("\n");
}

List createHeaderNode(int value)
{
  List temp;

  temp = (List)malloc(sizeof(struct node));
  temp->element = value;
  temp->next = NULL;

  return temp;
}

void insert(struct node *p, int n)
{
 

  position newNode = malloc(sizeof(struct node));
  newNode->element = n;
  newNode->next = p->next;
  p->next = newNode;

  
}

int IsEmpty( List L)
{
 return L->next=NULL;
}

int IsLast(Position P)
{
 return p->next=NULL;
}

Position Find(int x, List L)
{
    Position P;
    P = L->Next;
         
    while(P != NULL && P->element !=x)
    {
    
      P = P->Next;
    }
          
    return P;
}

Position FindPrevious(int x, List L)
{
   Position P = L;

    while ( P->Next != NULL && P->Next->element!=x)
    {
     if (P->Next->element == x)  // Does the next node contains the desired x?
        break;
        
     P = P->Next;
    }

    return P;
}

void deleteN(int x, List L)
{
    Position P, Temp;

    P = FindPrevious(x, L);

    if (!IsLast(P))
    {
     Temp = P->Next;
     P->Next = Temp->Next;
     free(Temp);
    }
}

