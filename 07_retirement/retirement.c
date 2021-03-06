#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

double calculate_balance(int startAge, double balance, retire_info info) {
  int age = startAge / 12;
  int month = startAge % 12;
  printf("Age %3d month %2d you have $%.2lf\n", age, month, balance);
  balance += balance * info.rate_of_return / 12;
  balance += info.contribution;
  return balance;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
  double balance = initial;
  for(int months = 0; months < working.months; months++, startAge++) {
    balance = calculate_balance(startAge, balance, working);
  }
  for(int months = 0; months < retired.months; months++, startAge++) {
    balance = calculate_balance(startAge, balance, retired);
  }
}

int main(void) {
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01;
  
  retirement(327, 21345,working, retired);
  return EXIT_SUCCESS;
}
