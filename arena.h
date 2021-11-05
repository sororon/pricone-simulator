#ifndef INCLUDED_ARENA
#define INCLUDED_ARENA

extern void arena();

typedef struct {
    char name[20];
    int hp; 
    int phy_at; 
    int mag_at; 
    int phy_df; 
    int mag_df;
} ArenaCharacter;

ArenaCharacter c1;
ArenaCharacter c2;
ArenaCharacter c3;

#endif /* INCLUDED_ARENA  */
