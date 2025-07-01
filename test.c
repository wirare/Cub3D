#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_spawn(char c) {
    return c == 'N' || c == 'S' || c == 'E' || c == 'W';
}

int check_closed(char **map, int height, int width) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char c = map[y][x];
            if (c == '0' || is_spawn(c)) {
                // Check 4 directions
                int dx[4] = {1, -1, 0, 0};
                int dy[4] = {0, 0, 1, -1};
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= width || ny >= height)
                        return 0; // map ouverte (hors map)
                    if (map[ny][nx] == ' ')
                        return 0; // map ouverte (padding)
                }
            }
        }
    }
    return 1; // map fermée
}

int max_line_len(char **map) {
    int max = 0;
    for (int i = 0; map[i]; i++) {
        int len = strlen(map[i]);
        if (len > max)
            max = len;
    }
    return max;
}

char **pad_map(char **map, int height, int maxlen) {
    char **out = malloc((height + 1) * sizeof(char *));
    for (int i = 0; i < height; i++) {
        out[i] = malloc(maxlen + 1);
        int j = 0;
        while (map[i][j]) {
            out[i][j] = map[i][j];
            j++;
        }
        while (j < maxlen)
            out[i][j++] = ' ';
        out[i][j] = 0;
    }
    out[height] = NULL;
    return out;
}

int main() {
    char *map[] = {
        strdup("0"),
        strdup("111"),
        strdup("1N1"),
        strdup("111"),
        NULL
    };

    int height = 0;
    while (map[height])
        height++;
    int width = max_line_len(map);

    char **padded = pad_map(map, height, width);

    int res = check_closed(padded, height, width);

    printf("Résultat : map %s\n", res ? "fermée" : "ouverte");

    // Free
    for (int i = 0; i < height; i++) {
        free(map[i]);
        free(padded[i]);
    }
    free(padded);
    return 0;
}
