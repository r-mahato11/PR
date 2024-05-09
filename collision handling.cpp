#include<iostream> 
#include<cstring> 
#define max 10 
using namespace std; 
struct client 
{ 
 long int iPhno; 
 char name[20]; 
 
};  
class hashtable 
{ 
 client ht[max]; 
  
 public: 
  hashtable() //constructor 
  { 
   for(int i=0;i<max;i++) 
   { 
    ht[i].iPhno=0; 
     
   } 
  }   
  void insert(); 
  void display(); 
 
 
 
  int search(int); 
  int del(int); 
  int hash(long int); 
}; 
void hashtable::insert() 
{ 
 client c; 
 int iPos; 
 char cAns; 
 do 
 { 
  cout<<"\n Enter Phone Number:"; 
  cin>>c.iPhno; 
  iPos=hash(c.iPhno); 
  
  if(ht[iPos].iPhno==0) 
  { 
   ht[iPos]=c; 
  } 
  else 
  { 
   for(int i=iPos+1;i%max!=iPos;i++) 
   { 
    ht[i]=c; 
    break; 
   } 
  } 
  cout<<"\n Add More:"; 
  cin>>cAns; 
 }while(cAns=='y' || cAns=='Y');  
 
 
 
} 
int hashtable::hash(long int key) 
{ 
 return(key%max); 
} 
void hashtable::display() 
{ 
 cout<<"\nSrno\tPhone number\n"; 
 for(int i=0;i<max;i++) 
 { 
  cout<<i<<"\t"<<ht[i].iPhno<<endl; 
 } 
} 
int hashtable::search(int x) 
{ 
 int iFlag=0;  
 cout<<"Enter Phone number to be searched:"; 
 cin>>x; 
 for(int i=0;i<max;i++) 
 { 
  if(ht[i].iPhno==x) 
  { 
   cout<<"\n Phone Number Found at position "<<i; 
   iFlag=1; 
  } 
 } 
 if(iFlag==0) 
 cout<<"\n Phone Number Not Found"; 
}//end of search 
 
 
 
 
int hashtable::del(int s) 
{ 
 int iF=0; 
 cout<<"\n Enter phone number to be deleted:"; 
 cin>>s; 
 for(int i=0;i<max;i++) 
 { 
  if(ht[i].iPhno==s) 
  { 
    
   ht[i].iPhno=0; 
   cout<<"\n Phone number found and deleted"; 
   iF=1; 
  } 
 } 
 if(iF==0) 
 cout<<"\n Phone number not found"; 
 
}  
 
int main() 
{ 
 int y,s,iCh; 
 hashtable h; 
 do 
 { 
  cout<<"\n1.INSERT\n2.DISPLAY\n3.SEARCH\n4.DELETE\n5.EXIT\n\n"; 
  cout<<"Enter your choice:"; 
  cin>>iCh; 
  cout<<"\n"; 
 
 
 
  switch(iCh) 
  { 
   case 1: 
    h.insert(); 
    cout<<"\n"; 
    break; 
     
   case 2: 
    h.display(); 
    cout<<"\n"; 
    break; 
     
   case 3:      
    h.search(y); 
    cout<<"\n"; 
    break; 
     
   case 4: 
    h.del(s); 
    cout<<"\n"; 
    break; 
     
   case 5: 
    break; 
  } 
 }while(iCh!=5);        
return 0; 
} 