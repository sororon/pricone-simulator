#ifndef INCLUDED_CHARACTER
#define INCLUDED_CHARACTER

extern void character();

typedef struct {
    char name[20];
    int hp; 
    int phy_at; 
    int mag_at; 
    int phy_df; 
    int mag_df;
} Character;

Character pecorine;
Character kokkoro;
Character kyaru;
Character yui;
Character rei;
Character hiyori;

#endif /* INCLUDED_CHARACTER */
