#include <iostream>
#include <string>
#include <cmath>
#include <emscripten.h> 

using namespace std;

extern "C" {
    EMSCRIPTEN_KEEPALIVE 
    int calculate_calories(char gender_char, int age, double weight, double height, int activityLevel) {
        double BMR;
        double calories;
        char gender = tolower(gender_char);

        // 1. حساب BMR 
        if (gender == 'm') {
            BMR = 88.36 + (13.4 * weight) + (4.8 * height) - (5.7 * age);
        } 
        else if (gender == 'f') {
            BMR = 447.6 + (9.2 * weight) + (3.1 * height) - (4.3 * age);
        } 
        else {
            return -1;
        }

        // 2. تعديل السعرات الحرارية
        switch (activityLevel) {
            case 1: calories = BMR * 1.2; break;
            case 2: calories = BMR * 1.375; break;
            case 3: calories = BMR * 1.55; break;
            case 4: calories = BMR * 1.725; break;
            case 5: calories = BMR * 1.9; break;
            default:
                return -2;
        }

        return (int)round(calories);
    }
}

int main() {
    return 0;
}