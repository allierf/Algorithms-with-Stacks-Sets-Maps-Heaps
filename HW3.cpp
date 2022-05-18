#include <stack>
#include <queue>
#include <string>
#include <stdexcept>

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>



/*
 *I approached this problem by using the mode algorithm learned in class. I created two unordered maps to contain the elements from bucket and recipe.
 *I assigned the key to each different characters in the maps and counted the number of characters that appeared in the string. Next I implemeted the mode algorithm for both the maps.
 *Then I checked to see if the modes carried the same character then divided the buckets value by the recipe value to find the largest number of lego houses that can be created. 
 *This works because finding the largest number of legos needed to build the house can be used to determine the number of lego houses that can be built by buckets value divided by reciped value.  
 */
int countLegoHouses(std::string recipe, std::string bucket) {
     if(recipe.empty()){
        throw std::invalid_argument("Invalid syntax.");
    }
        std::unordered_map<char,int>recMap;
        std::unordered_map<char,int>bucMap;

    for (const char &c: recipe) {
        recMap[c]++;

    }
    for (const char &c: bucket) {
        bucMap[c]++;
    }

    char mode;
    int modeCount = 0;
    for(auto kv: recMap){
        if(kv.second > modeCount){
            mode=kv.first;
            modeCount = kv.second;
        }
    }
    char mode2;
    int modeCount2 = 0;
    for(auto kv: bucMap){
        if(kv.second > modeCount2){
            mode2=kv.first;
            modeCount2 = kv.second;
        }
    }
    if(mode == mode2){
        return modeCount2/modeCount;
    }else if(modeCount>modeCount2){
        return 0;
    }else{
       return bucMap[mode]/modeCount;
    }
}

/*
 * For this solution I created an unordered map called resluts that holds a string as the key and a vector of strings. The key is the sorted words and the vector holds all of the unsorted words with the same letters. This works because once all of the words are sorted, if they are in the same anagroup they sorted words will
 equal each other. Since the max length of each word is 20, sorting the words take O(1) time. Then adding them to the map takes O(n) time where n is the number of words. Then I find the mode of the vectors to see which group has the most words and return that vector.
 *
 */
std::vector<std::string> findLargestAnagroup(const std::vector<std::string>& words) {
     
    std::unordered_map<std::string,std::vector<std::string>> results;

std::string sorted;

    for(const std::string &s : words){
        sorted = s;
       sort(sorted.begin(),sorted.end());
           results[sorted].push_back(s);

    }
    int max = 0;
    std::string maxAnagroup;
    for(auto kv : results){
        if(kv.second.size()>max){
            max = kv.second.size();
            maxAnagroup = kv.first;
        }
    }
return results[maxAnagroup];  
}

/*
* For this solution I created a minimum priority queue that holds a pair. The pair is used to hold the value of sortedVecs and the index of which vector the value is from. The first for loop adds the first value of every vector to the queue which takes O(m) where m is the number of vectors created. Then a while loop is needed to itterate through the vector elements while adding the minimum value to a results vector. This works by looking at the top element of the queue and popping its value off and adding it to the results vector. Then the priority queue is updated with the next element of the vector thats element was previously popped.
*/
std::vector<double> mergeSortedLists(const std::vector<std::vector<double>>& sortedVecs) {
  
    typedef std::pair<double,int>pi;
    std::priority_queue<pi, std::vector<pi>, std::greater<pi>> pq;
    std::vector<double> results;

    std::vector<int> vecPointers(sortedVecs.size(),0);

    for(auto i = 0; i < sortedVecs.size(); i++){
        auto temp = vecPointers[i];
        // pq.push(std::make_pair(sortedVecs[i][temp],i));
        // (Sami) suggested change instead of the above line
        if (!sortedVecs[i].empty()) {
          pq.push(std::make_pair(sortedVecs[i][temp],i));
        }
    }
  
    while(!pq.empty()){
        std::pair<double,int> min = pq.top();
       
         results.push_back(min.first);
       
      auto index = min.second;
      pq.pop();
      vecPointers[index]++;
      
      if(vecPointers[index]<sortedVecs[index].size()) {
          pq.push(std::make_pair(sortedVecs[index][vecPointers[index]], index));
      }
    }
return results;
}
