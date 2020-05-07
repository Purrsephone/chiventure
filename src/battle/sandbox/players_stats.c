#include <stdlib.h>
#include <stdio.h>

struct stats_t
{
	int speed;
	int stength;
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
	*test_stats = malloc(sizeof(stats_t));
	test_stats.speed = 30;
	test_stats.strength = 80;
	test_stats.dexterity = 20;
	test_stats.hp = 100;
	test_stats.xp = 180;
}

void create_test_player()
{

}

int main()
{
	printf("Meow\n");
}
