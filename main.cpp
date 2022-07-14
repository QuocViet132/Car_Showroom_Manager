#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void homepage(char &choose_number_int)
{
	//fstream input_file("F:\\Code\\C++\\Project C++\\giaodien.txt");
	fstream input_file_gd("giaodien.txt");
  while (!input_file_gd.eof())           // Doc tung dong du lieu va in ra man hinh
  {
    char temp[255];
    input_file_gd.getline(temp,255);    // Du lieu trong file se duoc nhap vao bien temp
    string line = temp;
    cout << line << endl;
  }
  input_file_gd.close();
  cout<<"\t \t \t Nhan Phim Chon Chuc Nang: ";
  cin>>choose_number_int;
}

void Title_Broad()
{
  cout<<"\t +-----+---------------------+-------------------+------------------+----------+\n";
  cout<<"\t | STT | Ten Xe              | Ten Hang SX       | Gia Ban (Ty VND) | So Luong |\n";
  cout<<"\t +-----+---------------------+-------------------+------------------+----------+\n"; 
}

void Split_String(string &str, char *split_str, int &stt)
{ 
  int i, j, k, l, temp;
  char tenxe[20], tenhang[18], giaban[16], soluong[9];

  for (i=0; i<str.find(";",i) ;i++)
  {
    tenxe[i]=split_str[i];
  }
    
  tenxe[i]='\0';                          // Danh dau vi tri ket thuc mang char, ngan khong cho cac phan tu chua duoc gan in ra ki tu rac tren nam hinh
  temp=0;

  for (j=i+1; j<str.find(";",j); j++)
  {
    tenhang[temp]=split_str[j];
    temp++;
  }

  tenhang[j-(i+1)]='\0';                
  temp=0;

  for (k=j+1; k<str.find(";",k); k++)
  {
    giaban[temp]=split_str[k];
    temp++;
  }

  giaban[k-(j+1)]='\0';
  temp=0;

  for (l=k+1; l<str.find(".",l); l++)
  {
    soluong[temp]=split_str[l];
    temp++;
  }

  soluong[l-(k+1)]='\0';
  
  cout<<"\t | "<<setw(4)<<left<<stt;               // Can le cho du lieu duoc in ra man hinh
  cout<<"| "<<setw(20)<<left<<tenxe;
  cout<<"| "<<setw(18)<<left<<tenhang;
  cout<<"| "<<setw(16)<<right<<giaban;
  cout<<" |"<<setw(9)<<right<<soluong<<" |"<<endl;
}

void In_Danh_Sach()                                                                                            // Ham chuc nang 1
{
  cout<<"1 - IN DANH SACH \n"<<endl;
  int stt=1;
  Title_Broad();
  ifstream input_file_data("data.txt",ios::in);

  while (!input_file_data.eof())       // Con tro chay den cuoi file
  {
    char split_str[150];
    input_file_data.getline(split_str,150);
    string str=split_str;
    Split_String(str,split_str,stt);
    stt++;
  }

  input_file_data.close();
  cout<<"\t +-----+---------------------+-------------------+------------------+----------+\n"<<endl;
}

void Them_Xe_Moi(string &car_name_str, string &company_name_str, float &price_float, int &amount_int)              // Ham chuc nang 2
{
  cout<<"2 - Them Xe Moi:\n"<<endl;
	fstream output_file("data.txt", ios::app);
  
  cin.ignore();
  cout<<"\t(?) Ten Xe: ";
  getline(cin,car_name_str);
  
  cout<<"\t(?) Ten Hang San Xuat: ";
  getline(cin,company_name_str);
 
  cout<<"\t(?) Gia Ban: ";
  cin>>price_float;
  
  cin.ignore();
  cout<<"\t(?) So Luong Xe: ";
  cin>>amount_int;

  output_file<<"\n"<<car_name_str<<";"<<company_name_str<<";"<<price_float<<";"<<amount_int<<".";
  output_file.close();

  cout<<"\n\t\tDa Luu Thong Tin. Nhan Phim Bat Ki De Hoan Tat !"<<endl;
}

void Xoa()                    //Ham chuc nang 4
{
  cout<<"5 - Xoa\n\t (?) Ban Muon Xoa: (1) Thong tin cua 1 xe \n\t\t\t   (2) Tat ca du lieu";
  cout<<"\n\t Chon chuc nang: ";
  string choose;
  cin.ignore();
  getline(cin,choose);

  if(choose=="1")           // Xoa thong tin 1 xe
  {

  }
    else if(choose=="2")    // Xoa toan bo du lieu
    {
      system("cls");
      cout<<"\n\n\t\t ! Canh bao ! \n\n\t Thao tac sau se xoa toan bo du lieu (y/n): ";
      string y_n;
      cin>>y_n;
      if (y_n=="y")
      {
        fstream input_file_data("data.txt",ios::trunc);
        input_file_data<<"?";
        input_file_data.close();
        cout<<"\n\t Du LIeu Da Xoa Thanh Cong !\n"<<endl;
      }
    }
      else cout<<"Lua chon that bai !"<<endl;
}

void TimKiem()                // Ham chuc nang 5
{
  cout<<"5 - Tim Kiem:\n\t\t(?) Tim Kiem Tu Khoa: ";
  string key_str;           //Khai bao bien tu khoa tim kiem
  cin.ignore();
  getline(cin,key_str);
  cout<<"\n\t\t\t\t\tKet Qua Tim Kiem\n"<<endl;
  Title_Broad();

  ifstream input_file_data("data.txt",ios::in);
  while (!input_file_data.eof())       // Con tro chay den cuoi file
  {
    char split_str[150];
    input_file_data.getline(split_str,150);
    string str=split_str;
    int position = 0, stt=1;
    position=str.find(key_str);
    if (position>=0 && position<=150)
    {
      Split_String(str,split_str,stt);
    }
  }
  input_file_data.close();
  cout<<"\t +-----+---------------------+-------------------+------------------+----------+\n"<<endl;
}

int main()
{
  char choose_number_int;
  string company_name_str, car_name_str;          // Khai bao bien ten hang Sx va ten xe
  float price_float=0;                                // Khai bao bien gia ban xe
  int import_int=0, export_int=0, amount_int=0;   // Khai bao bien so luong xe nhap, xuat, co trong kho
  bool checkError=true;
  
  do
  {
    system("cls");
    homepage(choose_number_int);
    switch (choose_number_int)
    {
      case '1':
        {
          system("cls");
          In_Danh_Sach();
          system("pause");
          break;
        }
      case '2':
        {
          system("cls");
          Them_Xe_Moi(car_name_str,company_name_str,price_float,amount_int);
          system("pause");
          break;
        }
      case '3':
        {
          break;
        }
      case '4':
        {
          system("cls");
          Xoa();
          system("pause");
          break;
        }
      case '5':
        {
          system("cls");
          TimKiem();
          system("pause");
          break;
        }
      case '6':
        {
          break;
        }
      case '7':
        {
          break;
        }
      case '8':
        {
          checkError=false;
          system("exit");
          break;
        }
      default:
        {
          system("cls");
          cout<<"\n\n\n\t\t\t\t !!! Loi Nhap Phim - Vui Long Nhap Lai !!!\n\n\n";
          system("pause");
        }
    }
  }while(checkError==true);

  system("pause");
  return 0;
}
