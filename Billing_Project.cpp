#include<iostream>
#include<fstream>

using namespace std;


class shopping
{
    private:
    int pcode;
    float price;
    float dis;
  string pname;

  public:
  void menu();
  void administrator();
  void buyer();
  void add();
  void edit();
  void rem();
  void list();
  void reciept();

};
void shopping :: menu(){
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t\t\t\t\t\t\t_________________________________\n";                                 
    cout<<"\t\t\t\t\t\t\t\t\t\t                                 \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t   Supermarket Main Menu         \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t_________________________________\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t                                 \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t| 1) Admistrator       |\n"; 
    cout<<"\t\t\t\t\t\t\t\t\t\t| 2) Buyer             |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t| 3) Exit              |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t|                      |\n";
    cout<<"\n\t\t\t Please select!";
    cin>>choice;

    switch(choice){
         
         case 1:
         cout<<"\t\t\t Please Login \n";
         cout<<"\t\t\t Enter Email   \n";
         cin>>email;
         cout<<"\t\t\t Enter password   \n";
         cin>>password;
        
        if(email=="accenture@gmail.com" && password=="accenture@123")
        {
            administrator();
        }
        else
         {
            cout<<"Invalid credentials";
         }
         break;

    
    case 2:
    {
        buyer();

    }

    case 3:
    {
        exit(0);
    }
    default:
    {
        cout<<"Please Select From Given Option";
    }


    }
     goto m;

}

void shopping :: administrator()
{ 
    m:
    int choice;
    cout<<"\n\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|___1) Add The Product____|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|___2) Modify The Product_|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|___3) Delete The Product__|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|___4) Back to main menu___|";
    cout<<"\n\t\t\t|                          |";

    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;
    switch(choice)
    {
        case 1:
         add();
         break;

         case 2:
           edit();
           break;

         case 3:
         rem();
         break; 

         case 4:
         menu();
         break;


         default:
         cout<<" OOps! Invalid Choice!"; 

    }
    goto m;


}
void shopping :: buyer(){
    m:
    int choice;
    cout<<"\t\t\t 1) Buyer          \n";
    cout<<"                         \n";
    cout<<"\t\t\t 2) Buy Product    \n";
    cout<<"                         \n";
    cout<<"\t\t\t 3) Go Back        \n";
    cout<<"\t\t\t Enter Your choice : ";

    cin>>choice;

    switch(choice){
        case 1:
        reciept();
        break;
        case 2:
        menu();
    
        default:
        cout<<"Invalod Choice";

    }
    goto m;
}

void shopping :: add()
{
    m:
     fstream data;
     int c;
     int token=0 ;
     float p;
     float d;
     string n;

      cout<<"\n\n\t\t\t\t Add New product";
      cout<<"\n\n\t\t\t\t Product code of New product" ;
      cin>>pcode;
      cout<<"\n\n\t\t\t\t Name of The Product";
      cin>>pname;
      cout<<"\n\n\t\t\t\t Price of New product";
      cin>>price;
      cout<<"\n\n\t\t\t\t Discount On  Product";
      cin>>dis;
     
     if(!data)
     {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
     }
     else
     {
        data>>c>>n>>p>>d;

        while(!data.eof()){
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d; 
        }
        data.close();  

     }
     if(token==1)
     {
        goto m;   
     }
     else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
     }
     cout<<"\n\t\t\t Record Inserted !";   
}


void shopping:: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify The record";
    cout<<"\n\t\t Product code:";
    cin>>pkey;

       data.open("database.txt",ios::in);
       if(!data){
        cout<<"\n\t\t File Dosn't exist: ";
       }
       else
       {
        data1.open("database1.text",ios::app | ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t Product New Code!";
                cin>>c;
                cout<<"\n\t\t <<Name Of The Product:";
                cin>>n;
                cout<<"\n\t\t Price:";
                cin>>p;
                cout<<"\n\t\t Discount";
                cin>>d;
                data<<" "<<c<<" "<<" "<<n<<" "<<p<<" "<<d;
                cout<<"Record Edited! ";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not fount sorry!";
        }

       }
}
void shopping:: rem(){
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product Code :";

    
    data.open("database.txt",ios::in);
    if(!data)
    {
     cout<<"File Dosn't exist";
    }
    else
    {
        data1.open("databas1.txt",ios::app| ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                  cout<<"\n\n\t  Product deleted succesfully";
            }
            else
            {
               data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record Not found";
        }
    }
}
void shopping :: list()
{
     fstream data;
     data.open("database.txt",ios::in);
    cout<<"\n\n|_______________________\n";
    cout<<"ProNo\t\tName\t\tproce"<<"\n";
    cout<<"\n\n|_______________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
     cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
     data>>pcode>>pname>>price>>dis;

   }
   data.close();
}
void shopping::reciept()
{
    m:
    fstream data;
    int arrc[100];
    int arrq[100]; 
    int c=0;
    float amount;
    char choice;
    float dis=0;
    float total=0;
    cout<<"\n\t\t\t\t RECEIPT";
   data.open("database.txt",ios::in);
   if(!data){
    cout<<"\n\n Empty database";
   }
   else
   {
     data.close();

     list();
    cout<<"\n______________________________\n";
    cout<<"\n|                             |\n";
    cout<<"\n   Please Place the order      \n";
    cout<<"\n|                             |\n";
    cout<<"\n______________________________\n";
    do
    {
        cout<<"\n\n Enter Product Code :";
        cin>>arrc[c];
        cout<<"\n\n Enter The quantity :";
        cin>>arrq[c];
        for(int i=0;i<c;i++)
        {
            if(arrc[c]==arrc[i]){
                cout<<"\n\n Duplicate Product Code.Please try again";
                goto m;
            }
        }
            c++;
            cout<<"\n\n Do you want to buy another Product? if yeas press y else n";
            cin>>choice;
        }
        while(choice=='y');

        cout<<"\n\n\t\t\t__________RECEIPT________\n";
        cout<<"\n Product no\t product name\tproduct quantity\t price\t amount with discount\n";

    
        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;

            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-((amount*dis)/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();

    
}
    cout<<"\n\n__________________________";
    cout<<"\n Total Amount : "<<total;
   
}

int main()
{
    shopping s;
    s.menu();

}
