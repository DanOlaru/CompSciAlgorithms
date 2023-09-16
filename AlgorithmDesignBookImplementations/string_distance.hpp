//
//  string_distance.hpp
//  AlgorithmDesignBookImplementations
//
//  Created by Dan Olaru on 9/3/23.
//

#ifndef string_distance_hpp
#define string_distance_hpp

#include <stdio.h>

#define MATCH       0
#define INSERT      1
#define DELETE      2

int indel(char argument);
int match(char c, char d);
int string_compare(char *s, char *t, int i, int j);

#endif /* string_distance_hpp */
