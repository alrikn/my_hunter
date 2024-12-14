/*
** EPITECH PROJECT, 2024
** fake_my_hunter
** File description:
** my
*/

#ifndef INCLUDED_MY_H
    #define INCLUDED_MY_H
    #include <SFML/Graphics.h>
    #include "./struct.h"
    #include <stdlib.h>
sfVector2f placement(core_t *fm);
int mouse_handler(core_t *fm, sfEvent *event, sfSprite *sprite);
int game_handler(sfEvent *event, core_t *fm);
char *num_to_str(int num);
int num_len(int nb);
char *my_revstr(char *str);
int my_cooler_putstr(char const *str);
void respawn(core_t *fm);
int destroy_everything(core_t *fm);
void animate_sprite(sfSprite *sprite, int frame_count);
sfSprite *create_background(char *filepath, core_t *fm);
sfSprite *create_sprite(char *filepath);
sfSprite *sprite_texture_add(char *filepath, core_t *fm);
sfText *create_score_text(sfFont *fontpath);
char *my_strcat(char *dest, char const *str);
char *my_strcpy(char *dest, char const *src);
int initializer(core_t *fm);
int pause_handler(core_t *fm, sfEvent *event);
int my_strlen(char const *str);
int my_str_to_int(const char *str);
int high_score_file(core_t *fm);
#endif
