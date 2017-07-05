// CDDA health calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>

using namespace std;

long rng(long val1, long val2)
{
    long minVal = (val1 < val2) ? val1 : val2;
    long maxVal = (val1 < val2) ? val2 : val1;
    return minVal + long((maxVal - minVal + 1) * double(rand() / double(RAND_MAX + 1.0)));
}

int sim_random_health(int nutrition) {
    int rand_health = 0;
    int day_in_turns = 14400;

    // This loop simulates the pass of a day
    for (int i = 0; i < day_in_turns; i++) {
        // This makes the up and down limits for the player's health
        if (rand_health > 200) {
            rand_health = 100;
        }
        else if (rand_health < -200) {
            rand_health = -200;
        }

        int health_mod = 0;
        int break_even = rand_health - health_mod + nutrition;
        const long roll = rng(-100, 100);
        if (roll > break_even) {
            rand_health += 1;
        }
        else if (roll < break_even) {
            rand_health -= 1;
        }

        // And healthy_mod decays over time.
        health_mod = (health_mod * 3 / 4);
    }

    return rand_health;

}

int sim_bad_health(int nutrition) {
    int bad_health = 0;
    int day_in_turns = 14400;
    // This loop simulates the pass of a day
    for (int i = 0; i < day_in_turns; i++) {
        // this makes the up and down limits for the player's health
        if (bad_health > 200) {
            bad_health = 100;
        }
        else if (bad_health < -200) {
            bad_health = -200;
        }
        int health_mod = 0;
        int break_even = bad_health - health_mod + nutrition;
        const long roll = rng(-100, 100);
        if (roll > break_even) {
            bad_health += 1;
        }
        else if (roll < break_even) {
            bad_health -= 1;
        }

        // And healthy_mod decays over time.
        health_mod = (health_mod * 3 / 4);

    }

    return bad_health;
}


int sim_good_health(int nutrition) {
    int good_health = 0;
    int day_in_turns = 14400;


    // This one simulates the passing of a day
    for (int i = 0; i < day_in_turns; i++) {
        if (good_health > 200) {
            good_health = 100;
        }
        else if (good_health < -200) {
            good_health = -200;
        }
        int health_mod = 0;
        int break_even = good_health - health_mod + nutrition;
        const long roll = rng(-100, 100);
        if (roll > break_even) {
            good_health += 1;
        }
        else if (roll < break_even) {
            good_health += 1;
        }

        // And healthy_mod decays over time.
        health_mod = (health_mod * 3 / 4);

    }

    return good_health;
}

void sim_health(int nutrition, int days)
{
    int rand_total = 0;
    int bad_total = 0;
    int good_total = 0;

    int rand_average = 0;
    int bad_average = 0;
    int good_average = 0;

    for (int i = 0; i < days; i++) {
        rand_total += sim_random_health(nutrition);
        bad_total += sim_bad_health(nutrition);
        good_total += sim_good_health(nutrition);
   }

    rand_average = rand_total / days;
    bad_average = bad_total / days;
    good_average = good_total / days;

    cout << "Simulation complete, this are the results for " << days << " days with " << nutrition << " nutrition daily:" << endl;
    cout << "Randomly: " << "[" << rand_average << "]" << endl;
    cout << "Min/max: " << "[" << bad_average << "," << good_average << "]" << endl;
}



int main()
{

    int nutrition = 0;
    int days = 0;
    bool exit = true;
    while (exit) {
        cout << "Enter the desired daily nutrition for simulation:" << endl;
        cin >> nutrition;
        cout << "Enter the desired number of days to simulate:" << endl;
        cin >> days;
        cout << "Running simulation..." << endl;
        sim_health(nutrition, days);
    }
    return 0;
}

