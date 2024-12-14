/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** high_score_updater
*/

#include "./../../include/my.h"
#include <unistd.h>
#include <fcntl.h>

int file_does_not_exist(core_t *fm, char *buffer, const char *filename, int fd)
{
    fd = open(filename, O_WRONLY | O_CREAT, 0666);
    if (fd < 0) {
        write(2, "failed to create file\n", 22);
        return 84;
    }
    my_strcpy(buffer, num_to_str(fm->score.high_score));
    my_strcat(buffer, "\n");
    write(fd, buffer, my_strlen(buffer));
    my_cooler_putstr("new high score is ");
    my_cooler_putstr(buffer);
    close(fd);
    return 0;
}

int file_needs_update(core_t *fm, char *buffer, const char *filename, int fd)
{
    fd = open(filename, O_WRONLY | O_TRUNC);
        if (fd < 0) {
            write(2, "failed to overwrite file\n", 25);
            return 84;
        }
        my_strcpy(buffer, num_to_str(fm->score.high_score));
        my_strcat(buffer, "\n");
        write(fd, buffer, my_strlen(buffer));
        my_cooler_putstr("updated high score is ");
        my_cooler_putstr(buffer);
        close(fd);
        return 0;
}

int get_high_score(char *buffer, unsigned long bytes_read, int temp_high_score)
{
    buffer[bytes_read] = '\0';
    temp_high_score = my_str_to_int(buffer);
    return temp_high_score;
}

int high_score_file(core_t *fm)
{
    const char *filename = "high_score.txt";
    int fd;
    char *buffer = malloc(sizeof(char) * 10);
    unsigned long bytes_read = 0;
    int temp_high_score = 0;

    fd = open(filename, O_RDONLY);
    if (!buffer)
        return 84;
    if (fd < 0)
        return file_does_not_exist(fm, buffer, filename, fd);
    bytes_read = read(fd, buffer, sizeof(buffer));
    close(fd);
    if (bytes_read > 0)
        temp_high_score = get_high_score(buffer, bytes_read, temp_high_score);
    if (fm->score.high_score > temp_high_score)
        return file_needs_update(fm, buffer, filename, fd);
    else
        fm->score.high_score = temp_high_score;
    return 0;
}
