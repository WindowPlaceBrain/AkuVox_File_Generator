// AkuVox_File_Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>      //required while dealing with files
#include <string>       //requiered for getline
#include <vector>
#include <conio.h>      //for _getch() with is used to select menu without the \n
#include <stdlib.h>     //for using the function sleep


int main()
{
    using namespace std;
    string version = "1.06";
    string delim = ";";
    const int const_valuecount = 4;
    int valuecount;
    string source_filename("_SOURCE.csv");
    string target_filename;
    string value1;
    string value2;
    string value3;
    string value4;
    string value5;
    string value6;
    string value7;
    string line;
    string target_filetype = (".cfg");
    size_t pos = 0;
    char menu_choice;


    cout << "By Luca Moser, version " << version << endl << endl;
    cout << "Welcome" << endl << "This program creates files according to a sourcefile, which contain the attributes." << endl <<
        "The sourcefile has to be located at the same place and has to be called '" << source_filename << "'." << endl <<
        "The seperation between the values is standard '" << delim << "'" << endl << endl;
  
    
    while (true)
    {
        // ask user what he wants to do
        menu_choice = 0;
        cout << endl << "************************************************************************************************************************" << endl <<
            "Choose from the menu: " << endl <<
            "-enter-    Create the configfiles for me." << endl <<
            "-1-        Create '" << source_filename << "' for me, so I know what I have to do. ! CAUTION, it will overwrite the existing file !" << endl <<
            "-2-        Change delimiter character, right now it is '" << delim << "'." << endl <<
            "-3-        Change filetype of the targetfile. Right now it is '" << target_filetype << "'." << endl <<
            "-4-        Change sourcefilename and type. Right now it is '" << source_filename << "'." << endl << 
            "-E-        Exit the program." << endl << 
            endl;
        menu_choice = _getch();

        switch (menu_choice)
        {
        case ' ': case '\r': // create the configfiles
        {
            ifstream input_file(source_filename); // open source file
            if (!input_file.is_open())
            {
                cerr << "Could not open the file - '"
                    << source_filename << "'" << endl;
                cout << "Press any key to exit" << endl;
                getchar();
                return EXIT_FAILURE;
            }

            while (getline(input_file, line)) //get line by line out of file till EOF
            {
                pos = line.find(delim);
                value1 = line.substr(0, pos);
                line.erase(0, pos + delim.length());

                if ((pos != string::npos) && (value1 != "")) // check if no delimiter in line or first attribute empty
                {
                    pos = line.find(delim);
                    value2 = line.substr(0, pos);
                    line.erase(0, pos + delim.length());

                    pos = line.find(delim);
                    value3 = line.substr(0, pos);
                    line.erase(0, pos + delim.length());

                    pos = line.find(delim);
                    value4 = line.substr(0, pos);
                    line.erase(0, pos + delim.length());

                    pos = line.find(delim);
                    value5 = line.substr(0, pos);
                    line.erase(0, pos + delim.length());

                    pos = line.find(delim);
                    value6 = line.substr(0, pos);
                    line.erase(0, pos + delim.length());

                    pos = line.find(delim);
                    value7 = line.substr(0, pos);
                    line.erase(0, pos + delim.length());

                    // cout << "Attributes red" << endl;

                    target_filename = value1 + target_filetype;
                    ofstream outfile(target_filename);
                    outfile
                        << "Config.Account1.GENERAL.Enable = " << value1 << endl
                        << "Config.Account1.GENERAL.Label = " << value2 << endl
                        << "Config.Account1.GENERAL.DisplayName = " << value3 << endl
                        << "Config.Account1.GENERAL.UserName = " << value4 << endl
                        << "Config.Account1.GENERAL.AuthName = " << value5 << endl
                        << "Config.Account1.GENERAL.Pwd = " << value6 << endl
                        << "Config.Account1.GENERAL.UserAgent = " << value7 << endl;

                    outfile.close();
                    cout << "-> File writen : " + target_filename << endl;

                }
                else
                {
                    cout << "-> No delimiter found or no attributes in line --> ignored line --> no file created" << endl;
                }
            }
            input_file.close(); // closing the source file

            cout << endl << "Press any key to continue" << endl;
            getchar();
            break;
        }
        case '1': // create a default sourcefile for the user
        {
            ofstream outfile(source_filename);
            outfile
                << "_Beispiel_File" << delim << "_Enable" << delim << "_Label" << delim << "_DisplayName" << delim << "_UserName" << delim << "_AuthName" << delim << "_Pwd" << delim << "_UserAgent" << endl
                << "Beispiel_MAC_hier_1" << delim << "1" << delim << "Zi. 100" << delim << "Zi. 100" << delim << "8000" << delim << "8000" << delim << "888000" << delim << "" << endl
                << "Beispiel_MAC_hier_2" << delim << "1" << delim << "Zi. 101" << delim << "Zi. 101" << delim << "8001" << delim << "8001" << delim << "888001" << delim << "" << endl
                << "Beispiel_MAC_hier_3" << delim << "1" << delim << "Zi. 102" << delim << "Zi. 102" << delim << "8002" << delim << "8002" << delim << "888002" << delim << "" << endl;
            outfile.close();
            cout << "A file with the name '" << source_filename << "' was successfully writen." << endl;
            break;
        }
        case '2': // change delimiter, can also be longer than char because is string, it even works like that
        {
            cout << "What should be the new delimiter between the attributes? Confirm your choice with 'enter'" << endl;
            cin >> delim;
            break;
        }
        case '3': // cahnge targetfile type
        {
            cout << "What filetype do you want to have for the targetfile? At the moment you have '" << target_filetype << "'. Confirm your choice with 'enter'" << endl;
            cin >> target_filetype;
            break;
        }
        case '4': // change sourcefilename and type
        {
            cout << "What filename with filetype do you want to have for the sourcefile? At the moment you have '" << source_filename << "'. Confirm your choice with 'enter'" << endl;
            cin >> source_filename;
            break;
        }
        case 'E': case 'e': // exit the program
        {
            cout << "Thanks, bye!" << endl;
            getchar();
            return EXIT_SUCCESS;
        }
        
        default: // do nothing, in case something goes wrong
            break;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file