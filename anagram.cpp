#include "anagram.h"
#include<string>
using namespace std;
void populateWord1(int alphabets[],const string& word1)
{
    for(int i_word1=0;i_word1<word1.length();i_word1++)
    {
        if(word1[i_word1]>'a'&&word1[i_word1]<'z')
            alphabets[word1[i_word1]-97]++;
        else if(word1[i_word1]>'A'&&word1[i_word1]<'Z')
            alphabets[word1[i_word1]-65]++;
    }
}
void populateWord2(int alphabets[],const string& word2)
{
    for(int i_word2=0;i_word2<word2.length();i_word2++)
    {
        if(word2[i_word2]>'a'&&word2[i_word2]<'z')
            --alphabets[word2[i_word2]-97];
        else if(word2[i_word2]>'A'&&word2[i_word2]<'Z')
            --alphabets[word2[i_word2]-65];
    }
}
bool Anagram::WordPairIsAnagram(const string& word1, const string& word2) {
    int alphabets[26]={0};
    int total_alphabets=26;
    populateWord1(alphabets,word1);
    populateWord2(alphabets,word2);
    for(int i_alphabets=0;i_alphabets<total_alphabets;i_alphabets++)
    {
        if(alphabets[i_alphabets]!=0)
            return false;
    }
    return true;
}

vector<string> Anagram::SelectAnagrams(const string& word,const vector<string>& candidates) {
    vector<string> anagramOfWords;
    for(int i_candidate=0;i_candidate<candidates.size();i_candidate++)
    {
        if(WordPairIsAnagram(word,candidates[i_candidate]))
                anagramOfWords.push_back(candidates[i_candidate]);
    }
    
    return anagramOfWords;
}
