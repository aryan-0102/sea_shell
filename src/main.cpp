#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>
#include <cstdlib> 
#include <fstream>

using namespace std;
using namespace std::filesystem;

string current_directory = "C:/"; // Starting directory

void shell_shape(){
    cout << "            ___" << endl;
    cout << "        .-\"; ! ;\"-." << endl;
    cout << "      .'!  : | :  !`." << endl;
    cout << "     /\\  ! : ! : !  /\\" << endl;
    cout << "    /\\ |  ! :|: !  | /\\" << endl;
    cout << "   (  \\ \\ ; :!: ; / /  )" << endl;
    cout << "  ( `. \\ | !:|:! | / .' )" << endl;
    cout << "  (`. \\ \\ \\!:|:!/ / / .')" << endl;
    cout << "   \\ `.`.\\ |!|! |/,'.' /" << endl;
    cout << "    `._`.\\\\\\!!!// .'_.' " << endl;
    cout << "       `.`.\\\\|//.'.'" << endl;
    cout << "        |`._`n'_.'|  hjw" << endl;
    cout << "        \"----^----\"" << endl;
}

void name(){
    cout<<"\033[32m";
    cout << "        _______. _______     ___              _______. __    __   _______  __       __            \n"
    << "       /       ||   ____|   /   \\            /       ||  |  |  | |   ____||  |     |  |           \n"
    << "      |   (----`|  |__     /  ^  \\          |   (----`|  |__|  | |  |__   |  |     |  |           \n"
    << "       \\   \\    |   __|   /  /_\\  \\          \\   \\    |   __   | |   __|  |  |     |  |           \n"
    << "   .----)   |   |  |____ /  _____  \\     .----)   |   |  |  |  | |  |____ |  `----.|  `----.      \n"
    << "   |_______/    |_______/__/     \\__\\    |_______/    |__|  |__| |_______||_______||_______|      \n";

    cout << "\033[0m";
}
// Function to split strings based on a delimiter
vector<string> split(const string &s, char delimiter = ' ') {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to list the contents of the directory
void listDirectoryContents(const string& path) {
    try {
        if (exists(path) && is_directory(path)) {
            for (const auto& entry : directory_iterator(path)) {
                cout << entry.path().string() << '\n';
            }
        } else {
            cerr << "The path either doesn't exist or is not a directory.\n";
        }
    } catch (const filesystem_error& e) {
        cerr << "Filesystem error: " << e.what() << '\n';
    } catch (const exception& e) {
        cerr << "General error: " << e.what() << '\n';
    }
}

// Function to change the current directory
void changeDirectory(const string& path) {
    if (exists(path) && is_directory(path)) {
        cout << "Changing directory to: " << path << endl;
        current_directory = path;
        current_path(path);
    } else {
        cout << "Directory does not exist." << endl;
    }
}

// Function to create a new file or directory
void create(const string& name, bool isFile = true) {
    if (isFile) {
        ofstream file(name);
        if (file) {
            cout << "File created: " << name << endl;
            file.close();
        } else {
            cout << "Failed to create file." << endl;
        }
    } else {
        if (create_directory(name)) {
            cout << "Directory created: " << name << endl;
        } else {
            cout << "Failed to create directory." << endl;
        }
    }
}

// Function to exit the program
void exitProgram() {
    cout << "Exiting program..." << endl;
    exit(0);
}

// Function to display the help menu
void help() {
    cout << "Help Menu:\n";
    cout << "1. Change (change <directory>) - Change current directory.\n";
    cout << "2. Create (create <filename> or <foldername>) - Create a new file or folder.\n";
    cout << "3. Exit (exit) - Exit the program.\n";
    cout << "4. Help (help) - Display this help menu.\n";
    cout << "5. Delete (delete <filename or folder>) - Delete a file or folder.\n";
    cout << "6. Print (print) - Print the current directory.\n";
    cout << "7. PWD (pwd) - Print the current working directory.\n";
    cout << "8. New (new <filename>) - Create a new file.\n";
    cout << "9. View (view <filename>) - View the contents of a file.\n";
    cout << "10. Clear (clear) - Clear the screen.\n";
    cout << "11. List (list) - List all files and folders in the current directory.\n";
}

// Function to delete a file or folder
void deleteItem(const string& name) {
    if (exists(name)) {
        if (is_directory(name)) {
            remove_all(name);
            cout << "Directory deleted: " << name << endl;
        } else {
            remove(name);
            cout << "File deleted: " << name << endl;
        }
    } else {
        cout << "Item does not exist." << endl;
    }
}

// Function to print the current directory
void printCurrentDirectory() {
    cout << "Current Directory: " << current_path() << endl;
}

// Function to print the current working directory (PWD)
void printPWD() {
    cout << "Current Working Directory (PWD): " << current_path() << endl;
}

// Function to create a new file
void createNewFile(const string& name) {
    ofstream file(name);
    if (file) {
        cout << "New file created: " << name << endl;
        file.close();
    } else {
        cout << "Failed to create new file." << endl;
    }
}

// Function to view the contents of a file
void viewFile(const string& name) {
    ifstream file(name);
    if (file) {
        cout << "Contents of file " << name << ":\n";
        cout << file.rdbuf() << endl;
        file.close();
    } else {
        cout << "File not found." << endl;
    }
}

// Function to clear the screen
void clearScreen() {
    cout << "\033[2J\033[1;1H";  // ANSI escape sequence for clearing the screen
}

// Function to print the prompt with the current directory in green
void printPrompt() {
    cout << "\033[1;32m" << current_directory << "\033[0m >> "; // Green color for directory
}

int main() {
    shell_shape();
    name();
    cout << "Welcome to Sea_Shell, an Open-Source Command Line Shell!" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "This shell allows you to interact with your file system and execute various commands." << endl;
    cout << "Feel free to type a command and press ENTER to execute." << endl;
    cout << "Use 'help' for a reminder of the available commands." << endl << endl;
    cout << "Let's get started!" << endl << endl;
    cout << "Programmed by: Aryan Dhasmana" << endl << "Email @ : aryan010204@protonmail.com";
    cout << "Version 0.1" << endl;
    cout << "----------------------------------------------------------" << endl;

    while (true) {
        string input;
        printPrompt();
        getline(cin, input);

        vector<string> tokens = split(input);

        if (tokens.empty()) continue;

        string command = tokens[0];

        if (command == "exit") {
            exitProgram();
        } else if (command == "help") {
            help();
        } else if (command == "list") {
            listDirectoryContents(current_directory);
        } else if (command == "change" && tokens.size() > 1) {
            changeDirectory(tokens[1]);
        } else if (command == "create" && tokens.size() > 1) {
            create(tokens[1]);
        } else if (command == "print") {
            printCurrentDirectory();
        } else if (command == "pwd") {
            printPWD();
        } else if (command == "clear") {
            clearScreen();
        } else if (command == "delete" && tokens.size() > 1) {
            deleteItem(tokens[1]);
        } else if (command == "view" && tokens.size() > 1) {
            viewFile(tokens[1]);
        } else {
            cout << "Unknown command. Type 'help' for a list of available commands." << endl;
        }
    }

    return 0;
}
