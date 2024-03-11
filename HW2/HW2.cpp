#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int limit, p[35] = { 0 }, w[35] = { 0 }, numOfItem = 0; //Variables of dataset.
void dataLoad_c(string fd); //Load c.txt into "limit".
void dataLoad_p(string fd); //Load p.txt into "p[]".
void dataLoad_w(string fd); //Load w.txt into "w[]".
void Show_and_txtOutput(int best, int* take, int numOfItem); //Show the result on Screen and Output ans of ds1.
void Show_and_txtOutput2(int best, int* take, int numOfItem); //Show the result on Screen and Output ans of ds2.
void Show_and_txtOutput3(int best, int* take, int numOfItem); //Show the result on Screen and Output ans of ds3.

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
    int i, index, totalPrize = 0, totalWeight = 0, max = 0, crt_max, take[35], min = 99999;

    //Main idea: "Prize" of GREEDY.
    while (1)
    {
        crt_max = 0;
        index = 0;
        if (max == 0) //First turn of loop.
        {
            for (i = 0; i <= numOfItem - 1; i++)
            {
                if (p[i] > crt_max)
                {
                    crt_max = p[i];
                    index = i;
                }
                if (p[i] < min) //Find minimum of prizes, to create an "end condition".
                    min = p[i];
            }
        }
        else
        {
            for (i = 0; i <= numOfItem - 1; i++)
            {
                if (p[i] > crt_max && p[i] < max)
                {
                    crt_max = p[i];
                    index = i;
                }
            }
        }

        //To determine that if totalWeight > limit.
        totalWeight += w[index];
        if (totalWeight >= limit)
        {
            totalWeight -= w[index];
            max = p[index];
        }
        else
        {
            max = p[index];
            totalPrize += p[index];
            take[index] = 1; //Representing item "take".
        }

        //The end condition.
        if (max == min)
            break;
    }

    //File output.
    if (folder == "ds1")
        Show_and_txtOutput(totalPrize, take, numOfItem);
    else if (folder == "ds2")
        Show_and_txtOutput2(totalPrize, take, numOfItem);
    else if (folder == "ds3")
        Show_and_txtOutput3(totalPrize, take, numOfItem);
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

void Show_and_txtOutput(int best, int* take, int numOfItem)
{
    int i;
    fstream f;
    f.open("ans_ds1.txt", ios::out);
    f << best << endl;
    cout << best << endl;
    for (i = 0; i < numOfItem; i++)
    {
        if (take[i] == 1)
        {
            cout << "1" << endl;
            f << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
            f << "0" << endl;
        }
    }
    f.close();
}

void Show_and_txtOutput2(int best, int* take, int numOfItem)
{
    int i;
    fstream f;
    f.open("ans_ds2.txt", ios::out);
    f << best << endl;
    cout << best << endl;
    for (i = 0; i < numOfItem; i++)
    {
        if (take[i] == 1)
        {
            cout << "1" << endl;
            f << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
            f << "0" << endl;
        }
    }
    f.close();
}

void Show_and_txtOutput3(int best, int* take, int numOfItem)
{
    int i;
    fstream f;
    f.open("ans_ds3.txt", ios::out);
    f << best << endl;
    cout << best << endl;
    for (i = 0; i < numOfItem; i++)
    {
        if (take[i] == 1)
        {
            cout << "1" << endl;
            f << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
            f << "0" << endl;
        }
    }
    f.close();
}