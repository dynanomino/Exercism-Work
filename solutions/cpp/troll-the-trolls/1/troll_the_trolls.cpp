#include <iostream>
#include <string>

namespace hellmath {

    enum class AccountStatus{

        troll,
        guest,
        user,
        mod
    };

    enum class Action{

        read,
        write,
        remove
    };

    bool display_post(AccountStatus poster, AccountStatus viewer){

        // case for troll-troll, troll-anyone_but_troll, anyone_but_troll-troll, and not_troll-not_troll
        // using switches on just the poster status, to then determine necessary logic

        switch (static_cast<int>(poster) + 1)
        {
            case 1:
                
                return viewer == AccountStatus::troll;
                break;
                
            default:
                return true;
        }
    }

    bool permission_check( Action action, AccountStatus player ){

        switch (static_cast<int>(action) + 1)
        {
            case 1:
                
                return true;
                break;
            
            case 2:

                return player != AccountStatus::guest;
                break;
            
            default:
                
                return player == AccountStatus::mod;
        }
    }

    bool valid_player_combination(AccountStatus player1, AccountStatus player2){

        switch (static_cast<int>(player1) + 1)
        {
            case 1:
                
                return player2 == AccountStatus::troll;
                break;
                
            case 2:

                return false;
                break;

            default:
                return !(player2 == AccountStatus::guest || player2 == AccountStatus::troll);
        }
    }

    bool has_priority(AccountStatus player1, AccountStatus player2){

        // any account type doesn't have priority over the same account type
        switch (static_cast<int>(player1) + 1)
        {   
            
            case 1:

                return false;
                break;
            
            case 2:

                switch (static_cast<int>(player2) + 1)
                {
                    case 1:

                        return true;
                        break;

                    default:
                        return false;
                }
                break;
            
            case 3:

                switch (static_cast<int>(player2) + 1)
                {
                    case 1:
                    case 2:
                        return true;
                        break;

                    default:
                        return false;
                }
                break;

            default:
                
                return player2 != AccountStatus::mod;
        }
    }
}
