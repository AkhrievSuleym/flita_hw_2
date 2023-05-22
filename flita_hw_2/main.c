#include "include/graph.h"

int count_lines(char *path) {
    FILE *file;
    int count = 0;
    char temp;
    file = fopen(path, "r");
    if (file) {
        while ((temp = getc(file)) != EOF) {
            if (temp == '\n') count++;
        }
        fclose(file);
    }
    return count;
}

int main() {
    FILE *file_txt;
    char *path = "../data/list_2.txt";
    int count;

    file_txt = fopen(path, "r");
    if(!file_txt) {
        printf("ERROR! With list_2.txt!\n");
        return 0;
    }
    count = count_lines(path);
    Graph_t graph;

    inputGraph(&graph, count, file_txt);
    outputGraph(&graph);

    clear_memory(count, &graph);
    fclose(file_txt);
    puts("Successful!");
    return 1;
}