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

struct player_t 
{
	enum class{bard, cleric, paladin, wizard};
	list_t inventory;
	list_t armor;
} player_t;

int main()
{
	printf("Meow\n");
}
