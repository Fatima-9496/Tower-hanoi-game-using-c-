/*
Group memebers:
	Ephrata Wedajo 
	Firdews Abrar
	Fatima Abayneh
	Seble Samuel
	Gelila Werkneh
*/
#include<iostream>
#include <cmath>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
int towerA[15],towerB[15],towerC[15],movecount=0;
int topA=-1,topB=-1,topC=-1,sizes=15,numd,move_to_win,temp;
bool check;

bool isEmptyA();
bool isEmptyB();
bool isEmptyC();
void menu();
void towergame();
bool moveA_to_b();
bool moveA_to_c();
bool moveb_to_a();
bool moveb_to_c();
bool movec_to_a();
bool movec_to_b();
int pushA(int val);
int pushB(int val);
int pushC(int val);
int popA();
int popB();
int popC();
void display();
void instruction();

int main()
{
	system("COLOR F4");
    menu();
    return 0;
}
void menu()
{
	c:
    cout<<"\n\n\n\t\t\t------------------------Tower Of Hanoi Game------------------------\n\n";
    cout<<"\t\t\t\t 1.play game\n";
    cout<<"\t\t\t\t 2.Game instruction\n";
    cout<<"\t\t\t\t 3.for exiting program\n\n";
    cout<<"\t\t\t\t Enter your choice: ";
    char choice;
    cin>>choice;

    while (choice < '1' || choice > '3')
{
    cout << " \n\n\t\t\t\tPlease enter a choice from numbers 1-3 " << endl;
    cin >> choice;
}
    switch(choice)
    {
    case '1':
       towergame();
       break;
    case '2':
       instruction();
       break;
    case '3':
       exit(1);
    }
}
void towergame()
{
	b:
    cout<<"\n\t\t\t\t Enter number of disc(Number of disk is between 3 and 8):";
    a:
	cin>>numd;
	system("cls");
    if (numd>2&&numd<=8){
    move_to_win=pow(2,numd)-1;
    for (int i=numd;i>0;i--)
	{
    pushA(i);
	}
	cout<<" \n\t\t\t\tEnter your move :";
	
	display();
		
    int ch;
    cin>>ch;

    do{
    switch(ch)
    {
    case 1:
        if(moveA_to_b()==false)
        {cout<<"\n\t\t\t\tIlligal move"<<endl;
        ++movecount;
        cout<<"\t\t\t\tNumber of move: "<<movecount<<endl;
        break;}
        else{
        ++movecount;
        display();
        cout<<"\t\t\t\tNumber of move: "<<movecount<<endl;
        cout<<"\t\t\t\tnext move";
        break;}
    case 2:
        if(moveA_to_c()==false)
        {cout<<"\n\t\t\t\tIlligal move"<<endl;
        ++movecount;
        cout<<"\t\t\t\tNumber of move: "<<movecount<<endl;
        break;}
        else{
        ++movecount;
        display();
        cout<<"\t\t\t\tNumber of move: "<<movecount<<endl;
        cout<<"\t\t\t\tnext move";
        break;}
    case 3:
        if(moveb_to_a()==false)
        {cout<<"\n\t\t\t\tIlligal move"<<endl;
        ++movecount;
        cout<<"\t\t\t\tNumber of move: "<<movecount<<endl;
        break;}
        else{
        ++movecount;
        display();
        cout<<"\t\t\t\tNumber of move: "<<movecount<<endl;
        cout<<"\t\t\t\tnext move";
        break;}
    case 4:
        if(moveb_to_c()==false)
        {cout<<"\n\t\t\t\tIlligal move"<<endl;
        ++movecount;
        cout<<"\t\t\t\tNumber of move: "<<movecount<<endl;
        break;}
        else{
        ++movecount;
        display();
        cout<<"\t\t\t\tNumber of move: "<<movecount<<endl;
        cout<<"\t\t\t\tnext move";
        break;}
    case 5:
        if(movec_to_a()==false)
        {cout<<"\n\t\t\t\tIlligal move"<<endl;
        ++movecount;
        cout<<"\t\t\t\tNumber of move: "<<movecount<<endl;
        break;}
        else{
        ++movecount;
        display();
        cout<<"\t\t\t\tNumber of move: "<<movecount<<endl;
        cout<<"\t\t\t\tnext move";
        break;}
    case 6:
        if(movec_to_b()==false)
        {cout<<"\n\t\t\t\tIlligal move"<<endl;
        ++movecount;
        cout<<"\t\t\t\tNumber of move: "<<movecount<<endl;
        break;}
        else{
        ++movecount;
        display();
        cout<<"\t\t\t\tNumber of move: "<<movecount<<endl;
        cout<<"\t\t\t\tnext move";
        break;}
    case 7:
    	exit(1);
    }
    if(movecount==move_to_win)
    break;
    cout<<" \n\t\t\t\tEnter your move :";
    cin>>ch;
    }while(movecount!=move_to_win);
    
    system("cls");/*
    if(topB==numd-1){
		check=true;
	}
	if(topA==numd-1){
		check=true;
	}*/
    if(movecount<=move_to_win)
	{
    	for (int i = 0; i < topB-1; i++)
		{
		if (towerB[i]>towerB[i+1])
		{
            check=true;
		}
        else{
            check=false;}
		}
		}
		else{
		check=false;}
		
		if(movecount<=move_to_win){
    	
    	for (int i = 0; i < topC-1; i++)
		{
		if (towerC[i]>towerC[i+1])
		{
            check=true;
		}
        else{
            check=false;}
		}
	}
	else
		check=false;
		if (check==true)
		{

			cout<<"\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
			cout<<"\t\t\t\t&                                             &\n";
    		cout<<"\t\t\t\t&   Congragulations you have won the game     &\n";
    		cout<<"\t\t\t\t&                                             &\n";
    		cout<<"\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
		}
		else
		{
			cout<<"\t\t\t\tsorry you have lost the gameS!!!";
		}
}
	else 
	{
		cout<<"\t\t\t\tinvalid number of disk try again";
		cout<<"\n\t\t\t\t Enter number of disc(Number of disk is between 3 and 8):";
		goto a;
	}
	
	char choi;
	cout<<"\n\n\t\t\t\tDo you want to play again(y:yes/N:no) ";
	cin>>choi;
	if (choi=='y'||choi=='Y')
	{
		movecount=0;
		while(topA>= 0)
    	popA();
    	while(topB>= 0)
    	popB();
    	while(topC>= 0)
    	popC();
		goto b;
	}
	else
	exit(1);
}

