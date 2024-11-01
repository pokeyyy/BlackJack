/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "BlackJack.h"
char *reflect[13] = {
  "A",
  "2",
  "3",
  "4",
  "5",
  "6",
  "7",
  "8",
  "9",
  "10",
  "J",
  "Q",
  "K"
};

void
blackjack_prog_1(char *host)
{
	CLIENT *clnt;
	Hand *hand;

#ifndef	DEBUG
	clnt = clnt_create (host, BLACKJACK_PROG, BLACKJACK_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

//start
	hand = start_game_1(NULL, clnt);
	if (hand == (struct Hand *) NULL) {
		clnt_perror (clnt, "start game failed");
	}
  printf("Your initial cards: ");
  for (int i = 0; i < hand->player_count; i++) {
    char *card_face = reflect[hand->player_cards[i]];
    printf("%s ", card_face);
  }
  printf("\nDealer's cards: %s \? \n", reflect[hand->dealer_cards[0]]);

  char command;
  while (1) {
    printf("Hit (h) or Stand (s)? ");
    scanf(" %c", &command);

    //hit
    if (command == 'h') {
      hand = hit_1(NULL, clnt);
	    if (hand == (struct Hand *) NULL) {
		    clnt_perror (clnt, "hit failed");
	    }
            
      printf("Your cards: ");
      for (int i = 0; i < hand->player_count; i++) {
        char *card_face = reflect[hand->player_cards[i]];
        printf("%s ", card_face);
        }
      printf("\nDealer's cards: %s \? \n", reflect[hand->dealer_cards[0]]);

      // 检查是否爆牌
      Result value = *get_result_1(NULL, clnt);
        if (value.player > 21) {
          printf("You bust! Total value: %d\n", value.player);
          break;
        }
    }
    // stand
    else if (command == 's') {
      hand = stand_1(NULL, clnt);
      if (hand == (struct Hand *) NULL) {
		    clnt_perror (clnt, "hit failed");
	    }
      printf("Your final cards: ");
      for (int i = 0; i < hand->player_count; i++) {
        char *card_face = reflect[hand->player_cards[i]];
        printf("%s ", card_face);
      }
      printf("\nDealer's cards: ");
      for (int i = 0; i < hand->dealer_count; i++) {
        char *card_face = reflect[hand->dealer_cards[i]];
        printf("%s ", card_face);
      }
      printf("\n");

      // 获取游戏结果
      Result *result = get_result_1(NULL, clnt);
      if (result == NULL) {
        clnt_perror (clnt, "get result failed");
      }

      if (result->dealer > 21 || result->dealer < result->player) {
        printf("You win!\n");
      } else if (result->dealer > result->player) {
          printf("You lose.\n");
      } else {
        printf("It's a push.\n");
      }
      break;
    } else {
      printf("Invalid command. Please enter 'h' for hit or 's' for stand.\n");
    }
  }

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	blackjack_prog_1 (host);
exit (0);
}
