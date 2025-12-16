#include <iostream>

namespace targets {

    class Alien{

        private:
            
            int health { 3 };
            int tel_block_bomb { false };
            
        public:

            bool shield { false };
            int x_coordinate { };
            int y_coordinate { };

            Alien(int x, int y){
                
                x_coordinate = x;
                y_coordinate = y;
            }

            int get_health(){

                return health;
            }
            
            // referring to the object itself being hit, not another object of the same class being hit
            bool hit(){

                // reduces the health by 1, health can't go below 0
                if (get_health() > 0){

                    if ( shield ){

                        return false;
                    }

                    health --;
                    return true;    
                } else {

                    return false;
                }
            }

            bool is_alive(){

                return health != 0;
            }

            bool teleport( int new_x, int new_y ){

                if ( tel_block_bomb ){

                    return false;
                }

                x_coordinate = new_x;
                y_coordinate = new_y;

                return true;
            }

            // seeing if a given alien has collided with another
            bool collision_detection( targets::Alien newAlien ){

                return (newAlien.x_coordinate == x_coordinate) && (newAlien.y_coordinate == y_coordinate);
            }  
    };
}
