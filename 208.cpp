#include <vector>
#include <string>
using namespace std;
struct ListNoded{
    vector<ListNoded*> data;
    ListNoded() : data(27, nullptr) {

    }
};
class Trie {
    ListNoded* tri;
public:
    Trie() {
        tri=new ListNoded();
    }
    
    void insert(string word) {
        ListNoded* tmp=tri;
        for(int i=0;i<word.size();i++){
            int k=word[i]-'a';
            if(!tmp->data[k])
                tmp->data[k]=new ListNoded();
            tmp= tmp->data[k];
        }
        tmp->data[26]=new ListNoded();
    }
    
    bool search(string word) {
        ListNoded* tmp=tri;
        for(int i=0;i<word.size();i++){
            int k=word[i]-'a';
            if(!tmp->data[k])
                return false;
            else
                tmp= tmp->data[k];
        }
        if(!tmp->data[26])
            return false;
        return true;
        
    }
    
    bool startsWith(string prefix) {
        ListNoded* tmp=tri;
        for(int i=0;i<prefix.size();i++){
            int k=prefix[i]-'a';
            if(!tmp->data[k])
                return false;
            else
                tmp= tmp->data[k];
        }

        return true;
        
    }
};