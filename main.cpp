#include <iostream>
#include <string>
using  namespace std;
void WelcomeMessage(){
   cout<<"       -------------------------------------------------------";
   cout<<"\n\t** Welcome to Restaurant Mr.Crab Restaurant. **"<<endl;
   cout<<"\t   ** A Restaurant Billing Application. **"<<endl;
   cout<<"       -------------------------------------------------------";
   cout<<endl;
}
void EndMessage(){
   cout<<"       ---------------------------------------";
   cout<<"\n\t** Thank you!!! For your shopping. **"<<endl;
   cout<<"\t   ** By Mr.Crab Restaurant. **"<<endl;
   cout<<"       ---------------------------------------";
   cout<<endl;
}
class billing{
public:
    string t;   //name of meal
    int num_of_meal;
    int price;
    billing*next;
    billing(){
        billing*next=NULL;
    }
};
class stack{
public:
    billing*head;
    //int size;
    int max;
    stack(int max){
       // size=0;
        this->max=max;
        head=NULL;
    }
void push(string a,int tt,int p){

        billing* new_billing=new billing;
        new_billing->t=a;
        new_billing->price=tt;
        new_billing->num_of_meal=p;
        if(head==NULL){
            head=new_billing;
             }
        else{
            new_billing->next=head;
            head=new_billing;
           // size++;
        }
    }
void pop(){
        if(head==NULL){
            cout<<"empty";
        }
        else{

            head=head->next;

        }
    }
void peak(){  //display billing
billing* temp = head;
cout<<"name"<<"         "<<"price"<<"           "<<"Quant"<<endl;
while (temp != NULL){
cout << temp->t <<"        ";    cout<<temp->price<<"$"<<"             ";
cout<<temp->num_of_meal<<endl;
temp = temp->next;}
cout << endl;
}
};

class MENU{ //doubly linked-list
  private:
  class MEAL{   //Node
    public:
    string Name;
    float Price;
    int quant;
    int ID;
    MEAL *next;
    MEAL *prev;
    MEAL () {   //constructor
     next = NULL;
     prev = NULL;
    }
  };
  MEAL*head=NULL;
 public:
     ~MENU();  //destructor

void Permission(int v){
   int x;
   if(v==1){
	cout<<"Please enter the password: "<<endl;
	cin>>x;
	if(x==123){
      cout<<"The password is correct."<<endl;
      cout<<"\tPlease choose one option: "<<endl;
      cout<<"\t1-Display The menu."<<endl;
      cout<<"\t2-Update The menu."<<endl;
      cout<<"\t3-Delete all The menu."<<endl;
    int e;  cin>>e;
    if(e==1){
      display();
      cout<<"   1-Search for a meal. or 2-Update the price. "<<endl;
    int b; cin>>b;
    if(b==2){
      int h1,h2;
   	  cout<<"Write the old price: "<<endl;
   	  cin>>h1;
      cout<<"Write the new price: "<<endl;
	  cin>>h2;
    newprice(h1,h2);}
	else if(b==1){
      cout<<"Enter the meal code: ";
	  int n;  cin>>n;
    searchmeal(n);}}
	else if(e==2){
      updatemenu();}
      else if(e==3){
        cout<<"   Are you sure?"<<endl;
        string qjj; cin>>qjj;
        if(qjj=="YES"||qjj=="Y"||qjj=="Yes"||qjj=="y"||qjj=="yes"){
        MENU::~MENU();
        cout<<"   The menu has been deleted."<<endl<<"   ";
        display();
        cout<<endl<<endl<<endl;
        }
        else{
            exit(1);
        }
      }
    }
	else{
		cout<<"The password is incorrect."<<endl;
		exit(1);}}
}
 void addfirst(string N,float P,int id,int q){
       MEAL* newMEAL= new MEAL;
       newMEAL->Name= N ;
       newMEAL->Price=P;
       newMEAL->ID=id;
       newMEAL->quant=q;
       newMEAL->next=head;
       head=newMEAL;
 }
void addlast(string N,float P,int id,int q){
       MEAL* newMEAL= new MEAL;
       newMEAL->Name= N ;
       newMEAL->Price=P;
       newMEAL->ID=id;
       newMEAL->quant=q;
       newMEAL->next=NULL;
       if(head==NULL){
           newMEAL->prev=NULL;
           head=newMEAL;
       }
       else{
        MEAL*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            newMEAL->prev=temp;
        }
        temp->next=newMEAL;
      }
  }
