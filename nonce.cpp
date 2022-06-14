//
// Created by Maurice on 6/11/22.
//

#include <iostream>
#include <vector>
#include "nonce.h"

std::vector<Record> records {};
std::vector<Record> duplicates {};
// our lambda to count duplicates
auto find_dupes = [](const Record r) { return r.count > 1; };

void print_record(Record& r) {
    std::cout << r.to_string() << std::endl;
}

std::__wrap_iter<Record *> find_record(const char* nonce) {
    auto nonce_matches = [nonce](const Record r) { return strcmp(r.nonce, nonce) == 0; };
    auto matching_record = std::find_if(records.begin(), records.end(), nonce_matches);
    return matching_record;
}

// find all the duplicates in the list
void find_duplicates() {
    std::copy_if(records.begin(), records.end(), std::back_inserter(duplicates), find_dupes);
}

void create_record_list(const char* file_path) {
    char nonce[MAX_NONCE_SIZE], date[MAX_DATE_SIZE], time[MAX_TIME_SIZE];
    auto file_pointer = fopen(file_path, "r");
    while (fscanf(file_pointer, "%36s %10s %15s[\n]", nonce, date, time) != EOF) {
        // while reading the file, look for any matching nonce already in the file
        auto record = find_record(nonce);
        if (record != records.end()) {
            record->count++;
            continue;
        }
        records.emplace_back(nonce, date, time, 1);
    }
    fclose(file_pointer);
}

int main() {
    create_record_list("/Users/maurice/development/cpp-nonce-homework/resources/nonce.txt");

    for (auto record : records) {
        print_record(record);
    }

    // get the count of duplicates
    long duplicates_count = std::count_if(records.begin(), records.end(), find_dupes);
    std::cout << "Found " << duplicates_count << " duplicates" << std::endl;
    if (duplicates_count > 0) {
        find_duplicates();
        for (auto duplicate : duplicates) {
            print_record(duplicate);
        }
    } else {
        std::cout << "No duplicates detected!" << std::endl;
    }

    return EXIT_SUCCESS;
}