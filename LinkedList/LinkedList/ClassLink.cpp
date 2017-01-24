//If you just create Node tmp, it associates a pointer to the tmp. 
//Just list<Node> si, associates  a beginner pointer to si, but doesnt initialize it? Must be initiallized with a value. And you cant use scanf directly to 
//initialize as it required a pointer to memory address inorder to scan info in.
using namespace std;
#include <iostream>
#include <list>
#include <vector>
#include<new.h>

const int namesize = 10;
struct Node{
	char firstname[namesize];
	char lastname[namesize];
	int grade;
};

//Declaring Constants 
char t;//trash
char c;

//list<Node> si;//student info
list<Node*> *si = new list<Node*>;//Create a new list of pointer to Nodes, the list is named si, and si stores the pointer to it.
list<Node*>::iterator it;//Iterator of class, list<Node*>(Pointer to a Nodes within list);
int p = 0;// Keeps track off the number of item in list
char ans;//Stores the value returned.
char ch1;//Gets rid of enter key strokes from scanf.
//

void add(){
	Node *tmp = new Node;// If you create new of anything it returns a pointer, which is stored in *tmp of type Node in this case.


	printf("Please enter student first name \n");
	scanf("%s", &tmp->firstname);//Accesses the firstname within the tmp struct
	printf("Please enter student last name\n");
	scanf("%s", &tmp->lastname);
	printf("Please enter student grade\n");
	scanf("%i", &tmp->grade);
	scanf("%c", &ch1);
	//printf("%i   %i   %i  %s   %i\n", tmp->firstname, tmp, &(tmp->lastname), (tmp->lastname), &tmp);
	si->push_back(tmp);//sticks a pointer to the current tmp Node, at the end of si,


}

int location(list<Node*> ::iterator i, list<Node*> ::iterator f, list<Node*> ::iterator val){
	list<Node*>::iterator t;
	int tmp = 0;
	for (t = i; t != f; t++){//Start iterator at t, increment by 1 till f, return tmp when found value.
		if (t == val){
			return tmp;
		}
		tmp++;//only increments if, if statement is falsel. Val doesnt match location of pointer.
		
	} printf("Value not foud \n"); return NULL;
}

list<Node*>::iterator search(list<Node*>::iterator i, list<Node*>::iterator l){//Send the iterator pointing to the first item in list.
	char FName[namesize];
	list<Node*>::iterator k = i;//Set initial to beginning of list
	printf("What is the first name of the student you would like to search? \n");
	scanf("%s", &FName);
	for (k = i; k != l; k++){//If second bool is true stay in loop
		//char* tmp[namesize] = { (*k)->firstname };
		//char* tmp1[namesize] = { (*k)->lastname };//Star k is a pointer. tmp1 is now pointing too it
		if (strcmp(FName, { (*k)->firstname }) == 0){
			int tmp = location(i, l, k);
			printf("Student Located at %i, Grade is %i\n", tmp , (*k)->grade);
			return k;
		}


	} printf("Student Not found!\n"); 
}



void print(list<Node*>:: iterator i, list<Node*>:: iterator l){
	list<Node*>:: iterator it;
	for (it = i; it != l; ++it){
		printf(" First name is %s, Last name is %s, and Grade is %i \n", (*it)->firstname, (*it)->lastname, (*it)->grade);//it is an iterator which points to 
		//different items within a list. This iterator is of class list<Node*> 
	}
}
int main(){

	
	
	
	printf("What would you like to do?, 'a' (add), 's' (search)\n");
	scanf("%c", &ans);
	do {
		if (ans == 'a'){
			add();
		}if (ans == 's'){
			it = search(si->begin(), si->end());
		}if (ans == 'p'){
			print(si->begin(), si->end());
			
		}
	
	printf("What would you like to do?, 'a' (add), 's' (search)\n");
	scanf("%c", &ans);

	} while (ans == 'p' || 'a' || 's');


	

	scanf("%c   ", &t);
}




/*list<int> i;
list<int>::iterator ik;


int main(){	
	ik = i.begin();

	printf("continue? \n");
	scanf("%c", &c);
	
	while (c == 'y'){
		int tmp;
		scanf("%i", &tmp);
		scanf("%c", &t);
    i.insert(ik, tmp);
	//tmp = *ik;
	//++ik;
	 printf("continue? \n");
	 scanf("%c", &c);
	}
		ik = i.begin();
		//int k = *ik;
		 ++ik;
		 printf("%i\n", *ik);
		 ++ik; 
	printf("%i (%i) %f %f   \n", (*ik),i,&i,ik);
	++ik; //++ik;


	
	for (ik = i.begin(); ik != i.end(); ++ik){
		printf("%i  %i \n" , (*ik),ik);
	
		//std::cout << ' ' << *ik;
	}
	scanf("%c ", &c);

}*/