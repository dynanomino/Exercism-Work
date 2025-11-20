

// interest_rate returns the interest rate for the provided balance.
double interest_rate(double balance) {
    // TODO: Implement the interest_rate function

    double rate{};

    if (balance < 0){   

        rate = 3.213;
    }
    else if (balance >= 0 && balance < 1000){

        rate = 0.5;
    }
    else if (balance >= 1000 && balance < 5000){

        rate = 1.621;
    }
    else {

        rate = 2.475;
    }

    return rate;
}

// yearly_interest calculates the yearly interest for the provided balance.
double yearly_interest(double balance) {

    // TODO: Implement the yearly_interest function
    return interest_rate(balance)/100 * balance;
}

// annual_balance_update calculates the annual balance update, taking into
// account the interest rate.
double annual_balance_update(double balance) {

    // TODO: Implement the annual_balance_update function
    return yearly_interest(balance) + balance;
}

// years_until_desired_balance calculates the minimum number of years required
// to reach the desired balance.
int years_until_desired_balance(double balance, double target_balance) {

    double cur_balance{balance};
    int num_years{};

    while (cur_balance < target_balance){

        cur_balance = annual_balance_update(cur_balance);
        num_years += 1;
    }

    // TODO: Implement the years_until_desired_balance function
    return num_years;
}