void insert_at_pos(string N,float P,int id ,int pos,int q){
		MEAL* newMEAL = new MEAL;
        newMEAL->Name= N ;
        newMEAL->Price=P;
        newMEAL->ID=id;
        newMEAL->quant=q;
        if(head==NULL){
            head=newMEAL;
            return;
        }
        if(pos==0){
            newMEAL->next=head;
            head->prev=newMEAL;
            head=newMEAL;
            return;
        }
        MEAL*temp=head;
        for(int i=0;i<pos&&temp!=NULL;i++){
          temp = temp->next;
        }
        if(temp==NULL){
            this->addfirst(N,P,id,q);
            return;
        }
        newMEAL->prev=temp->prev;
        temp->prev->next=newMEAL;
        temp->prev=newMEAL;
        newMEAL->next=temp;
}
void remfirst(){
    if (head == NULL)
        exit(1);
    else {
    MEAL*ptr;
    ptr = head;
    head = head -> next;
    delete ptr;
  }
        }
void remove_at_pos(int pos){
		if (head == NULL)
			return;
		MEAL* temp = head;
		if (pos == 0){
			remfirst();
		}
		for (int i = 1; i < pos && temp != NULL; i++)
			temp = temp->next;
		if (temp == NULL)
			return;
		temp->prev->next = temp->next;
		if (temp->next)
			temp->next->prev = temp->prev;
		delete temp;
	}
