//
//  string_distance_dynamic_programming.cpp
//  AlgorithmDesignBookImplementations
//
//  Created by Dan Olaru on 9/3/23.
//

#include "string_distance_dynamic_programming.hpp"

#include <iostream>
#include <cstring>
#include "string_distance.hpp"
using namespace std;

int MAXLEN = 100;

typedef struct {
    int cost;
    int parent;
} cell;

//cell m[MAXLEN+1][MAXLEN+1];
cell m[101][101];

void row_init(int i) {
    m[0][i].cost = i;
    
    if (i>0) m[0][i].parent = INSERT;
    else m[0][i].parent = -1;
}

void column_init(int i) {
    m[i][0].cost = i;
    if (i>0)
        m[i][0].parent = DELETE;
    else
        m[i][0].parent = -1;
}

void goal_cell(char *s, char *t, int *i, int *j)
{
  *i = strlen(s) - 1;
  *j = strlen(t) - 1;
}


void insert_out(char *t, int j)
{
    printf("I");
}

void delete_out(char *s, int i)
 {
    printf("D");
}

void match_out(char *s, char *t,int i, int j) {
    if (s[i]==t[j]) printf("M");
    else printf("S");
}


void print_matrix() {
    for (int i=0; i<14; i++) {
        for (int j=0; j<14; j++) {
            cout << m[i][j].parent;
            
        }
        cout << endl;
    }
}

void reconstruct_path(char *s, char *t, int i, int j) //TODO: doesn't return right result
 {
     if (m[i][j].parent == -1) return;
     if (m[i][j].parent == MATCH) {
             reconstruct_path(s,t,i-1,j-1);
             match_out(s, t, i, j);
             return;
     }
    
    if (m[i][j].parent == INSERT) {
        reconstruct_path(s,t,i,j-1);
        insert_out(t,j);
        return;
    }
    
     if (m[i][j].parent == DELETE) {
             reconstruct_path(s,t,i-1,j);
             delete_out(s,i);
             return;
    }
}

int string_compare_dynamic_programming(char *s, char *t)
{
    int i,j,k;              /* counters */
    int opt[3];             /* cost of the three options */
    for (i=0; i<MAXLEN; i++) {
        row_init(i);
        column_init(i);
    }
    for (i=1; i<strlen(s); i++) {
        for (j=1; j<strlen(t); j++) {
            opt[MATCH] = m[i-1][j-1].cost + match(s[i],t[j]);
            opt[INSERT] = m[i][j-1].cost + indel(t[j]);
            opt[DELETE] = m[i-1][j].cost + indel(s[i]);
            m[i][j].cost = opt[MATCH];
            m[i][j].parent = MATCH;
            for (k=INSERT; k<=DELETE; k++)
                if (opt[k] < m[i][j].cost) {
                    m[i][j].cost = opt[k];
                    m[i][j].parent = k;
                }
        }
    }
    goal_cell(s,t,&i,&j);
    return( m[i][j].cost );
}


