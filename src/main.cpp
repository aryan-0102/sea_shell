#include <bits/stdc++.h>
using namespace std;

string current_directory = "C:/ ";
unordered_map<string, string> commands = {
    {"cwd", "Displays the current working directory"},
    {"show", "Displays the contents of a file"},
    {"help", "Displays all the available commands."},
    {"clear", "Clears the screen"},
    {"cd", "Change directory to specified location"}
};

// Class to handle "cwd" command (current working directory)
class cwd {
public:
    static void display() {
        cout << "Current Working directory ---> " << current_directory << endl;
    }
};

// Class to handle "show" command (show file contents)
class show {
public:
    static void display(const string& filename) {
        ifstream file(filename);
        if (file) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
        } else {
            cout << "File not found!" << endl;
        }
    }
};

// Class to handle "cd" command (change directory)
class cd {
private:
    string address;
public:
    cd(string comm = "C:/") : address(comm) {}

    void change() {
        current_directory = this->address;
    }
};

// Class to handle "clear" command (clear the screen)
class clear {
public:
    static void display() {
        system("cls");
    }
};

// Class to handle "help" command (display help)
class help {
public:
    static void display() {
        for (auto it = commands.begin(); it != commands.end(); ++it) {
            cout << it->first << "\t" << it->second << endl;
        }
    }
};

// Class to process the input commands
class process {
private:
    string inp;

public:
    process(string input = "") : inp(input) {}

    void execute() {
        
        stringstream ss(inp);
        string command;
        ss >> command;

        if (command == "cwd") {
            cwd::display();
        } else if (command == "help") {
            help::display();
        } else if (command == "clear") {
            clear::display();
        } else if (command == "cd") {
            string path;
            ss >> path;
            cd changeDir(path);
            changeDir.change();
        } else if (command == "show") {
            string filename;
            ss >> filename;
            show::display(filename);
        } else if (command == "exit") {
            cout << "Exiting the shell..." << endl;
            exit(0);
        } else {
            cout << "Unknown command. Type 'help' for the list of available commands." << endl;
        }
    }
};

int main() {
    cout << "Welcome to Sea_Shell , an Open-Source Command Line Shell!" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "This shell allows you to interact with your file system and execute various commands." << endl;
    cout << "Feel free to type a command and press ENTER to execute." << endl;
    cout << "Use 'help' for a reminder of the available commands." << endl << endl;
    cout << "Let's get started!" << endl << endl;
    cout << "Programmed by: Aryan Dhasmana" << endl<<"Email @ : aryan010204@protonmail.com";
    cout <<"Version 0.1"<<endl;  
    cout << "----------------------------------------------------------" << endl;


    while (true) {
        string input;
        cout << current_directory << ">> ";
        getline(cin, input);

        
        process cmd(input);
        cmd.execute();
    }

    return 0;
}
