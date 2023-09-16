//
//  string_distance.cpp
//  AlgorithmDesignBookImplementations
//
//  Created by Dan Olaru on 9/3/23.
//

#include "string_distance.hpp"

int indel(char argument) {
    return 1;
}

int match(char c, char d)
{
  if (c == d) return(0);
  else return(1); 
}

int string_compare(char *s, char *t, int i, int j) {
    int k;
    int opt[3];
    int lowest_cost;
    
    if (i==0) return (j * indel(' '));
    if (j==0) return (i * indel(' '));
    
    opt[MATCH] = string_compare(s, t, i-1, j-1) + match(s[i], t[j]) ;
    opt[INSERT] = string_compare(s,t,i,j-1) + indel(t[j]);
    opt[DELETE] = string_compare(s,t,i-1,j) + indel(s[i]);
    
    
    lowest_cost = opt[MATCH];
    for (k=INSERT; k<=DELETE; k++)
            if (opt[k] < lowest_cost) lowest_cost = opt[k];
    return( lowest_cost );
    
}
