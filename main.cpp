#include <iostream>

#include <string>

#include <stdlib.h>

using namespace std;
void message();
void signup();
void signin();
void mainmenu();
void searching();
void marketplace();
void feedback();
void request();
void additem();
void monthlyreports();
//declare global variables to use them as index of struct of array
int memberindex = 1, itemsindex = 5, dateindex = 0, idindex = 111;
struct date {
    int day;
    int month;
    int year;

}
date1[100], date2;

struct item {
    int number;
    string category;
    int startingprice;
    string startingdate;
    string enddate;
    string status;
    int userid;
}
item1[100];
struct member {
    int ID;
    string email;
    string name;
    string password;
    string address;
    string phone;
    int points;
}
member1[100];
struct report {
    string categories;
    int solditems;

}
report1[100];
int main() {
    member1[0] = {
        110,
        "fcis2023@gmail.com",
        "fcis",
        "fcis2023",
        "ainshams_university",
        "0123456789",
        4
    };
    item1[0] = {
        101,
        "shoes",
        200,
        "15/3/2020",
        "24/8/2020",
        "available",
        110

    };
    item1[1] = {
        102,
        "bag",
        150,
        "29/5/2019",
        "29/1/2021",
        "available",
        110
    };
    item1[2] = {
        103,
        "mobile",
        2500,
        "11/9/2018",
        "6/5/2022",
        "available",
        110
    };
    item1[3] = {
        104,
        "shoes",
        650,
        "15/7/2019",
        "24/8/2025",
        "available",
        110
    };
    item1[4] = {
        105,
        "mobile",
        12000,
        "2/2/2020",
        "3/3/2023",
        "available",
        110
    };
    for (int i = 0; i < 100; i++) {
        report1[i].categories = item1[i].category;
    }
    message();
}
void message() {
    //display messages to the user to know what he wants to do
    cout << "press 1 to sign up" << "\n";
    cout << "press 2 to sign in" << "\n";
    cout << "press 0 to close the program" << "\n";
    int msg;
    cin >> msg;
    if (msg == 1) {
        signup();
        message();
    } else if (msg == 2) {
        signin();
    } else if (msg == 0) {
        exit(0);

    }
    //validation to the input taken from the user
    else {
        cout << "invalid input" << "\n";
        message();
    }
}
void signup() {
    //declare variable to check the availability of the email and password
    bool check = false;

    // make accounts to the new users

    cout << "please enter your name" << "\n";
    cin.ignore();
    getline(cin, member1[memberindex].name);
    cout << "please enter email" << "\n";
    cin >> member1[memberindex].email;
    cout << "please enter your password" << "\n";
    cin >> member1[memberindex].password;

    //check the availability of the email and password
    for (int i = 0; i < memberindex; i++) {
        if (member1[i].email == member1[memberindex].email && member1[i].password == member1[memberindex].password) {
            check = true;
        }

    }
    if (check == true) {
        cout << "email and password are taken .. try to change them " << endl << endl;
        signup();
    }
    cout << "please enter your address" << "\n";
    cin.ignore();
    getline(cin, member1[memberindex].address);
    cout << "please enter your number" << "\n";
    cin >> member1[memberindex].phone;

    member1[memberindex].ID = idindex;
    cout << "you have signed up successfully" << endl;
    cout << "Your account ID is " << idindex << endl;

    memberindex++;

    idindex++;
    cout << endl;
    message();

}
void signin() {
    //variable check to check the correction of email and password
    bool check = false;
    // to save the index of the user to use it
    int index = 0;
    // declare email and password string to recieve the inputs from the user at them and compare it with the registered accounts
    string email, password;
    cout << "please enter your email" << endl;
    cin >> email;
    cout << "please enter your password" << endl;
    cin >> password;
    for (int i = 0; i < 100; i++) {
        if (email == member1[i].email && password == member1[i].password) {
            check = true;
            index = i;
        }
    }
    //if statement to check the email and password true or not
    if (check == true) {
        cout << endl;
        cout << "hello " << member1[index].name << " your point is " << member1[index].points << endl;
        cout << endl;
        mainmenu();
    } else {
        cout << "incorrect email or password" << endl;
        signin();
    }
}
void mainmenu() {
    int order;
    cout << "to go to the market place enter 1" << endl;
    cout << "to search for item press 2" << endl;
    cout << "to make a request to buy item from marketplace enter 3" << endl;
    cout << "to give your feedback about a member enter 4" << endl;
    cout << "to add item into market place enter 5" << endl;
    cout << "to show the top category in the month enter 6" << endl;
    cout << "to sign out enter 7" << endl;
    cout << "to close the program enter 0" << endl;
    cin >> order;
    if (order == 1) {
        marketplace();
    } else if (order == 2) {
        searching();
    } else if (order == 3) {
        request();
    } else if (order == 4) {
        feedback();
    } else if (order == 5) {
        additem();
    } else if (order == 6) {
        monthlyreports();

    } else if (order == 7) {
        message();
    } else if (order == 0) {
        exit(0);
    } else {
        cout << "invalid input" << endl;
        mainmenu();
    }
}
void searching() {
    //  int order to recieve the order of the user .. counter to check the availability of the item user search for
    int order, price, counter = 0;
    //declare string category to recieve the category the user search for
    string categ;

    cout << "enter 1 to search via category only" << endl;
    cout << "enter 2 to search via category and price" << endl;
    cout << "enter 0 to go back to main menu" << endl;
    cin >> order;
    if (order == 1) {
        cout << "enter the category of the item you search for" << endl;
        cin >> categ;
        for (int i = 0; i < 100; i++) {
            if (categ == item1[i].category) {
                cout << "the item number is " << item1[i].number << endl;
                cout << "the item category is " << item1[i].category << endl;
                cout << "the item starting price is " << item1[i].startingprice << endl;
                cout << "the item starting date is " << item1[i].startingdate << endl;
                cout << "the item end date is " << item1[i].enddate << endl;
                cout << "the item status is " << item1[i].status << endl;
                cout << "the user id is " << item1[i].userid << endl;
                cout << endl;
            } else {
                counter++;
            }
        }

        if (counter == 100) {
            cout << "item not found" << endl;
            cout << endl;
            searching();
        } else {
            cout << endl;
            searching();
        }
    } else if (order == 2) {
        cout << "enter the category and the price of the item you search for" << endl;
        cin >> categ;
        cin >> price;
        for (int i = 0; i < 100; i++) {
            if (categ == item1[i].category && price >= item1[i].startingprice) {
                cout << "the item number is " << item1[i].number << endl;
                cout << "the item category is " << item1[i].category << endl;
                cout << "the item starting price is " << item1[i].startingprice << endl;
                cout << "the item starting date is " << item1[i].startingdate << endl;
                cout << "the item end date is " << item1[i].enddate << endl;
                cout << "the item status is " << item1[i].status << endl;
                cout << "the user id is " << item1[i].userid << endl;
                cout << endl;
            } else {
                counter++;
            }
        }
        if (counter == 100) {
            cout << "item not found" << endl;
            cout << endl;
            searching();
        } else {
            cout << endl;
            searching();
        }
    } else if (order == 0) {
        mainmenu();
    } else {
        cout << "invalid input" << endl;
        searching();
    }
}

