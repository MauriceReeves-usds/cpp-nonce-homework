//
// Created by Maurice on 6/11/22.
//

#ifndef CPP_NONCE_HOMEWORK_NONCE_H
#define CPP_NONCE_HOMEWORK_NONCE_H

#include <sstream>

#define         MAX_NONCE_SIZE              39
#define         MAX_DATE_SIZE               25
#define         MAX_TIME_SIZE               25

struct Nonce_Date {
    char date[MAX_DATE_SIZE];
    char time[MAX_TIME_SIZE];
};

struct Record {
    Record(): Record("", "", "", 0) { }
    Record(const char* nonce, const char* date, const char* time, int count = 0) {
        this->count = count;
        strlcpy(this->nonce, nonce, MAX_NONCE_SIZE);
        strlcpy(this->date, date, MAX_DATE_SIZE);
        strlcpy(this->time, time, MAX_TIME_SIZE);
    }
    // our variables
    char nonce[MAX_NONCE_SIZE]{};
    char date[MAX_DATE_SIZE]{};
    char time[MAX_TIME_SIZE]{};
    int count;

    // return a string representation of the record
    [[nodiscard("Why discard the string result?")]] std::string to_string() const {
        std::ostringstream s;
        s << "Nonce -> " << this->nonce
          << " Date -> " << this->date
          << " Time -> " << this->time
          << " Count -> " << this->count;
        return s.str();
    }
};

#endif //CPP_NONCE_HOMEWORK_NONCE_H
