#include <stdio.h>

#include "print.h"

void print_text(Array* const text_for_sorting, int* const opening_cnt, int* const cnt, bool* const right_enter) 
{                                                                                                               
    assert(text_for_sorting != nullptr);
    assert(opening_cnt != nullptr);
    assert(cnt != nullptr);
    assert(right_enter != nullptr);

    FILE* end_file_pointer = 0;
    
    switch(*opening_cnt)
    {
        case 0:
            end_file_pointer = fopen("end_text.txt", "wb");
            if (end_file_pointer == nullptr)
            {
                *right_enter = false;
                printf("file wasn't opened\n");
                return;
            }
            break;
        default:
            end_file_pointer = fopen("end_text.txt", "ab");
            if (end_file_pointer == nullptr)
            {
                *right_enter = false;
                printf("file wasn't opened\n");
                return;
            }
            break;
    }

    *opening_cnt = *opening_cnt + 1;

    switch(*cnt)
    {
        case 0:
            fputs("print forward sorting\n\n", end_file_pointer);
            break;
        case 1:
            fputs("print reverse sorting\n\n", end_file_pointer);
            break;
    }

    size_t string_index = 0;
    while (string_index < text_for_sorting->amount_of_strings)
    {
        char* s = text_for_sorting->addresses[string_index].start;

        fputs(s, end_file_pointer);
        fputs("\n", end_file_pointer);

        string_index++;
    }

    fputs("\n", end_file_pointer);

    *cnt = *cnt + 1;

    if (*cnt == 2)
    {
        *opening_cnt = 0;
        *cnt = 0;
    }

    fclose(end_file_pointer);
}