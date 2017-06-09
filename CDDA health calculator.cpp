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

void sim_health(int nutrition)
{
		int rand_health = 0;
		int good_health = 0;
		int bad_health = 0;
		
		int weeks = 2;
		int day_in_turns = 14400;
		
		/**
		// Limit healthy_mod to [-200, 200].
		// This also sets approximate bounds for the character's health.
		if (health > 200) {
			health = 200;
		}
		else if (health < -200) {
			health = -200;
		}
		*/
		

		// Over the long run, health tends toward healthy_mod.
		

		// But we allow some random variation.
		/*
		std::random_device rd;  //Will be used to obtain a seed for the random number engine
		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		std::uniform_int_distribution<> rng(-100, 100);
		*/

		

		// Loops that simulates the pass of time
		// The first one passes in days
		// Random loop
		for (int d = 0; d < weeks; d++) {
			// This one simulates the passing of a day
			for (int i = 0; i < day_in_turns; i++) {
				if (rand_health > 200) {
					rand_health = 100;
				}
				else if (rand_health < -200) {
					rand_health = -200;
					}

				int health_mod = 0;
				int break_even = rand_health - health_mod + nutrition;
				const long roll = rng(-100,100);
				if (roll > break_even) {
					rand_health += 1;
				}
				else if (roll < break_even) {
					rand_health -= 1;
				}

				// And healthy_mod decays over time.
				health_mod = (health_mod * 3 / 4);
		
			}
		}
		// Loops that simulates the pass of time
		// The first one passes in days
		// Bad loop
		for (int d = 0; d < weeks; d++) {
			// This one simulates the passing of a day
			for (int i = 0; i < day_in_turns; i++) {
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
		}

		// Loops that simulates the pass of time
		// The first one passes in days
		// Good loop
		for (int d = 0; d < weeks; d++) {
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
		}

		cout << "Simulation complete, this are the results:" << endl;
		cout << "Randomly: " << "[" << rand_health << "]" << endl;
		cout << "Min/max: " << "[" << bad_health << "," << good_health<<"]" <<endl;
}



int main()
{

	int nutrition = 0;
	bool exit = true;
	while (exit) {
		cout << "Enter the desired daily nutrition for a 2 weeks estimation:" <<endl;
		cin >> nutrition;
		cout << "Running simulation..."<< endl;
		sim_health(nutrition);
	}
    return 0;
}

