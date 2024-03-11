#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <time.h>

using namespace std;

int limit, p[35], w[35], numOfItem = 0;
void dataLoad_c(string fd); //Load c.txt into "limit".
void dataLoad_p(string fd); //Load p.txt into "p[]".
void dataLoad_w(string fd); //Load w.txt into "w[]".
string toBinary(int n); //Decimal to Binary.
void addZero(int i, char *arr); //eg. "101" -> "00101".
void Show_and_txtOutput(int best, char* take, int numOfItem); //Show the result on Screen and Output ans of ds1.
void Show_and_txtOutput2(int best, char* take, int numOfItem); //Show the result on Screen and Output ans of ds2.
void Show_and_txtOutput3(int best, char* take, int numOfItem); //Show the result on Screen and Output ans of ds3.

int main()
{
    //Readfile.
    string folder;
    cout << "Please input the dataset U wanna test: ";
    cin >> folder;
    dataLoad_p(folder);
    dataLoad_w(folder);
    dataLoad_c(folder);

    //Variables.
    int i, j, k, weight = 0, prize = 0, best = 0;
    string str;
    char s[35], take[35];

    //Main idea: Decimal to Binary.
    for (i = 0; i < pow(2, numOfItem) ; i++) //One item, one bit.
    {
        strcpy_s(s, toBinary(i).c_str());
        addZero(i, s);
        weight = 0;
        prize = 0;
        for (j = 0; j < numOfItem; j++)
        {
            if (s[j] == '1') //Representing item "take". ex:"11000".
            {
                weight += w[j];
                prize += p[j];
            }
            if (weight <= limit) 
            {
                if (prize > best)
                {
                    best = prize;
                    for (k = 0; k < numOfItem; k++) //For output of "xxxxx".
                        take[k] = s[k];
                }
            }
        }
        if ((double)clock() / CLOCKS_PER_SEC > 10) //If executing time > 60(sec), break.
            break;
    }

    //File output.
    if (folder == "ds1")
        Show_and_txtOutput(best, take, numOfItem);
    else if (folder == "ds2")
        Show_and_txtOutput2(best, take, numOfItem);
    else if (folder == "ds3")
        Show_and_txtOutput3(best, take, numOfItem);
}

void dataLoad_c(string fd)
{
    fstream f;
    string path;
    path = "./dataset/" + fd + "/c.txt";
    f.open(path);
    if (!f)
        printf("Cannot open c.txt!\n");
    while (!f.eof())
        f >> limit;
    f.close();
}

void dataLoad_p(string fd)
{
    fstream f;
    string path;
    path = "./dataset/" + fd + "/p.txt";
    f.open(path);
    if (!f)
        printf("Cannot open p.txt!\n");
    while (!f.eof())
    {
        f >> p[numOfItem];
        numOfItem++;
    }
    f.close();
}

void dataLoad_w(string fd)
{
    fstream f;
    numOfItem = 0;
    string path;
    path = "./dataset/" + fd + "/w.txt";
    f.open(path);
    if (!f)
        printf("Cannot open w.txt!\n");
    while (!f.eof())
    {
        f >> w[numOfItem];
        numOfItem++;
    }
    f.close();
}

string toBinary(int n)
{
    string bi;
    while (n != 0) {
        bi += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    return bi;
}

void addZero(int i, char *arr)
{
    int j; 

    if (i > pow(2, 28) - 1 && i <= pow(2, 29) - 1)
        for (j = 29; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 27) - 1 && i <= pow(2, 28) - 1)
        for (j = 28; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 26) - 1 && i <= pow(2, 27) - 1)
        for (j = 27; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 25) - 1 && i <= pow(2, 26) - 1)
        for (j = 26; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 24) - 1 && i <= pow(2, 25) - 1)
        for (j = 25; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 23) - 1 && i <= pow(2, 24) - 1)
        for (j = 24; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 22) - 1 && i <= pow(2, 23) - 1)
        for (j = 23; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 21) - 1 && i <= pow(2, 22) - 1)
        for (j = 22; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 20) - 1 && i <= pow(2, 21) - 1)
        for (j = 21; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 19) - 1 && i <= pow(2, 20) - 1)
        for (j = 20; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 18) - 1 && i <= pow(2, 19) - 1)
        for (j = 19; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 17) - 1 && i <= pow(2, 18) - 1)
        for (j = 18; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 16) - 1 && i <= pow(2, 17) - 1)
        for (j = 17; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 15) - 1 && i <= pow(2, 16) - 1)
        for (j = 16; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 14) - 1 && i <= pow(2, 15) - 1)
        for (j = 15; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 13) - 1 && i <= pow(2, 14) - 1)
        for (j = 14; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 12) - 1 && i <= pow(2, 13) - 1)
        for (j = 13; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 11) - 1 && i <= pow(2, 12) - 1)
        for (j = 12; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > pow(2, 10) - 1 && i <= pow(2, 11) - 1)
        for (j = 11; j <= numOfItem - 1; j++)
            arr[j] = '0';
    
    if (i > pow(2, 9) - 1 && i <= pow(2, 10) - 1)
        for (j = 10; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > 255 && i <= 511)
        for (j = 9; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > 127 && i <= 255)
        for (j = 8; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > 63 && i <= 127)
        for (j = 7; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > 31 && i <= 63)
        for (j = 6; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > 15 && i <= 31)
        for (j = 5; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > 7 && i<=15)
        for (j = 4; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > 3 && i <= 7)
        for (j = 3; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > 1 && i <= 3)
        for (j = 2; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i > 0 && i <= 1)
        for (j = 1; j <= numOfItem - 1; j++)
            arr[j] = '0';

    if (i == 0)
        for (j = 0; j <= numOfItem - 1; j++)
            arr[j] = '0';
}

void Show_and_txtOutput(int best, char* take, int numOfItem)
{
    int i;
    fstream f;
    f.open("ans_ds1.txt", ios::out);
    f << best << endl;
    cout << best << endl;
    for (i = 0; i < numOfItem; i++)
    {
        cout << take[i] << endl;
        f << take[i] << endl;
    }
    f.close();
}

void Show_and_txtOutput2(int best, char* take, int numOfItem)
{
    int i;
    fstream f;
    f.open("ans_ds2.txt", ios::out);
    f << best << endl;
    cout << best << endl;
    for (i = 0; i < numOfItem; i++)
    {
        cout << take[i] << endl;
        f << take[i] << endl;
    }
    f.close();
}

void Show_and_txtOutput3(int best, char* take, int numOfItem)
{
    int i;
    fstream f;
    f.open("ans_ds3.txt", ios::out);
    f << best << endl;
    cout << best << endl;
    for (i = 0; i < numOfItem; i++)
    {
        cout << take[i] << endl;
        f << take[i] << endl;
    }
    f.close();
}