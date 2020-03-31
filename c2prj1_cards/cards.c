#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <= VALUE_ACE);
  assert(c.suit == SPADES 
      || c.suit == HEARTS 
      || c.suit == DIAMONDS 
      || c.suit == CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
    case STRAIGHT_FLUSH:
      return "STRAIGHT_FLUSH";
    case FOUR_OF_A_KIND:
      return "FOUR_OF_A_KIND"; 
    case FULL_HOUSE:
      return "FULL_HOUSE";
    case FLUSH:
      return "FLUSH";
    case STRAIGHT:
      return "STRAIGHT";
    case THREE_OF_A_KIND:
      return "THREE_OF_A_KIND";
    case TWO_PAIR:
      return "TWO_PAIR";
    case PAIR:
      return "PAIR";
    default:
      return "NOTHING";
  }
}

char value_letter(card_t c) {
  if(c.value >= 2 && c.value <= 9) {
    return '0' + c.value;
  }
  switch(c.value) {
    case VALUE_JACK:
      return 'J';
    case VALUE_QUEEN:
      return 'Q';
    case VALUE_KING:
      return 'K';
    case VALUE_ACE:
      return 'A';
  }   
  return '0';
}


char suit_letter(card_t c) {
  switch(c.suit) {
    case SPADES:
      return 's';
    case HEARTS:
      return 'h';
    case DIAMONDS:
      return 'd';
    case CLUBS:
      return 'c';
    default:
      return 'x';
  }
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  assert(value_let == '0' 
         || (value_let >= 50 && value_let <= 57)
         || value_let == 'J' || value_let == 'Q'
         || value_let == 'K' || value_let == 'A');
  assert(suit_let == 's' || suit_let == 'h' 
         || suit_let == 'd' || suit_let == 'c');

  if(value_let == '0') {
    temp.value = 10;
  } else if (value_let >= 50 && value_let <= 57) {
    temp.value = value_let - '0';
  } else if(value_let == 'J') {
    temp.value = VALUE_JACK;
  } else if(value_let == 'Q') {
    temp.value = VALUE_QUEEN;
  } else if(value_let == 'K') {
    temp.value = VALUE_KING;
  } else {
    temp.value = VALUE_ACE;
  }

  if(suit_let == 's') {
    temp.suit = SPADES;
  } else if(suit_let == 'h') {
    temp.suit = HEARTS;
  } else if(suit_let == 'd') {
    temp.suit = DIAMONDS;
  } else {
    temp.suit = CLUBS;
  }
  return temp;
}

card_t card_from_num(unsigned c) {
  assert(c >= 0 && c < 52);
  card_t temp;
  if(c >= 0 && c <= 12) {
    temp.suit = SPADES; 
  } else if (c > 12 && c <= 25) {
    temp.suit = HEARTS;
  } else if (c > 25 && c <= 38) {
    temp.suit = DIAMONDS;
  } else {
    temp.suit = CLUBS;
  }

  temp.value = c % 13 + 2;
  return temp;
}
