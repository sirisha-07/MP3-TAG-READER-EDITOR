/**
 * @file main.c
 * @brief Main entry point for the MP3 Tag Reader application.
 */

#include <stdio.h>
#include <string.h>
#include "main.h"
#include "id3_reader.h"
#include "id3_writer.h"
#include "error_handling.h"


/**
 * @brief Displays the help message for the MP3 Tag Reader application.
 */
void display_help() {
    printf("-------------------------HELP MENU-------------------------\n");
    printf(" \n1. -v -> to view mp3 file contents\n2. -e -> to edit mp3 file contents\n         2.1. -t -> to edit song title\n         2.2. -a -> to edit artist name\n         2.3. -A -> to edit album name\n         2.4. -y -> to edit year\n         2.5. -m -> to edit content\n         2.6. -c -> to edit comment\n----------------------------------------------------------\n");
}

/**
 * @brief Main function to handle command-line arguments and execute appropriate actions.
 * 
 * @param argc Argument count.
 * @param argv Argument vector. 
 * @return 1 on success, zero on failure.
 */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("------------------------------------------------------------\n");
        printf(" \nERROR: ./a.out : INVALID ARGUMENTS\nUSAGE : \nTo view please pass like: ./a.out -v mp3filename\nTo edit please pass like: ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\nTo get help pass like: ./a.out --help\n");
        printf("------------------------------------------------------------\n");
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0) {
        display_help();
        return 0;
    } else if (strcmp(argv[1], "-v") == 0 && argc == 3) {
        view_tags(argv[2]);
    } else if (strcmp(argv[1], "-e") == 0 && argc == 5) {
        char *tag = argv[2];
        char *filename = argv[4];
        char *value = argv[3];
        if (edit_tag(filename, tag, value)==0) {
            display_error("Failed to edit tag.");
            return 1;
        }
        printf("Tag edited successfully.\n");
    } else {
        display_help();
        return 1;
    }

    return 0;
}