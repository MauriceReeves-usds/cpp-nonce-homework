//
// Created by Maurice on 6/11/22.
//

#ifndef CPP_NONCE_HOMEWORK_NONCE_H
#define CPP_NONCE_HOMEWORK_NONCE_H

#define         MAX_NONCE_SIZE              39
#define         MAX_DATE_SIZE               25
#define         MAX_TIME_SIZE               25
#define         RECORD_STRING_MIN_SIZE      100

struct Nonce_Date {
    char date[MAX_DATE_SIZE];
    char time[MAX_TIME_SIZE];
};

struct Record {
    char nonce[MAX_NONCE_SIZE];
    char date[MAX_DATE_SIZE];
    char time[MAX_TIME_SIZE];
    int count;
    Record* next;
};

#endif //CPP_NONCE_HOMEWORK_NONCE_H