void remend(){
  if (head == NULL)
    exit(1);
  if (head -> next == NULL) {
    delete head;
    exit(1);
  }
  MEAL * second_last = head;
  while (second_last -> next -> next != NULL)
    second_last = second_last -> next;
  delete (second_last -> next);
  second_last -> next = NULL;
}
void display(){
        cout << "ID       "<<"Name    "<<"      price"<<"      Quantity"<<endl;
		MEAL* temp = head;
		while (temp != NULL){
			cout << temp->ID<<"     "<<temp->Name<< "      " <<temp->Price<<"$"<< "        " <<temp->quant<<endl;
			temp = temp->next;
		}
		cout <<endl;
}
void sortlist(){
    MEAL*poin1;
    MEAL*poin2;
    poin1=head;
    poin2=NULL;
    int temp;
    if(head==NULL){
        return;
    }
    else{
        while(poin1!=NULL){
            poin2=poin1->next;
            while(poin2!=NULL){
                if(poin1->ID>poin2->ID){
                    temp=poin1->ID;
                    poin1->ID=poin2->ID;
                    poin2->ID=temp;
                }
                poin2=poin2->next;
            }
            poin1=poin1->next;
        }
    }
}
 void updatemenu(){
			 cout<<"  please enter the password"<<endl;
			 int pss; cin>>pss;
			 if(pss==123){
			 cout<<"  The password is correct."<<endl;
			 cout<<"  Please choose one option: "<<endl;
			 cout<<"1-Do you want to add a meal? or 2-delete a meal?"<<endl;
			 int ww; cin>>ww;   if(ww==1){
			 cout<<"  Where do you want to add the meal? "<<endl;
			 cout<<"  1-At First     2-At End     3-At position "<<endl;
			 int z; cin>>z;
			 if(z==1){
			 	string qq; float pp; int l,nb;
			 	cout<<"The Name of the meal: "<<endl;
			 	cin>>qq;
			 	cout<<"The Price of the meal: "<<endl;
				cin>>pp;
				cout<<"The ID of the meal: "<<endl;
				cin>>l;
				cout<<"The Quantities of the meal: "<<endl;
				cin>>nb;
			 	addfirst(qq,pp,l,nb);
			 	cout<<qq<<"  meal has been added "<<endl;
			 	cout<<"The new menu is: "<<endl;
			 	display();
			 	cout<<"Do you want to sort The menu?  Y/N?"<<endl;
			 	char rw;  cin>>rw;
			 	if(rw=='Y'){
			 	sortlist();
			 	display();}
			 	else if(rw=='N'){
                exit(1);
			 	}
			 }
			 else if(z==2){
			 	string zq; float kk; int j,xz;
			 	cout<<"The Name of the meal: "<<endl;
			 	cin>>zq;
			 	cout<<"The Price of the meal: "<<endl;
				cin>>kk;
				cout<<"The ID of the meal: "<<endl;
				cin>>j;
				cout<<"The Quantities of the meal: "<<endl;
				cin>>xz;
			 	addlast(zq,kk,j,xz);
			 	cout<<zq<<"  meal has been added "<<endl;
			 	cout<<"The new menu is: "<<endl;
			 	display();
			 	cout<<"Do you want to sort The menu?  Y/N?"<<endl;
			 	char rw;  cin>>rw;
			 	if(rw=='Y'){
			 	sortlist();
			 	display();}
			 	else if(rw=='N'){
                exit(1);
			 	}
			 }
			 else if(z==3){
			 	string po; float yy; int jo,ji,mn;
			 	cout<<"The Name of the meal: "<<endl;
			 	cin>>po;
			 	cout<<"The Price of the meal: "<<endl;
				cin>>yy;
				cout<<"The ID of the meal: "<<endl;
				cin>>jo;
				cout<<"The Position of the meal: "<<endl;
				cin>>ji;
				cout<<"The Quantities of the meal: "<<endl;
				cin>>mn;
			 	insert_at_pos(po,yy,jo,ji,mn);
			 	cout<<po<<"  meal has been added "<<endl;
			 	cout<<"The new menu is: "<<endl;
			 	display();
			 	cout<<"Do you want to sort The menu?  Y/N?"<<endl;
			 	char rw;  cin>>rw;
			 	if(rw=='Y'){
			 	sortlist();
			 	display();}
			 	else if(rw=='N'){
                exit(1);
			 	}
			 }
			 }
			 else if(ww==2){
             cout<<"  Where is the meal you want to delete? "<<endl;
			 cout<<"  1-At First     2-At End     3-At position "<<endl;
			 int lo; cin>>lo;
			 if(lo==1){
			 	remfirst();
			 	cout<<"The meal has been deleted "<<endl;
			 	cout<<"The new menu is: "<<endl;
			 	display();
			 }
			 else if(lo==2){
			 	remend();
			 	cout<<"The meal has been deleted "<<endl;
			 	cout<<"The new menu is: "<<endl;
			 	display();
			 }
			  else if(lo==3){
			     cout<<"Write the position: "<<endl;
                int jj;  cin>>jj;
			 	remove_at_pos(jj);
			 	cout<<"The meal has been deleted "<<endl;
			 	cout<<"The new menu is: "<<endl;
			 	display();  }}}
			 else{
			 	cout<<"password is incorrect."<<endl;
			 	exit(1);
			 }}
 void searchmeal(int IDsearch){
     MEAL*temp=head;
     int found=0;
     int i=0;
     if(temp==NULL){
         cout<<"MENU IS EMPTY "<<endl;}
     else{
         while(temp!=NULL){ i++;
         if(temp->ID==IDsearch){
             found++;
             break;
         }
        temp= temp->next;}
        if(found==1){
     	 if(IDsearch==1001){
     	 	cout<<"Pizza: ";}
         else if(IDsearch==1002){
     	 	cout<<"Meat: ";
			  }
         else if(IDsearch==1003){
			cout<<"Pasta: ";
			  }
         else if(IDsearch==1004){
			cout<<"Liver: ";
			  }
         else if(IDsearch==1005){
			cout<<"Burger: ";
			  }
            cout<<temp->quant;
         }
        else{
			 cout<<IDsearch<<"    Didn't found the meal "<<endl;
			 cout<<"     Do you want to update the menu?    Y/N?"<<endl;
			 char q; cin>>q;
			 if(q=='Y'){
			 updatemenu();}
			 else if(q=='N'){
			 	exit(1);  }}}}
 void newprice(int old, int new_val){
         if(old !=75 && old !=100 && old !=50 && old !=60 && old !=40){
            cout<<"   The old Price is incorrect."<<endl;
            exit(1);
         }
         else{
         int c =0;
          MEAL*temp=head;
          if(head ==NULL){
              return;
          }
          while (temp!=NULL){
              c++;
              if(temp->Price==old){
                  temp->Price=new_val;
                  new_val=temp->Price;
                  cout<<"new update "<<endl;
                  display();
              }
              if(temp->next!=NULL){
                  temp=temp->next;
              }
              else {
                  break;
             }}}}};
   MENU::~MENU(){ //destructor
		MEAL* temp = head;
		while (head != NULL){
        head = head->next;
        delete temp;
        temp = head;}}

