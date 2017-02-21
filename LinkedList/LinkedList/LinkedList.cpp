#include <iostream>

using namespace std;
//Defining structs
struct Node{
	string firstname[10];
	string lastname[10];
	int grade;

	Node* next; //Stores Next node PTR.
	Node* prv;

};
//Defining Constant/initiallizing variables
string name;
char ans;
Node* curr = NULL;
Node* head = NULL;//Initiallizing head
char ch1; //Throwaway 

//Defining function calls

struct Node* newentry(Node* head,Node* prev){         //returns the address of this new Node 
	Node* tmp1 = prev;//Store the location of previous linked list.
	Node *tmp = (struct Node*)malloc(sizeof(struct Node));	
	printf("Please enter student first name \n");
	scanf("%s", &tmp->firstname);
	printf("Please enter student last name");
	scanf("%s", &tmp->lastname);
	printf("Please enter student grade");
	scanf("%i", &tmp->grade);
	scanf("%c", &ch1);//Gets rid of the enter keystroke.

	if (head == NULL){//If list is starting
		head = tmp;
		tmp->next = NULL;
		tmp->prv = NULL;
		return tmp;//Returns the List Header location
	}
	else{//Header has been defined 
		while (head->next == NULL){ head->next = prev; prev->prv = head; };//To fill in the next node for header. Only used for second item in list.
		/// This code is for list size greater than 2
		tmp1->next = tmp;//The nxt location of prev is current list.
		tmp->next = NULL;
		tmp->prv = prev;
		return tmp;//Returns the location of the current/latest Node
		///
	}

	
}

void Print(Node* Head){
	if (Head == NULL){
		return;
	}
	printf("First Name is %s \n", Head->firstname);
	printf("Last Name is %s \n", Head->lastname);
	printf("Grade is %i \n", Head->grade);
	Print(Head->next);
}

int main()
{

	printf("Would you like to continue adding names?");
	scanf("%c", &ans);
	while (ans == 'y'){
			if (head == NULL){//If list is starting
				head = newentry(head, curr);//Update the location of header.
				
				curr = head;
			}
			else{
				
				curr= newentry(head,curr);//Update the location of current Node.
			}
			printf("Would you like to continue adding names?");
			scanf("%c", &ans);
		
	}

	Print(head);
	while (ans != 'y'){}

}