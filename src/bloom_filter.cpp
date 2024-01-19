//
// Created by Tal on 12/01/2024.
//
#include "../header/bloom_filter.h"
#include <iostream>
#include <list>
#include <string>
using namespace std;

string checkFalsePositive(int arr[], int arraySize, list<string> *lst, int
hashNum, string url, hash<string> myHashing) {
    //saving hashing on the first url
    size_t hashPlacing = myHashing(url);
    //doing modulu in order to get a place in the array
    size_t placeInArray = hashPlacing%(arraySize);
    if(hashNum==1) {
        //if we use one hash function, check if the array is already
        // blacklisted in this point.
        if(*(arr+placeInArray)==1) {
            //check if the url exists in the list
            if(!isBlackListed(url, lst)) {
                return "true false";
            }
            else {
                //the url exists
                return "true true";
            }
        }
        else {
            //if it was not found then its false
            return "false";
        }
    }
    if(hashNum==2)
    {
        //use the second hash function
        size_t hashPlacingSecond = myHashing(to_string(hashPlacing));
        size_t placeInArraySecond = hashPlacingSecond%(arraySize);
        //check if the array is already blacklisted in this point.
        if(*(arr+placeInArraySecond)==1) {
            //check if the url exists in the list
            if(!isBlackListed(url, lst)) {
                return "true false";
            } else {
                return "true true";
            }
        }
        else {
            //if it was not found in the array it is false
            return "false";
        }
    }
    if(hashNum==3) {
        //use both first and the second hash function
        size_t hashPlacingSecond = myHashing(to_string(hashPlacing));
        size_t placeInArraySecond = hashPlacingSecond%(arraySize);
        //check if the array is already blacklisted at both point.
        if(*(arr+placeInArray)==1 && *(arr+placeInArraySecond)==1) {
            if(!isBlackListed(url, lst)) {
                //check if the url exists in the list
                return "true false";
            }
            else {
                return "true true";
            }
        }
        else {
            //if it was not found in the array it is false
            return "false";
        }
    }

}

//adding url to the blacklist of url's
void addURL(string url, list<string> *lst) {
    //adding url to the end of the list
    (*lst).push_back(url);
}

//checking if an url is already in the list.
bool isBlackListed(string url, list<string> *lst) {
    list<string> temp = *lst;
    //going over all strings in black list, and checking if we have a match
    for (string search_url : temp) {
        if(url.compare(search_url)==0) {
            return true;
        }
    }
    return false;
}
void addBlackList(int arr[], int hashNum, string url, int arraySize,
                  list<string> *lst, hash<string> myHashing) {
    //saving hashing on the first url
    size_t hashPlacing = myHashing(url);
    //doing modulu in order to get a place in the array
    size_t placeInArray = hashPlacing%(arraySize);
    if(hashNum==1) {
        //if we use one hash function, check if the array is already
        // blacklisted in this point.
        if(*(arr+placeInArray)==1) {
            //check if the url exists in the list
            if(!isBlackListed(url, lst)) {
                //if not, add it
                addURL(url, lst);
            }
        }
        else {
            //if it was not found in the array add it
            arr[placeInArray]=1;
            addURL(url, lst);
        }
    }
    if(hashNum==2)
    {
        //use the second hash function
        size_t hashPlacingSecond = myHashing(to_string(hashPlacing));
        size_t placeInArraySecond = hashPlacingSecond%(arraySize);
        //check if the array is already blacklisted in this point.
        if(*(arr+placeInArraySecond)==1) {
            //check if the url exists in the list
            if(!isBlackListed(url, lst)) {
                addURL(url, lst);
            }
        }
        else {
            //if it was not found in the array add it
            arr[placeInArraySecond]=1;
            addURL(url, lst);
        }
    }
    if(hashNum==3) {
        //use both first and the second hash function
        size_t hashPlacingSecond = myHashing(to_string(hashPlacing));
        size_t placeInArraySecond = hashPlacingSecond%(arraySize);
        //check if the array is already blacklisted at both point.
        if(*(arr+placeInArray)==1 && *(arr+placeInArraySecond)==1) {
            if(!isBlackListed(url, lst)) {
                //check if the url exists in the list
                addURL(url, lst);
            }
        }
        else {
            //if it was not found in the array add it
            arr[placeInArray]=1;
            arr[placeInArraySecond]=1;
            addURL(url, lst);
        }
    }
}

int app() {
    //this code has a lot of code smells, but this is only the first step.
    //on the next commits you will be able to see the evaluation of our code
    // to include OOP structure.
    //creating hash function
    hash<string> firstHash;
    list<string> lstURL;
    int arraySize;
    int hashNum;
    //getting input from the user
    cin >> arraySize;
    cin >> hashNum;
    //create an array
    int blackList[arraySize];
    //reset all elemnts to zero.
    for (int i=0;i<arraySize;i++) {
        blackList[i]=0;
    }
    std::cin.clear();
    int choice;
    string url;
    while (true) {
        //get users choice and url.
        cin >> choice;
        cin >> url;
        switch (choice) {
            case 1:
                //add the url to the bloom filter
                addBlackList(blackList, hashNum, url, arraySize, &lstURL, firstHash);
                break;
            case 2:
                //check if the url already in the bloom filter, and check for
                // false positives.
                cout << checkFalsePositive(blackList, arraySize,&lstURL,hashNum,
                                        url,
                                   firstHash)<<endl;
                break;
        }
    }
}
