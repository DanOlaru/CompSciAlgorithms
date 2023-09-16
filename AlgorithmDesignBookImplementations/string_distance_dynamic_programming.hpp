//
//  string_distance_dynamic_programming.hpp
//  AlgorithmDesignBookImplementations
//
//  Created by Dan Olaru on 9/3/23.
//

#ifndef string_distance_dynamic_programming_hpp
#define string_distance_dynamic_programming_hpp

#include <stdio.h>
int string_compare_dynamic_programming(char *s, char *t);
void reconstruct_path(char *s, char *t, int i, int j);
void print_matrix();

#endif /* string_distance_dynamic_programming_hpp */