bool isEmptyA(){
	return (topA < 0);
}

bool isEmptyB(){
	return (topB < 0);
}

bool isEmptyC(){		
	return (topC < 0);
}

int pushA(int val) {
    if(topA>=sizes-1){
    	cout<<"\t\t\t\tyou are trying to add to a full tower"<<endl;
    	}
    else {
      ++topA;
      towerA[topA]=val;
	}
	return val;
}
int popA() {
    if(isEmptyA()){
   cout<<"\t\t\t\tYou are trying to move from empty tower"<<endl;
   }
   else {
    	temp=towerA[topA];
    	--topA;
}
	return temp;
}

int pushB(int val) {
	if(topB>=sizes-1){
    	cout<<"\t\t\t\tyour move is invalid"<<endl;
    	}
    else {  
    	++topB;
    	towerB[topB]=val;
}	
	return val; 
}
int popB() {
    if(isEmptyB()){
   cout<<"\t\t\t\tYou are trying to move from empty tower"<<endl;
   }
   else {
      temp=towerB[topB];
      --topB;
}
	return temp;
}

int pushC(int val) {
    if(topC>=sizes-1){
    	cout<<"\t\t\t\tyour move is invalid"<<endl;
    	}
    else {
    	++topC;
    	towerC[topC]=val;
}
	return val;
}
int popC() {
    if(isEmptyC()){
	   cout<<"\t\t\t\tYou are trying to move from empty tower"<<endl;
	   }
    else {
      temp=towerC[topC];
      --topC;
  }
  return temp;
}

