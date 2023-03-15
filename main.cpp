#include <iostream>
using namespace std;

void introductoryMessage(){
    cout << "Welcome to Group 4's Nutrition Planner!";
    cout << "\n--------------------------------------------------";
    cout << "\nHow many people would you like to calculate? ";
}

void insertData (string name[], string sex[], double age[], double height[],
                 double weight[], char activityLevel[], char dietPlan[], int n){
    for (int i=0; i<n; i++){
        cout << "\nInsert your name! ";
        cin >> name[i];
        cout << "\nInsert your sex! ";
        cin >> sex[i];
        cout << "\nInsert your age! ";
        cin >> age[i];
        cout << "\nInsert your height! (in cm)";
        cin >> height[i];
        cout << "\nInsert your weight! (in kg)";
        cin >> weight[i];

        cout << endl << "Choose your activity level!" << endl
             << "a). Sedentary (little to no exercise)" << endl
             << "b). Lightly active (1-3 exercises/week)" << endl
             << "c). Moderately active (3-5 exercises/week)" << endl
             << "d). Active (6-7 exercises/week)" << endl
             << "e). Very active (6-7 days hard exercises/week)" << endl;
        cin >> activityLevel[i];

        cout << endl << "Choose your diet plan!" << endl
             << "a). Extreme weight gain" << endl
             << "b). Moderate weight gain" << endl
             << "c). Mild weight gain" << endl
             << "d). Maintain current weight" << endl
             << "e). Mild weight loss" << endl
             << "f). Moderate weight loss" << endl
             << "g). Extreme weight loss" << endl;
        cin >> dietPlan[i];

    }
}

void calculateBMR(string sex[], double age[], double height[], double weight[], double bmr[], int n){
    for (int i=0; i<n; i++){
        bmr[i] = (10 * weight[i]) + (6.25 * height[i]) - (5 * age[i]);
        if(sex[i] == "male"){
            bmr[i] += 5;
        } else if (sex[i] == "female"){
            bmr[i] -= 161;
        }
    }
}

void calculateAMR(double bmr[], char activityLevel[], double amr[], int n){
    for (int i=0; i<n; i++){
        switch (activityLevel[i]) {
            case 'a':
                amr[i] = bmr[i] * 1.2;
                break;
            case 'b':
                amr[i] = bmr[i] * 1.375;
                break;
            case 'c':
                amr[i] = bmr[i] * 1.55;
                break;
            case 'd':
                amr[i] = bmr[i] * 1.725;
                break;
            case 'e':
                amr[i] = bmr[i] * 1.9;
                break;
        }
    }
}

void calculateCalories(double amr[], char dietPlan[], string dietOption[], double totalCalories[], int n){
    for (int i=0; i<n; i++){
        switch (dietPlan[i]) {
            case 'a':
                dietOption[i] = "Extreme weight gain";
                totalCalories[i] = amr[i] * 145/100;
                break;
            case 'b':
                dietOption[i] = "Moderate weight gain";
                totalCalories[i] = amr[i] * 122/100;
                break;
            case 'c':
                dietOption[i] = "Mild weight gain";
                totalCalories[i] = amr[i] * 111/100;
                break;
            case 'd':
                dietOption[i] = "Maintain current weight";
                totalCalories[i] = amr[i] * 100/100;
                break;
            case 'e':
                dietOption[i] = "Mild weight loss";
                totalCalories[i] = amr[i] * 89/100;
                break;
            case 'f':
                dietOption[i] = "Moderate weight loss";
                totalCalories[i] = amr[i] * 78/100;
                break;
            case 'g':
                dietOption[i] = "Extreme weight loss";
                totalCalories[i] = amr[i] * 55/100;
                break;
        }
    }
}

void displayData(string name[], string sex[], double height[], double weight[],
                 string dietOption[], double totalCalories[], int n){
    for (int i=0; i<n; i++){
        cout << endl << "--------------------------------------------------" << endl
             << "Name: " << name[i] << endl
             << "Sex: " << sex[i] << endl
             << "Height: " << height[i] << "cm" << endl
             << "Weight: " << weight[i] << "kg" << endl
             << "Your preferred diet plan: " << dietOption[i] << endl
             << "Calories needed: " << totalCalories[i] << "kkal" << endl;
    }
}

void sortCalories(string name[], double totalCalories[], int n){
    for(int j=1; j<n; j++){
        int i = j - 1;
        double temp1 = totalCalories[j];
        string temp2 = name[j];
        while(totalCalories[i] > temp1 && i>=0){
            totalCalories[i + 1] = temp1;
            name[i + 1] = temp2;
        }
    }

}

void displayRank(string name[], double totalCalories[], int n){

    cout << endl << "The person with the most calory need is: " << name[n - 1] << " with the calory need of " << totalCalories[n - 1] << "kkal" << endl
         << "The person with the lowest calory need is: " << name[0] << " with the calory need of " << totalCalories[0] << "kkal" << endl;
}

int main()
{
    introductoryMessage();

    int n;
    cin >> n;
    cout << endl;

    string name[n];
    string sex[n];
    double age[n];
    double height[n];
    double weight[n];
    double bmr[n];
    char activityLevel[n];
    double amr[n];
    char dietPlan[n];
    string dietOption[n];
    double totalCalories[n];

    insertData(name, sex, age, height, weight, activityLevel, dietPlan, n);
    calculateBMR(sex, age, height, weight, bmr, n);
    calculateAMR(bmr, activityLevel, amr, n);
    calculateCalories(amr, dietPlan, dietOption, totalCalories, n);
    displayData(name, sex, height, weight, dietOption, totalCalories, n);
    sortCalories(name, totalCalories, n);
    displayRank(name, totalCalories, n);

}