void marketplace() {
    for (int i = 0; i < 10; i++) {
        if (item1[i].number != 0) {
            cout << "the item number " << i + 1 << endl;
            cout << "number of the item is " << item1[i].number << endl;
            cout << "category of the item is " << item1[i].category << endl;
            cout << "the starting price of the item is " << item1[i].startingprice << endl;
            cout << "the item starting date is " << item1[i].startingdate << endl;
            cout << "the item end date is " << item1[i].enddate << endl;
            cout << "the status of the item is " << item1[i].status << endl;
            cout << "the user id is " << item1[i].userid << endl;
        }
    }
    cout << endl;
    mainmenu();
}
void feedback() {
    //bool to check the availability of the ID entered by the user
    bool check = false;
    // to recieve the id and rate entered by the user to do feedback process
    int id, rate;
    cout << "enter the ID of the user" << endl;
    cin >> id;
    for (int i = 0; i < 100; i++) {
        if (id == member1[i].ID) {
            check = true;
            break;
        }
    }
    if (check == false) {
        cout << "the user id not found" << endl;
        feedback();
    }
    cout << "give the user a rate from 1 to 5" << endl;
    cin >> rate;
    if (rate > 0 && rate <= 5) {

        for (int i = 0; i < 100; i++) {

            if (id == member1[i].ID && rate >= 3) {
                member1[i].points += 1;
                break;
            }
        }

        mainmenu();
    } else {
        cout << "the rate must be from 1 to 5" << endl;
        feedback();
    }
}
void request() {
    //declare variable to enter the item number and price variable to recieve the price of the item and display it
    int no, order, index = -1;
    int price_wanted;
    cout << "enter the item number" << endl;
    cin >> no;
    for (int i = 0; i < 100; i++) {
        if (no == item1[i].number && item1[i].status == "available") {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "the item number " << no << " may be sold or not available" << endl;
        cout << endl;
        mainmenu();
    } else {

        if (item1[index].startingprice != 0) {
            cout << " the item number " << no << " it is price is equal to " << item1[index].startingprice << endl;
            cout << "the user ID is  " << item1[index].userid << endl << endl;
            cout << "if you agree with the price enter 1" << endl;
            cout << "if you don`t agree with the price and want to negotiate enter 2" << endl;
            cout << "to go back to main menu enter 0" << endl;
            cin >> order;
            if (order == 1) {
                cout << "please enter the date of the day you buy this item" << endl << endl;

                cout << "please enter the day " << endl;
                cin >> date1[dateindex].day;
                cout << "please enter the month" << endl;
                cin >> date1[dateindex].month;
                cout << "please enter the year" << endl;
                cin >> date1[dateindex].year;

                //validate from the date entered by the user

                if (date1[dateindex].day >= 1 && date1[dateindex].day <= 31 && date1[dateindex].month >= 1 && date1[dateindex].month <= 12 && date1[dateindex].year <= 2020) {

                    dateindex += 1;

                    item1[index].status = "sold";
                    cout << "you now have the item number " << no << endl;
                    cout << endl;
                    for (int i = 0; i < 100; i++) {
                        if (report1[i].categories == item1[index].category) {
                            report1[i].solditems += 1;
                        } else {
                            continue;
                        }
                    }
                    mainmenu();
                } else {
                    cout << "the date entered is wrong .. enter the right date" << endl;
                    cout << endl;
                    request();
                }
            } else if (order == 2) {
                cout << "enter the price you want" << endl;
                cin >> price_wanted;
                cout << "the request to buy the item number " << no << " is done successfully .. wait for the buyer to agree or refuse with this price" << endl;
                cout << endl;
                mainmenu();
            } else if (order == 0) {
                mainmenu();
            } else {
                cout << "invalid input" << endl;
                request();
            }
        }

    }
}
void additem() {

    int check = 0;
    bool checkno = false, checkid = false;

    if (itemsindex == 99) {
        cout << " the market place is full .. you can`t add item into the market place now" << endl;
        cout << endl;
        mainmenu();
    }
    cout << "enter the number you want to the item" << endl;
    cin >> item1[itemsindex].number;
    for (int i = 0; i < itemsindex; i++) {
        if (item1[i].number == item1[itemsindex].number) {
            checkno = true;
            break;
        }
    }
    if (checkno == true) {
        cout << "the number of item added may be not available .. choose another number" << endl << endl;
        additem();
    }
    cout << "enter the category of the item" << endl;
    cin >> item1[itemsindex].category;
    cout << "enter the starting price of the item" << endl;
    cin >> item1[itemsindex].startingprice;
    cout << "enter the starting date of the item" << endl;
    cin.ignore();
    getline(cin, item1[itemsindex].startingdate);
    cout << "enter the end date of the item" << endl;
    cin.ignore();
    getline(cin, item1[itemsindex].enddate);
    cout << "enter the id of your email " << endl;
    cin >> item1[itemsindex].userid;
    for (int i = 0; i < 100; i++) {
        if (member1[i].ID == item1[itemsindex].userid) {
            checkid = true;
        }
    }
    if (checkid == false) {
        cout << "the ID entered is not available " << endl << endl;
        additem();
    }

    item1[itemsindex].status = "available";

    for (int i = 0; i < 100; i++) {

        if (report1[i].categories == item1[itemsindex].category) {
            check++;
            break;
        }

    }

    if (check == 0) {
        report1[itemsindex].categories = item1[itemsindex].category;
    }

    check = 0;
    checkno = false;
    itemsindex++;
    cout << "item added successfully" << endl;
    cout << endl;
    mainmenu();

}

void monthlyreports() {
    int index = 0;

    cout << "please enter the date of the day" << endl;
    cout << "please enter the day" << endl;
    cin >> date2.day;
    cout << "please enter the month" << endl;
    cin >> date2.month;
    date2.month--;
    cout << "please enter the year" << endl;
    cin >> date2.year;
    // validate the date entered by the user
    if (date2.day >= 1 && date2.day <= 31 && date2.month >= 1 && date2.month <= 12 && date2.year <= 2020) {

        for (int i = 0; i < 100; i++) {
            if (date1[i].year != date2.year) {
                continue;
            } else if (date1[i].year == date2.year) {

                if (date1[i].month > date2.month) {
                    if (report1[i].solditems > index) {
                        index = i;
                    } else {
                        continue;
                    }

                } else if (date1[i].month == date2.month) {
                    if (date1[i].day >= date2.day) {
                        if (report1[i].solditems > index) {

                            index = i;
                        } else {
                            continue;
                        }

                    } else if (date1[i].day < date2.day) {
                        continue;
                    }
                }
            }
        }

        cout << "the top category sold in the last month is " << report1[index].categories << endl;
        cout << "the number of sold items " << report1[index].solditems << endl;
        cout << endl;

        mainmenu();
    } else {
        cout << "the date entered is wrong .. enter the right date" << endl;
        cout << endl;
        monthlyreports();
    }

}
