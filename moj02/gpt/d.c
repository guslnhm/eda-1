#include <stdio.h>

void move_xs(char *input, char *output, int *index) {
    if (*input == '\0' || *input == '\n') return;

    if (*input != 'x') {
        output[*index] = *input;
        (*index)++;
    }

    move_xs(input + 1, output, index);

    if (*input == 'x') {
        output[*index] = 'x';
        (*index)++;
    }
}

int main() {
    char input[102], output[102];
    int index = 0;

    fgets(input, sizeof(input), stdin);

    move_xs(input, output, &index);
    output[index] = '\0';

    printf("%s\n", output);

    return 0;
}
