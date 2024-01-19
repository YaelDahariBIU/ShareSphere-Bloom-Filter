//
// Created by Tal on 12/01/2024.
//
#ifndef FACEBOOK_PROJECT_BLOOM_FILTER_H
#define FACEBOOK_PROJECT_BLOOM_FILTER_H
#include <iostream>
#include <list>
using namespace std;
int app();
void addBlackList(int[], int, string, int, list<string> *, hash<string>);
void addURL(string, list<string> *);
bool isBlackListed(string, list<string> *);
string checkFalsePositive(int[], int, list<string> *, int, string,
                          hash<string>);
#endif //FACEBOOK_PROJECT_BLOOM_FILTER_H
