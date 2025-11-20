// ovenTime returns the amount in minutes that the lasagna should stay in the
// oven.
int ovenTime() {

    // 40 mins is the standard time for cooking a lasagna
    int expected_oven_time { 40 };

    return expected_oven_time;
}

/* remainingOvenTime returns the remaining
   minutes based on the actual minutes already in the oven.
*/
int remainingOvenTIme(int actualMinutesInOven){

    return ( ovenTime() - actualMinutesInOven );

}

/* preparationTime returns an estimate of the preparation time based on the
   number of layers and the necessary time per layer.
*/
int preparationTIme(int numberOfLayers){
    // TODO: Calculate and return the preparation time with the
    // `numberOfLayers`.

    // layers take 2 mins to prepare
    int time_layer_prep { 2 };

    return ( time_layer_prep * numberOfLayers );
}

// elapsedTime calculates the total time spent to create and bake the lasagna so
// far.
int elapsedTime(int numberOfLayers, int actualMinutesInOven){

    // so far, it's the time it took to prepare plus how long it's been in oven
    return ( preparationTIme(numberOfLayers) + actualMinutesInOven );
}
