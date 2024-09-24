#include<iostream>
using namespace std;

int lookup_recursive(string dict[], string word, int left, int right, int n)
{
    if(left == right)
    {
        if(word == dict[left])
            return left;
        else
            return -1;
    }
        

    int mid = (left + right) / 2;
    string mid_word = dict[mid];
    char mid_alpha = mid_word[0];
    char word_alpha = word[0];
    
    if(mid_alpha == word_alpha)
    {
        int i = mid;
        while(i>0 && dict[i][0] == word_alpha)
        {
            if(word == dict[i])
                return i;
            i--;
        }
        
        i = mid + 1;
        while(i<n && dict[i][0] == word_alpha)
        {
            if(word == dict[i])
                return i;
            i++;
        }
        
        return -1;
    }

    if(mid_alpha >= word_alpha)
        return lookup_recursive(dict, word, left, mid, n);
    else
        return lookup_recursive(dict, word, mid + 1, right, n);
}

int lookup(string dict[], string word, int n)
{
    return lookup_recursive(dict, word, 0, n-1, n);
}

int main()
{
    string dict[] = {
        "apple",
        "banana",
        "babi",
        "girl",
        "hieu",
        "huhu",
        "oppa",
        "onichan",
        "oho",
        "tu",
        "yamete",
    };

    cout<<lookup(dict, "onichan", 11);
}