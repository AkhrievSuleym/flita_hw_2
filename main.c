#include <stdio.h>
#include <stdint.h>

#define LEN 100

int main() {
    FILE *file_txt, *file_graph;
    char temp[LEN];

    file_txt = fopen("list.txt", "r");
    file_graph = fopen("graph.dot", "w");
    fprintf(file_graph, "digraph current_graph {\n");

    if(!file_txt) {
        printf("ERROR! With list.txt!\n");
        return 0;
    }

    while (fgets(temp, LEN, file_txt) != NULL) {
        for (int i = 0; temp[i] != '\0'; i++) {
            if (temp[i] == ' ') {
                fputs("->", file_graph);
            } else {
                fputc(temp[i], file_graph);
            }
        }
    }

    fprintf(file_graph, "\n}");
    fclose(file_txt);
    fclose(file_graph);
    puts("Successful!");
    return 1;
}