#include <iostream>

class Date {
private:
    int day, month, year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void increaseDay() {
        day++;
    }

    bool operator==(const Date& other) const {
        return (day == other.day && month == other.month && year == other.year);
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    bool operator>(const Date& other) const {
        if (year > other.year) return true;
        if (year == other.year && month > other.month) return true;
        return (year == other.year && month == other.month && day > other.day);
    }

    bool operator<(const Date& other) const {
        return !(*this == other || *this > other);
    }

    Date& operator=(const Date& other) {
        if (this != &other) {
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
    }

    Date& operator+=(int days) {
        for (int i = 0; i < days; ++i) {
            increaseDay();
        }
        return *this;
    }

    Date& operator-=(int days) {
        for (int i = 0; i < days; ++i) {
            day--;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);
};

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
    is >> date.day >> date.month >> date.year;
    return is;
}

int main() {
    Date date1(25, 1, 2024);
    Date date2(26, 1, 2024);

    std::cout << "Date 1: " << date1 << std::endl;
    std::cout << "Date 2: " << date2 << std::endl;

    if (date1 == date2) {
        std::cout << "Dates are equal." << std::endl;
    }
    else if (date1 < date2) {
        std::cout << "Date 1 is earlier than Date 2." << std::endl;
    }
    else {
        std::cout << "Date 1 is later than Date 2." << std::endl;
    }

    date1 += 5;
    std::cout << "Date 1 after += 5: " << date1 << std::endl;

    date2 -= 3;
    std::cout << "Date 2 after -= 3: " << date2 << std::endl;

    return 0;
}
