// total_budget_calculation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>

using namespace std;

class buget_optimzer
{
    double z_approved;
   //total add spend
    double x1;// budget for each cost
    double x2;// budget for each cost
    double x4;// budget for each cost
    double y1; // agency fee percntage
    double y2;//thrid party tool fee
    double hours;
   // double tolrence;// fixed cost per agency hours
    double initial_guess_amt;
public:
    buget_optimzer()
    {
        cout << "please enter the target_z" << endl;
        cin >> z_approved;
        cout << "please enter the x1 budget" << endl;
        cin >> x1;
        cout << "please enter the  x2 budget" << endl;
        cin >> x2;
        cout << "please enter the  x4 budget" << endl;
        cin >> x4;
        cout << "please enter the y1 percentage" << endl;
        cin >> y1;
        cout << "please enter the y2 percentage" << endl;
        cin >> y2;
        cout << "please enter the hours" << endl;
        cin >> hours;
        cout << "please enter the initial_guess_amt" << endl;
        cin >> initial_guess_amt;
    }
    buget_optimzer(double z_approved, double x1, double x2, double x4, double y1, double y2, double hours, double initial_guess_amt)
        {
        cout << "parameterized_constructor" << endl;
        this->z_approved = z_approved;
        //total add spend
        this->x1 = x1;// budget for each cost
        this->x2 = x2;// budget for each cost
        this->x4 = x4;// budget for each cost
        this->y1 = y1; // agency fee percntage
        this->y2 = y2;//thrid party tool fee
        this->hours = hours;
        this->initial_guess_amt = initial_guess_amt;
        }
    double calculateBudget(double xtarget)
    {
        double x = xtarget + x1 + x2 + x4;
        double z = x + y1 * x + y2 * (x1 + x2 + x4) + hours;
        cout << z << endl;
        return z;
    }

    double goalSeek()
    {
        double low = 0.0;
        double high = z_approved;//zappreoved
        double maxitr = 100;
        double stepsize = 0.1;//tolrence
        double xtarget;//midle value
        for (int i = 0;i < maxitr;i++)
        {
            xtarget = (low + high) / 2;
            double z_target = calculateBudget(xtarget);
            cout << "z_target - z_approved = " << z_target - z_approved<<endl;
            if (abs(z_target - z_approved) < stepsize)
            {
                cout << xtarget << endl;
                return xtarget;
            }
            else if (z_target > z_approved)
            {
                high = xtarget;
            }
            else
            {
                low = xtarget;
            }
        }
        return -1.0;
    }
};

int main()
{
    char ch;
    cout << "If you want  manualy  enter the value  of the budget variable like Z_approved ,x1,x2  please enter y or Y " << endl;
    cin >> ch;
    buget_optimzer* budgetpptr = nullptr;
    if (ch == 'Y' || ch == 'y')
    {
        budgetpptr = new buget_optimzer();
       ;
    }
    else
    {
        double Z_approved = 10000.0;
        double X1 = 2000.0;
        double X2 = 3000.0;
        double X4 = 1000.0;
        double Y1 = 0.05;
        double Y2 = 0.03;
        double HOURS = 500.0;
        double initial_guess = 500.0; ;
        
        budgetpptr = new buget_optimzer(Z_approved,X1,X2,X4,Y1,Y2, HOURS, initial_guess);
       
    }

    double xtarget = budgetpptr->goalSeek();
       if (xtarget >= 0.0)
       {
           cout << "Maximum budget for the specific ad: " << xtarget << std::endl;
       }
       else
       {
           cout << "Error: Goal Seek function did not converge." << std::endl;
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
