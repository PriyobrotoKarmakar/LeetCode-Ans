class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        //swap if need
        if(s1.length()<s2.length())
        swap(s1,s2);

        //deque
        deque<string> d1,d2;

        stringstream S1(s1);
        string word1;
        while(S1>>word1){
            d1.push_back(word1);
        }
        stringstream S2(s2);
        string word2;
        while(S2>>word2){
            d2.push_back(word2);
        }

        //prefix
        while(!d1.empty() && !d2.empty() && d1.front()==d2.front()){
            d1.pop_front();
            d2.pop_front();
        }
        //suffix
        while(!d1.empty() && !d2.empty() && d1.back()==d2.back()){
            d1.pop_back();
            d2.pop_back();
        }

        return d2.empty();
    }
};