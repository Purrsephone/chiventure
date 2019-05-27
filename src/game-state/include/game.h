#ifndef _GAME_H
#define _GAME_H

#include "game_state_common.h"
#include "player.h"
#include "room.h"
#include "item.h"


/* The game struct is built to contain all the relevant information
 * for anyone who needs to work the game
 */

typedef struct game {
    /* an iteratable hashtable of players */
    /* using the macros provided in uthash.h */
    /* the expected size is 1 for single player games but this can change */
    player_hash_t all_players;

    /* an iteratable hashtable of rooms */
    /* using the macros provided in uthash.h */
    room_hash_t all_rooms;

    /* pointer to current room struct */
    room_t *curr_room;

    /* pointer to current player struct */
    player_t *curr_player;

    /* starting string description to be presented at beginning of game */
    char *start_desc;
  
    /* time when game started */
    //int time_start;
} game_t;


/* Malloc space for a new game struct
 * This only takes in the beginning string description and 
 * creates a new game without rooms and players
 *
 * Parameters:
 *  string description 
 *
 * Returns:
 *  a new game struct
 */
game_t *game_new(char *start_desc);

/* Given the pointer to another room, changes the current room in game-state
 * This function does NOT check if the move is legal
 *
 * Parameters:
 *  game struct
 *  room that we're changing to
 *
 * Returns:
 *  none
 */
void move_room(game_t *game, room_t *new_room);

/* Exits game safely (frees all memory)
 * Future easter egg :) :) :)
 * pls dont hate
 *
 * Parameters:
 *  game struct
 *
 * Returns:
 *  none
 */
void game_quit(game_t *game);

/* Frees everything in the game struct safely
 *
 * Parameters:
 *  game struct that needs to be freed
 *
 * Returns:
 *  SUCCESS if successful
 */
int game_free(game_t *game);

/* Adds a player to the given game
 *
 * Parameters:
 *  game struct
 *  player struct
 *
 * Returns:
 *  SUCCESS if successful, FAILURE if failed
 */
int add_player_to_game(game_t *game, player_t *player);

/* Adds a room to the given game
 *
 * Parameters:
 *  game struct
 *  room struct
 *
 * Returns:
 *  SUCCESS if successful, FAILURE if failed
 */
int add_room_to_game(game_t *game, room_t *room);


/*
*
* Set current player in game
*
* Parameters:
* game, player
*
* Returns:
*  SUCCESS if the game->curr_player != NULL, FAILURE if NULL
*/
int set_curr_player(game_t *game, player_t *player);


/*
* Function to find player given game and player id
* Parameters:
* Game, player id
*
* Returns
* player struct or NULL if not found
*/
player_t *get_player(game_t *game, char *player_id);

/*
* Function to find room from all_rooms
* Parameters:
* Game, room_id
*
* Returns:
* pointer to room or NULL if not found
*/
room_t *find_room(game_t *game, char* room_id);


/* Returns pointer to room given path
* Parameters:
* ptr to game, ptr to path 
*
* Returns: 
* ptr to room or NULL if not found
*/
room_t *find_room_from_path(path_t *path);

/* Returns ptr to adjacent room given direction
* Parameters:
* ptr to room, char* direction (must follow initialized direction characters)
*
* Returns:
* ptr to room or NULL if not found
*/
room_t *find_room_from_dir(room_t *curr, char* direction);

#endif