int main() {
    WelcomeMessage();
	 MENU rest;
	//The Menu :
	rest.addfirst("Pizza   ",75,1001,50);
    rest.addfirst("Meat   ",100,1002,60);
    rest.addfirst("Pasta   ",50,1003,20);
    rest.addfirst("Liver   ",60,1004,17);
    rest.addfirst("Burger  ",40,1005,42);
    cout<<"\t\tPlease choose one option: "<<endl;
    cout<<"\t\t1-Admin           2-Customer"<<endl;
    int v;  cin>>v;
    if(v==1){
    rest.Permission(v); }  //Admin or Customer

    else if(v==2){
     cout<<"\tPlease choose one option: "<<endl;
     cout<<"\t1-Display The menu."<<endl;
     int y;  cin>>y;  if(y==1){
     rest.display();
     cout<<"\tWould you like to make an order?   Y/N?"<<endl;
   char ff; cin>>ff;
    if(ff=='N'){
	  exit(1);}

    else if(ff=='Y'){
stack *bill=new stack(10);
int p=0;
double price;
string name;
int t[50];   //price
cout<<"Please enter number of meals: "<<endl;
   int n;  int s=0;   cin>>n;
   for(int i=0;i<n;i++){
    int arr[n];
    cout<<"Enter the meal code: "<<endl;
    cin>>arr[i];
    if(arr[i]==1001){
       name="Pizza ";
       cout<<name;
       t[i]=75;
       }
    else if(arr[i]==1002){
       name="Meat ";
       cout<<name;
       t[i]=100;
        }
    else if(arr[i]==1003){
       name="Pasta ";
       cout<<name;
       t[i]=50;
        }
    else if(arr[i]==1004){
       name="Liver ";
       cout<<name;
      t[i]=60;
        }
    else if(arr[i]==1005){
       name="Burger ";
       cout<<name;
       t[i]=40;
       }
    cout<<"meal has been added."<<endl;
    cout<<"How many quantities you want? "<<endl;
    int q;  cin>>q;
    bill->push(name,t[i],q);
    s+=t[i]*(q);
    p=s-t[i]*(q);
    }
   cout<<"1-Do you want to delete The Last meal? OR  2-End your Order?"<<endl;
   int endd;  cin>>endd;
   if(endd==2){
   bill->peak();
   cout<<"TOTAL :-"<<"   "<<s<<endl;
   EndMessage();
   exit(1);
   }
   else if(endd==1){
    bill->pop();
    bill->peak();
   cout<<"TOTAL :-"<<"   "<<p<<endl;
   EndMessage();
   exit(1);}
   }}}
   return 0;
}
