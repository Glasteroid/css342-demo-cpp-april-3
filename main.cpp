#include <iostream>

bool is_power_of_2(int);
bool recur_is_power_of_2(int);
bool check_prime_num(int);
void reduce_frac(std::string &);
void test();

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    std::string to_string() {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    // operator overload
    bool operator==(Fraction &other) {
        return this->numerator == other.numerator &&
            this->denominator == other.denominator;
    }
};

Fraction reduce(Fraction input) {
    int divider = 2;
    while (divider <= input.numerator and divider <= input.denominator) {
        if (input.numerator % divider == 0 &&
            input.denominator % divider == 0) {
            input.numerator /= divider;
            input.denominator /= divider;
            continue;
        }
        divider++;
    }

    return input;
}

int main() {

    /*int num = 4;
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
        std::cout << "PASS!" << std::endl;
    } else {
        std::cout << "FAIL!" << std::endl;
    }

    std::cout << std::endl;*/

    test();

}

bool is_power_of_2(int num) {
    if (num < 2) return false;
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
    if (num < 2) return false;

    if (num == 2) {
        return true;
    }

    if (num % 2 == 0) {
        return recur_is_power_of_2(num/2);
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
    int inputs[4] = {1, 2, 3, 4};

    for (int i = 0; i < 4; i++) {
        if (is_power_of_2(inputs[i])) {
            printf("%d is divisible by 2", inputs[i]);
        } else {
            printf("%d is not divisible by 2", inputs[i]);
        }

        std::cout << std::endl;

        if (recur_is_power_of_2(inputs[i])) {
            printf("%d is divisible by 2", inputs[i]);
        } else {
            printf("%d is not divisible by 2", inputs[i]);
        }

        std::cout << std::endl;

        if (check_prime_num(inputs[i])) {
            std::cout << "PASS!" << std::endl;
        } else {
            std::cout << "FAIL!" << std::endl;
        }

        std::cout << std::endl;
    }

    // reduce given fraction to minimum terms
    // 1/2 -> 1/2
    // 2/4 -> 1/2
    // 4/2 -> 2/1
    // 6/8 -> 3/4

    // given an input, the actual output should match the expected output
    Fraction fraction_inputs[4] = {Fraction(1,2),
                        Fraction(2,4),
                        Fraction(4,2),
                        Fraction(6,8)};

    Fraction fraction_outputs[4] = {Fraction(1,2),
                        Fraction(1,2),
                        Fraction(2,1),
                        Fraction(3,4)};

    for (int i = 0; i < 4; i++) {
        Fraction input = fraction_inputs[i];
        Fraction expect = fraction_outputs[i];

        Fraction actual = reduce(input);

        // compare expected vs actual
        if (expect == actual) {
            std::cout << "PASS!" << std::endl;
        } else {
            std::cout << "FAIL! case is: " << input.to_string() << std::endl;
        }
    }

}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.