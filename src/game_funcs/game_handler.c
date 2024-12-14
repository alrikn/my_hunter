/*
** EPITECH PROJECT, 2024
** fake_my_hunter
** File description:
** game_handler
*/

#include "./../../include/my.h"
#include <SFML/Audio/Music.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <stdbool.h>
#include <stdlib.h>

int pause_handler(core_t *fm, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed) {
        if (mouse_handler(fm, event, fm->start_sprite) == 0) {
            fm->status.is_paused = false;
        }
    }
    return 0;
}

static int lose_condition(core_t *fm)
{
    my_cooler_putstr("better luck next time!\n");
    if (fm->score.score_num > fm->score.high_score) {
        fm->score.high_score = fm->score.score_num;
    }
    fm->score.bad_score_num = 0;
    fm->score.score_num = 0;
    fm->status.is_paused = true;
    return high_score_file(fm);
}

int game_handler(sfEvent *event, core_t *fm)
{
    char *str;

    if (event->type == sfEvtMouseButtonPressed) {
        if (mouse_handler(fm, event, fm->bird_sprite) == 0) {
            fm->score.score_num += 1;
            sfMusic_play(fm->hit_sound);
            respawn(fm);
            my_cooler_putstr("score : ");
            str = num_to_str(fm->score.score_num);
            my_cooler_putstr(str);
            free(str);
            my_cooler_putstr("\n");
        }
    }
    if (fm->score.bad_score_num >= 10)
        lose_condition(fm);
    return 0;
}