bool moveA_to_b()
{
	if(!isEmptyA()){
	if(isEmptyB()){
		pushB(popA());
		return true;}
	else
	{
		if (towerB[topB]>towerA[topA]){
			pushB(popA());
			return true;}
		else
		return false;
	}
	}
   else
   {
   cout<<"\t\t\t\tTHE STACK IS EMPTY";
   return false;
   }
    
}
bool moveA_to_c()
{
	if(!isEmptyA()){
	if(isEmptyC()){
		pushC(popA());
		return true;}
	else
	{		
		if (towerC[topC]>towerA[topA]){
			pushC(popA());
			return true;}
		else
		return false;
	}
	}
   else
    cout<<"\t\t\t\tTHE STACK IS EMPTY";
}
bool moveb_to_a()
{
	if(!isEmptyB()){
	if(isEmptyA()){
		pushA(popB());
		return true;}
	else
	{
		if (towerA[topA]>towerB[topB]){
			pushA(popB());
			return true;}
		else
		return false;
	}
	}
  else
    {
    cout<<"\t\t\t\tTHE STACK IS EMPTY";
    return false;
    }
}
bool moveb_to_c()
{
	if(!isEmptyB()){
	if(isEmptyC()){
		pushC(popB());
		return true;}
	else
	{
		if (towerC[topC]>towerB[topB]){
			pushC(popB());
			return true;}
		else
		return false;
	}
	}
else
    {
   cout<<"\t\t\t\tTHE STACK IS EMPTY";
   return false;
   }
}
bool movec_to_a()
{
	 if(!isEmptyC()){
	if(isEmptyA()){
		pushA(popC());
		return true;}
	else
	{
		if (towerA[topA]>towerC[topC]){
			pushA(popC());
			return true;}
		else
		return false;
	}
	}
  else
{
   cout<<"\t\t\t\tTHE STACK IS EMPTY";
   return false;
   }
   }
bool movec_to_b()
{
	if(!isEmptyC()){
	if(isEmptyB()){
		pushB(popC());
		return true;}
	else 
	{
		if (towerB[topB]>towerC[topC]){
			pushB(popC());
			return true;}
		else
		return false;
	}
	}
  else
{
   cout<<"\t\t\t\tTHE STACK IS EMPTY";
   return false;
   }
   }

void instruction()
{
	system("cls");
	int chh;
	cout<<"\t\t\t\tYou can only move one disk per move, and you can only move the top disk on a stack.\n";
	cout<<"\t\t\t\tThe top disk of any stack can be moved to the top disk of any other stack, with the\n";
	cout<<"\t\t\t\trestriction that you can't move a larger disk on top of a smaller disk -- i.e., disks\n";
	cout<<"\t\t\t\tcan only be moved to empty stacks or on top of larger disks.\n\n";
	cout<<"\t\t\t\t1.Back to menu : ";
	cin>>chh;
	if (chh==1)
	system("cls");
	menu();
	
	
}

void display()
{
	
	system("cls");
    cout<<"\n\n\n";
    cout<<"\n\t\t\t\t1.To move from tower A to B\n";
    cout<<"\t\t\t\t2.To move from tower A to c\n";
    cout<<"\t\t\t\t3.To move from tower B to A\n";
    cout<<"\t\t\t\t4.To move from tower B to C\n";
    cout<<"\t\t\t\t5.To move from tower C to A\n";
    cout<<"\t\t\t\t6.To move from tower C to B\n";
    cout<<"\t\t\t\t7.To exit the game\n";
  
	cout<<" \n\t\t\t\tEnter your move :\n\n\n";
  
    for (int i = topA; i >=0; --i)
  
    cout<<"\t\t\t\t|   "<<towerA[i]<<"   |\n";
  
    cout<<"\t\t\t\t|_______|\n";
    cout<<"\t\t\t\t    A   \n\n\n\n";
  
	for (int i = topB; i >=0; --i)
    cout<<"\t\t\t\t|   "<<towerB[i]<<"   |\n";
  
    cout<<"\t\t\t\t|_______|\n";
    cout<<"\t\t\t\t    B   \n\n\n\n";
  
    for (int i = topC; i >=0; --i)
    cout<<"\t\t\t\t|   "<<towerC[i]<<"   |\n";
  
    cout<<"\t\t\t\t|_______|\n";
    cout<<"\t\t\t\t    C   \n\n\n\n";
}
