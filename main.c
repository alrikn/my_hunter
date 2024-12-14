/*
** EPITECH PROJECT, 2024
** fake_my_hunter
** File description:
** main
*/

#include "./include/my.h"
#include "include/struct.h"
#include <SFML/Audio/Music.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <stdlib.h>


int manage_events(core_t *fm, sfEvent *event)
{
    if (fm->status.game_over == true) {
        destroy_everything(fm);
        return 1;
    }
    while (sfRenderWindow_pollEvent(fm->window, event)) {
        if (event->type == sfEvtClosed) {
            fm->status.game_over = true;
            destroy_everything(fm);
            return 1;
        }
    }
    return 0;
}

static int score_str(core_t *fm, int num, char *first)
{
    char *buffer = malloc(25);

    if (!buffer) {
        my_cooler_putstr("did not allocate properly");
        return 84;
    }
    my_strcpy(buffer, first);
    my_strcat(buffer, num_to_str(num));
    sfText_setString(fm->text, buffer);
    sfRenderWindow_drawText(fm->window, fm->text, NULL);
    free(buffer);
    return 0;
}

bool update_animate(core_t *fm)
{
    sfTime elapsed_time = sfClock_getElapsedTime(fm->time.clock);
    long long frame = sfTime_asMilliseconds(elapsed_time);

    if (frame >= 45) {
        sfClock_destroy(fm->time.clock);
        fm->time.clock = sfClock_create();
        sfMusic_stop(fm->hit_sound);
        return true;
    } else {
        return false;
    }
}

static int pause_loop(core_t *fm, sfEvent *event)
{
    sfRenderWindow_clear(fm->window, sfBlack);
    fm->position.x = 150;
    fm->position.y = 300;
    sfSprite_setPosition(fm->start_sprite, fm->position);
    sfRenderWindow_drawSprite(fm->window, fm->background.back_pause,
    NULL);
    sfRenderWindow_drawSprite(fm->window, fm->start_sprite,
    NULL);
    score_str(fm, fm->score.high_score, "high score : ");
    pause_handler(fm, event);
    sfRenderWindow_display(fm->window);
    return 0;
}

int game_loop(core_t *fm, sfEvent *event, int animation_framerate)
{
    if (update_animate(fm) == true) {
        sfRenderWindow_clear(fm->window, sfBlack);
        sfRenderWindow_drawSprite(fm->window, fm->background.back_sp,
        NULL);
        game_handler(event, fm);
        score_str(fm, fm->score.score_num, "score : ");
        placement(fm);
        sfSprite_setPosition(fm->bird_sprite, fm->position);
        sfRenderWindow_drawSprite(fm->window, fm->bird_sprite, NULL);
        sfRenderWindow_display(fm->window);
        if (fm->time.frame == 0)
            animate_sprite(fm->bird_sprite, 8);
        fm->time.frame = (fm->time.frame + 4) % animation_framerate;
    }
    return 0;
}

int running(core_t *fm, sfEvent *event, int animation_framerate)
{
    int return_result = 0;

    sfRenderWindow_setFramerateLimit(fm->window, 60);
    sfMusic_setLoop(fm->background.background_music, sfTrue);
    sfMusic_play(fm->background.background_music);
    sfMusic_setVolume(fm->background.background_music, 50);
    while (sfRenderWindow_isOpen(fm->window)) {
        if (fm->status.is_paused == true) {
            pause_loop(fm, event);
        } else {
            game_loop(fm, event, animation_framerate);
        }
        if (manage_events(fm, event) == 1)
            return 0;
    }
    return return_result;
}

static int explanation(void)
{
    my_cooler_putstr("[MY_HUNTER]\n\t-h shows this help message\n");
    my_cooler_putstr("Usage: \n\t");
    my_cooler_putstr(
        "This is a bad copy of the hunter game, being reproduced in c.\n");
    my_cooler_putstr(
        "\tPlay by clicking on the birds as they go by. you have 10 lives.\n");
    return 0;
}

int main(int argc, char **av)
{
    core_t fm = {0};
    sfEvent event = {0};
    int is_working = 0;

    if (argc != 1) {
        if (av[1][0] == '-' && av[1][1] == 'h' && my_strlen(av[1]) == 2) {
            return explanation();
        }
    } else {
        initializer(&fm);
        is_working = high_score_file(&fm);
        if (is_working == 84) {
            my_cooler_putstr("smth went wrong\n");
            return 84;
        }
        return running(&fm, &event, 5);
    }
}
