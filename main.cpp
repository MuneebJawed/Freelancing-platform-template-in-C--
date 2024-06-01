#include <iostream>
#include <string>

using namespace std;

bool login() {
    string name;
    string password;

    cout << "Enter your Name: ";
    cin.ignore(); // Clear any leftover characters in the input buffer
    getline(cin, name);
    cout << "Enter the Password: ";
    getline(cin, password);

    if (password.length() != 7 || password.substr(0, 4) != "2023") {
        cout << "Incorrect Password!" << endl;
        return false;
    }

    cout << "Login Accessed! " << endl;
    return true;
}

class Task {
public:
    string title;
    int budget;
    string deadline;

    void basic_details() {
        cout << "Enter the Title: ";
        cin.ignore(); // Clear any leftover characters in the input buffer
        getline(cin, title);
        cout << "Enter Budget($): ";
        cin >> budget;
        cout << "Enter Deadline (D/M): ";
        cin.ignore(); // Clear newline left in the input buffer from previous input
        getline(cin, deadline);
    }

    virtual void display() {
        cout << "Title: " << title << endl;
        cout << "Budget: " << budget << endl;
        cout << "Deadline: " << deadline << endl;
    }

    void post() {
        cout << "YOUR TASK HAS BEEN REGISTERED!" << endl;
    }

    void bid_post() {
        cout << "YOUR BID HAS BEEN SUCCESSFULLY POSTED!" << endl;
    }
};

class WritingTask : public Task {
public:
    int noOfWords;
    string purpose;

    void writing() {
        Task::basic_details();
        cout << "Enter No of Words: ";
        cin >> noOfWords;
        cout << "Enter the purpose (Education, Health, Sitcom, etc): ";
        cin.ignore(); // Clear newline left in the input buffer from previous input
        getline(cin, purpose);
    }

    void display() override {
        Task::display();
        cout << "No of Words: " << noOfWords << endl;
        cout << "Purpose: " << purpose << endl;
    }
};

class ProgrammingTask : public Task {
public:
    int lineOfCode;
    string purpose;

    void programming() {
        Task::basic_details();
        cout << "Enter the Lines of Code: ";
        cin >> lineOfCode;
        cout << "Enter the purpose (website, application, etc): ";
        cin.ignore(); // Clear newline left in the input buffer from previous input
        getline(cin, purpose);
    }

    void display() override {
        Task::display();
        cout << "Lines of Code: " << lineOfCode << endl;
        cout << "Purpose: " << purpose << endl;
    }
};

class GraphicTask : public Task {
public:
    string theme;
    string purpose;

    void graphing() {
        Task::basic_details();
        cout << "Enter the theme (light, dark, pale, etc): ";
        cin.ignore(); // Clear newline left in the input buffer from previous input
        getline(cin, theme);
        cout << "Enter the purpose (animation, poster, etc): ";
        getline(cin, purpose);
    }

    void display() override {
        Task::display();
        cout << "Theme: " << theme << endl;
        cout << "Purpose: " << purpose << endl;
    }
};

int main() {
    int choice;
    int choose;
    WritingTask WT;
    ProgrammingTask PT;
    GraphicTask GT;

    cout << "WELCOME TO FREELANCING PLATFORM" << endl;
    cout << "Select Role: " << endl;
    cout << "1. Client" << endl;
    cout << "2. Freelancer" << endl;
    cout << "Select: ";
    cin >> choice;

    if (!login()) {
        cout << "Login Failed! Exiting..." << endl;
        return 0;
    }

    cout << (choice == 1 ? "Post your Task" : "Bid your Task") << endl;
    cout << "1. Writing Task" << endl;
    cout << "2. Programming Task" << endl;
    cout << "3. Graphic Task" << endl;
    cout << "Choose: ";
    cin >> choose;

    switch (choose) {
        case 1: {
            if (choice == 1) {
                WT.writing();
                WT.display();
                WT.post();
            } else {
                WT.writing();
                WT.display();
                WT.bid_post();
            }
            break;
        }
        case 2: {
            if (choice == 1) {
                PT.programming();
                PT.display();
                PT.post();
            } else {
                PT.programming();
                PT.display();
                PT.bid_post();
            }
            break;
        }
        case 3: {
            if (choice == 1) {
                GT.graphing();
                GT.display();
                GT.post();
            } else {
                GT.graphing();
                GT.display();
                GT.bid_post();
            }
            break;
        }
        default:
            cout << "Invalid choice! Exiting..." << endl;
            return 0;
    }

    return 0;
}
