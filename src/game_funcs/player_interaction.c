/*
** EPITECH PROJECT, 2024
** fake_my_hunter
** File description:
** player_interaction
*/

#include "./../../include/my.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
//sfSprite_destroy(bird_sprite);
//event->mouseButton.x;

int mouse_handler(core_t *fm, sfEvent *event, sfSprite *sprite)
{
    sfVector2i m_po = sfMouse_getPositionRenderWindow(fm->window);
    sfVector2f m_w_p = sfRenderWindow_mapPixelToCoords(fm->window, m_po, NULL);
    sfFloatRect sprite_hitbox = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&sprite_hitbox, m_w_p.x, m_w_p.y)) {
        return 0;
    }
    return 1;
}
