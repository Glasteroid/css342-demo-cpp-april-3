#include <iostream>

bool is_power_of_2(int);
bool recur_is_power_of_2(int);
bool check_prime_num(int);
void reduce_frac(std::string &);
void test();

int main() {
    test();
    int num = 4;
    bool result = is_power_of_2(num);
    bool rec_result = recur_is_power_of_2(num);

    // test for loop-method to check if number is a power of two
    if (result == true) {
        printf("%d is divisible by 2", num);
    } else {
        printf("%d is not divisible by 2", num);
    }

    std::cout << std::endl;

    // test for non-loop (recursion) method to check if number is power of two
    if (rec_result == true) {
        printf("%d is divisible by 2", num);
    } else {
        printf("%d is not divisible by 2", num);
    }

    std::cout << std::endl;

    // test for prime number
    int num_2 = 11;
    if (check_prime_num(num_2)) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }

    std::cout << std::endl;

    // test for reduce fractions method
    std::string fraction = "-6/8";
    reduce_frac(fraction);
}

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    }
};

Fraction reduce(Fraction input);

bool is_power_of_2(int num) {
    // keep dividing by 2 until either 1 or non-divisible
    while (num!=1) {
        if (num%2==0) { // divisible by 2
            num = num/2;
            continue;
        } else {
            return false;
        }
    }
    return true;
}

bool recur_is_power_of_2(int num) {
    if (num == 1) {
        return true;
    }

    if (num % 2 == 0) {
        return is_power_of_2(num/2);
    }

    return false;
}

bool check_prime_num(int num) {
    for (int i = 2; i < num - 1; i++) {
        if (num == i) {
            continue;
        }

        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void reduce_frac(std::string &fraction) {
    int slash_pos = 0;

    for (int i = 0; i < fraction.length(); i++) {
        if (fraction[i] == '/') {
            slash_pos = i;
        }
    }

    int numerator = std::stoi(fraction.substr(0, slash_pos));
    int denominator = std::stoi(fraction.substr(slash_pos + 1));
    int least = numerator;

    if (denominator < numerator) {
        least = numerator;
    }

    int gcd = 1;

    for (int i = 2; i < least; i++) {
        if (least % i == 0) {
            gcd = i;
        }
    }

    if (gcd == 1) {
        std::cout << fraction << std::endl;
    } else {
        printf("%d/%d", numerator/gcd, denominator/gcd);
    }

}

void test() {

}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.