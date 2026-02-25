#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <sys/stat.h>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;
int main()
{int Choice;
  do
  {
    int option;
  cout << "FILE MANAGEMENT SYSTEM\n";
  cout << "----------------------\n";
  cout << "\n1. write and create a file";
  cout << "\n2. add more to a file";
  cout << "\n3. read a file ";
  cout << "\n4. delete a file ";
  cout << "\n5. Copy a file ";
  cout << "\n6. Create a folder ";
  cout << "\n7. move a file in a folder ";
  cout << "\n8. Delete a folder ";
  cout << "\n9. Search a file ";
  cout << "\n10. List files in a folder ";
  cout << "\n11. Rename a file";
  cout << "\n12. Rename a folder ";
  cout << "\n13. Show information of a file ";
  cout << "\n0. Exit ";
  cout << "\nenter a option : ";

  cin >> option;

  if (option == 1)
  {
    string file_name_to_write;
    cout << "enter file name : ";
    cin >> file_name_to_write;
    string text_to_be_written;
    cout << "enter the text that you want in file : ";
    cin.ignore();
    getline(cin, text_to_be_written);
    fstream write;
    write.open(file_name_to_write, ios::out);
    if (write.is_open())
    {
      write << text_to_be_written;
      cout << endl
           << "File has has been wrote and created";
    }
    else
    {
      cout << "failure to create and write file";
    }
  };

  if (option == 2)
  {
    fstream append;
    string file_name_to_append;
    cout << "enter file name : ";
    cin >> file_name_to_append;
    string text_to_append;
    cin.ignore();
    cout << "enter text to append : ";
    getline(cin, text_to_append);
    append.open(file_name_to_append, ios::app);
    if (append.is_open())
    {
      append << text_to_append;
    }
    append.close();
  };

  if (option == 3)
  {
    fstream read;
    string file_name_to_read;
    string file_data;
    cout << "enter the name of the file to read : ";
    cin >> file_name_to_read;
    read.open(file_name_to_read, ios::in);
    while (getline(read, file_data))
    {
      cout << file_data << endl;
    };

    read.close();
  };

  if (option == 4)
  {
    string fdelete;
    cout << "enter file name : ";
    cin >> fdelete;
    int status = remove(fdelete.c_str());
    if (status != 0)
    {
      cout << "error deleting file";
    }
    else
    {
      cout << "File successfully deleted" << endl;
    }
  }

  if (option == 5)
  {
    ifstream read;
    string file_name_to_read;
    string file_data;
    cout << "enter the name of the file to copy : ";
    cin >> file_name_to_read;
    read.open(file_name_to_read, ios::in);
    cout << file_data << endl;
    string line;
    while (getline(read, line))
    {
      file_data += line + '\n';
    };
    string file_namee;
    cout << "Enter file name to copy to : ";
    cin >> file_namee;
    ofstream copy;
    copy.open(file_namee, ios::out);
    if (copy.is_open())
    {
      copy << file_data;
    }
    read.close();
    copy.close();
  }
  if (option == 6)
  {
    string folder_name;
    cout << "Enter folder name : ";
    cin >> folder_name;
    mkdir(folder_name.c_str());
  }

  if (option == 7)
  {
    string file_name;
    cout << "enter the name of the file : ";
    cin >> file_name;
    string folder_name;
    cout << "Enter folder name : ";
    cin >> folder_name;
    string file_directory_name = folder_name + "/";
    string file_directory = file_directory_name + file_name;
    int status = rename(file_name.c_str(), file_directory.c_str());
    if (status == 0)
    {
      cout << "Error moving File ";
    }
    else
    {
      cout << "File moved successfully ";
    }
  }
  if (option == 8)
  {
    cout << "enter the name of the folder to delete : ";
    string folder_name;
    cin >> folder_name;
    int status = rmdir(folder_name.c_str());
    if (status != 0)
    {
      cout << "Error deleting Folder ";
    }
    else
    {
      cout << "Folder deleted successfully ";
    }
  }

  if (option == 9)
  {
    cout << "enter the name of the file to search : ";
    string file_name;
    cin >> file_name;
    ifstream search(file_name.c_str());
    int status = search.is_open();
    if (status == 0)
    {
      cout << "Error finding file ";
    }
    else
    {
      cout << "File found successfully " << endl;
      cout << "Full path of File : " << fs::absolute(file_name) << endl;
    }
    search.close();
  }

  if (option == 10)
  {
    string path = "C:/Users/PC/Desktop/vs_code/";
    string wanted_folder;
    cout << "enter the folder name for that you want file names : ";
    cin >> wanted_folder;
    string full_path = path + wanted_folder;
    for (auto &p : fs::recursive_directory_iterator(full_path))
      if (fs::is_regular_file(p))
        cout << p.path() << '\n';
  }

  if (option == 11)
  {
    string file_name, name_to_give_file;
    cout << "enter the name of the file to rename : ";
    cin >> file_name;
    cout << "enter the new name of the file : ";
    cin >> name_to_give_file;
    int status = rename(file_name.c_str(), name_to_give_file.c_str());
    if (status == 1)
    {
      cout << "file renamed";
    }
    else
    {
      cout << "error to rename a file";
    }
  }

  if (option == 12)
  {
    string file_name, name_to_give_file;
    cout << "enter the name of the folder to rename : ";
    cin >> file_name;
    cout << "enter the new name of the folder : ";
    cin >> name_to_give_file;
    int status = rename(file_name.c_str(), name_to_give_file.c_str());
    if (status == 1)
    {
      cout << "folder renamed";
    }
    else
    {
      cout << "error to rename a folder";
    }
  }

  if (option == 13)
  {
    string file_name;
    cout << "Enter the name of file : ";
    cin >> file_name;
    if (fs::exists(file_name))
    {

      cout << "File name : " << file_name << endl;
      cout << "Full path of File : " << fs::absolute(file_name) << endl;
      cout << "Size of file : " << fs::file_size(file_name) << " bytes" << endl;
    }
    else
    {
      cout << "file does not exists !";
    }
  }

  if (option == 0)
  {
    cout << "\nSystem SHUTING DOWN !";
    return 0;
  }
  else{
    cout<<"invalid option !"<<endl;

  }
cout<<"DO you want to continue : 0 == No, 1 == yes";
cin>>Choice;
  
}
  
while(Choice==1);
  }