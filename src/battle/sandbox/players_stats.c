#include <stdlib.h>
#include <stdio.h>

struct stats_t
{
	int speed;
	int strength;
	int dexterity;
	int hp;
	int xp;
} stats_t;

typedef struct list_t {
    int val;
    struct list_t * next;
} list_t;

enum class{bard, cleric, paladin, wizard};

struct player_t 
{
	enum class cl;
	list_t inventory;
	list_t armor;
} player_t;

void create_test_stats()
{
	struct stats_t *test_stats = malloc(sizeof(stats_t));
	test_stats->speed = 30;
	test_stats->strength = 80;
	test_stats->dexterity = 20;
	test_stats->hp = 100;
	test_stats->xp = 180;
}

void create_test_inventory()
{
	list_t *inv_list = malloc(sizeof(list_t));
	
}

void create_test_player()
{
	struct player_t *test_player = malloc(sizeof(player_t));
	test_player->cl = 3;
//	test_player->inventory = NULL;
//	test_player->armor = NULL;
}

int main()
{
	printf("Meow\n");
}
