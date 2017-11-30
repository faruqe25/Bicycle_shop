#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>




using namespace std;

class Bicycle{
private :

    char brand[100],model[100];
    double price,stock;
public :
    Bicycle()
    {
        strcpy(brand,"Not inserted");
        strcpy(model,"Not inserted");
        price =0;
        stock=0;
    }
    void insert_data();
    void show_Bicycle();

    void store_data_to_file();
    void view_all_cycle();

    void search_cycle( char *);
    void search_cycle_with_update( char *);
    void buy_cycle();
    void update_stock();
    void delete_file_record(char *);
    void delete_data();



};


void Bicycle ::insert_data()
{
    cout << endl<<endl<<endl;
    cout << "Enter Brand name : ";
    cin>>brand;
    cout << "Enter Model name : ";
    cin>>model;
    cout << "Enter Price : ";
    cin>>price;
    cout << "Enter stock Amount : ";
    cin>>stock;
}

void Bicycle::show_Bicycle()
{
  cout <<brand<< "  <--->  "<< model<< "  <--->  "<<price<< "   <--->  "<<stock<<endl;

}

void Bicycle::store_data_to_file()
{

    if(price ==0 && brand == "Not inserted")
        {
            cout<< "Data did not inserted";
        }
    else
        {
            ofstream file;
            file.open("cycle.dat",ios::app|ios::binary);
            file.write((char*)this,sizeof(*this));
            file.close();

        }

}

void  Bicycle::view_all_cycle()
{
 ifstream file ;

 file.open("cycle.dat",ios::in|ios::binary);
 if(!file)
 {
     cout << "File does not exists" <<endl;

 }
 else
    {
    file.read((char*)this,sizeof(*this));
    while(!(file.eof()))
    {
       show_Bicycle();
       file.read((char*)this,sizeof(*this));

    }
    file.close();


   }
}

void Bicycle::search_cycle(char *t)
{
    ifstream file;
    int ck=0;
    file.open("cycle.dat",ios::in|ios::binary);
    if(!file)
        {
            cout << "File does not exists  "<<endl;
        }
    else
        {
            file.read((char *)this,sizeof(*this));
            while(!file.eof())
            {
                if(!strcmp(t,brand))
                {
                    show_Bicycle();
                    ck++;


                }
                file.read((char *)this,sizeof(*this));
            }
            if(ck==0)
            {
                cout << "Record does not found " <<endl;
            }
            file.close();
        }
}

void Bicycle::search_cycle_with_update(char *k)
{
    fstream file;
    int ck=0;
    file.open("cycle.dat",ios::in|ios::ate|ios::out|ios::binary);
    file.seekg(0);
    file.read((char *)this,sizeof(*this));
    while(!file.eof())
     {
       if(!strcmp(k,brand))
        {
          cout << "You are trying to buy this product "<<endl<<endl;
          show_Bicycle();
          update_stock();
          file.seekg(file.tellp()-sizeof(*this));
          file.write((char *)this,sizeof(*this));
          ck++;
        }
         file.read((char *)this,sizeof(*this));
     }
     if(ck==0)
     {
         cout << "Invalid insertion "<<endl;
     }

file.close();
}

void Bicycle::delete_file_record(char *l)
{
    ifstream fin;
    ofstream fout;
    fin.open("cycle.dat",ios::in|ios::binary);
    if(!fin.is_open())
    {
        cout << "Error opening file "<<endl;
    }
    else
    {
        fout.open("tem.dat",ios::out|ios::binary);
        fin.read((char *)this,sizeof(*this));
        while(!fin.eof())
        {
            if(strcmp(l,brand))
            {
              fout.write((char *)this,sizeof(*this));
            }
             fin.read((char *)this,sizeof(*this));

        }
        fin.close();
        fout.close();
        remove("cycle.dat");
        rename("tem.dat","cycle.dat");

    }


}




