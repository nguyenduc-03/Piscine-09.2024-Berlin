#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    int numLines;
    char emptyChar;
    char obstacleChar;
    char fullChar;
} MapInfo;

bool readMapInfo(const char *line, MapInfo *mapInfo);
bool isValidMap(const char *buffer, MapInfo *mapInfo, size_t bufferSize);
bool hasValidCharacters(const char *line, MapInfo *mapInfo);
bool checkCharactersUniqueness(const MapInfo *mapInfo);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("fopen");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    if (!fgets(line, sizeof(line), file)) {
        fprintf(stderr, "Error reading the map info line\n");
        fclose(file);
        return 1;
    }

    MapInfo mapInfo;
    if (!readMapInfo(line, &mapInfo) || !checkCharactersUniqueness(&mapInfo)) {
        fprintf(stderr, "map error\n");
        fclose(file);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(fileSize);
    if (!buffer) {
        perror("malloc");
        fclose(file);
        return 1;
    }

    fread(buffer, 1, fileSize, file);
    fclose(file);

    if (!isValidMap(buffer, &mapInfo, fileSize)) {
        fprintf(stderr, "map error\n");
    } else {
        printf("The map is valid.\n");
    }

    free(buffer);
    return 0;
}

bool readMapInfo(const char *line, MapInfo *mapInfo) {
    return sscanf(line, "%d%c%c%c", &mapInfo->numLines, &mapInfo->emptyChar, &mapInfo->obstacleChar, &mapInfo->fullChar) == 4;
}

bool checkCharactersUniqueness(const MapInfo *mapInfo) {
    return mapInfo->emptyChar != mapInfo->obstacleChar &&
           mapInfo->obstacleChar != mapInfo->fullChar &&
           mapInfo->fullChar != mapInfo->emptyChar;
}

bool isValidMap(const char *buffer, MapInfo *mapInfo, size_t bufferSize) {
    const char *p = buffer;
    int lineCount = 0;
    size_t currentLineLength = 0;
    size_t expectedLineLength = 0;
    bool hasNonEmptyLine = false;
    bool validCharacters = true;
    bool lineBreakRequired = false;

    while (p < buffer + bufferSize) {
        if (*p == '\n') {
            if (currentLineLength == 0) {
                p++;
                continue;
            }
            lineCount++;
            if (expectedLineLength == 0) {
                expectedLineLength = currentLineLength;
            } else if (currentLineLength != expectedLineLength) {
                return false;
            }
            currentLineLength = 0;
            hasNonEmptyLine = true;
            lineBreakRequired = false;
        } else {
            if (*p != mapInfo->emptyChar && *p != mapInfo->obstacleChar && *p != mapInfo->fullChar) {
                validCharacters = false;
            }
            currentLineLength++;
            lineBreakRequired = true;
        }
        p++;
    }

    if (currentLineLength > 0) {
        lineCount++;
        if (expectedLineLength == 0) {
            expectedLineLength = currentLineLength;
        } else if (currentLineLength != expectedLineLength) {
            return false;
        }
    }

    return hasNonEmptyLine && validCharacters && lineCount == mapInfo->numLines && lineBreakRequired;
}
