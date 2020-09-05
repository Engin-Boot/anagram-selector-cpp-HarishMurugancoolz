#include "anagram.h"
#include<string>
using namespace std;
bool isInsideatoz(const char ch){
    if(ch>'a'&&ch<'z')
        return true;
    return false;
}
bool isInsideAtoZ(const char CH){
    if(CH>'A'&&CH<'Z')
        return true;
    return false;
}
void populateWordsForaz(int alphabets[],const string& word){
    for(unsigned int i_word=0;i_word<word.length();i_word++){
        if(isInsideatoz(word[i_word]))
            alphabets[word[i_word]-97]++;
    }
}
void populateWordsForAZ(int alphabets[],const string& word){
    for(unsigned int i_word=0;i_word<word.length();i_word++){
            if(isInsideAtoZ(word[i_word]))
            alphabets[word[i_word]-65]++;
    }
}
void dePopulateWordsForaz(int alphabets[],const string& word){
    for(unsigned int i_word=0;i_word<word.length();i_word++){
        if(isInsideatoz(word[i_word]))
            --alphabets[word[i_word]-97];
    }
}
void dePopulateWordsForAZ(int alphabets[],const string& word){
    for(unsigned int i_word=0;i_word<word.length();i_word++){
            if(isInsideAtoZ(word[i_word]))
            alphabets[word[i_word]-65]--;
    }
}
bool Anagram::WordPairIsAnagram(const string& word1, const string& word2) {
    int alphabets[26]={0};
    unsigned int total_alphabets=26;
    populateWordsForaz(alphabets,word1);
    populateWordsForAZ(alphabets,word1);
    dePopulateWordsForaz(alphabets,word2);
    dePopulateWordsForAZ(alphabets,word2);
    for(unsigned int i_alphabets=0;i_alphabets<total_alphabets;i_alphabets++){
        if(alphabets[i_alphabets]!=0)//all elements should br zero for anagram
            return false;
    }
    return true;
}
vector<string> Anagram::SelectAnagrams(const string& word,const vector<string>& candidates) {
    vector<string> anagramOfWords;
    for(int i_candidate=0;i_candidate<candidates.size();i_candidate++){
        if(WordPairIsAnagram(word,candidates[i_candidate]))
                anagramOfWords.push_back(candidates[i_candidate]);
    }
    return anagramOfWords;
}
