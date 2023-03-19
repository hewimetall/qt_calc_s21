#include "headers/api_calc.h"

void remove_space(string s_string) {
    char dest[s_string.len];
    char *string = s_string.str;
    int i, j;
    for (i = j = 0; string[i] != '\0'; i++)
        if (string[i] != ' ') {
            dest[j] = string[i];
            j++;
        }
    dest[j] = '\0';
    strcpy(string, dest);
}

int check_bracket(char *const string) {
    int count = 0;
    int flag = 1;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '(') {
            count++;
        } else if (string[i] == ')') {
            count--;
        }
        if (count < 0) {
            flag = 0;
        }
    }
    if (count != 0) {
        flag = 0;
    }
    return flag;
}

int check_symbol(char *const string) {
    int flag = 1;
    for (int i = 0; string[i] != '\0'; i++) {
        if ((string[i] < 48 || string[i] > 57) && string[i] != 120 &&
            string[i] != 46 && string[i] != 42 && string[i] != 43 &&
            string[i] != 'w' && string[i] != 'e' && string[i] != 'r' &&
            string[i] != 45 && string[i] != 47 && string[i] != 94) {
            flag = 0;
        }
    }
    return flag;
}

void replace_substring(char *string, char *sub_str, char *sub_str_rep) {
    const int BUFFER_SIZE = 256;
    char *buffer = NULL;
    int buffer_len = 0;
    while (strstr(string, sub_str) != NULL) {
        buffer = (char *) malloc(BUFFER_SIZE);

        memset(buffer, buffer_len, strlen(string));

        strncpy(buffer, string, strlen(string) - strlen(strstr(string, sub_str)));
        strcat(buffer, sub_str_rep);
        strcat(buffer, strstr(string, sub_str) + strlen(sub_str));

        strcpy(string, buffer);

        free(buffer);
    }
}

int check_validation(string str) {
    int flag = 1;

    op *oper = get_oper();
    char *test = (char *) malloc(1000);
    remove_space(str);
    strcpy(test, str.str);
    if (check_bracket(test)) {
        replace_substring(test, "(", "");
        replace_substring(test, ")", "");
    } else {
        flag = 0;
    }
    for (int i = 0; i < 9; i++) {
        replace_substring(test, oper[i].name, "");
    }
    if (!check_symbol(test)) {
        flag = 0;
    }
    free(test);
    return flag;
}

void cast_string(string ss) {
    op *oper = get_oper();
    for (int i = 0; i < 9; i++) {
        replace_substring(ss.str, oper[i].name, oper[i].polperf);
    }
}
