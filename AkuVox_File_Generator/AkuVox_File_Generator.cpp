// AkuVox_File_Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>      //required while dealing with files
#include <string>       //requiered for getline
#include <vector>

int main()
{
    using namespace std;
    string version = "1.04";
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


    cout << "By Luca Moser, version " << version << endl << endl;
    cout << "Welcome" << "This program creates files according to a sourcefile, which contain the attributes." << endl <<
        "The sourcefile has to be located at the same place and has to be called '" << source_filename << "'." << endl <<
        "The seperation between the values is standard '" << delim << "'" << endl;

    cout << "Press any key to continue" << endl;
    getchar();

    // open source file
    ifstream input_file(source_filename);
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

    cout << "Press any key to exit" << endl;
    getchar();
    return EXIT_SUCCESS;
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