void Bicycle::update_stock()
{
 double a;
 cout << "Enter the amount : ";
 cin >> a ;
 if (a >0 && stock >=a)
 {

     stock =stock - a;
     cout << " You have purchased the the cycle successfully " <<endl;
 }
 else
    {
     cout << "Stock is not available " <<endl;
    }
}
void Bicycle::buy_cycle()
{
    cout <<endl<<endl<<"Brand" <<" <--->" << " Model"<<" <--->" << " Price"<<" <--->" << " Stock"<<endl<<endl;
    view_all_cycle();
    char p[100];
    double a;
    cout <<endl<<endl<< "Enter Brand Name : ";
    cin>>p;
    search_cycle_with_update(p);
}
int Menu()
{
    int ch;
    cout << endl<<" <<----------------- Welcome to Bicycle Shop --------------->> " << endl <<endl <<endl;
    cout << "Press 1 for login Admin  " << endl;
    cout << "Press 2 for selling product " << endl;
    cout << "Press 0 to exit " << endl;
    cout << endl<<endl<<"Enter your choice : ";
    cin>> ch;
    return ch;
}
int admin()
{
    cout  <<endl<<endl<< "Congratulation, You have successfully logged in as a Admin " <<endl <<endl;
    cout << "Press 1 for insert Data"<<endl;
    cout << "Press 2 for view all Bicycle"<<endl;
    cout << "Press 3 for search Bicycle"<<endl;
    cout << "Press 4 to Delete specific record " <<endl;
    cout << "Press 5 to Delete whole file " <<endl;
    cout << "Press 6 to Main menu " <<endl;
    cout << "Press 0 to exit" <<endl;
    int a;
    cout << endl<<endl<<"Enter your choice : ";
    cin >> a;
    return a;
}
int buyer()
{
    cout  <<endl<<endl<< "Congratulation, Welcome to Bicycle shop " <<endl <<endl;
    cout << "Press 1 for view all cycle"<<endl;
    cout << "Press 2 for Buy Product"<<endl;
    cout << "Press 0 to exit" <<endl;
    int a;
    cout << endl<<endl<<"Enter your choice : ";
    cin >> a;
    return a;
}
void details ()
{
    cout <<endl<<endl<<"Brand" <<" <--->" << " Model"<<" <--->" << " Price"<<" <--->" << " Stock"<<endl<<endl;
}

int main()
{
     Bicycle c1;

     x:
     while(1)
     {

             system("cls");

            switch(Menu())
            {
                case 1:
                    switch(admin())
                        {
                            case 1:
                                c1.insert_data();
                                c1.store_data_to_file();
                                system("cls");
                                cout<< endl<<"Data Successfully Recorded to the file "<<endl;

                                cout<< "Press any key";
                                getch();
                                break;
                            case 2:
                                details ();

                                c1.view_all_cycle();

                                cout<<endl<< "Press any key";
                                getch();
                                break;
                            case 3:
                                    system ("cls");
                                    char p[100];
                                    cout <<endl<<endl<<"You are going to search from here --->" <<endl;
                                    details ();
                                    c1.view_all_cycle();
                                    cout << endl<<"Enter Brand Name to  : ";
                                    cin>>p;
                                    system ("cls");
                                    cout << "Search result ==>>"<<endl<<endl;

                                    c1.search_cycle(p);
                                    cout<<endl<<endl<< "Press any key";
                                    getch();
                                    break;
                            case 4:
                                   char o[100];
                                    details ();
                                    c1.view_all_cycle();
                                    cout << endl<<"Enter Brand Name to delete : ";
                                    cin>>o;
                                    system ("cls");
                                    c1.view_all_cycle();
                                    c1.delete_file_record(o);
                                    cout << endl<<"You have successfully deleted the record "<<endl<<endl;
                                    getch();
                                    cout <<endl<<endl<< "Press any key "<<endl;
                                    break;
                            case 5:
                                system("cls");
                                char c;
                                cout << endl<<endl<<endl<< "Are you sure for deleting the whole file ??  ";
                                cout << endl<<endl<< "You can not reach the file again";
                                cout << endl<< "Press ( Y ) to confirm";
                                cout << endl<< "Press ( N ) to confirm";
                                cout << endl<< "Enter your choice : ";
                                cin>>c;
                                if(c=='Y' ||c=='y')
                                    {
                                       remove("cycle.dat");
                                       cout<<endl <<endl<<"You have successfully Deleted the whole file ...."<<endl;
                                       break;
                                    }
                                else
                                    {
                                         system("cls");
                                         goto x;

                                    }


                            case 6:
                                system("cls");
                                goto x;



                            case 0:
                                cout << endl<<"You have Successfully logged out "<<endl;
                                cout<<endl<<endl<< "Press any key";
                                getch();
                                exit(0);
                                break;
                            default :
                                cout << "Invalid Choice "<<endl;
                                exit(0);


                        }


                        goto x;

                    case 2:
                        y:
                        switch(buyer()){
                            case 1:
                                system("cls");
                                details ();
                                c1.view_all_cycle();
                                cout<<endl<<endl<< "Press any key";
                                getch();
                                system("cls");
                                goto y;

                            case 2:
                                c1.buy_cycle();
                                cout<<endl<<endl<< "Press any key";
                                getch();
                                break ;
                            case 0:
                                cout <<endl<<endl<<endl<< "             Thanks for using The APPLICATION              " << endl;
                                cout<<endl<<endl<< "Press any key";
                                getch();
                                exit(0);
                                break;

                            default:
                                cout << "Invalid choice " <<endl;




                        }


                        case 0:
                            cout <<endl<<endl<<endl<< "                          Thanks for using The APPLICATION              " << endl;
                            cout<<endl<<endl<< "Press any key";
                            getch();
                            exit(0);
                            break;
                        default:
                            cout <<endl<<endl<< "Invalid choice " <<endl;

                            cout<<endl<<endl<< "Press any key";
                              getch();
                            exit(0);







            }
     }


   

    return 0;

}
