/*
** EPITECH PROJECT, 2024
** fake_my_hunter
** File description:
** struct
*/

#ifndef INCLUDED_STRUCT_H
    #define INCLUDED_STRUCT_H
    #include <SFML/Audio/Types.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Event.h>
    #include <SFML/System/Vector2.h>
    #include <stdbool.h>
    #include <SFML/Audio/Music.h>
typedef struct status {
    bool game_over;
    bool is_paused;
}status_t;

typedef struct lag {
    sfClock *clock;
    int frame;
}lag_t;

typedef struct node {
    int score_num;
    int bad_score_num;
    int high_score;
    char *score_str;
} score_count_t;

typedef struct background {
    sfSprite *back_sp;
    sfMusic *background_music;
    sfSprite *back_pause;
}background_t;

typedef struct core {
    score_count_t score;
    sfVector2f position;
    sfSprite *bird_sprite;
    sfSprite *start_sprite;
    sfRenderWindow *window;
    sfVideoMode mode;
    status_t status;
    background_t background;
    sfText *text;
    sfMusic *hit_sound;
    lag_t time;
}core_t;
#endif
