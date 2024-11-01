struct Hand {
    int player_cards[50]; 
    int player_count;        
    int dealer_cards[50];
    int dealer_count;       
};

struct Result {
  int player;
  int dealer;
};

program BLACKJACK_PROG {
    version BLACKJACK_VERS {
        struct Hand START_GAME() = 1;
        struct Hand HIT() = 2;
        struct Hand STAND() = 3;
        struct Result GET_RESULT() = 4;
    } = 1;
} = 123456;