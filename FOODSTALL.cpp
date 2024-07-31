#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <conio.h>
using namespace std;
char input_uniqueid[20];         
char input_stallid[20];         
char input_foodtype[20];        

class Admin{
    private:
        int total_items;
        float price[10];     
        char name[20];
        char food_menu[10][10], food_type[20];
        char password[20], recovery_password[20];
	protected:
        char mobile[15], email[50], stall_id[20];

    public:
		char unique_id[15];
        int login();                            
        int recover();                          
        void set_rest_data();                   
        void rest_display();                    
        int rest_profile();                     
		int know_rest_menu();                   
        void add_rest_menu();                   
        void del_rest_menu();                   
        void mod_rest_profile();                
        int display_rest_menu_to_customer();    
        void redisplay_menu_to_customer();      
        int search_rest_by_foodtype();          
        void invalid_input();                   
        
}admin, owner; 

int Admin::login(){
    if ((strcmp(::input_uniqueid, unique_id)) == 0)
    {
        cout<<"\nEnter the Login Password: ";
        int len = 0;
        len = strlen(password);
        char input_password[20];
	
		int i;
        for(i=0; i<len; i++)
        {
            input_password[i] = getch();
            cout<<"*";
        }
		input_password[i] = '\0';

        if((strcmp(input_password, password) == 0))
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

int Admin::recover()
{
    char key[20];
    if ((strcmp(::input_uniqueid, unique_id)) == 0)
    {
        cout<<"\nEnter the Unique ID: ";
        cin >> key;
        if ((strcmp(key, recovery_password)) == 0)
        {
            cout<<"\nYou are a valid user.";
            cout<<"\nYour password is: "<<password;
            cout<<"\nPlease Exit to login again.";
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

void Admin::set_rest_data()
{
    cout<<"\nEnter the Food Stall Name: ";
    cin>>name;
    cout<<"\nEnter the Food Stall Unique ID: ";
    cin>>unique_id;
    cout<<"\nEnter the Mobile Number: ";
    cin>>mobile;
    cout<<"\nEnter the Email ID: ";
    cin>>email;
    cout<<"\nEnter the Stall ID: ";
    cin>>stall_id;
    cout<<"\nFood Stall Food options available are \n1. South-Indian\n2. Continental\n3. Chinese\n4. Thai\n5. Multiple ";
    int foodtype;
    cout<<"\nEnter the Food Stall Food Options Type (Unique Number)";
    cin>>foodtype;

    switch(foodtype){
        case 1: strcpy(food_type , "South Indian");
                break;
        case 2: strcpy(food_type , "Continental");
                break;
        case 3: strcpy(food_type , "Chinese");
                break;
        case 4: strcpy(food_type , "Thai");
                break;
        case 5: strcpy(food_type , "Multiple");
                break;
    }

    cout<<"\nEnter the Total number of Food menu items: ";
    cin>>total_items;

    for(int i=0; i<total_items; i++)
    {
        cout<<"\nEnter the Food Item "<<i+1<<" Name: ";
        cin>>food_menu[i];
        cout<<"\nEnter the Price of the Food Item "<<i+1<<" INR: ";
        cin>>price[i];
    }

    cout<<"\nCreate your Login Password: ";
    cin>>password;
    cout<<"\nEnter the Unique Keyword to recover Password: ";
    cin>>recovery_password;

    cout<<"\n\nPlease note your Username is --> "<<unique_id<<"\n";
}

void Admin::rest_display()
{
    cout<<"\nFood Stall Name                            :"<<name;
    cout<<"\nFood Stall ID                              :"<<unique_id;
    cout<<"\nFood Stall Mobile Number                   :"<<mobile;
    cout<<"\nFood Stall Email ID                        :"<<email;
    cout<<"\nFood Stall total Food Menu Items           :"<<total_items;

    if(total_items==0)
        cout<<"\n(No Food Items Specified...)";

    for(int i=0;i<total_items;i++)
    {
        cout<<"\n\tFood Item "<<i+1<<" : "<<food_menu[i]<<" :: Price: INR"<<price[i];
    }
}

int Admin::rest_profile()
{
    if(strcmp(::input_uniqueid, unique_id) == 0)
    {
        cout<<"\nFood Stall Name                    :"<<name;
        cout<<"\nFood Stall Mobile Number           :"<<mobile;
        cout<<"\nFood Stall Food Items Type         :"<<food_type;
        return 1;
    }
    else 
        return 0;
}

int Admin::know_rest_menu()
{
    if(strcmp(::input_uniqueid, unique_id) == 0)
    {
        cout<<"\nFood Stall Food Items Type         :"<<food_type;
        cout<<"\nFood Stall Total Menu Items        :"<<total_items;

        for(int i=0;i<total_items;i++)
        {
            cout<<"\n\tFood Item "<<i+1<<" : "<<food_menu[i]<<" :: Price: INR"<<price[i];
        }
        
        return 1;
    }
    else 
        return 0;
}

void Admin::add_rest_menu()
{
    if(strcmp(::input_uniqueid, unique_id) == 0)
    {
        cout<<"\nEnter the New Food Item: ";
        cin>>food_menu[total_items];
        cout<<"\nEnter the Price of new Food Item: INR ";
        cin>>price[total_items];

        total_items++;
        cout<<"\n\nNew Menu Item Added Successfully...";
    }
}

void Admin::del_rest_menu()
{
    know_rest_menu();
    int del=0;
    
    if(strcmp(::input_uniqueid, unique_id) == 0)
    {
        if(total_items==0 || total_items<0)
        {
            total_items = 0;
            cout<<"\nNo items exist in menu...";
            getch();
            exit(0);
        }
        cout<<"\nEnter the item number to be deleted: ";
        cin>>del;

        if(del == total_items)
        {
            total_items--;
            strcpy(food_menu[total_items], '\0');
            price[total_items] = 0;
        }
        else if(total_items == 1)
        {
            total_items = 0;
            strcpy(food_menu[total_items], '\0');
            price[total_items] = 0;
        }
        else
        {
            del--;
            for(int p=del;p<total_items;p++)
            {
                strcpy(food_menu[p], food_menu[p+1]);
                price[p] = price[p+1];
            }
            total_items--;
        }
        cout<<"\n\nRecords updated successfully...";
    }
}

void Admin::mod_rest_profile()
{
    if(strcmp(::input_uniqueid, unique_id) == 0)
    {
        cout<<"\nThe Profile details are :- ";
        cout<<"\n  1. Food Stall Email ID       : "<<email;
        cout<<"\n  2. Food Stall Mobile no.     : "<<mobile;
        cout<<"\n  3. Food Stall Type           : "<<food_type;

        int ch=0;
        cout<<"\n\nEnter the details to be modified (Unique No.): ";
        cin>>ch;

        switch (ch)
        {
            case 1: 
                    {
                        char nmail[50];
                        cout<<"\nEnter the new email id: ";
                        cin>>nmail;
                        strcpy(email, nmail);
                        cout<<"\n\nRecords updated successfully...";
                        break;
                    } 

            case 2: 
                    {
                        char nmobile[15];
                        cout<<"\nEnter the new mobile no.: ";
                        cin>>nmobile;
                        strcpy(mobile, nmobile);
                        cout<<"\n\nRecords updated successfully...";
                        break;
                    }

            case 3: 
                    {
                        char ntype[20];

                        cout<<"\nFood Stall Food options available are \n1. South-Indian\n2. Continental\n3. Chinese\n4. Thai\n5. Multiple ";
                        int n;
                        cout<<"\nEnter the Food Stall Food Options Type (Unique Number)";
                        cin>>n;

                        switch(n){
                            case 1: strcpy(ntype , "South Indian");
                                    break;
                            case 2: strcpy(ntype , "Continental");
                                    break;
                            case 3: strcpy(ntype , "Chinese");
                                    break;
                            case 4: strcpy(ntype , "Thai");
                                    break;
                            case 5: strcpy(ntype , "Multiple");
                                    break;
                        }
                        strcpy(food_type, ntype);
                        cout<<"\n\nRecords updated successfully...";
                        break;
                    }
            
            default:    cout<<"\nInvalid Input Provided...";
                        break;
        }
    }
}

int Admin::display_rest_menu_to_customer()
{
    if(strcmp(::input_stallid, stall_id) == 0)
    {
        cout<<"\nFood Stall Name                            :"<<name;
        cout<<"\nFood Stall ID                              :"<<stall_id;
        cout<<"\nFood Stall Food Menu Type                  :"<<food_type;
        cout<<"\nFood Stall Food Menu Items                 :"<<total_items;

        if(total_items==0)
            cout<<"\n(No Food Items Specified...)";

        for(int i=0;i<total_items;i++)
        {
            cout<<"\n\tFood Item "<<i+1<<" : "<<food_menu[i]<<" :: Price: INR"<<price[i];
        }

        return 1;
    }
    else
        return 0;
}

void Admin::redisplay_menu_to_customer()
{
        cout<<"\nFood Stall Name                            :"<<name;
        cout<<"\nFood Stall ID                              :"<<stall_id;
        cout<<"\nFood Stall total Food Menu Items           :"<<total_items;

        if(total_items==0)
            cout<<"\n(No Food Items Specified...)";

        for(int i=0;i<total_items;i++)
        {
            cout<<"\n\tFood Item "<<i+1<<" : "<<food_menu[i]<<" :: Price: INR"<<price[i];
        }
}

int Admin::search_rest_by_foodtype()
{
    if(strcmp(::input_foodtype, food_type)==0)
    {
        cout<<"\nFood Stall Name                            :"<<name;
        cout<<"\nFood Stall ID                              :"<<stall_id;
        cout<<"\nFood Stall Food Menu Items                 :"<<total_items;

        if(total_items==0)
            cout<<"\n(No Food Items Specified...)";

        for(int i=0;i<total_items;i++)
        {
            cout<<"\n\tFood Item "<<i+1<<" : "<<food_menu[i]<<" :: Price: INR"<<price[i];
        }
        return 1;
    }
    else
        return 0;
}


void Admin::invalid_input()
{
    cout<<"\n\n\n\n\t\t\tInvalid Input Provided !!!";
    getch();
    system("cls");
    cout<<"\n\n\n\n\t\t\tThank You...";
}  


class MainMenu{

    public:
        void admin_call();
        void food_stall_call();
        void customer_call();
        void invalid_user_input();

}menu;


void MainMenu::admin_call()
{
    char adminuser[20], adminpass[20];
    cout<<"\n\n\n\t\t\tWelcome to Admin Login Portal of FoodFleet";
    cout<<"\n\nEnter the Username: ";
    cin>>adminuser;
    cout<<"\nEnter the Password: ";
    
    int i;
    for(i=0;i<8;i++)
    {
        adminpass[i] = getch();
        cout<<"*";
    }
    getch();
    adminpass[i] = '\0';

    if((strcmp(adminuser,"yash") == 0) && (strcmp(adminpass,"yash1234") == 0))
        system("cls");

    else
    {
        cout<<"\n\n\t\t\tInvalid Access to Portal";
        cout<<"\n\n\t\t\tThank You ...";
        getch();
        exit(0);
    }

    int temp;
    char option = 'y';
    
    do
    {
        cout<<"\n\n\t\t\tWelcome to Admin Panel";
        cout<<"\n\nPress 1 to Add Single Food Stall with records";
        cout<<"\n\nPress 2 to Add Multiple Food Stalls with records";
        cout<<"\n\nPress 3 to View all Food Stalls with records";
        cout<<"\n\nPress 4 to Delete a Food Stall with records";
        cout<<"\n\tEnter your Choice: ";
        cin>>temp;
        system("cls");


        switch(temp)
        {
            case 1:
                    {
                        cout<<"\nEnter the details:-";
                        fstream fs;
                        fs.open("foodstallinfo.txt", ios::in | ios::out | ios::ate);
                        admin.set_rest_data();
                        fs.write((char *)&admin, sizeof(Admin));
                        fs.close();
                        cout<<"\nRecord added successfully...";
                    }
                    break;

            case 2:
                    {
                        int m=0;
                        fstream fs;
                        fs.open("foodstallinfo.txt", ios::in | ios::out | ios::ate);
                        do
                        {
                            cout<<"\nEnter the details:-";
                            admin.set_rest_data();
                            fs.write((char *)&admin, sizeof(Admin));
                            cout<<"\nPress 1 if you want to enter more records, else press 0: ";
                            cin>>m;

                        }while(m==1);
                        fs.close();
                        cout<<"\nRecords entered successfully...";
                    }
                    break;

            case 3:
                    {
                        fstream fs;
                        fs.open("foodstallinfo.txt", ios::in);
                        fs.seekg(0);
                         

                        while (fs.peek() != EOF)
                        {
                           fs.read((char *)&admin, sizeof(Admin));
                           admin.rest_display();
                        }
                        fs.close();
                    }
                    break;
            
            case 4:
                    {
                        char tempid[15];
                        int del = 0, result = -1;

                        cout<<"\nEnter the Food Stall ID: ";
                        cin>>tempid;

                        fstream fs;
                        fs.open("foodstallinfo.txt", ios::in);
                        fstream fs1;
                        fs1.open("tempinfo.txt", ios::out | ios::ate);
                         

                        while(fs.peek() != EOF)
                        {
                            fs.read((char *)&admin, sizeof(Admin));
                            result = strcmp(tempid, admin.unique_id);

                            if(result == 0)
                                del = 1;

                            else    
                                fs1.write((char *)&admin, sizeof(Admin));
                        }

                        if(del == 1)
                            cout<<"\nRecord deletion successful...";
                        else    
                            cout<<"\nRecord not found...";
                        
                        fs.close();
                        fs1.close();
                        remove("foodstallinfo.txt");
                        rename("tempinfo.txt" , "foodstallinfo.txt");
                    }
                    break;
        }

        getch();
        cout<<"\n\nPress 'y' for more operations, else press 'n'...";
        cin>>option;

        if( option!='y' && option!='Y')
        {
            system("cls");
            cout<<"\n\n\n\n\n\t\t\t\t\tThank You...";
            getch();
            exit(0);
        }

    } while (option == 'Y' || option == 'y');
    
}


void MainMenu::food_stall_call()
{
    system("cls");
    int val, s=0;
    cout<<"\n\t\tWelcome to Food Stall Login Page of FoodFleet";
    cout<<"\nEnter the Username: ";
    cin>>::input_uniqueid;

    fstream fs;
    fs.open("foodstallinfo.txt", ios::in | ios::binary);
    fs.seekg(0);
     

    while (fs.peek() != EOF)
    {
        val = -1;
        fs.read((char *)&owner, sizeof(Admin));
        val = owner.login();

        if(val==1)
        {
            s=1;
            break;
        }
    }
    fs.close();
    if (s==1)
        system("cls");
    
    if (s!=1)
    {
        system("cls");
        int option = 0;

        cout<<"\n\n\n\t\t\tYour Login Credentials are Incorrect";
        cout<<"\nThe Username is your Unique ID.";
        cout<<"\nThe Password is Case-sensitive.";
        cout<<"\nPress 1 to Recover Password and Press 2 to Re-attempt Login";
        cout<<"\nEnter the Choice: ";
        cin>>option;

        if(option == 1)
        {
            cout<<"\nEnter the username: ";
            cin>>::input_uniqueid;
            
            fstream fs;
            fs.open("foodstallinfo.txt", ios::in | ios::binary);
            fs.seekg(0);
             

            int re, su = -1;
            while (fs.peek() != EOF)
            {
                re = -1;
                fs.read((char *)&owner, sizeof(Admin));
                re = owner.recover();

                if(re == 1)
                {
                    su = 1;
                    break;
                }
            }
            fs.close();
            
            if(su==1)
            {
                getch();
                system("cls");
                cout<<"\n\n\n\n\n\t\t\t\tThank You...";
                getch();
                exit(0);
            }
            else
            {
                cout<<"\nYou are an invalid user.";
                getch();
                exit(0);
            }
        }

        if(option == 2)
        {
            cout<<"\nEnter the Username: ";
            cin>>::input_uniqueid;

            fstream fs;
            fs.open("foodstallinfo.txt", ios::in | ios::binary);
            fs.seekg(0);
             


            int suc = -1, val;
            while (fs.peek() != EOF)
            {
                val = -1;
                fs.read((char *)&owner, sizeof(Admin));
                val = owner.login();

                if(val == 1)
                {
                    suc = 1;
                    break;
                }
            }
            fs.close();
            
            if(suc == 1)
                system("cls");
            else
            {
                getch();
                cout<<"\nYou are an invalid user.";
                getch();
                exit(0);
            }

        }

        if(option!=1 && option!=2)
        {
            cout<<"\n\n\nInvalid input provided.";
            cout<<"\n\n\t\t\t\tThank You...";
            getch();
            exit(0);
        }
    }

    char ch = 'y';

    do
    {
        system("cls");
        cout<<"\n\n\n\t\t\tWelcome to Food Stall Panel of FoodFleet";
        cout<<"\n\n\t\t\t\t\t\tYour Unique ID is: "<<::input_uniqueid;
        cout<<"\n\nPress 1 to View your profile.";
        cout<<"\nPress 2 to See your Menu.";
        cout<<"\nPress 3 to Add a Food Item.";
        cout<<"\nPress 4 to Delete a Food Item.";
        cout<<"\nPress 5 to Modify your Profile.";

        int choice;
        cout<<"\n\nEnter your Choice: ";
        cin>>choice;

        if(choice == 1)
        {
            fstream fs;
            fs.open("foodstallinfo.txt", ios::in);
            fs.seekg(0);
            int x;
             

            while (fs.peek() != EOF)
            {
                x=0;
                fs.read((char *)&owner, sizeof(Admin));
                x=owner.rest_profile();

                if(x==1)
                    break;
            }
            fs.close();
        }

        if(choice == 2)
        {
            fstream fs;
            fs.open("foodstallinfo.txt", ios::in);
            fs.seekg(0);
            int y;
             

            while (fs.peek() != EOF)
            {
                y=0;
                fs.read((char *)&owner, sizeof(Admin));
                int y = owner.know_rest_menu();

                if(y==1)
                    break;
            }
            fs.close();
        }

        if(choice == 3)
        {
            fstream fs;
            fstream fs1;
            fs.open("foodstallinfo.txt", ios::in | ios::binary);
            fs1.open("tempinfo.txt", ios::out | ios::ate);
            fs.seekg(0);
             

            while (fs.peek() != EOF)
            {
                fs.read((char *)&owner, sizeof(Admin));
                owner.add_rest_menu();
                fs1.write((char *)&owner, sizeof(Admin));
            }
            fs.close();
            fs1.close();

            remove("foodstallinfo.txt");
            rename("tempinfo.txt" , "foodstallinfo.txt");
        }

        if (choice == 4)
        {
            fstream fs;
            fstream fs1;
            fs.open("foodstallinfo.txt", ios::in | ios::binary);
            fs1.open("tempinfo.txt", ios::out | ios::ate);
            fs.seekg(0);
             

            while (fs.peek() != EOF)
            {
                fs.read((char *)&owner, sizeof(Admin));
                owner.del_rest_menu();
                fs1.write((char *)&owner, sizeof(Admin));
            }
            fs.close();
            fs1.close();

            remove("foodstallinfo.txt");
            rename("tempinfo.txt" , "foodstallinfo.txt");   
        }

        if (choice == 5)
        {   
            cout<<"\nEnter the Unique ID of the Food Stall: ";
            cin>>::input_uniqueid;
            fstream fs;
            fstream fs1;
            fs.open("foodstallinfo.txt", ios::in | ios::binary);
            fs1.open("tempinfo.txt", ios::out | ios::ate);
            fs.seekg(0);
             

            while (fs.peek() != EOF)
            {
                fs.read((char *)&owner, sizeof(Admin));
                owner.mod_rest_profile();
                fs1.write((char *)&owner, sizeof(Admin));
            }
            fs.close();
            fs1.close();

            remove("foodstallinfo.txt");
            rename("tempinfo.txt" , "foodstallinfo.txt");
        }
        
        if(choice<1 || choice>5)
            cout<<"\nInvalid input provided.";

        cout<<"\n\n\t\t\tEnter to Continue";
        getch();
        
        cout<<"\n\nPress 'y' for more operations, else press 'n'...";
        cin>>ch;

        if( ch!='y' && ch!='Y')
        {
            system("cls");
            cout<<"\n\n\n\n\n\t\t\t\t\tThank You...";
            getch();
            exit(0);
        }

    } while (ch=='y' || ch=='Y');
    
}

void MainMenu::customer_call()
{
    char option = 'y';
    system("cls");

    do
    {
        system("cls");
        cout<<"\n\n\t\t\tWelcome to Customer Panel of FoodFleet";
        cout<<"\n\nPress 1 to View All Food Stall Details.";
        cout<<"\n\nPress 2 to Search a Stall by its ID.";
        cout<<"\n\nPress 3 to Search a Food Stall depending on food type.";

        int choice;
        cout<<"\n\nEnter your Choice: ";
        cin>>choice;

        if (choice == 1)
        {
            fstream fs;
            fs.open("foodstallinfo.txt", ios::in);
            fs.seekg(0);
             

            while (fs.peek() != EOF)
            {
                fs.read((char *)&admin, sizeof(Admin));
                admin.redisplay_menu_to_customer();
            }
            fs.close();
        }
        
        if (choice == 2)
        {
            int result = -1;
            cout<<"\nEnter the Food Stall ID: ";
            cin>>::input_stallid;

            fstream fs;
            fs.open("foodstallinfo.txt", ios::in);
            fs.seekg(0);
             

            while (fs.peek() != EOF)
            {
                fs.read((char *)&admin, sizeof(Admin));
                result = admin.display_rest_menu_to_customer();

                if(result == 1)
                    break;
            }
            if(result!=1)
                cout<<"\nRecords not Found...";
            fs.close();
        }
        
        if (choice == 3)
        {
            cout<<"\nFood Stall Food options available are \n1. South-Indian\n2. Continental\n3. Chinese\n4. Thai\n5. Multiple ";
            int result;
            cout<<"\nEnter the Food Stall Food Options Type (Unique Number)";
            cin>>result;

            switch(result){
                case 1: strcpy(::input_foodtype , "South Indian");
                        break;
                case 2: strcpy(::input_foodtype , "Continental");
                        break;
                case 3: strcpy(::input_foodtype , "Chinese");
                        break;
                case 4: strcpy(::input_foodtype , "Thai");
                        break;
                case 5: strcpy(::input_foodtype , "Multiple");
                        break;
            }

            fstream fs;
            fs.open("foodstallinfo.txt", ios::in);
            fs.seekg(0);
             

            while (fs.peek() != EOF)
            {
                fs.read((char *)&admin, sizeof(Admin));
                result = admin.search_rest_by_foodtype();

                // if(result == 1)
                //     break;
            }
            if(result!=1)
                cout<<"\nRecords not Found...";
            fs.close();
        }
        
        if (choice<1 || choice>3)
        cout<<"\nInvalid input provided.";

        cout<<"\n\n\t\t\tEnter to Continue";
        getch();
        
        cout<<"\n\nPress 'y' for more operations, else press 'n'...";
        cin>>option;

        if( option !='y' && option !='Y')
        {
            system("cls");
            cout<<"\n\n\n\n\n\t\t\t\t\tThank You...";
            getch();
            exit(0);
        }

    } while (option=='y' || option=='Y');
    
}


void MainMenu::invalid_user_input()
{
    admin.invalid_input();
}


int main()
{
    int ch;
    system("cls");

    cout<<"\n\n\n\t\t\tWelcome to FoodFleet";
    cout<<"\n\n\n\t\t\t\tEnter to Continue";
    getch();
    system("cls");

    cout<<"\n\n\n\t\t\tPress 1 for Admin Portal";
    cout<<"\n\t\t\tPress 2 for Food Stall Portal";
    cout<<"\n\t\t\tPress 3 for Customer Portal";
    cout<<"\n\n\t\t\tEnter your Choice: ";
    cin>>ch;
    system("cls");

    if(ch==1)
        menu.admin_call();
   else if(ch==2)
       menu.food_stall_call();
   else if(ch==3)
       menu.customer_call();
    else
        menu.invalid_user_input();

    return 0;
}
