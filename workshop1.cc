//Annica Steinberg CSCI 3081W
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<string>
#include<iomanip>
using namespace std;

int main(){
    int numUsers, count=0, num, totEx=0;
    float avgEx;
    string name;
    string end = "done";
    //vectors of names and balances
    vector<string> names;
    vector<float> bal;

    cout << "Input Number of Users: ";
    cin >> numUsers;
    cout << endl;

    cout << "Input name (or 'done' to finish): ";
    while(cin >> name){//while input, checks if done, if not adds name to vector and asks for bal, also adds to vector
        count += 1;
        if(name.compare(end)==0){
            break;
        }
        else if(count > numUsers){
                cout <<"You have exceeded the previously stated number of users. Program will end" << endl;
                return 0;
            }
        else{
            names.push_back(name);
        }
        cout << "Enter expense amount: ";
        cin >> num;
        bal.push_back(num);
        totEx += num;
        cout << "Input name (or 'done' to finish): ";
    }
    
    avgEx = float(totEx)/float(numUsers);

    //prints display
    cout << "Expense Summary: " << endl;
    cout << "Participant\tExpense\t\tAmount Owes/Owed" << endl;
    cout << "----------------------------------------------------" << endl;
    for(int i=0;i<names.size();i++){
        float owe = float(avgEx) - float(bal[i]);
        cout << names[i] << "\t\t$" << (int)bal[i] << "\t\t$";
        cout << fixed << setprecision(2) << owe << endl;
    }
    
}