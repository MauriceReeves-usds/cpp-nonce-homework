//
// Created by Maurice on 6/11/22.
//

#include <iostream>
#include "nonce.h"

Record* head;
Record* duplicates;

void record_to_string(char* target_string, const Record* r) {
    assert(target_string != nullptr);
    sprintf(
            target_string,
            "Nonce -> %s Date -> %s Time -> %s Count -> %d",
            r->nonce, r->date, r->time, r->count
            );
}

void print_record(const Record* r) {
    assert(r != nullptr);
    char string_repr[RECORD_STRING_MIN_SIZE];
    record_to_string(string_repr, r);
    std::cout << string_repr << std::endl;
}

int main() {
    std::cout << "Hello, World" << std::endl;
    Record record{};
    strlcpy(record.nonce, "A pretty nonce", 39);
    print_record(&record);
}