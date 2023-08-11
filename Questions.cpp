//Exercise 1: learn how to build the simple monthly calendar

// Step 1: declare the required variables
// step 2: input + input validation
// step 3: process
// 3.1 finds the days in that month of that year
// step 4: output
// 4.1 print out the heading of the calendar
// 4.2 print out the body of the calendar
// 4.2.1 find the first day location of the calendar
// 4.2.2 start printing the overall calendar


#include <iostream>
#include <string>
#include <limits>
#include <iomanip>  

using namespace std;

int main(){
    int year, month, day; string monthWord;

    cout << "Enter calendar's year: ";
    cin >> year;

    while (cin.fail() || year < 1900 || year > 2050)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("pause");
        system("cls");
        cout << "Enter calendar's year: ";
        cin >> year;
    }

    cout << "Enter calendar's month: ";
    cin >> month;

    while (cin.fail() || month < 1 || month > 12)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("pause");
        system("cls");
        cout << "Enter calendar's year: " << year << endl;
        cout << "Enter calendar's month: ";
        cin >> month;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        day = 30;
    }

    else if (month == 2)
    {
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        {
            day = 29;
        }
        else {
            day = 28;
        }
    }
    else {
        day = 31;
    }

    switch(month){
        case 1: monthWord = "January"; break;
        case 2: monthWord = "February"; break;
        case 3: monthWord = "March"; break;
        case 4: monthWord = "April"; break;
        case 5: monthWord = "May"; break;
        case 6: monthWord = "June"; break;
        case 7: monthWord = "July"; break;
        case 8: monthWord = "August"; break;
        case 9: monthWord = "September"; break;
        case 10: monthWord = "October"; break;
        case 11: monthWord = "November"; break;
        case 12: monthWord = "December"; break;

    }

    unsigned a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    int startday = (((31 + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)/ 12)) + 5) % 7);

    cout << endl << "\t\t\tCalendar Title : " << monthWord << " - " << year << endl;
    cout << string(110, '-') << endl;
    cout << "|" << setw(11) << "Sunday\t|" << setw(11) << "Monday\t|" << setw(11) << "Tuesday\t|" << setw(11) << "Wednesday\t|" << setw(11)
         << "Thursday\t|" << setw(11) << "Friday\t|" << setw(11) << "Saturday\t|";
    cout << endl << string(110, '-') << endl;

    int countday = 0;
    for (int i = 0; i < startday; i++)
    {
        cout << setw(11) << "\t";
        countday ++;
    }

    for (int i = 1; i <= day; i++){
        cout << setw(11) << i << "\t";
        countday++;
        if (countday % 7 == 0)
        {
            cout << endl;
        }
    }
    
    cout << endl << string (110, '=') << endl;
    return 0;

}